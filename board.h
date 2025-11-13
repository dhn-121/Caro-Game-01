#pragma once
#include <Windows.h>
#define BOARD_SIZE 10
#define LEFT 3
#define TOP 1

class Board 
{
private:
    int rows;
    int cols;
public:
    static void FixConsoleWindow();
    static void Gotoxy(int x, int y);

    Board(int r = BOARD_SIZE, int c = BOARD_SIZE);
    void DrawBoard();
    /*void Board::Draw(int, int, int);*/
};