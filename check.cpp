#include "Library.h"
using namespace std;
bool has_empty_cell = 0;
bool test_board(char ch, int x1, int y1, char A[N][N])
{
    int m, n;
    if (ch == 79) { m = 79; n = 88; }
    else { m = 88; n = 79; }
    for (int i = 0; i < 5; i++)
    {
        if (A[x1 - 4 + i][y1] == m && A[x1 - 3 + i][y1] == m && A[x1 - 2 + i][y1] == m && A[x1 - 1 + i][y1] == m && A[x1 + i][y1] == m)
            if (A[x1 - 5 + i][y1] != n || A[x1 + 1 + i][y1] != n) return 1;
    }
    for (int i = 0; i < 5; i++)
    {
        if (A[x1][y1 - 4 + i] == m && A[x1][y1 - 3 + i] == m && A[x1][y1 - 2 + i] == m && A[x1][y1 - 1 + i] == m && A[x1][y1 + i] == m)
            if (A[x1][y1 - 5 + i] != n || A[x1][y1 + 1 + i] != n) return 1;
    }
    for (int i = 0; i < 5; i++)
    {
        if (A[x1 - 5 + i][y1 - 5 + i] != n || A[x1 + 1 + i][y1 + 1 + i] != n) return 1;
    }
    for (int i = 0; i < 5; i++)
    {
        if (A[x1 + 5 - i][y1 - 5 + i] != n || A[x1 - 1 - i][y1 + 1 + i] != n) return 1;
    }
    return 0;
}
//int check_game_status(const vector<vector<int>>& board, int size, int k) {
//    // 8 hướng di chuyển: ngang, dọc, 2 đường chéo
//    int dr[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
//    int dc[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
//
//    // Vòng lặp kiểm tra từng ô trên bảng
//    for (int r = 0; r < size; ++r) {
//        for (int c = 0; c < size; ++c) {
//            int player = board[r][c];
//            // Bỏ qua ô trống
//            if (player == 0) {
//                continue;
//            }
//
//            // Kiểm tra 4 hướng chính (ngang phải, dọc xuống, chéo phải-xuống, chéo trái-xuống)
//            // Chỉ cần kiểm tra 4 hướng này, vì các hướng ngược lại sẽ được kiểm tra từ ô khác.
//            for (int dir = 0; dir < 4; ++dir) {
//                int count = 1; // Bắt đầu với quân hiện tại
//
//                for (int i = 1; i < k; ++i) {
//                    int nr = r + dr[dir] * i;
//                    int nc = c + dc[dir] * i;
//
//                    if (nr >= 0 && nr < size && nc >= 0 && nc < size && board[nr][nc] == player) {
//                        count++;
//                    }
//                    else {
//                        break; // Đã ra khỏi biên hoặc gặp quân khác
//                    }
//                }
//
//                // Nếu đạt đủ số quân liên tiếp (k), thì thắng
//                if (count >= k) {
//                    return player; // Trả về 1 hoặc 2
//                }
//            }
//        }
//    }

    // Sau khi kiểm tra hết các ô mà chưa có ai thắng, kiểm tra xem còn ô trống không
//    bool has_empty_cell = false;
//    for (int r = 0; r < size; ++r) {
//        for (int c = 0; c < size; ++c) {
//            if (board[r][c] == 0) {
//                has_empty_cell = true;
//                break;
//            }
//        }
//        if (has_empty_cell) break;
//    }
//
//    // Nếu còn ô trống, game đang tiếp diễn
//    if (has_empty_cell) {
//        return 0; // Đang chơi
//    }
//    else {
//        // Hết ô trống mà chưa ai thắng -> Hòa
//        return -1; // Hòa
//    }
//}
