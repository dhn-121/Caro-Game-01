#pragma once
#ifndef _AI_H_
#define _AI_H_
#include "Library.h"
#include <cmath>
#include <algorithm>

long calculateScore(int r, int c, int dr, int dc, char board[N][N], char player);
void getBestMove(char board[N][N], int& bestRow, int& bestCol, char aiPlayer);
void getEasyMove(char board[N][N], int& row, int& col);
void getSmartMove(char board[N][N], int& bestRow, int& bestCol, char aiPlayer);
bool isRelevantMove(int r, int c, char board[N][N]);
long long minimax(char board[N][N], int depth, bool isMaximizing, long long alpha, long long beta, char aiPlayer);
long long evaluateBoardState(char board[N][N], char aiPlayer);
void getBestMove(char board[N][N], int& bestRow, int& bestCol, char aiPlayer);


#endif

