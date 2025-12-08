#pragma once

#ifndef _SAVELOAD_H_
#define _SAVELOAD_H_
#include <iostream>
#include <fstream>
#include <string>
#include <direct.h>// library create directory
bool saveGame(std::string& filename, char board[][15], char currentPlayer, int score_X, int score_O, char name1[], char name2[],int difficulty=4);
bool loadGame(std::string& filename, char board[][15], char& currentPlayer, int &score_X, int &score_O, char name1[], char name2[],int &difficulty);
void drawSaveLoadScreen(int Width, int Height);
bool customInput(std::string& result);
bool checkFileExists(const std::string& filename);
bool getfilename(std::string& filename);
void loadproductfile(std::string& filename, char board[][15], char& currentPlayer, int& score_X, int& score_O, char name1[], char name2[], int &difficulty);
bool loadactive(std::string& filename, char board[][15], char& currentPlayer, int& score_X, int& score_O, char name1[], char name2[], int &difficulty);
void loadGameScreen(std::string& filename, char board[][15], char& currentPlayer, int& score_X, int& score_O, char name1[], char name2[], int &difficulty);
void loadGameMenu(std::string& filename, char board[][15], char& currentPlayer, int& score_X, int& score_O, char name1[], char name2[], int& difficulty);
void saveGameScreen(std::string& filename, char board[][15], char& currentPlayer, int& score_X, int& score_O, char name1[], char name2[], int &difficulty);
#endif
// progame savedgame caro