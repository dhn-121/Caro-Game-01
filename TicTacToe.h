#pragma once 
#ifndef TICTACTOE_H
#define TICTACTOE_H

#include "board.h"


    struct _Point 
    {
        int X, Y;
        char opt;
    };
    extern _Point status[BOARD_SIZE + 5][BOARD_SIZE + 5];
    extern char player_X;
    extern char player_O;
    extern int count_X;
    extern int count_O;
    const int N = BOARD_SIZE +2;
    extern char board[N][N];
    bool ValidMove(int row, int col);
    bool MakeMove(char player, int row, int col);
    char check_XO();
    
#endif