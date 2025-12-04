#include "Library.h"
using namespace std;

#define backgroundcolor 15 //màu nền xám nhẹ
#define fontcolor 0 //màu chữ đen
#define co_theme 15,0 //màu chủ đề xanh dương
int ConsoleWidth = 120;
int ConsoleHeight = 35;

int BoardRealWidth = 0; 
int BoardRealHeight = 0;

int Box_Gap = 0; 

// Biến kích thước Box/Menu (Sẽ được tính toán động)
int buttonWidth = 0;
int buttonHeight = 0;
int TurnboxWidth = 0;
int TurnboxHeight = 0;

int Title_Width = 0;
int Title_Height = 0;

int ToggleBox_Width = 0;
int ToggleBox_Height = 0;

// Biến Group (Tính lại mỗi lần kích thước Box thay đổi)
int Group_Width = 0;
int Group_Height = 0;
int SettingsGroup_Height = 0;

// Biến Vị trí
int paddingX = 0;
int paddingY = 0;
int Xi = 0; 
int Yi = 0;
int X_Start_Group = 0;
int Y_Start_Group = 0;
int X_Start_Box = 0;
int Y_Start_Play = 0;
int Y_Start_Saved = 0;
int Y_Start_Settings = 0;
int Y_Start_About = 0;
int Y_Start_Exit = 0;
int Y_Start_MenuBox[MenuBoxNum];
int Y_Start_Settings_Group = 0;
int X_Start_ToggleBox = 0;
int Content_X = 0;
int SFX_Y = 0;
int MUSIC_Y = 0;
int BackY = 0;
int STATUS_X = 0;

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

void drawSETTINGS(int XX,int YY){
	/*drawS(XX, YY);*/
	drawE(XX + 5, YY);
	drawT(XX + 13, YY);
	drawT(XX + 22, YY);
	drawI(XX + 31, YY);
	drawN(XX + 34, YY);
	drawG(XX + 44, YY);
	/*drawS(XX + 53, YY);*/
}

void calculateLayoutParameters()
{
    if (ConsoleWidth <= 0 || ConsoleHeight <= 0) return;

    BoardRealWidth = BOARD_SIZE * CellWidth + (BOARD_SIZE + 1); 
    BoardRealHeight = BOARD_SIZE * CellHeight + (BOARD_SIZE + 1); 

    Box_Gap = max(2, ConsoleHeight / 40); 

    Title_Width = ConsoleWidth * 40 / 100; // 40% ConsoleWidth
    Title_Height = ConsoleHeight * 10/100;; 
    buttonWidth = ConsoleWidth * 15 / 100; // 15% ConsoleWidth
    buttonHeight = ConsoleHeight * 8 / 100;   
    TurnboxWidth = ConsoleWidth * 10 / 100; // 10% ConsoleWidth
    TurnboxHeight = ConsoleHeight * 30 / 100;
    ToggleBox_Width = ConsoleWidth * 20 / 100;
    ToggleBox_Height = ConsoleHeight * 15 / 100;

    Group_Width = Title_Width; 
    Group_Height = Title_Height + Box_Gap + MenuBoxNum * buttonHeight + (MenuBoxNum - 1) * Box_Gap;
    SettingsGroup_Height = Title_Height + Box_Gap + ToggleBox_Height + Box_Gap + buttonHeight;

    paddingX = (ConsoleWidth - BoardRealWidth) / 2;
    paddingY = (ConsoleHeight - BoardRealHeight) / 2;
    Xi = paddingX; 
    Yi = paddingY;

    X_Start_Group = (ConsoleWidth - Group_Width)/2;
    Y_Start_Group = (ConsoleHeight - Group_Height)/2;
    X_Start_Box = X_Start_Group + (Group_Width - buttonWidth)/2;

    Y_Start_Play = Y_Start_Group + Title_Height + Box_Gap;
    Y_Start_Saved = Y_Start_Play + buttonHeight + Box_Gap;
    Y_Start_Settings = Y_Start_Saved + buttonHeight + Box_Gap;
    Y_Start_About = Y_Start_Settings + buttonHeight + Box_Gap;
    Y_Start_Exit = Y_Start_About + buttonHeight + Box_Gap;
    Y_Start_MenuBox[0] = Y_Start_Play;
    Y_Start_MenuBox[1] = Y_Start_Saved;
    Y_Start_MenuBox[2] = Y_Start_Settings;
    Y_Start_MenuBox[3] = Y_Start_About;
    Y_Start_MenuBox[4] = Y_Start_Exit;

    Y_Start_Settings_Group = (ConsoleHeight - SettingsGroup_Height) / 2;
    X_Start_ToggleBox = (ConsoleWidth - ToggleBox_Width) / 2;
    Content_X = X_Start_ToggleBox + 3;
    SFX_Y = Y_Start_Settings_Group + Title_Height + Box_Gap + 1; // Nội dung cách viền trên 1 đơn vị
    MUSIC_Y = SFX_Y + 2;
    BackY = Y_Start_Settings_Group + Title_Height + Box_Gap + ToggleBox_Height + Box_Gap;
    STATUS_X = Content_X + 15;
}

void setColor(int bgcolor, int fgcolor)
{
    HANDLE consoleHandler = GetStdHandle(STD_OUTPUT_HANDLE);
    int color = 16 * bgcolor + fgcolor;
    SetConsoleTextAttribute(consoleHandler, color);
}

// VẼ KHUNG //

struct STATUS 
{
    int Top_Left = 218;
    int Top_Right = 191;
    int Bot_Left = 192;
    int Bot_Right = 217;
    int Hori_Bar = 196;
    int Verti_Bar = 179;
    int Blank = 255;
    int Dot_Square = 176; //Để vẽ mấy cái nhạt nhạt
    int Bold_Dot_Square = 176; //Để vẽ mấy cái đậm đạm

} symbol;

void drawBox(int x, int y, int w, int h, string text)
{
    setPos(x, y);

    cout << char(symbol.Top_Left);
    for (int i = 0; i < w-2; i++)
        cout << char(symbol.Hori_Bar);
    cout << char(symbol.Top_Right);

    for (int i = 1; i < h-1; i++) //in các | ở giữa (không tính) 2 bên rìa
    {
        setPos(x, y+i);
        cout << char(symbol.Verti_Bar);
        setPos(x+w-1, y+i);
        cout << char(symbol.Verti_Bar);
    }

    setPos(x, y + h - 1);
    cout << char(symbol.Bot_Left);
    for (int i = 0; i < w-2; i++)
        cout << char(symbol.Hori_Bar);
    cout << char(symbol.Bot_Right);

    //Văn bản (nếu có văn bản thì nó sẽ được căn giữ cho đẹp)
    if (!text.empty())
    {
        int txtlength = text.length(); 
        int blank_width = w - 2; //phần trống theo chiều ngang
        int center = (blank_width - txtlength)/2;
        int textX = x + 1 + center;

        int blank_height = h - 2; //phần trống theo chiều dọc
        int middle = (blank_height - 1)/2;
        int textY = y + 1 +  middle;

        setPos(textX, textY);
        cout << text;
    }
}


void getConsoleSize(int& WIDTH, int& HEIGHT) {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hOut, &csbi);

    // Lấy kích thước Viewport (Cửa sổ hiển thị)
    WIDTH = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    HEIGHT = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}
void fixConsoleWindow(int WIDTH, int HEIGHT)
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    HWND consoleWindow = GetConsoleWindow();
    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
    DWORD currMode;
    CONSOLE_FONT_INFOEX fontex;

    // Turn off maximize, resize, horizontal and vertical scrolling
    style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME) & ~(WS_HSCROLL) &
        ~(WS_VSCROLL);
    SetWindowLong(consoleWindow, GWL_STYLE, style);

    // Turn off mouse input
    GetConsoleMode(hOut, &currMode);
    SetConsoleMode(
        hOut,
        ((currMode | ENABLE_EXTENDED_FLAGS) & ~ENABLE_QUICK_EDIT_MODE &
            ~ENABLE_MOUSE_INPUT)
    );

    // Hide scoll bar
    ShowScrollBar(consoleWindow, SB_BOTH, FALSE);
    // Set font bold
    /*fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    GetCurrentConsoleFontEx(hOut, 0, &fontex);
    fontex.FontWeight = 800;
    fontex.dwFontSize.X = 24;
    fontex.dwFontSize.Y = 24;
    wcscpy_s(fontex.FaceName, L"Consolas");
    SetCurrentConsoleFontEx(hOut, NULL, &fontex);*/

    // Faster UI Update
    std::ios_base::sync_with_stdio(0);
    std::wcout.tie(0);
}
void fixviewConsoleWindow()
{
    fixConsoleWindow(ConsoleWidth, ConsoleHeight);
    getConsoleSize(ConsoleWidth, ConsoleHeight);
    calculateLayoutParameters();
    //calculateCellSize();
	calculateStartPos();
}

//==================== LOADING... =====================

void drawLoadingScreen()
{
    system("cls");
    setColor(backgroundcolor, fontcolor);

    setColor(0, 15);
    string message = "It can takes some seconds";
    int message_x = (ConsoleWidth - message.length())/2;
    int message_y = ConsoleHeight/2;

    const int total_cycles = 5 * 5;

    for (int i = 0; i < total_cycles; i++)
    {
        setPos(message_x, message_y);
        cout << message;

        int num_dots = (i % 3) + 1;

        setPos(message_x + message.length(), message_y);
        string dots = "";

        for (int j = 0; j < num_dots; j++)
        {
            dots += ".";
        }
        cout << dots;

        if (num_dots == 1)
            cout << "  "; 
        else if (num_dots == 2)
            cout << " ";
        Sleep(100);
    }
    setColor(backgroundcolor,fontcolor);
}

//==================== MÀN HÌNH CHÍNH ====================

void drawTitle()
{
	int Title_Width = 33;
	int Title_Height = 6;
	int Title_XX = ConsoleWidth / 2 - Title_Width / 2;
	int Title_YY = 4;
	drawCARO(Title_XX, Title_YY);
}

void drawPlayBox()
{
    Y_Start_MenuBox[0] = Y_Start_Play;
    drawBox(X_Start_Box, Y_Start_Play, buttonWidth, buttonHeight, "Play Game");
}

void drawSavedBox()
{
    Y_Start_MenuBox[1] = Y_Start_Saved;
	drawBox(X_Start_Box, Y_Start_Saved, buttonWidth, buttonHeight, "Load Game");
}

void drawSettingsBox()
{
    Y_Start_MenuBox[2] = Y_Start_Settings;
    drawBox(X_Start_Box, Y_Start_Settings, buttonWidth, buttonHeight, "Settings");
}

void drawAboutBox()
{
    Y_Start_MenuBox[3] = Y_Start_About;
	drawBox(X_Start_Box, Y_Start_About, buttonWidth, buttonHeight, "Help");
}

void drawExitBox()
{
    Y_Start_MenuBox[4] = Y_Start_Exit;
    drawBox(X_Start_Box, Y_Start_Exit, buttonWidth, buttonHeight, "Exit");
}

void drawMenuScreen()
{
    drawTitle();
    drawPlayBox();
    drawSavedBox();
    drawSettingsBox();
    drawAboutBox();
    drawExitBox();
    setColor(backgroundcolor, fontcolor);
}

const int Selected_BG = 8;
const int Selected_FG = 7;
const int Default_BG = backgroundcolor;
const int Default_FG = fontcolor;

//Nếu được chọn thì ô chọn sẽ có màu đen chữ trắng
void drawIsSelected(int idx, bool isSelected)
{
    if (isSelected)
        setColor(Selected_BG, Selected_FG);
    else
        setColor(Default_BG, Default_FG);
    string content;
    int Y0 = Y_Start_MenuBox[idx];
    switch (idx)
    {
        case 0: 
            content = "Play Game"; 
            break;
        case 1: 
			content = "Load Game";
            break;
        case 2: 
            content = "Settings"; 
            break;
        case 3: 
			content = "Help";
            break;
        case 4: 
            content = "Exit"; 
            break;
        default: 
            setColor(Default_BG, Default_FG);
            return;
    }
    drawBox(X_Start_Box, Y0, buttonWidth, buttonHeight, content);
    setColor(Default_BG, Default_FG);
}

int ControlMenu()
{
    int present_choice = 0; //Tại nút play

    drawIsSelected(present_choice, true);

    int key;
    while(true)
    {
        key = _getch();
        int past_choice = present_choice;
        if (key == 0 || key == 224)
        {
            key = _getch();
            switch(key)
            {
                case 72:
                    key = 'W';
                    break;
                case 80:
                    key = 'S';
                    break;
                default:
                    continue;
            }
        }
        switch(toupper(key))
        {
            case 'W': 
                present_choice = (present_choice - 1 + MenuBoxNum) % MenuBoxNum;
				playMoveSound();
                break;
            case 'S': 
                present_choice = (present_choice + 1) % MenuBoxNum;
				playMoveSound();
                break;
            case 13: //enter
				playClickSound();
				return present_choice + 1; 
            default:
                continue;
        }
        if (present_choice != past_choice)
        {
            drawIsSelected(past_choice, false);
            drawIsSelected(present_choice, true);
        }
    }
}

//==================== MÀN HÌNH NHẬP TÊN ==========================
//dang duoc cap nhat...

//==================== MÀN HÌNH CHƠI GAME ==========================

void drawCaroBoard()
{
    setColor(backgroundcolor, fontcolor);
    DrawBoard();
    setColor(backgroundcolor, fontcolor);
}

bool isClickedButton(int xx, int yy, int X_start, int Y_start)
{
    int X_end = X_start + buttonWidth;
    int Y_end = Y_start + buttonHeight;
    if (xx >= X_start && xx <= X_end && yy >= Y_start && yy <= Y_end)
        return true;
    return false;
}

void drawExitButton()
{
    setColor(backgroundcolor, fontcolor);
    int X_start = Xi + (BoardRealWidth/2 - buttonWidth)/2 ;
    int Y_start = Yi - (paddingY + buttonHeight)/2;
    setPos(X_start, Y_start);
    drawBox(X_start, Y_start, buttonWidth, buttonHeight, "Exit");
}

void drawAgainButton()
{
    setColor(backgroundcolor, fontcolor);
    int X_start = Xi + BoardRealWidth/2 + (BoardRealWidth/2 - buttonWidth)/2;
    int Y_start = Yi - (paddingY + buttonHeight)/2;
    setPos(X_start, Y_start);
    drawBox(X_start, Y_start, buttonWidth, buttonHeight, "Play Again");
}

int checkClicked(int xx, int yy)
{
    const int Exit_X = Xi + (BoardRealWidth/2 - buttonWidth)/2;
    const int Exit_Y = Yi - (paddingY + buttonHeight)/2;
    const int Again_X = Xi + BoardRealWidth/2 + (BoardRealWidth/2 - buttonWidth)/2;
    const int Again_Y = Yi - (paddingY + buttonHeight)/2;
    if (isClickedButton(xx, yy, Exit_X, Exit_Y))
        return 6;
    else if (isClickedButton(xx, yy, Again_X, Again_Y))
        return 7;
    return 0;
}

void drawTurnBox(char player, char name1[], char name2[])
{
    setColor(backgroundcolor, fontcolor);
    int X_start = Xi - (paddingX + TurnboxWidth)/2;
    int Y_start = Yi + (BoardRealHeight - TurnboxHeight )/2;
    string name_player;
    player = check_XO();
    if (player == 'X')
        name_player = name1;
    else
        name_player = name2;
    string content = "Turn (" + std::string(1, player) + "): " + name_player;
    setPos(X_start, Y_start);
    drawBox(X_start, Y_start, TurnboxWidth, TurnboxHeight, content);
}

void drawTimeBox(char min[], char sec[])
{
    setColor(backgroundcolor, fontcolor);
    int X_start = Xi + BoardRealWidth + (paddingX - TurnboxWidth)/2;
    int Y_start = Yi + (BoardRealHeight - TurnboxHeight)/2;
    string content = "Time Set: " + string(min) + ":" + string(sec);
    setPos(X_start, Y_start);
    drawBox(X_start, Y_start, TurnboxWidth, TurnboxHeight, content);
}

void drawFilename(std::string filename)
{
    int length = filename.length();
    int X_start = Xi + BoardRealWidth/2 - length/2;
	//int X_start =1; 
    int Y_start = ConsoleHeight - 1;
    setPos(X_start, Y_start);
    cout << filename;
}

void drawGamePlayScreen(char player, char name1[], char name2[], char min[], char sec[], std::string filename)
{
    system("cls");
    setColor(backgroundcolor, fontcolor);
    drawCaroBoard();
    drawExitButton();
    drawAgainButton();
    drawTurnBox(player, name1, name2);
    drawTimeBox(min, sec);
    drawFilename(filename);
}

// SAVED GAME SCREEN
    //dang duoc cap nhat...

// VẼ SETTINGS GREEN

struct GameSettings Default_Set = {true, true};

string getToggleStatus(bool isActive)
{
    return isActive ? "ON" : "OFF";
}

 void drawSettingsTitle()
{
	 drawSETTINGS(Xi + 9, Yi - 1);
}

void drawSettingsToggleBox()
{
    drawBox(X_Start_ToggleBox, Y_Start_Settings_Group + Title_Height + Box_Gap, ToggleBox_Width, ToggleBox_Height, "");
    setColor(backgroundcolor, fontcolor);
    setPos(Content_X, SFX_Y);
    cout << "SFX:           ";

    setPos(Content_X + 15, SFX_Y);
    cout << getToggleStatus(Default_Set.sfx_active);

    setPos(Content_X, MUSIC_Y);
    cout << "MUSIC:         ";

    setPos(Content_X + 15, MUSIC_Y);
    cout << getToggleStatus(Default_Set.music_active);

    drawSettingsHighlight(0, false);
    drawSettingsHighlight(1, true);

    setColor(backgroundcolor, fontcolor);
}

void drawSettingsBackBox()
{
    drawBox(X_Start_Box, BackY, buttonWidth, buttonHeight, "BACK");
}

void drawSettingsScreen()
{
    system("cls");
    setColor(backgroundcolor, fontcolor);
    drawSettingsTitle();
    drawSettingsToggleBox();
    drawSettingsBackBox();
}

void drawSettingsHighlight(int idx, bool isSelected)
{
    int current_BG = Default_BG;
    int current_FG = Default_FG;

    string content;

    if (isSelected)
    {
        current_BG = Selected_BG;
        current_FG = Selected_FG;
    }
    setColor(current_BG, current_FG);

    if (idx == 0)
    {
        setColor(Default_BG, Default_FG);
        setPos(Content_X, SFX_Y);
        cout << "SFX:           ";
        setColor(current_BG, current_FG);
        setPos(STATUS_X, SFX_Y);
        cout << getToggleStatus(Default_Set.sfx_active) << "   ";
    }
    else if (idx == 1)
    {
        setColor(Default_BG, Default_FG);
        setPos(Content_X, MUSIC_Y);
        cout << "MUSIC:           ";
        setColor(current_BG, current_FG);
        setPos(STATUS_X, MUSIC_Y);
        cout << getToggleStatus(Default_Set.music_active) << "   ";
    }
    else if (idx == 2)
    {
        setColor(current_BG, current_FG);
        drawBox(X_Start_Box, BackY, buttonWidth, buttonHeight, "BACK");
    }
    setColor(Default_BG, Default_FG);
}

int ControlSettings()
{
    drawSettingsScreen();
    int present_choice = 0; // Bắt đầu ở SFX

    // Highlight lựa chọn ban đầu
    drawSettingsHighlight(present_choice, true);

    int key;
    while(true)
    {
        key = _getch();
        int past_choice = present_choice;
        
        // Xử lý phím điều hướng
        if (key == 0 || key == 224)
        {
            key = _getch();
            switch(key)
            {
                case 72: 
					key = 'W'; 
					break; // Lên
                case 80: 
					key = 'S'; 
					break; // Xuống
                default: continue;
            }
        }

        switch(toupper(key))
        {
            case 'W': 
                present_choice = (present_choice - 1 + SettingsBoxNum) % SettingsBoxNum; ;
                break;
            case 'S': 
                present_choice = (present_choice + 1) % SettingsBoxNum; ;
                break;
            case 13: // Enter
				playClickSound();
                if (present_choice == 0) 
                {
                    Default_Set.sfx_active = !Default_Set.sfx_active;
                    drawSettingsHighlight(present_choice, true); 
                } 
                else if (present_choice == 1) 
                {
                    Default_Set.music_active = !Default_Set.music_active;
                    drawSettingsHighlight(present_choice, true);

                } else if (present_choice == 2) {
                    // BACK
                    return 0; // Trả về 0 để báo hiệu quay lại Menu chính
                }
                continue;
            default:
                continue;
        }

        if (present_choice != past_choice)
        {
            drawSettingsHighlight(past_choice, false); // Hủy chọn cái cũ
            drawSettingsHighlight(present_choice, true); // Chọn cái mới
        }
    }
}

//ABOUT US SCREEN....

void drawAboutUsScreen()
{
	system("cls");
	setColor(backgroundcolor, fontcolor);
	drawHELP(Xi + 9, Yi - 1);
}
    // dang duoc cap nhat...
