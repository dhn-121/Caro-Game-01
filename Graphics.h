#pragma once
#ifndef _GRAPHIC_H_
#define _GRAPHIC_H_
    #include <string>
    #include <vector>
    
    class Board;
    //Thay đổi màu sắc của nền và văn bản
    void setColor(int bgcolor, int fgcolor);//fgcolor là dành cho những phần cần "nổi" như chữ...
    void drawBox(int x, int y, int w, int h, std::string text);
    
    void fixConsoleWindow(int WIDTH, int HEIGHT);

    extern const int Xi;
    extern const int Yi;

    void drawTitle();
    typedef std::vector<int> Y_Start;
    void VectorInit();
    void clearMenuBoxData();
    void drawPlayBox(Y_Start& YY);
    void drawSavedBox(Y_Start& YY);
    void drawSettingsBox(Y_Start& YY);
    void drawAboutBox(Y_Start& YY);
    void drawExitBox(Y_Start& YY);
    void drawMenu();
    void drawIsSelected(int idx, Y_Start& YY, bool isSelected);
    int ControlMenu();

    class Board;
    void drawCaroBoard(Board& CaroBoard);
    bool isClickedButton(int xx, int yy, int X_start, int Y_start);
    void drawExitButton();
    void drawAgainButton();
    int checkClicked(int xx, int yy);
    void drawTurnBox(char player, char name1[], char name2[]);
    void drawTimeBox(char min[], char sec[]);
    void drawFilename(std::string filename);
    void drawGamePlayScreen(Board& CaroBoard, char player, char name1[], char name2[], char min[], char sec[], std::string filename);

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
