#include "Library.h" // Remember to include your original library

// Scores for different board patterns (e.g., 5-in-a-row is 1,000,000)
const long ARR_SCORES[] = { 0, 10, 100, 1000, 10000, 1000000 };

// Function to calculate the score of a potential move in a specific direction.
// It counts consecutive stones and checks for open ends.
long calculateScore(int r, int c, int dr, int dc, char board[N][N], char player) {
    long score = 0;
    int count = 0;
    int openEnds = 0;

    // Count stones for the player in the positive direction
    for (int i = 1; i < 5; i++) {
        if (r + i * dr >= 0 && r + i * dr < BOARD_SIZE && c + i * dc >= 0 && c + i * dc < BOARD_SIZE && board[r + i * dr][c + i * dc] == player) count++;
        else {
            // Check if the end is open (empty cell)
            if (r + i * dr >= 0 && r + i * dr < BOARD_SIZE && c + i * dc >= 0 && c + i * dc < BOARD_SIZE && board[r + i * dr][c + i * dc] == '-') openEnds++;
            break;
        }
    }

    // Count stones for the player in the negative direction
    for (int i = 1; i < 5; i++) {
        if (r - i * dr >= 0 && r - i * dr < BOARD_SIZE && c - i * dc >= 0 && c - i * dc < BOARD_SIZE && board[r - i * dr][c - i * dc] == player) count++;
        else {
            // Check if the end is open (empty cell)
            if (r - i * dr >= 0 && r - i * dr < BOARD_SIZE && c - i * dc >= 0 && c - i * dc < BOARD_SIZE && board[r - i * dr][c - i * dc] == '-') openEnds++;
            break;
        }
    }

    if (count >= 5) return ARR_SCORES[5]; // Instant win
    if (openEnds == 0 && count < 5) return 0; // Useless if blocked on both ends and less than 5 stones

    score = ARR_SCORES[count];
    if (openEnds == 2) score *= 2; // Significant bonus for fully open lines (Live/Open N)
    else if (openEnds == 1) score *= 1.5; // Smaller bonus for semi-open lines (Sleep N)

    return score;
}

// Function to find the best move using a scoring heuristic
void getBestMove(char board[N][N], int& bestRow, int& bestCol, char aiPlayer) {
    long maxScore = -1;
    char humanPlayer = (aiPlayer == 'X') ? 'O' : 'X';
    bestRow = -1; bestCol = -1;

    // Iterate through all cells on the board (from 0 to BOARD_SIZE-1)
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == '-') { // Only consider empty cells

                // 1. Calculate attack score (How strong is this move for the AI?)
                // This simulates the AI moving here.
                board[i][j] = aiPlayer;
                long attackScore = 0;
                attackScore += calculateScore(i, j, 0, 1, board, aiPlayer); // Horizontal
                attackScore += calculateScore(i, j, 1, 0, board, aiPlayer); // Vertical
                attackScore += calculateScore(i, j, 1, 1, board, aiPlayer); // Main diagonal
                attackScore += calculateScore(i, j, 1, -1, board, aiPlayer); // Anti-diagonal
                board[i][j] = '-'; // Backtrack

                // 2. Calculate defense score (How dangerous is the opponent if we don't block here?)
                // This simulates the human player moving here.
                board[i][j] = humanPlayer;
                long defenseScore = 0;
                defenseScore += calculateScore(i, j, 0, 1, board, humanPlayer);
                defenseScore += calculateScore(i, j, 1, 0, board, humanPlayer);
                defenseScore += calculateScore(i, j, 1, 1, board, humanPlayer);
                defenseScore += calculateScore(i, j, 1, -1, board, humanPlayer);
                board[i][j] = '-'; // Backtrack

                // Prioritize defense significantly, especially if there's an immediate threat (SCORE[4] is 100000)
                // If the human can win immediately, defenseScore will be very high.
                // Can multiply defense by a factor if a super defensive AI is desired (e.g., defenseScore * 10)
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