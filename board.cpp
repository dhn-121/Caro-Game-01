#include <iostream>
#include "board.h"
#include "Console.h"
#include "Graphics.h"
using namespace std;

//Cố định màn hình
void FixConsoleWindow() {
    HWND consoleWindow = GetConsoleWindow();
    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
    style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
    SetWindowLong(consoleWindow, GWL_STYLE, style);
}


void DrawBoard() {
    const int cellWidth = 8;  // tăng khoảng ngang để vuông hơn
    const int cellHeight = 3; // chiều cao mỗi ô

    // Hàng đầu tiên
    cout << char(218);
    for (int j = 0; j < BOARD_SIZE- 1; j++) {
        for (int k = 0; k < cellWidth; k++) cout << char(196);
        cout << char(194);
    }
    for (int k = 0; k < cellWidth; k++) cout << char(196);
    cout << char(191) << endl;

    // Thân 
    for (int i = 0; i < BOARD_SIZE - 1; i++) {
        for (int h = 0; h < cellHeight; h++) {
            cout << char(179);
            for (int j = 0; j < BOARD_SIZE; j++) {
                for (int k = 0; k < cellWidth; k++) cout << ' ';
                cout << char(179);
            }
            cout << endl;
        }

        cout << char(195);
        for (int j = 0; j < BOARD_SIZE - 1; j++) {
            for (int k = 0; k < cellWidth; k++) cout << char(196);
            cout << char(197);
        }
        for (int k = 0; k < cellWidth; k++) cout << char(196);
        cout << char(180) << endl;
    }

    // Hàng cuối
    for (int h = 0; h < cellHeight; h++) {
        cout << char(179);
        for (int j = 0; j < BOARD_SIZE; j++) {
            for (int k = 0; k < cellWidth; k++) cout << ' ';
            cout << char(179);
        }
        cout << endl;
    }

    cout << char(192);
    for (int j = 0; j < BOARD_SIZE - 1; j++) {
        for (int k = 0; k < cellWidth; k++) cout << char(196);
        cout << char(193);
    }
    for (int k = 0; k < cellWidth; k++) cout << char(196);
    cout << char(217) << endl;
}


int main() {
    FixConsoleWindow();
    DrawBoard();
    cout << "\nBan co da ve xong!\n";
    cin.get();
    return 0;
}




