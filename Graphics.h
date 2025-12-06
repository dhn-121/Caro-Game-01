#pragma once
#ifndef _GRAPHIC_H_
#define _GRAPHIC_H_
#include <string>
    
const int backgroundcolor = 15;
const int fontcolor = 0;
    //==================== Bảng cờ và Console ====================
    extern int ConsoleWidth;
    extern int ConsoleHeight;
    void calculateLayoutParameters();

    // Kích thước thực của bảng cờ (Được tính dựa trên constants trong board.h)
    extern int BoardRealWidth; 
    extern int BoardRealHeight;

    // Toạ độ neo của bảng cờ
    extern int paddingX;
    extern int paddingY;
    extern int Xi; 
    extern int Yi;
    
    //==================== Kích thước UI (Dynamic Variables) ====================
    extern int buttonWidth;
    extern int buttonHeight;
    extern int TurnboxWidth; // Kích thước hộp nhỏ (Turn/Time)
    extern int TurnboxHeight;
    
    extern int Title_Width; 
    extern int Title_Height;
    extern int Box_Gap; // Khoảng cách chung (Dynamic Gap)
    
    // MenuBox/ToggleBox
    extern int ToggleBox_Width;
    extern int ToggleBox_Height;

    //==================== Group và Vị trí (Dynamic Variables) ====================
    extern int Group_Width;
    extern int Group_Height;
    extern int X_Start_Group;
    extern int Y_Start_Group;
    extern int X_Start_Box;
    
    // Tọa độ Y cho các Menu Box
    extern int Y_Start_Play;
    extern int Y_Start_Saved;
    extern int Y_Start_Settings;
    extern int Y_Start_About;
    extern int Y_Start_Exit;
    #define MenuBoxNum 5
    extern int Y_Start_MenuBox[MenuBoxNum];

    // Settings
    #define SettingsBoxNum 3
    extern int SettingsGroup_Height;
    extern int Y_Start_Settings_Group;
    extern int X_Start_ToggleBox;
    extern int Content_X;
    extern int SFX_Y;
    extern int MUSIC_Y;
    extern int BackY;
    extern int STATUS_X;

    //==================== Khai báo hàm và Struct ====================
    

    void drawA(int XX, int YY);
    void drawB(int XX, int YY);
    void drawC(int XX, int YY);
    void drawO(int XX, int YY, int co_txt);
    void drawR(int XX, int YY);
    void drawU(int XX, int YY);
    void drawT(int XX, int YY);
    void drawL(int XX, int YY);
    void drawS(int XX, int YY, int co_txt);
    void drawD(int XX, int YY);
    void drawG(int XX, int YY);
    void drawM(int XX, int YY);
    void drawE(int XX, int YY);
    void drawN(int XX, int YY);
    void drawW(int XX, int YY);
    void drawH(int XX, int YY);
    void drawP(int XX, int YY);
    void drawX(int XX, int YY, int co_txt);
    void drawI(int XX, int YY);

    void drawCARO(int XX, int YY);
    void drawABOUT(int XX, int YY);
    void drawLOAD_GAME(int XX, int YY);
    void drawNEW_GAME(int XX, int YY);
    void drawHELP(int XX, int YY);
    void drawIN_MATCH(int XX, int YY);
    void drawX_WIN(int XX, int YY);
    void drawO_WIN(int XX, int YY);
    void drawDRAW(int XX, int YY);
    void drawSETTINGS(int XX, int YY);

    //Thay đổi màu sắc của nền và văn bản
    void setColor(int bgcolor, int fgcolor);//fgcolor là dành cho những phần cần "nổi" như chữ...
    void drawBox(int x, int y, int w, int h, std::string text);
    
    void getConsoleSize(int& width, int& height);
    void fixConsoleWindow(int WIDTH, int HEIGHT);
    void fixviewConsoleWindow();
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
    #define SettingsBoxNum 3 // Cố định
    std::string getToggleStatus(bool isActive);
    void drawSettingsTitle();
    void drawSettingsToggleBox();
    void drawSettingsScreen();
    void drawSettingsHighlight(int idx, bool isSelected);
    int ControlSettings();

	void drawAboutUsScreen();

#endif

