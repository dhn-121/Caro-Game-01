#pragma once
#ifndef _AI_H_
#define _AI_H_
#include "Library.h"
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <string>
long calculateScore(int r, int c, int dr, int dc, char board[N][N], char player);
void getBestMove(char board[N][N], int& bestRow, int& bestCol, char aiPlayer);
void getEasyMove(char board[N][N], int& row, int& col);
void getSmartMove(char board[N][N], int& bestRow, int& bestCol, char aiPlayer);
void getBestMove(char board[N][N], int& bestRow, int& bestCol, char aiPlayer);


#endif

