#pragma once

#ifndef _SAVELOAD_H_
#define _SAVELOAD_H_
#include <iostream>
#include <fstream>
#include <string>
#include <direct.h>// library create directory
bool saveGame();
bool loadGame();
void drawSaveLoadScreen(int Width, int Height);
bool customInput(std::string& result);
bool checkFileExists(const std::string& filename);
bool getfilename(std::string& filename);
void loadproductfile();
bool loadactive();
void loadGameScreen();
void loadGameMenu();
void saveGameScreen();
#endif
// progame savedgame caro