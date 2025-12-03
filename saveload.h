#pragma once

#ifndef _SAVELOAD_H_
#define _SAVELOAD_H_
#include <iostream>
#include <fstream>
#include <string>
#include <direct.h>// library create directory
void saveGame(const std::string& filename, char board[][15], char currentPlayer, int timeMinutes, int timeSeconds);
bool loadGame(const std::string& filename, char board[][15], char& currentPlayer, int& timeMinutes, int& timeSeconds);
void drawSaveLoadScreen(int Width, int Height);
bool checkFileExists(const std::string& filename);
#endif
// progame savedgame caro