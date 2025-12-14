#pragma once
#ifndef _GRAPHIC_H_
#define _GRAPHIC_H_
#include <string>
#include "board.h"
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
int GetDisplayLength(const std::string& str);
void drawBox(int x, int y, int w, int h, std::string text);
void ShowConsoleCursor(bool showFlag);
void fixConsoleWindow(int WIDTH, int HEIGHT);
std::string BlankCal(std::string content);

void drawLoadingScreen();

void drawMenuScreen();
void drawIsSelected(int idx, bool isSelected);
int ControlMenu();

void Player_1(std::string& name, int XX, int YY, int Width, int Height);
void Player_2(std::string& name2, int mode, int XX, int YY, int Width, int Height);
void drawNameButton(int XX, int YY, int choice);
int NameControl(int XX, int YY);
int drawNameScreen(std::string& name1, std::string& name2, int mode);

extern int TurnData[4];
void drawTurnBox(int XX, int YY, int Width, int Height, char player, std::string name1, std::string name2);
void drawScoreBox(int XX, int YY, int Width, int Height, std::string name1, std::string name2);
void drawGamePlayScreen(char player, std::string name1, std::string name2, std::string filename);

// void drawLoadGameScreen()ı;

void drawWinStatus(char player, std::string name1, std::string name2);
void drawDrawStatus();
int ControlGaming(int type);
int AiControlGaming(int type);
bool isGameSelected(int idx, bool isSelected, int type);
void updateScore(char player);
struct GameSettings
{
    bool sfx_active = true;
    bool music_active = true;
    int language = 0;
};

extern struct GameSettings Default_Set;

std::string getToggleStatus(bool isActive);
std::string LanguageStatus(int choice);
void drawSettingsScreen();
void drawSettingsHighlight(int idx, bool isSelected);
int ControlSettings();

void drawHelpScreen();

// Function to control the Game Mode selection menu
int ControlGameMode();
// Function to draw the Game Mode screen
void drawGameModeScreen(int choice);
int ControlDifficulty();
char getCharAtCursor(int x, int y);
void HighlightPos(int x, int y, int mode);
void highlightWinningSequence(int, int, char[15][15]);

#endif