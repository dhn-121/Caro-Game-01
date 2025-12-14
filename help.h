#pragma once
#ifndef HELP_H
#define HELP_H
#include <iostream>
#include <conio.h>
#include "Console.h"
#include "Graphics.h"
#include <vector>
#include <string>

using namespace std;

struct QAPair {
    string question;
    string answer;
};
// Khai báo các biến toàn cục nếu chưa có
extern int ConsoleWidth;
extern int ConsoleHeight;
vector<QAPair> createQAList();
vector<string> wrapText(const string& text, int maxWidth);
void displayHelp(const vector<QAPair>& qaList, int selectedIndex);
void drawBorderOnly(int x, int y, int width, int height);
string safeTruncate(const string& str, int maxWidth);
void ControlHelp();

#endif 