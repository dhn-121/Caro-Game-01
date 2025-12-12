#ifndef _CONSOLE_H_
#define _CONSOLE_H_
#include <utility>
#include <conio.h>
#include "Graphics.h"
#include <Windows.h>
void setPos(int , int );
int isNextMove();
void Movexy(int&, int&, int);
COORD getCursorPos();;
// mang di chuyen xy
const std::pair<int, int> dxy[4] = {{0,-1},{-1,0},{0,1},{1,0}};
//const int xbegin = Xi+(CellWidth+2)/2;//vi tri bat dau x
//const int ybegin = Yi+(CellHeight+2)/2;//vi tri bat dau y
#define xbegin  (Xi + CellWidth / 2 +1)//vi tri bat dau x
#define ybegin  (Yi + CellHeight / 2 +1)//vi tri bat dau y
#endif