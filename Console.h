#ifndef _CONSOLE_H_
#define _CONSOLE_H_
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <utility>
void setPos(int , int );
int isNextMove();
void Movexy(int&, int&, int);
// mang di chuyen xy
const std::pair<int, int> dxy[4] = {{0,-1},{-1,0},{0,1},{1,0}};

#endif