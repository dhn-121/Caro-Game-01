#pragma once
#ifndef _CHECK_H_
#define _CHECK_H_
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <utility>
#include "board.h"
#include "Console.h"
#include "Check.h"
#include "TicTacToe.h"
bool test_board(char, int, int, char [N][N]);
void getij(int&, int&, int, int);
bool check_iswin(int, int, char[N][N]);
extern bool has_empty_cell;
#endif