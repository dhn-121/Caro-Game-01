#pragma once
#ifndef _DRAW_H_
#define _DRAW_H_
#include "library.h"
using namespace std;

void drawA(int XX, int YY);
void drawB(int XX, int YY);
void drawC(int XX, int YY);
void drawO(int XX, int YY, int co_txt);
void drawR(int XX, int YY);
void drawU(int XX, int YY);
void drawT(int XX, int YY);
void drawL(int XX, int YY);
void drawL(int XX, int YY);
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
//void drawDino(int XX, int YY);

void drawBoard(int startX, int startY, string name1, string name2, int Xscore, int Oscore, string fileName);
void drawBoardMenu(int XX, int YY, int size, int b_color, string str);
void drawBoardSize(int XX, int YY, int h, int w);
void drawPopUp(int XX, int YY, int h, int w);
void drawName_Board(int XX, int YY, string fileName);
void drawStatus(int XX, int YY, int opt);


#endif
