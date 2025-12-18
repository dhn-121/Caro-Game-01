#include "Library.h"
using namespace std;

//Từ vị trí cột x, hàng y, di chuyển đến vị trí bạn muốn 
#define MoveTo(x,y) (setPos(x, y))

//const int CellWidth = 8;
//const int CellHeight = 3;

//Tạo bảng 17x17 để xử lí các phần ô rìa hoặc góc (trong bảng 15x15 của tụi mình) dễ dàng hơn.
char board[N][N];
char player_X = 'X';
char player_O = 'O';
int count_X = 0;
int count_O = 0;
_Point status[BOARD_SIZE + 5][BOARD_SIZE + 5];

char first_player = 'X';

char RandomFirstPlayer()
{
    int first = rand() % 2;
    if (first == 1)
        return player_O;
    return player_X;
}

//Sau đây là hàm đếm số quân 'X' và 'O'. Nếu số lượng quân X nhiều hơn số lượng quân O thì lượt tiếp theo đến O. Nếu quân X bằng quân O hì lượt tiếp theo là quân X.
bool ValidMove(int row, int col)
{
    if (board[row][col] != '-')
        return false;
    return true;
}

bool MakeMove(char player, int row, int col)
{
    int i, j;
	getij(i, j, row, col);
    if(!ValidMove(i, j))
		return 0;
	
    board[i][j] = player;
    HighlightPos(row, col, 0);
    setPos(row, col);
    if (player == player_X)
    {
		setColor(15, 12);
        cout << "X";
        count_X++;
    }
    else if (player == player_O)
    {
        setColor(15, 12);
        cout << 'O';
        count_O++;
    }
    else
    {
        cout << ' ';
        return 0;
    }
	setColor(backgroundcolor, fontcolor);
    HighlightPos(row, col, 1);
    return 1;
}


char check_XO(char first)
{
    if (first == 'X')
    {
        if (count_X > count_O)
            return player_O;
        else if (count_X == count_O)
            return player_X;
    }
    else if (first == 'O')
    {
        if (count_O > count_X)
            return player_X;
        else if (count_O == count_X)
            return player_O;
    }
}

