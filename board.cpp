#include "Library.h"
using namespace std;

//void calculateCellSize() 
//{
//    const float ASPECT_RATIO_W_H = 2.5f; 
//    
//    // Giới hạn không gian cho Bảng cờ (Ví dụ: 85% chiều cao, 70% chiều rộng)
//    int MaxBoardHeight = ConsoleHeight * 85 / 100;
//    int MaxBoardWidth = ConsoleWidth * 70 / 100;
//    
//    int h_candidate = (MaxBoardHeight - (BOARD_SIZE + 1)) / BOARD_SIZE;
//    CellHeight = max(1, h_candidate); 
//    
//    int w_candidate = (MaxBoardWidth - (BOARD_SIZE + 1)) / BOARD_SIZE;
//    CellWidth = max(2, w_candidate); 
//
//    int required_width = static_cast<int>(CellHeight * ASPECT_RATIO_W_H);
//    
//    CellWidth =min(required_width, CellWidth); 
//    
//    int required_height = static_cast<int>(CellWidth / ASPECT_RATIO_W_H);
//
//    CellHeight = min(CellHeight, required_height);
//
//    CellHeight = max(1, CellHeight);
//    CellWidth = max(2, CellWidth);
//}

void DrawBoard()
{
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

