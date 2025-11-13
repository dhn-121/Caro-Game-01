#include <iostream>
#include "board.h"
#include "Console.h"
#include "Graphics.h"
using namespace std;

Board::Board(int r, int c) {
    rows = r;
    cols = c;
}

//Cố định màn hình
void Board::FixConsoleWindow() {
    HWND consoleWindow = GetConsoleWindow();
    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
    style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
    SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void Board::DrawBoard() {
    const int cellWidth = 8;  // tăng khoảng ngang để vuông hơn
    const int cellHeight = 3; // chiều cao mỗi ô
    int current_Y = Yi;

    // Hàng đầu tiên
    setPos(Xi, current_Y++);
    cout << char(218);
    for (int j = 0; j < cols - 1; j++) {
        for (int k = 0; k < cellWidth; k++) cout << char(196);
        cout << char(194);
    }
    for (int k = 0; k < cellWidth; k++) cout << char(196);
        cout << char(191);

    // Thân bàn
    for (int i = 0; i < rows - 1; i++) {
        for (int h = 0; h < cellHeight; h++) {
            setPos(Xi, current_Y++);
            cout << char(179);
            for (int j = 0; j < cols; j++) {
                for (int k = 0; k < cellWidth; k++) cout << ' ';
                cout << char(179);
            }
        }

        setPos(Xi, current_Y++); 
        cout << char(195);
        for (int j = 0; j < cols - 1; j++) {
            for (int k = 0; k < cellWidth; k++) cout << char(196);
            cout << char(197);
        }
        for (int k = 0; k < cellWidth; k++) cout << char(196);
        cout << char(180);
    }

    // Hàng cuối
    for (int h = 0; h < cellHeight; h++) {
        setPos(Xi, current_Y++);
        cout << char(179);
        for (int j = 0; j < cols; j++) {
            for (int k = 0; k < cellWidth; k++) cout << ' ';
            cout << char(179);
        }
    }

    setPos(Xi, current_Y++);
    cout << char(192);
    for (int j = 0; j < cols - 1; j++) {
        for (int k = 0; k < cellWidth; k++) cout << char(196);
        cout << char(193);
    }
    for (int k = 0; k < cellWidth; k++) cout << char(196);
    cout << char(217);
}

// int main() {
//     Board::FixConsoleWindow();
//     Board b;
//     b.DrawBoard();
//     cout << "\nBan co da ve xong!\n";
//     cin.get();
//     return 0;
// }





