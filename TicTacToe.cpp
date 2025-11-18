#include "Library.h"
using namespace std;

//Từ vị trí cột x, hàng y, di chuyển đến vị trí bạn muốn 
#define MoveTo(x,y) (setPos(x, y))

const int CellWidth = 8;
const int CellHeight = 3;

//Tạo bảng 17x17 để xử lí các phần ô rìa hoặc góc (trong bảng 15x15 của tụi mình) dễ dàng hơn.
char board[N][N];
char player_X = 'X';
char player_O = 'O';
int count_X = 0;
int count_O = 0;
_Point status[BOARD_SIZE + 5][BOARD_SIZE + 5];
//Sau đây là hàm đếm số quân 'X' và 'O'. Nếu số lượng quân X nhiều hơn số lượng quân O thì lượt tiếp theo đến O. Nếu quân X bằng quân O hì lượt tiếp theo là quân X.
bool ValidMove(int row, int col)
{
   /* if (row < 1 || row > 15 || col < 1 || col > 15)
        return false;*/
    if (board[row][col] != ' ')
        return false;
    return true;
}

void MakeMove(char player, int row, int col)
{
    if (!ValidMove(row, col))
        return;
    int screen_X = Xi + (col-1) * (CellWidth + 1) + 3;
    int screen_Y = Yi + (row - 1) * (CellHeight + 1) + 1;
    board[row][col] = player;
    setPos(screen_X, screen_Y);
    if (player == player_X)
    {
        cout << "X";
        count_X++;
    }
    else if (player == player_O)
    {
        cout << 'O';
        count_O++;
    }
    else 
        cout << '.';
}


char check_XO()
{
    if (count_X == count_O)
        return player_X; //X đi rước
    return player_O; //O đi trước
}
