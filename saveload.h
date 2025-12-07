#pragma once

#ifndef _SAVELOAD_H_
#define _SAVELOAD_H_
#include <iostream>
#include <fstream>
#include <string>
#include <direct.h>// library create directory
bool saveGame(const std::string& filename, char board[][15], char currentPlayer, int score_X, int score_O);
bool loadGame(const std::string& filename, char board[][15], char& currentPlayer, int& score_X, int& score_O);
void drawSaveLoadScreen(int Width, int Height);
bool checkFileExists(const std::string& filename);
bool getfilename(std::string& filename);
void loadproductfile(std::string& filename, char board[][15], char& currentPlayer, int score_X, int score_O);
bool loadactive(std::string& filename, char board[][15], char& currentPlayer, int score_X, int score_O);
#endif
// progame savedgame caro