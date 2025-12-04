#include "draw.h"
#include "Library.h"
#define co_theme 15,0
//const int BOARD_SIZE = 15;

extern _Point status[BOARD_SIZE + 5][BOARD_SIZE + 5];
void drawA(int XX, int YY) { // 6 * 8
	setPos(XX + 1, YY);
	setColor(0, 0); cout << "     ";
	setColor(co_theme); cout << char(187);

	setPos(XX, YY + 1);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(201) << char(205) << char(205);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(187);

	setPos(XX, YY + 2);
	setColor(0, 0); cout << "       ";
	setColor(co_theme); cout << char(186);

	setPos(XX, YY + 3);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(201) << char(205) << char(205);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	setPos(XX, YY + 4);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186) << "  ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	setPos(XX, YY + 5);
	cout << char(200) << char(205) << char(188) << "  " << char(200) << char(205) << char(188);
}

void drawB(int XX, int YY) { // 6 * 8
	setPos(XX, YY);
	setColor(0, 0); for (int i = 0; i < 6; ++i) cout << " ";
	setColor(co_theme); cout << char(187);

	setPos(XX, YY + 1);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(201) << char(205) << char(205);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(187);

	setPos(XX, YY + 2);
	setColor(0, 0); for (int i = 0; i < 6; ++i) cout << " ";
	setColor(co_theme); cout << char(201) << char(188);

	setPos(XX, YY + 3);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(201) << char(205) << char(205);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(187);

	setPos(XX, YY + 4);
	setColor(0, 0); for (int i = 0; i < 6; ++i) cout << " ";
	setColor(co_theme); cout << char(201) << char(188);

	setPos(XX, YY + 5);
	cout << char(200);
	for (int i = 0; i < 5; ++i) cout << char(205);
	cout << char(188);
}

void drawC(int XX, int YY) { // 6 * 8
	setPos(XX + 1, YY);
	setColor(0, 0); cout << "      ";
	setColor(co_theme); cout << char(187);

	setPos(XX, YY + 1);
	setColor(0, 0);  cout << "  ";
	setColor(co_theme);
	cout << char(201);
	for (int i = 1; i <= 4; ++i) cout << char(205);
	cout << char(188);

	setPos(XX, YY + 2);
	setColor(0, 0);  cout << "  ";
	setColor(co_theme); cout << char(186);

	setPos(XX, YY + 3);
	setColor(0, 0);  cout << "  ";
	setColor(co_theme); cout << char(186);

	setPos(XX, YY + 4);
	cout << char(200);
	setColor(0, 0);  cout << "      ";
	setColor(co_theme); cout << char(187);

	setPos(XX + 1, YY + 5);
	cout << char(200);
	for (int i = 1; i <= 5; ++i) cout << char(205);
	cout << char(188);
}

void drawO(int XX, int YY, int co_txt = 0) { // 6 * 9
	setPos(XX + 1, YY);
	setColor(co_txt, 0); cout << "      ";
	setColor(15, co_txt); cout << char(187);

	setPos(XX, YY + 1);
	setColor(co_txt, 0); cout << "  ";
	setColor(15, co_txt); cout << char(201) << char(205) << char(205) << char(205);
	setColor(co_txt, 0); cout << "  ";
	setColor(15, co_txt); cout << char(187);

	setPos(XX, YY + 2);
	setColor(co_txt, 0); cout << "  ";
	setColor(15, co_txt); cout << char(186) << "   ";
	setColor(co_txt, 0); cout << "  ";
	setColor(15, co_txt); cout << char(186);

	setPos(XX, YY + 3);
	setColor(co_txt, 0); cout << "  ";
	setColor(15, co_txt); cout << char(186) << "   ";
	setColor(co_txt, 0); cout << "  ";
	setColor(15, co_txt); cout << char(186);

	setPos(XX, YY + 4);
	cout << char(200);
	setColor(co_txt, 0); cout << "      ";
	setColor(15, co_txt); cout << char(201) << char(188);

	setPos(XX + 1, YY + 5);
	cout << char(200);
	for (int i = 1; i <= 5; ++i) cout << char(205);
	cout << char(188);
	setColor(co_theme);
}

void drawR(int XX, int YY) { // 6 * 8
	setPos(XX, YY);
	setColor(0, 0); cout << "      ";
	setColor(co_theme); cout << char(187);

	setPos(XX, YY + 1);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(201) << char(205) << char(205);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(187);

	setPos(XX, YY + 2);
	setColor(0, 0); cout << "      ";
	setColor(co_theme); cout << char(201) << char(188);

	setPos(XX, YY + 3);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(201) << char(205) << char(205);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(187);

	setPos(XX, YY + 4);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186) << "  ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	setPos(XX, YY + 5);
	cout << char(200) << char(205) << char(188) << "  " << char(200) << char(205) << char(188);
}

void drawU(int XX, int YY) { // 6 * 9
	setPos(XX, YY);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(187) << "   ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(187);

	setPos(XX, YY + 1);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186) << "   ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	setPos(XX, YY + 2);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186) << "   ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	setPos(XX, YY + 3);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186) << "   ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	setPos(XX, YY + 4);
	cout << char(200);
	setColor(0, 0); cout << "      ";
	setColor(co_theme); cout << char(201) << char(188);

	setPos(XX + 1, YY + 5);
	cout << char(200);
	for (int i = 1; i <= 5; ++i) cout << char(205);
	cout << char(188);
}

void drawT(int XX, int YY) { // 6 * 9
	setPos(XX, YY);
	setColor(0, 0);  cout << "        ";
	setColor(co_theme); cout << char(187);

	setPos(XX, YY + 1);
	cout << char(200) << char(205) << char(205);
	setColor(0, 0); cout << "  ";
	setColor(co_theme);  cout << char(201) << char(205) << char(205) << char(188);

	for (int i = 0; i < 3; ++i) {
		setPos(XX + 3, YY + 2 + i);
		setColor(0, 0); cout << "  ";
		setColor(co_theme); cout << char(186);
	}

	setPos(XX + 3, YY + 5);
	cout << char(200) << char(205) << char(188);
}

void drawL(int XX, int YY) {  // 6 * 8
	setPos(XX, YY);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(187);

	for (int i = 1; i <= 3; ++i) {
		setPos(XX, YY + i);
		setColor(0, 0); cout << "  ";
		setColor(co_theme); cout << char(186);
	}

	setPos(XX, YY + 4);
	setColor(0, 0); cout << "       ";
	setColor(co_theme); cout << char(187);

	setPos(XX, YY + 5);
	cout << char(200);
	for (int i = 0; i < 6; ++i) cout << char(205);
	cout << char(188);
}

void drawD(int XX, int YY) {  // 6 * 8
	setPos(XX, YY);
	setColor(0, 0); cout << "      ";
	setColor(co_theme); cout << char(187);

	setPos(XX, YY + 1);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(201) << char(205) << char(205);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(187);

	for (int i = 2; i <= 3; ++i) {
		setPos(XX, YY + i);
		setColor(0, 0); cout << "  ";
		setColor(co_theme); cout << char(186) << "  ";
		setColor(0, 0); cout << "  ";
		setColor(co_theme); cout << char(186);
	}

	setPos(XX, YY + 4);
	setColor(0, 0); cout << "      ";
	setColor(co_theme); cout << char(201) << char(188);

	setPos(XX, YY + 5);
	cout << char(200);
	for (int i = 0; i < 5; ++i) cout << char(205);
	cout << char(188);
}

void drawG(int XX, int YY) {  // 6 * 9
	setPos(XX + 1, YY);
	setColor(0, 0); cout << "      ";
	setColor(co_theme); cout << char(187);

	setPos(XX, YY + 1);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(201);
	for (int i = 0; i < 4; ++i) cout << char(205);
	cout << char(188);

	setPos(XX, YY + 2);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186) << "  ";
	setColor(0, 0); cout << "   ";
	setColor(co_theme); cout << char(187);

	setPos(XX, YY + 3);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186) << "   ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	setPos(XX, YY + 4);
	cout << char(200);
	setColor(0, 0); cout << "      ";
	setColor(co_theme); cout << char(201) << char(188);

	setPos(XX + 1, YY + 5);
	cout << char(200);
	for (int i = 0; i < 5; ++i) cout << char(205);
	cout << char(188);
}

void drawM(int XX, int YY) {  // 6 * 11
	setPos(XX, YY);
	setColor(0, 0); cout << "   ";
	setColor(co_theme); cout << char(187) << "   ";
	setColor(0, 0); cout << "   ";
	setColor(co_theme); cout << char(187);

	setPos(XX, YY + 1);
	setColor(0, 0); cout << "    ";
	setColor(co_theme); cout << char(187) << " ";
	setColor(0, 0); cout << "    ";
	setColor(co_theme); cout << char(186);

	setPos(XX, YY + 2);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(201);
	setColor(0, 0); cout << "    ";
	setColor(co_theme); cout << char(201);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	setPos(XX, YY + 3);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186) << char(200);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(201) << char(188);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	setPos(XX, YY + 4);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186) << " " << char(200) << char(205) << char(188) << " ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	setPos(XX, YY + 5);
	cout << char(200) << char(205) << char(188) << "     " << char(200) << char(205) << char(188);
}

void drawE(int XX, int YY) {  // 6 * 8
	setPos(XX, YY);
	setColor(0, 0); cout << "       ";
	setColor(co_theme); cout << char(187);

	setPos(XX, YY + 1);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(201);
	for (int i = 0; i < 4; ++i) cout << char(205);
	cout << char(188);

	setPos(XX, YY + 2);
	setColor(0, 0); cout << "     ";
	setColor(co_theme); cout << char(187);

	setPos(XX, YY + 3);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(201) << char(205) << char(205) << char(188);

	setPos(XX, YY + 4);
	setColor(0, 0); cout << "       ";
	setColor(co_theme); cout << char(187);

	setPos(XX, YY + 5);
	cout << char(200);
	for (int i = 0; i < 6; ++i) cout << char(205);
	cout << char(188);
}

void drawN(int XX, int YY) {  // 6 * 10
	setPos(XX, YY);
	setColor(0, 0); cout << "   ";
	setColor(co_theme); cout << char(187) << "   ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(187);

	setPos(XX, YY + 1);
	setColor(0, 0); cout << "    ";
	setColor(co_theme); cout << char(187) << "  ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	setPos(XX, YY + 2);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(201);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(187) << " ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	setPos(XX, YY + 3);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186) << char(200);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(187);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	setPos(XX, YY + 4);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186) << " " << char(200);
	setColor(0, 0); cout << "    ";
	setColor(co_theme); cout << char(186);

	setPos(XX, YY + 5);
	cout << char(200) << char(205) << char(188) << "  " << char(200);
	for (int i = 0; i < 3; ++i) cout << char(205);
	cout << char(188);
}

void drawW(int XX, int YY) {  // 6 * 10
	setPos(XX, YY);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(187) << "    ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(187);

	setPos(XX, YY + 1);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186) << "    ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	setPos(XX, YY + 2);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186) << " ";
	setColor(0, 0); cout << " ";
	setColor(co_theme); cout << char(187) << " ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	setPos(XX, YY + 3);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);
	setColor(0, 0); cout << "   ";
	setColor(co_theme); cout << char(187);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	setPos(XX, YY + 4);
	setColor(co_theme); cout << char(200);
	setColor(0, 0); cout << "   ";
	setColor(co_theme); cout << char(201);
	setColor(0, 0); cout << "   ";
	setColor(co_theme); cout << char(201) << char(188);

	setPos(XX + 1, YY + 5);
	cout << char(200) << char(205) << char(205) << char(188) << char(200) << char(205) << char(205) << char(188);
}

void drawH(int XX, int YY) {  // 6 * 8
	setPos(XX, YY);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(187) << "  ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(187);

	setPos(XX, YY + 1);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186) << "  ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	setPos(XX, YY + 2);
	setColor(0, 0); cout << "       ";
	setColor(co_theme); cout << char(186);

	setPos(XX, YY + 3);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(201) << char(205) << char(205);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	setPos(XX, YY + 4);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186) << "  ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	setPos(XX, YY + 5);
	cout << char(200) << char(205) << char(188) << "  " << char(200) << char(205) << char(188);
}

void drawP(int XX, int YY) {  // 6 * 8
	setPos(XX, YY);
	setColor(0, 0); cout << "      ";
	setColor(co_theme); cout << char(187);

	setPos(XX, YY + 1);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(201) << char(205) << char(205);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(187);

	setPos(XX, YY + 2);
	setColor(0, 0); cout << "      ";
	setColor(co_theme); cout << char(201) << char(188);

	setPos(XX, YY + 3);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(201) << char(205) << char(205) << char(205) << char(188);

	setPos(XX, YY + 4);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	setPos(XX, YY + 5);
	cout << char(200) << char(205) << char(188);
}

void drawX(int XX, int YY, int co_txt = 0) {  // 6 * 8
	setPos(XX, YY);
	setColor(co_txt, 0); cout << "  ";
	setColor(15, co_txt); cout << char(187) << "  ";
	setColor(co_txt, 0); cout << "  ";
	setColor(15, co_txt); cout << char(187);

	setPos(XX, YY + 1);
	cout << char(200);
	setColor(co_txt, 0); cout << "  ";
	setColor(15, co_txt); cout << char(187);
	setColor(co_txt, 0); cout << "  ";
	setColor(15, co_txt); cout << char(201) << char(188);

	setPos(XX, YY + 2);
	cout << " " << char(200);
	setColor(co_txt, 0); cout << "   ";
	setColor(15, co_txt); cout << char(201) << char(188);

	setPos(XX, YY + 3);
	cout << " ";
	setColor(co_txt, 0); cout << "  ";
	setColor(15, co_txt); cout << char(201);
	setColor(co_txt, 0); cout << "  ";
	setColor(15, co_txt); cout << char(187);

	setPos(XX, YY + 4);
	setColor(co_txt, 0); cout << "  ";
	setColor(15, co_txt); cout << char(201) << char(188) << " ";
	setColor(co_txt, 0); cout << "  ";
	setColor(15, co_txt); cout << char(187);

	setPos(XX, YY + 5);
	cout << char(200) << char(205) << char(188) << "  " << char(200) << char(205) << char(188);
	setColor(co_theme);
}

void drawI(int XX, int YY) {  // 6 * 3
	setPos(XX, YY);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(187);

	setPos(XX, YY + 1);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	setPos(XX, YY + 2);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	setPos(XX, YY + 3);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	setPos(XX, YY + 4);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	setPos(XX, YY + 5);
	cout << char(200) << char(205) << char(188);
}

void drawCARO(int XX, int YY) {
	drawC(XX, YY);
	drawA(XX + 8, YY);
	drawR(XX + 16, YY);
	drawO(XX + 24, YY);
}

void drawABOUT(int XX, int YY) {
	drawA(XX, YY);
	drawB(XX + 8, YY);
	drawO(XX + 16, YY);
	drawU(XX + 25, YY);
	drawT(XX + 34, YY);
}

void drawLOAD_GAME(int XX, int YY) {
	drawL(XX, YY);
	drawO(XX + 8, YY);
	drawA(XX + 17, YY);
	drawD(XX + 25, YY);
	drawG(XX + 37, YY);
	drawA(XX + 46, YY);
	drawM(XX + 54, YY);
	drawE(XX + 65, YY);
}

void drawNEW_GAME(int XX, int YY) {
	drawN(XX, YY);
	drawE(XX + 10, YY);
	drawW(XX + 18, YY);
	drawG(XX + 32, YY);
	drawA(XX + 41, YY);
	drawM(XX + 49, YY);
	drawE(XX + 60, YY);
}

void drawHELP(int XX, int YY) {
	drawH(XX, YY);
	drawE(XX + 8, YY);
	drawL(XX + 16, YY);
	drawP(XX + 24, YY);
}

void drawIN_MATCH(int XX, int YY) {
	drawI(XX, YY);
	drawN(XX + 3, YY);
	drawM(XX + 17, YY);
	drawA(XX + 28, YY);
	drawT(XX + 36, YY);
	drawC(XX + 45, YY);
	drawH(XX + 53, YY);
}

void drawX_WIN(int XX, int YY) {
	drawX(XX, YY);
	drawW(XX + 12, YY);
	drawI(XX + 22, YY);
	drawN(XX + 25, YY);
}

void drawO_WIN(int XX, int YY) {
	drawO(XX, YY);
	drawW(XX + 13, YY);
	drawI(XX + 23, YY);
	drawN(XX + 26, YY);
}

void drawDRAW(int XX, int YY) {
	drawD(XX, YY);
	drawR(XX + 8, YY);
	drawA(XX + 16, YY);
	drawW(XX + 24, YY);
}

//void drawDino(int XX, int YY) {
//	setColor(0, 0);
//
//	setPos(XX, YY);
//	cout << "   " << char(219) << char(219) << char(219);
//
//	setPos(XX, YY + 1);
//	cout << "  " << char(219) << char(219) << char(219) << char(219) << char(219);
//
//	setPos(XX, YY + 2);
//	cout << "  " << char(219) << " " << char(219) << char(219);
//
//	setPos(XX, YY + 3);
//	cout << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219);
//
//	setPos(XX, YY + 4);
//	cout << char(219) << char(219) << char(219) << char(219) << char(219);
//
//	setPos(XX, YY + 5);
//	cout << char(219) << char(219) << " " << char(219);
//
//	setPos(XX, YY + 6);
//	cout << "  " << char(219) << " " << char(219);
//
//	setPos(XX, YY + 7);
//	cout << "  " << char(219) << " " << char(219);
//}


