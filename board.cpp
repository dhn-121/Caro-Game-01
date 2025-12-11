#include "Library.h"
using namespace std;

const char* B_TOP_LEFT = u8"\u250C"; // ┌
const char* B_HORIZ = u8"\u2500"; // ─
const char* B_TOP_TEE = u8"\u252C"; // ┬
const char* B_TOP_RIGHT = u8"\u2510"; // ┐
const char* B_VERT = u8"\u2502"; // │
const char* B_LEFT_TEE = u8"\u251C"; // ├
const char* B_CROSS = u8"\u253C"; // ┼
const char* B_RIGHT_TEE = u8"\u2524"; // ┤
const char* B_BOT_LEFT = u8"\u2514"; // └
const char* B_BOT_TEE = u8"\u2534"; // ┴
const char* B_BOT_RIGHT = u8"\u2518"; // ┘ 

void DrawBoard() {
    int current_Y = Yi;

    // 1. Vẽ Hàng đầu tiên (Top)
    setPos(Xi, current_Y);
    cout << B_TOP_LEFT;
    for (int j = 0; j < BOARD_SIZE - 1; j++) {
        for (int k = 0; k < CellWidth; k++) cout << B_HORIZ;
        cout << B_TOP_TEE;
    }
    for (int k = 0; k < CellWidth; k++) cout << B_HORIZ;
    cout << B_TOP_RIGHT;
    current_Y++;

    // 2. Vẽ Thân (Middle)
    for (int i = 0; i < BOARD_SIZE - 1; i++) {
        // Dòng chứa ô trống
        for (int h = 0; h < CellHeight; h++) {
            setPos(Xi, current_Y);
            cout << B_VERT;
            for (int j = 0; j < BOARD_SIZE; j++) {
                for (int k = 0; k < CellWidth; k++) cout << " "; // Khoảng trắng
                cout << B_VERT;
            }
            current_Y++;
        }

        // Dòng kẻ ngang phân cách
        setPos(Xi, current_Y);
        cout << B_LEFT_TEE;
        for (int j = 0; j < BOARD_SIZE - 1; j++) {
            for (int k = 0; k < CellWidth; k++) cout << B_HORIZ;
            cout << B_CROSS;
        }
        for (int k = 0; k < CellWidth; k++) cout << B_HORIZ;
        cout << B_RIGHT_TEE;
        current_Y++;
    }

    // 3. Vẽ hàng ô cuối cùng (trước khi đóng đáy)
    for (int h = 0; h < CellHeight; h++) {
        setPos(Xi, current_Y);
        cout << B_VERT;
        for (int j = 0; j < BOARD_SIZE; j++) {
            for (int k = 0; k < CellWidth; k++) cout << " ";
            cout << B_VERT;
        }
        current_Y++;
    }

    // 4. Vẽ Hàng cuối cùng (Bottom)
    setPos(Xi, current_Y);
    cout << B_BOT_LEFT;
    for (int j = 0; j < BOARD_SIZE - 1; j++) {
        for (int k = 0; k < CellWidth; k++) cout << B_HORIZ;
        cout << B_BOT_TEE;
    }
    for (int k = 0; k < CellWidth; k++) cout << B_HORIZ;
    cout << B_BOT_RIGHT;

    // Reset vị trí con trỏ về đầu
    setPos(Xi, current_Y);
}