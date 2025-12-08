#pragma once
#ifndef _GRAPHIC_H_
#define _GRAPHIC_H_
#include <string>
     
    //==================== Các thông số của bảng (đơn vị: ký tự) ====================

    extern const int backgroundcolor; //màu nền trắng
    extern const int fontcolor; //màu chữ đen
    
    extern int ConsoleWidth;
    extern int ConsoleHeight;
    //Kích thước thực của bảng cờ được tính theo dạng ký tự (BOARD_SIZE = 15, 16 là viền dọc, ngang )
    const int BoardRealWidth = BOARD_SIZE * CellWidth + 16;
    const int BoardRealHeight = BOARD_SIZE * CellHeight + 16;
    extern int Xi;
    extern int Yi;

    struct DATA 
    {
        int Width;
        int Height;
        int XX;
        int YY;
    };

    //Thay đổi màu sắc của nền và văn bản
    void setColor(int bgcolor, int fgcolor);//fgcolor là dành cho những phần cần "nổi" như chữ...
    void drawBox(int x, int y, int w, int h, std::string text);
    void ShowConsoleCursor(bool showFlag);
    void fixConsoleWindow(int WIDTH, int HEIGHT);
    void drawLoadingScreen();
    void drawMenuScreen();
    void drawIsSelected(int idx, bool isSelected);
    int ControlMenu();

    extern int TurnData[4];
    void drawTurnBox(int XX, int YY, int Width, int Height, char player,  char name1[],  char name2[]);
    void drawScoreBox(int XX, int YY, int Width, int Height, char player);
    void drawGamePlayScreen(char player, char name1[], char name2[], std::string filename);

    // void drawLoadGameScreen()ı;

    void drawWinStatus(char player, char name1[], char name2[]);
    void drawDrawStatus();
    int ControlGaming();
	bool isGameSelected(int idx, bool isSelected);
	void updateScore(char player);
    struct GameSettings
    {
        bool sfx_active = true;
        bool music_active = true;
    };

    extern struct GameSettings Default_Set;

    std::string getToggleStatus(bool isActive);
    void drawSettingsScreen();
    void drawSettingsHighlight(int idx, bool isSelected);
    int ControlSettings();

    void drawHelpScreen();

    // Function to control the Game Mode selection menu
    int ControlGameMode();
    // Function to draw the Game Mode screen
    void drawGameModeScreen(int choice);
	int ControlDifficulty();


#endif
