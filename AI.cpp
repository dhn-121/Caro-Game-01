#include "AI.h"
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

// =================================================================================
// CẤU HÌNH CHO AI (BOSS MODE)
// =================================================================================

// Điểm số cho các chuỗi liên tiếp (0, 1, 2, 3, 4, 5 quân)
// Tăng theo cấp số nhân để AI biết sợ khi đối thủ sắp thắng
const long long SCORE_BY_COUNT[] = {0, 10, 200, 8000, 500000, 1000000000LL};

const int SEARCH_RADIUS = 2;       // Bán kính tìm kiếm quanh các quân cờ đã đánh
const int MAX_CANDIDATES = 15;     // Giới hạn số nước đi tốt nhất để tính toán (Top-K)
const int MINIMAX_DEPTH = 5;       // Độ sâu suy nghĩ (5 là ổn với cấu trúc này)

// Cấu trúc lưu nước đi để sắp xếp
struct Move {
    int r, c;
    long long score;
    Move(int rr = -1, int cc = -1, long long s = 0) : r(rr), c(cc), score(s) {}
};

// Mảng điểm cho chế độ Normal
const long ARR_SCORES[] = { 0, 10, 100, 1000, 10000, 1000000 };

long calculateScore(int r, int c, int dr, int dc, char board[N][N], char player) {
    long score = 0;
    int count = 0;
    int openEnds = 0;

    for (int i = 1; i < 5; i++) {
        if (r + i * dr >= 0 && r + i * dr < BOARD_SIZE && c + i * dc >= 0 && c + i * dc < BOARD_SIZE && board[r + i * dr][c + i * dc] == player) count++;
        else {
            if (r + i * dr >= 0 && r + i * dr < BOARD_SIZE && c + i * dc >= 0 && c + i * dc < BOARD_SIZE && board[r + i * dr][c + i * dc] == '-') openEnds++;
            break;
        }
    }
    for (int i = 1; i < 5; i++) {
        if (r - i * dr >= 0 && r - i * dr < BOARD_SIZE && c - i * dc >= 0 && c - i * dc < BOARD_SIZE && board[r - i * dr][c - i * dc] == player) count++;
        else {
            if (r - i * dr >= 0 && r - i * dr < BOARD_SIZE && c - i * dc >= 0 && c - i * dc < BOARD_SIZE && board[r - i * dr][c - i * dc] == '-') openEnds++;
            break;
        }
    }

    if (count >= 5) return ARR_SCORES[5];
    if (openEnds == 0 && count < 5) return 0;

    score = ARR_SCORES[count];
    if (openEnds == 2) score *= 2;
    else if (openEnds == 1) score *= 1.5;

    return score;
}

// NORMAL MODE AI
void getBestMove(char board[N][N], int& bestRow, int& bestCol, char aiPlayer) {
    long maxScore = -1;
    char humanPlayer = (aiPlayer == 'X') ? 'O' : 'X';
    bestRow = -1; bestCol = -1;

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == '-') {
                board[i][j] = aiPlayer;
                long attackScore = 0;
                attackScore += calculateScore(i, j, 0, 1, board, aiPlayer);
                attackScore += calculateScore(i, j, 1, 0, board, aiPlayer);
                attackScore += calculateScore(i, j, 1, 1, board, aiPlayer);
                attackScore += calculateScore(i, j, 1, -1, board, aiPlayer);
                board[i][j] = '-';

                board[i][j] = humanPlayer;
                long defenseScore = 0;
                defenseScore += calculateScore(i, j, 0, 1, board, humanPlayer);
                defenseScore += calculateScore(i, j, 1, 0, board, humanPlayer);
                defenseScore += calculateScore(i, j, 1, 1, board, humanPlayer);
                defenseScore += calculateScore(i, j, 1, -1, board, humanPlayer);
                board[i][j] = '-';

                long totalScore = attackScore + defenseScore;
                if (totalScore > maxScore) {
                    maxScore = totalScore;
                    bestRow = i;
                    bestCol = j;
                }
            }
        }
    }
}

// EASY MODE AI
void getEasyMove(char board[N][N], int& row, int& col) {
    std::vector<std::pair<int, int>> emptyCells;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == '-') {
                emptyCells.push_back({ i, j });
            }
        }
    }
    if (!emptyCells.empty()) {
        int index = rand() % emptyCells.size();
        row = emptyCells[index].first;
        col = emptyCells[index].second;
    }
    else {
        row = -1; col = -1;
    }
}

// =================================================================================
// HARD MODE AI (BOSS LOGIC - ADAPTED)
// =================================================================================

// Kiểm tra tọa độ có hợp lệ không
inline bool inBounds(int r, int c) {
    return r >= 0 && r < BOARD_SIZE && c >= 0 && c < BOARD_SIZE;
}
//HỆ THỐNG ADAPTIVE DEPTH
int getAdaptiveDepth(char board[N][N]) {
    int pieceCount = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] != '-') pieceCount++;
        }
    }

    // Điều chỉnh depth dựa trên số quân cờ
    if (pieceCount < 10) return 5;        // Đầu game: Suy nghĩ sâu
    else if (pieceCount < 30) return 4;   // Giữa game: Cân bằng
    else if (pieceCount < 60) return 3;   // Muộn game: Giảm depth
    else return 2;                        // Rất muộn: Chỉ nhìn 2 bước
}
//TRANSPOSITION TABLE (CACHE KẾT QUẢ)
struct TranspositionEntry {
    long long score;
    int depth;
};

unordered_map<string, TranspositionEntry> transTable;

// Hash bàn cờ thành string để lưu cache
string hashBoard(char board[N][N]) {
    string hash = "";
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            hash += board[i][j];
        }
    }
    return hash;
}
// Kiểm tra thắng thua nhanh
bool isWin(char board[N][N], int r, int c, char player) {
    const int dirs[4][2] = { {0,1},{1,0},{1,1},{1,-1} };
    for (int d = 0; d < 4; ++d) {
        int cnt = 1;
        int dr = dirs[d][0], dc = dirs[d][1];
        // Forward
        for (int k = 1; k < 5; k++) {
            int nr = r + dr * k, nc = c + dc * k;
            if (!inBounds(nr, nc) || board[nr][nc] != player) break;
            cnt++;
        }
        // Backward
        for (int k = 1; k < 5; k++) {
            int nr = r - dr * k, nc = c - dc * k;
            if (!inBounds(nr, nc) || board[nr][nc] != player) break;
            cnt++;
        }
        if (cnt >= 5) return true;
    }
    return false;
}

// Tính điểm chi tiết cho một hướng (Dùng cho hàm evaluate)
long long scoreDirectionBoss(char board[N][N], int r, int c, int dr, int dc, char player) {
    int cnt = 1;
    int openEnds = 0;

    // Forward
    for (int k = 1; k < 5; k++) {
        int nr = r + dr * k, nc = c + dc * k;
        if (!inBounds(nr, nc)) break;
        if (board[nr][nc] == player) cnt++;
        else {
            if (board[nr][nc] == '-') openEnds++;
            break;
        }
    }
    // Backward
    for (int k = 1; k < 5; k++) {
        int nr = r - dr * k, nc = c - dc * k;
        if (!inBounds(nr, nc)) break;
        if (board[nr][nc] == player) cnt++;
        else {
            if (board[nr][nc] == '-') openEnds++;
            break;
        }
    }

    if (cnt >= 5) return SCORE_BY_COUNT[5];
    if (openEnds == 0 && cnt < 5) return 0;

    long long base = SCORE_BY_COUNT[std::min(5, cnt)];
    if (openEnds == 2) base *= 2;        // 2 đầu mở -> Ngon
    else if (openEnds == 1) base = (base * 3) / 2; // 1 đầu mở -> Tạm

    return base;
}

// Đánh giá sơ bộ một nước đi (Heuristic) để lọc Candidates
long long evaluateMoveScore(char board[N][N], int r, int c, char aiChar, char humanChar) {
    if (!inBounds(r, c) || board[r][c] != '-') return 0;

    // Giả lập AI đi
    long long total = 0;
    board[r][c] = aiChar;
    const int dirs[4][2] = { {0,1},{1,0},{1,1},{1,-1} };
    for (int d = 0; d < 4; ++d) {
        total += scoreDirectionBoss(board, r, c, dirs[d][0], dirs[d][1], aiChar);
    }
    board[r][c] = '-';

    // Giả lập Human đi (để tính điểm chặn)
    board[r][c] = humanChar;
    long long totalBlock = 0;
    for (int d = 0; d < 4; ++d) {
        totalBlock += scoreDirectionBoss(board, r, c, dirs[d][0], dirs[d][1], humanChar);
    }
    board[r][c] = '-';

    // Tổng điểm = Công + Thủ * Hệ số (Ưu tiên thủ)
    return total + totalBlock;
}

// Đánh giá toàn bộ bàn cờ (Leaf node evaluation)
long long evaluateBoardBoss(char board[N][N], char aiChar, char humanChar) {
    long long attack = 0, defense = 0;

    // Chỉ quét trong vùng có quân cờ (bỏ qua vùng trống)
    int minR = BOARD_SIZE, maxR = 0, minC = BOARD_SIZE, maxC = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] != '-') {
                minR = min(minR, i);
                maxR = max(maxR, i);
                minC = min(minC, j);
                maxC = max(maxC, j);
            }
        }
    }

    // Mở rộng vùng quét thêm 2 ô
    minR = max(0, minR - 2);
    maxR = min(BOARD_SIZE - 1, maxR + 2);
    minC = max(0, minC - 2);
    maxC = min(BOARD_SIZE - 1, maxC + 2);

    // Chỉ tính điểm trong vùng này
    for (int i = minR; i <= maxR; i++) {
        for (int j = minC; j <= maxC; j++) {
            if (board[i][j] == aiChar) {
                const int dirs[4][2] = { {0,1},{1,0},{1,1},{1,-1} };
                for (int d = 0; d < 4; ++d)
                    attack += scoreDirectionBoss(board, i, j, dirs[d][0], dirs[d][1], aiChar);
            }
            else if (board[i][j] == humanChar) {
                const int dirs[4][2] = { {0,1},{1,0},{1,1},{1,-1} };
                for (int d = 0; d < 4; ++d)
                    defense += scoreDirectionBoss(board, i, j, dirs[d][0], dirs[d][1], humanChar);
            }
        }
    }

    return attack - defense * 2; // AI sợ thua nên trọng số thủ cao hơn
}

// Tìm các nước đi ứng viên (Chỉ tìm xung quanh các quân đã đánh)
vector<pair<int, int>> generateCandidates(char board[N][N]) {
    bool mark[BOARD_SIZE][BOARD_SIZE] = { false };
    vector<pair<int, int>> candidates;

    // Ưu tiên các ô gần quân cờ gần đây nhất
    bool anyStone = false;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] != '-') {
                anyStone = true;
                // CHỈ quét bán kính 2 để giảm candidates
                for (int dr = -SEARCH_RADIUS; dr <= SEARCH_RADIUS; ++dr) {
                    for (int dc = -SEARCH_RADIUS; dc <= SEARCH_RADIUS; ++dc) {
                        if (dr == 0 && dc == 0) continue;
                        int nr = i + dr, nc = j + dc;
                        if (inBounds(nr, nc) && board[nr][nc] == '-' && !mark[nr][nc]) {
                            mark[nr][nc] = true;
                            candidates.push_back({ nr, nc });
                        }
                    }
                }
            }
        }
    }

    if (!anyStone) {
        candidates.push_back({ BOARD_SIZE / 2, BOARD_SIZE / 2 });
    }

    return candidates;
}

// Lọc và sắp xếp ứng viên (Move Ordering) để Minimax cắt tỉa tốt hơn
vector<pair<int, int>> selectTopCandidates(char board[N][N], vector<pair<int, int>>& raw, char aiChar, char humanChar) {
    vector<Move> scored;
    scored.reserve(raw.size());

    for (auto& p : raw) {
        long long score = evaluateMoveScore(board, p.first, p.second, aiChar, humanChar);
        scored.push_back(Move(p.first, p.second, score));
    }

    // Sắp xếp điểm từ cao xuống thấp
    std::sort(scored.begin(), scored.end(), [](const Move& a, const Move& b) {
        return a.score > b.score;
        });

    vector<pair<int, int>> out;
    int limit = std::min((int)scored.size(), MAX_CANDIDATES);
    for (int i = 0; i < limit; i++) {
        out.push_back({ scored[i].r, scored[i].c });
    }
    return out;
}

// Hàm Minimax đệ quy với Alpha-Beta Pruning
long long minimax_boss(char board[N][N], int depth, long long alpha, long long beta, bool maximizingPlayer, char aiChar, char humanChar,bool useCache = true) {
    // Kiểm tra cache
    if (useCache && depth > 0) {
        string hash = hashBoard(board);
        if (transTable.find(hash) != transTable.end()) {
            TranspositionEntry& entry = transTable[hash];
            if (entry.depth >= depth) {
                return entry.score;  // Dùng kết quả đã tính
            }
        }
    }

    if (depth == 0) return evaluateBoardBoss(board, aiChar, humanChar);

    vector<pair<int, int>> raw = generateCandidates(board);
    if (raw.empty()) return 0;

    vector<pair<int, int>> candidates = selectTopCandidates(board, raw, aiChar, humanChar);

    if (maximizingPlayer) {
        long long maxEval = -LLONG_MAX;
        for (auto& mv : candidates) {
            int r = mv.first, c = mv.second;
            board[r][c] = aiChar;

            if (isWin(board, r, c, aiChar)) {
                board[r][c] = '-';
                return SCORE_BY_COUNT[5];
            }

            long long eval = minimax_boss(board, depth - 1, alpha, beta, false, aiChar, humanChar, useCache);
            board[r][c] = '-';

            maxEval = max(maxEval, eval);
            alpha = max(alpha, eval);
            if (beta <= alpha) break;  // Pruning
        }

        // Lưu cache
        if (useCache) {
            string hash = hashBoard(board);
            transTable[hash] = { maxEval, depth };
        }

        return maxEval;
    }
    else {
        long long minEval = LLONG_MAX;
        for (auto& mv : candidates) {
            int r = mv.first, c = mv.second;
            board[r][c] = humanChar;

            if (isWin(board, r, c, humanChar)) {
                board[r][c] = '-';
                return -SCORE_BY_COUNT[5];
            }

            long long eval = minimax_boss(board, depth - 1, alpha, beta, true, aiChar, humanChar, useCache);
            board[r][c] = '-';

            minEval = min(minEval, eval);
            beta = min(beta, eval);
            if (beta <= alpha) break;  // Pruning
        }

        // Lưu cache
        if (useCache) {
            string hash = hashBoard(board);
            transTable[hash] = { minEval, depth };
        }

        return minEval;
    }
}

// ================= ENTRY POINT CHO HARD MODE =================
void getSmartMove(char board[N][N], int& bestRow, int& bestCol, char aiPlayer) {
    char humanPlayer = (aiPlayer == 'X') ? 'O' : 'X';

    auto startTime = chrono::high_resolution_clock::now();

    // Xóa cache cũ nếu quá lớn (tránh memory leak)
    if (transTable.size() > 100000) {
        transTable.clear();
    }

    // Tính adaptive depth dựa trên số quân cờ
    int adaptiveDepth = getAdaptiveDepth(board);

    vector<pair<int, int>> raw = generateCandidates(board);

    if (raw.empty()) {
        bestRow = BOARD_SIZE / 2;
        bestCol = BOARD_SIZE / 2;
        return;
    }

    // ========== BƯỚC 1: KIỂM TRA THẮNG NGAY ==========
    for (auto& mv : raw) {
        int r = mv.first, c = mv.second;
        board[r][c] = aiPlayer;
        if (isWin(board, r, c, aiPlayer)) {
            board[r][c] = '-';
            bestRow = r;
            bestCol = c;
            return;
        }
        board[r][c] = '-';
    }

    // ========== BƯỚC 2: CHẶN NƯỚC THẮNG ĐỐI THỦ ==========
    for (auto& mv : raw) {
        int r = mv.first, c = mv.second;
        board[r][c] = humanPlayer;
        if (isWin(board, r, c, humanPlayer)) {
            board[r][c] = '-';
            bestRow = r;
            bestCol = c;
            return;
        }
        board[r][c] = '-';
    }

    // ========== BƯỚC 3: PHÁT HIỆN MỐI ĐE DỌA 4 QUÂN ==========
    struct ThreatMove {
        int r, c;
        int count;
        int openEnds;
        bool operator<(const ThreatMove& other) const {
            if (count != other.count) return count > other.count;
            return openEnds > other.openEnds;
        }
    };

    vector<ThreatMove> threats;

    for (auto& mv : raw) {
        int r = mv.first, c = mv.second;
        board[r][c] = humanPlayer;

        const int dirs[4][2] = { {0,1},{1,0},{1,1},{1,-1} };
        for (int d = 0; d < 4; ++d) {
            int dr = dirs[d][0], dc = dirs[d][1];
            int cnt = 1, openEnds = 0;

            for (int k = 1; k < 5; k++) {
                int nr = r + dr * k, nc = c + dc * k;
                if (!inBounds(nr, nc)) break;
                if (board[nr][nc] == humanPlayer) cnt++;
                else {
                    if (board[nr][nc] == '-') openEnds++;
                    break;
                }
            }

            for (int k = 1; k < 5; k++) {
                int nr = r - dr * k, nc = c - dc * k;
                if (!inBounds(nr, nc)) break;
                if (board[nr][nc] == humanPlayer) cnt++;
                else {
                    if (board[nr][nc] == '-') openEnds++;
                    break;
                }
            }

            if ((cnt >= 4 && openEnds >= 1) || (cnt == 3 && openEnds == 2)) {
                threats.push_back({ r, c, cnt, openEnds });
                break;
            }
        }
        board[r][c] = '-';
    }

    if (!threats.empty()) {
        sort(threats.begin(), threats.end());
        bestRow = threats[0].r;
        bestCol = threats[0].c;
        return;
    }

    // ========== BƯỚC 4: MINIMAX VỚI ADAPTIVE DEPTH ==========
    vector<pair<int, int>> candidates = selectTopCandidates(board, raw, aiPlayer, humanPlayer);

    long long bestVal = -LLONG_MAX;
    pair<int, int> bestMove = candidates[0];

    for (auto& mv : candidates) {
        int r = mv.first, c = mv.second;

        board[r][c] = aiPlayer;

        // Sử dụng adaptive depth thay vì cố định
        long long val = minimax_boss(board, adaptiveDepth - 1, -LLONG_MAX, LLONG_MAX,
            false, aiPlayer, humanPlayer, true);

        long long base = evaluateMoveScore(board, r, c, aiPlayer, humanPlayer);
        val += base / 10;

        board[r][c] = '-';

        if (val > bestVal) {
            bestVal = val;
            bestMove = { r, c };
        }

        // TIME LIMIT: Nếu đã tính quá 5 giây, dừng ngay
        auto currentTime = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::milliseconds>(currentTime - startTime).count();
        if (elapsed > 5000) {  // 5 giây
            break;
        }
    }

    bestRow = bestMove.first;
    bestCol = bestMove.second;

}
void resetAI() {
    transTable.clear();
}
