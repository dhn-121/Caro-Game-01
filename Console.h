#ifndef _CONSOLE_H_
#define _CONSOLE_H_
#include <utility>
#include <conio.h>
#include "Graphics.h"
void setPos(int , int );
int isNextMove();
void Movexy(int&, int&, int);
// mang di chuyen xy
const std::pair<int, int> dxy[4] = {{0,-1},{-1,0},{0,1},{1,0}};
//const int xbegin = Xi+(CellWidth+2)/2;//vi tri bat dau x
//const int ybegin = Yi+(CellHeight+2)/2;//vi tri bat dau y
extern int xbegin ;//vi tri bat dau x
extern int ybegin ;//vi tri bat dau y
void calculateStartPos();
#endif