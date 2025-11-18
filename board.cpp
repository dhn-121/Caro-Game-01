#include "Library.h"
using namespace std;

//Cố định màn hình
//void FixConsoleWindow() {
//    HWND consoleWindow = GetConsoleWindow();
//    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
//    style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
//    SetWindowLong(consoleWindow, GWL_STYLE, style);
//}


void DrawBoard() {
    //const int cellWidth = 8;  // tăng khoảng ngang để vuông hơn
    //const int cellHeight = 3; // chiều cao mỗi ô
    int current_Y = Yi;
    // Hàng đầu tiên
    setPos(Xi, current_Y);
    cout << char(218);
    for (int j = 0; j < BOARD_SIZE- 1; j++) {
        for (int k = 0; k < CellWidth; k++) cout << char(196);
        cout << char(194);
    }
    for (int k = 0; k < CellWidth; k++) cout << char(196);
    cout << char(191);
    current_Y++;

    // Thân
    for (int i = 0; i < BOARD_SIZE - 1; i++) {
        for (int h = 0; h < CellHeight; h++) {
            setPos(Xi, current_Y);
            cout << char(179);
            for (int j = 0; j < BOARD_SIZE; j++) {
                for (int k = 0; k < CellWidth; k++) cout << ' ';
                cout << char(179);
            }
            current_Y++;
        }
        setPos(Xi, current_Y);
        cout << char(195);
        for (int j = 0; j < BOARD_SIZE - 1; j++) {
            for (int k = 0; k < CellWidth; k++) cout << char(196);
            cout << char(197);
        }
        for (int k = 0; k < CellWidth; k++) cout << char(196);
        cout << char(180);
        current_Y++;
    }

    // Hàng cuối
    for (int h = 0; h < CellHeight; h++) {
        setPos(Xi, current_Y);
        cout << char(179);
        for (int j = 0; j < BOARD_SIZE; j++) {
            for (int k = 0; k < CellWidth; k++) cout << ' ';
            cout << char(179);
        }
        current_Y++;
    }

    setPos(Xi, current_Y);
    cout << char(192);
    for (int j = 0; j < BOARD_SIZE - 1; j++) {
        for (int k = 0; k < CellWidth; k++) cout << char(196);
        cout << char(193);
    }
    for (int k = 0; k < CellWidth; k++) cout << char(196);
    cout << char(217);
    setPos(Xi, current_Y);
}


 //int main() {
 //    FixConsoleWindow();
 //    DrawBoard();
 //    cout << "\nban co da ve xong!\n";
 //    cin.get();
 //    return 0;
 //}







