#pragma once
#ifndef _PLAY_H_
#define _PLAY_H_
#include "Library.h"
using namespace std;
void drawContinueGameScreen();
void GamePlay(int typegame);
void AiGamePlay(int typegame);


extern int score_X;
extern int score_O;
extern std::string filename;
extern int count_moves;
extern char currentPlayer;
extern string name1;
extern string name2;
extern int difficulty;
#endif