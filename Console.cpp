#include "Library.h"
using namespace std;

//ham dat vi tri con tro
void setPos(int x, int y)
{
	COORD coord{};
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
//ham kiem tra key nhap vao
int isNextMove()
{
	while (true)
	{
		char key = _getch();
		// Enter
		if (key == 13 || key == ' ') return 0;
		// ESC
		if (key == 27) return -1;
		if (key == -32) {						// Arrow
			key = _getch();
			if (key == 72) return 1;			// Up
			if (key == 75) return 2;			// Left
			if (key == 80) return 3;			// Down
			if (key == 77) return 4;			// Right
		}
		// WASD
		if (key == 'W' || key == 'w') return 1;
		if (key == 'A' || key == 'a') return 2;
		if (key == 'S' || key == 's') return 3;
		if (key == 'D' || key == 'd') return 4;
	}
}
//ham di chuyen
void Movexy(int &x,int &y,int typemove)
{
	int DXX = CellWidth +1;//do dai nhay X
	int DXY = CellHeight +1;//do dai nhay Y

	//di chuyen
	x += DXX*dxy[typemove - 1].first;
	y += DXY*dxy[typemove - 1].second;

	//kiem tra vuot bien
	if (x > (DXX) * (BOARD_SIZE - 1) + xbegin)x = xbegin;
	if (x < xbegin)x = (DXX) * (BOARD_SIZE - 1) + xbegin;
	if (y >= DXY * (BOARD_SIZE)+ybegin)y = ybegin;
	if (y < ybegin)y = DXY * (BOARD_SIZE - 1) + ybegin;
	//dat con tro
	setPos(x, y);
}



