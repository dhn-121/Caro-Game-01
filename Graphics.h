#pragma once
#ifndef _GRAPHIC_H_
#define _GRAPHIC_H_
    #include <string>
    #include <vector>
     
    //==================== Các thông số của bảng (đơn vị: ký tự) ====================

#define backgroundcolor 7 //màu nền xám nhẹ
#define fontcolor 0 //màu chữ đen
    //Các thông số ô cờ được lấy từ board.cpp
    //Màn hình Console tôi thấy ổn nhất (có thể thay đổi) gần bằng kích cỡ 10:16
    extern int ConsoleWidth;
    extern int ConsoleHeight;
    //Kích thước thực của bảng cờ được tính theo dạng ký tự (BOARD_SIZE = 15, 16 là viền dọc, ngang )
    const int BoardRealWidth = BOARD_SIZE * CellWidth + 16;
    const int BoardRealHeight = BOARD_SIZE * CellHeight + 16;

    //Khoảng cách giữa viền bảng cờ và Console
    const int paddingX = (ConsoleWidth - BoardRealWidth) / 2;
    const int paddingY = (ConsoleHeight - BoardRealHeight) / 2;
    // Toạ độ điểm neo được thay đổi thành chỗ bắt đầu vẽ bảng cờ 
    const int Xi = paddingX;
    const int Yi = paddingY;
    
    //Kích thước nút
	const int buttonWidth = 20;
	const int buttonHeight = 3;

    class Board;
    //Thay đổi màu sắc của nền và văn bản
    void setColor(int bgcolor, int fgcolor);//fgcolor là dành cho những phần cần "nổi" như chữ...
    void drawBox(int x, int y, int w, int h, std::string text);
    
	void getConsoleSize(int& width, int& height);
    void fixConsoleWindow(int WIDTH, int HEIGHT);
    //void fixConsoleWindow(int WIDTH, int HEIGHT);

    extern const int Xi;
    extern const int Yi;
   
    void drawTitle();
    void drawPlayBox();
    void drawSavedBox();
    void drawSettingsBox();
    void drawAboutBox();
    void drawExitBox();
    void drawMenuScreen();
    void drawIsSelected(int idx, bool isSelected);
    int ControlMenu();

    void drawLoadingScreen();


    void drawCaroBoard();
    bool isClickedButton(int xx, int yy, int X_start, int Y_start);
    void drawExitButton();
    void drawAgainButton();
    int checkClicked(int xx, int yy);
    void drawTurnBox(char player, char name1[], char name2[]);
    void drawTimeBox(char min[], char sec[]);
    void drawFilename(std::string filename);
    void drawGamePlayScreen( char player, char name1[], char name2[], char min[], char sec[], std::string filename);

    struct GameSettings
    {
        bool sfx_active = true;
        bool music_active = true;
    };
    extern struct GameSettings Default_Set;
    #define SettingsBoxNum 3
    std::string getToggleStatus(bool isActive);
    void drawSettingsTitle();
    void drawSettingsToggleBox();
    void drawSettingsScreen();
    void drawSettingsHighlight(int idx, bool isSelected);
    int ControlSettings();

#endif

