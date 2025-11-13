#include "Console.h"
#include "board.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>
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
	/*if (typemove == 0)
	{
		cout << 'x';
		setPos(x, y);
		return;
	}*/
	int DXX = LEFT -1;//do dai nhay X
	int DXY = TOP;//do dai nhay Y
	x += DXX*dxy[typemove - 1].first;
	y += DXY*dxy[typemove - 1].second;
	int xbegin = 4;//vi tri bat dau x
	int ybegin = 1;//vi tri bat dau y
	if (x >= (DXX)*(BOARD_SIZE+1))x = xbegin;
	if (x < xbegin)x = (DXX)*(BOARD_SIZE-1)+ xbegin-1;
	if (y > DXY * (BOARD_SIZE))y = ybegin;
	if (y < ybegin)y = (DXY)*(BOARD_SIZE)+ ybegin-1;
	setPos(x, y);
}