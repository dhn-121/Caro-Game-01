#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "board.h"
#include "Console.h"
#include "Check.h"
#include "TicTacToe.h"
using namespace std;

// int main() {
//     Board::FixConsoleWindow();
//     Board b;
//     b.DrawBoard();
//     int x = 4;
//     int y = 1;
//     setPos(x, y);
//     for (int i = 0; i < N; i++)
//     {
//         for (int j = 0; j < N; j++)
//         {
//             board[i][j] = ' ';
//         }
//     }
//     while (true)
//     {
//         int type = isNextMove();
//         if (type == -1)break;
//         char player_main = check_XO();
//         if (type == 0)
//         {
//             MakeMove(player_main, x, y);
//             if (!test_board(player_main, x, y, board))
//             {
//                 cout << player_main << "WIN";
//                 return 0;
//             }
//         }
//         else Movexy(x, y, type);
//     }
//     return 0;

// }