#include "Library.h"
#define num_ground 120
using namespace std;
char ground[3][num_ground + 1];  //khởi tạo mảng 2 chiều 3 dòng để vẽ mặt đất
void drawA(int XX, int YY) { // 6 * 8
	setPos(XX + 1, YY);
	setColor(0, 0); cout << "     ";
	setColor(co_theme); cout << u8"╗";

	setPos(XX, YY + 1);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"╔" << u8"═" << u8"═";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"╗";

	setPos(XX, YY + 2);
	setColor(0, 0); cout << "       ";
	setColor(co_theme); cout << u8"║";

	setPos(XX, YY + 3);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"╔" << u8"═" << u8"═";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"║";

	setPos(XX, YY + 4);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"║" << "  ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"║";

	setPos(XX, YY + 5);
	cout << u8"╚" << u8"═" << u8"╝" << "  " << u8"╚" << u8"═" << u8"╝";
}

void drawB(int XX, int YY) { // 6 * 8
	setPos(XX, YY);
	setColor(0, 0); for (int i = 0; i < 6; ++i) cout << " ";
	setColor(co_theme); cout << u8"╗";

	setPos(XX, YY + 1);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"╔" << u8"═" << u8"═";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"╗";

	setPos(XX, YY + 2);
	setColor(0, 0); for (int i = 0; i < 6; ++i) cout << " ";
	setColor(co_theme); cout << u8"╔" << u8"╝";

	setPos(XX, YY + 3);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"╔" << u8"═" << u8"═";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"╗";

	setPos(XX, YY + 4);
	setColor(0, 0); for (int i = 0; i < 6; ++i) cout << " ";
	setColor(co_theme); cout << u8"╔" << u8"╝";

	setPos(XX, YY + 5);
	cout << u8"╚";
	for (int i = 0; i < 5; ++i) cout << u8"═";
	cout << u8"╝";
}

void drawC(int XX, int YY) { // 6 * 8
	setPos(XX + 1, YY);
	setColor(0, 0); cout << "      ";
	setColor(co_theme); cout << u8"╗";

	setPos(XX, YY + 1);
	setColor(0, 0);  cout << "  ";
	setColor(co_theme);
	cout << u8"╔";
	for (int i = 1; i <= 4; ++i) cout << u8"═";
	cout << u8"╝";

	setPos(XX, YY + 2);
	setColor(0, 0);  cout << "  ";
	setColor(co_theme); cout << u8"║";

	setPos(XX, YY + 3);
	setColor(0, 0);  cout << "  ";
	setColor(co_theme); cout << u8"║";

	setPos(XX, YY + 4);
	cout << u8"╚";
	setColor(0, 0);  cout << "      ";
	setColor(co_theme); cout << u8"╗";

	setPos(XX + 1, YY + 5);
	cout << u8"╚";
	for (int i = 1; i <= 5; ++i) cout << u8"═";
	cout << u8"╝";
}

void drawO(int XX, int YY, int co_txt = 0) { // 6 * 9
	setPos(XX + 1, YY);
	setColor(co_txt, 0); cout << "      ";
	setColor(15, co_txt); cout << u8"╗";

	setPos(XX, YY + 1);
	setColor(co_txt, 0); cout << "  ";
	setColor(15, co_txt); cout << u8"╔" << u8"═" << u8"═" << u8"═";
	setColor(co_txt, 0); cout << "  ";
	setColor(15, co_txt); cout << u8"╗";

	setPos(XX, YY + 2);
	setColor(co_txt, 0); cout << "  ";
	setColor(15, co_txt); cout << u8"║" << "   ";
	setColor(co_txt, 0); cout << "  ";
	setColor(15, co_txt); cout << u8"║";

	setPos(XX, YY + 3);
	setColor(co_txt, 0); cout << "  ";
	setColor(15, co_txt); cout << u8"║" << "   ";
	setColor(co_txt, 0); cout << "  ";
	setColor(15, co_txt); cout << u8"║";

	setPos(XX, YY + 4);
	cout << u8"╚";
	setColor(co_txt, 0); cout << "      ";
	setColor(15, co_txt); cout << u8"╔" << u8"╝";

	setPos(XX + 1, YY + 5);
	cout << u8"╚";
	for (int i = 1; i <= 5; ++i) cout << u8"═";
	cout << u8"╝";
	setColor(co_theme);
}

void drawR(int XX, int YY) { // 6 * 8
	setPos(XX, YY);
	setColor(0, 0); cout << "      ";
	setColor(co_theme); cout << u8"╗";

	setPos(XX, YY + 1);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"╔" << u8"═" << u8"═";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"╗";

	setPos(XX, YY + 2);
	setColor(0, 0); cout << "      ";
	setColor(co_theme); cout << u8"╔" << u8"╝";

	setPos(XX, YY + 3);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"╔" << u8"═" << u8"═";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"╗";

	setPos(XX, YY + 4);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"║" << "  ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"║";

	setPos(XX, YY + 5);
	cout << u8"╚" << u8"═" << u8"╝" << "  " << u8"╚" << u8"═" << u8"╝";
}

void drawU(int XX, int YY) { // 6 * 9
	setPos(XX, YY);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"╗" << "   ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"╗";

	setPos(XX, YY + 1);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"║" << "   ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"║";

	setPos(XX, YY + 2);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"║" << "   ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"║";

	setPos(XX, YY + 3);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"║" << "   ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"║";

	setPos(XX, YY + 4);
	cout << u8"╚";
	setColor(0, 0); cout << "      ";
	setColor(co_theme); cout << u8"╔" << u8"╝";

	setPos(XX + 1, YY + 5);
	cout << u8"╚";
	for (int i = 1; i <= 5; ++i) cout << u8"═";
	cout << u8"╝";
}

void drawT(int XX, int YY) { // 6 * 9
	setPos(XX, YY);
	setColor(0, 0);  cout << "        ";
	setColor(co_theme); cout << u8"╗";

	setPos(XX, YY + 1);
	cout << u8"╚" << u8"═" << u8"═";
	setColor(0, 0); cout << "  ";
	setColor(co_theme);  cout << u8"╔" << u8"═" << u8"═" << u8"╝";

	for (int i = 0; i < 3; ++i) {
		setPos(XX + 3, YY + 2 + i);
		setColor(0, 0); cout << "  ";
		setColor(co_theme); cout << u8"║";
	}

	setPos(XX + 3, YY + 5);
	cout << u8"╚" << u8"═" << u8"╝";
}

void drawL(int XX, int YY) {  // 6 * 8
	setPos(XX, YY);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"╗";

	for (int i = 1; i <= 3; ++i) {
		setPos(XX, YY + i);
		setColor(0, 0); cout << "  ";
		setColor(co_theme); cout << u8"║";
	}

	setPos(XX, YY + 4);
	setColor(0, 0); cout << "       ";
	setColor(co_theme); cout << u8"╗";

	setPos(XX, YY + 5);
	cout << u8"╚";
	for (int i = 0; i < 6; ++i) cout << u8"═";
	cout << u8"╝";
}

void drawD(int XX, int YY) {  // 6 * 8
	setPos(XX, YY);
	setColor(0, 0); cout << "      ";
	setColor(co_theme); cout << u8"╗";

	setPos(XX, YY + 1);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"╔" << u8"═" << u8"═";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"╗";

	for (int i = 2; i <= 3; ++i) {
		setPos(XX, YY + i);
		setColor(0, 0); cout << "  ";
		setColor(co_theme); cout << u8"║" << "  ";
		setColor(0, 0); cout << "  ";
		setColor(co_theme); cout << u8"║";
	}

	setPos(XX, YY + 4);
	setColor(0, 0); cout << "      ";
	setColor(co_theme); cout << u8"╔" << u8"╝";

	setPos(XX, YY + 5);
	cout << u8"╚";
	for (int i = 0; i < 5; ++i) cout << u8"═";
	cout << u8"╝";
}

void drawG(int XX, int YY) {  // 6 * 9
	setPos(XX + 1, YY);
	setColor(0, 0); cout << "      ";
	setColor(co_theme); cout << u8"╗";

	setPos(XX, YY + 1);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"╔";
	for (int i = 0; i < 4; ++i) cout << u8"═";
	cout << u8"╝";

	setPos(XX, YY + 2);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"║" << "  ";
	setColor(0, 0); cout << "   ";
	setColor(co_theme); cout << u8"╗";

	setPos(XX, YY + 3);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"║" << "   ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"║";

	setPos(XX, YY + 4);
	cout << u8"╚";
	setColor(0, 0); cout << "      ";
	setColor(co_theme); cout << u8"╔" << u8"╝";

	setPos(XX + 1, YY + 5);
	cout << u8"╚";
	for (int i = 0; i < 5; ++i) cout << u8"═";
	cout << u8"╝";
}

void drawM(int XX, int YY) {  // 6 * 11
	setPos(XX, YY);
	setColor(0, 0); cout << "   ";
	setColor(co_theme); cout << u8"╗" << "   ";
	setColor(0, 0); cout << "   ";
	setColor(co_theme); cout << u8"╗";

	setPos(XX, YY + 1);
	setColor(0, 0); cout << "    ";
	setColor(co_theme); cout << u8"╗" << " ";
	setColor(0, 0); cout << "    ";
	setColor(co_theme); cout << u8"║";

	setPos(XX, YY + 2);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"╔";
	setColor(0, 0); cout << "    ";
	setColor(co_theme); cout << u8"╔";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"║";

	setPos(XX, YY + 3);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"║" << u8"╚";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"╔" << u8"╝";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"║";

	setPos(XX, YY + 4);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"║" << " " << u8"╚" << u8"═" << u8"╝" << " ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"║";

	setPos(XX, YY + 5);
	cout << u8"╚" << u8"═" << u8"╝" << "     " << u8"╚" << u8"═" << u8"╝";
}

void drawE(int XX, int YY) {  // 6 * 8
	setPos(XX, YY);
	setColor(0, 0); cout << "       ";
	setColor(co_theme); cout << u8"╗";

	setPos(XX, YY + 1);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"╔";
	for (int i = 0; i < 4; ++i) cout << u8"═";
	cout << u8"╝";

	setPos(XX, YY + 2);
	setColor(0, 0); cout << "     ";
	setColor(co_theme); cout << u8"╗";

	setPos(XX, YY + 3);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"╔" << u8"═" << u8"═" << u8"╝";

	setPos(XX, YY + 4);
	setColor(0, 0); cout << "       ";
	setColor(co_theme); cout << u8"╗";

	setPos(XX, YY + 5);
	cout << u8"╚";
	for (int i = 0; i < 6; ++i) cout << u8"═";
	cout << u8"╝";
}

void drawN(int XX, int YY) {  // 6 * 10
	setPos(XX, YY);
	setColor(0, 0); cout << "   ";
	setColor(co_theme); cout << u8"╗" << "   ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"╗";

	setPos(XX, YY + 1);
	setColor(0, 0); cout << "    ";
	setColor(co_theme); cout << u8"╗" << "  ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"║";

	setPos(XX, YY + 2);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"╔";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"╗" << " ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"║";

	setPos(XX, YY + 3);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"║" << u8"╚";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"╗";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"║";

	setPos(XX, YY + 4);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"║" << " " << u8"╚";
	setColor(0, 0); cout << "    ";
	setColor(co_theme); cout << u8"║";

	setPos(XX, YY + 5);
	cout << u8"╚" << u8"═" << u8"╝" << "  " << u8"╚";
	for (int i = 0; i < 3; ++i) cout << u8"═";
	cout << u8"╝";
}

void drawW(int XX, int YY) {  // 6 * 10
	setPos(XX, YY);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"╗" << "    ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"╗";

	setPos(XX, YY + 1);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"║" << "    ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"║";

	setPos(XX, YY + 2);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"║" << " ";
	setColor(0, 0); cout << " ";
	setColor(co_theme); cout << u8"╗" << " ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"║";

	setPos(XX, YY + 3);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"║";
	setColor(0, 0); cout << "   ";
	setColor(co_theme); cout << u8"╗";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"║";

	setPos(XX, YY + 4);
	setColor(co_theme); cout << u8"╚";
	setColor(0, 0); cout << "   ";
	setColor(co_theme); cout << u8"╔";
	setColor(0, 0); cout << "   ";
	setColor(co_theme); cout << u8"╔" << u8"╝";

	setPos(XX + 1, YY + 5);
	cout << u8"╚" << u8"═" << u8"═" << u8"╝" << u8"╚" << u8"═" << u8"═" << u8"╝";
}

void drawH(int XX, int YY) {  // 6 * 8
	setPos(XX, YY);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"╗" << "  ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"╗";

	setPos(XX, YY + 1);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"║" << "  ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"║";

	setPos(XX, YY + 2);
	setColor(0, 0); cout << "       ";
	setColor(co_theme); cout << u8"║";

	setPos(XX, YY + 3);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"╔" << u8"═" << u8"═";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"║";

	setPos(XX, YY + 4);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"║" << "  ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"║";

	setPos(XX, YY + 5);
	cout << u8"╚" << u8"═" << u8"╝" << "  " << u8"╚" << u8"═" << u8"╝";
}

void drawP(int XX, int YY) {  // 6 * 8
	setPos(XX, YY);
	setColor(0, 0); cout << "      ";
	setColor(co_theme); cout << u8"╗";

	setPos(XX, YY + 1);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"╔" << u8"═" << u8"═";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"╗";

	setPos(XX, YY + 2);
	setColor(0, 0); cout << "      ";
	setColor(co_theme); cout << u8"╔" << u8"╝";

	setPos(XX, YY + 3);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"╔" << u8"═" << u8"═" << u8"═" << u8"╝";

	setPos(XX, YY + 4);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"║";

	setPos(XX, YY + 5);
	cout << u8"╚" << u8"═" << u8"╝";
}

void drawX(int XX, int YY, int co_txt = 0) {  // 6 * 8
	setPos(XX, YY);
	setColor(co_txt, 0); cout << "  ";
	setColor(15, co_txt); cout << u8"╗" << "  ";
	setColor(co_txt, 0); cout << "  ";
	setColor(15, co_txt); cout << u8"╗";

	setPos(XX, YY + 1);
	cout << u8"╚";
	setColor(co_txt, 0); cout << "  ";
	setColor(15, co_txt); cout << u8"╗";
	setColor(co_txt, 0); cout << "  ";
	setColor(15, co_txt); cout << u8"╔" << u8"╝";

	setPos(XX, YY + 2);
	cout << " " << u8"╚";
	setColor(co_txt, 0); cout << "   ";
	setColor(15, co_txt); cout << u8"╔" << u8"╝";

	setPos(XX, YY + 3);
	cout << " ";
	setColor(co_txt, 0); cout << "  ";
	setColor(15, co_txt); cout << u8"╔";
	setColor(co_txt, 0); cout << "  ";
	setColor(15, co_txt); cout << u8"╗";

	setPos(XX, YY + 4);
	setColor(co_txt, 0); cout << "  ";
	setColor(15, co_txt); cout << u8"╔" << u8"╝" << " ";
	setColor(co_txt, 0); cout << "  ";
	setColor(15, co_txt); cout << u8"╗";

	setPos(XX, YY + 5);
	cout << u8"╚" << u8"═" << u8"╝" << "  " << u8"╚" << u8"═" << u8"╝";
	setColor(co_theme);
}

void drawI(int XX, int YY) {  // 6 * 3
	setPos(XX, YY);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"╗";

	setPos(XX, YY + 1);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"║";

	setPos(XX, YY + 2);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"║";

	setPos(XX, YY + 3);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"║";

	setPos(XX, YY + 4);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"║";

	setPos(XX, YY + 5);
	cout << u8"╚" << u8"═" << u8"╝";
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

void drawGAME_MODE(int XX, int YY) {
	drawG(XX, YY);
	drawA(XX + 9, YY);
	drawM(XX + 17, YY);
	drawE(XX + 28, YY);
	drawM(XX + 40, YY);
	drawO(XX + 49, YY);
	drawD(XX + 59, YY);
	drawE(XX + 68, YY);
}

void drawS(int XX, int YY) {
	setPos(XX, YY);
	setColor(0, 0); cout << "       ";
	setColor(co_theme); cout << u8"╗";

	setPos(XX, YY + 1);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"╔";
	for (int i = 0; i < 4; ++i) cout << u8"═";
	cout << u8"╝";

	setPos(XX, YY + 2);
	setColor(0, 0); cout << "       ";
	setColor(co_theme); cout << u8"╗";

	setPos(XX + 5, YY + 3);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"║";

	setPos(XX, YY + 4);
	setColor(0, 0); cout << "       ";
	setColor(co_theme); cout << u8"║";

	setPos(XX, YY + 5);
	cout << u8"╚";
	for (int i = 0; i < 6; ++i) cout << u8"═";
	cout << u8"╝";


}

void drawV(int XX, int YY) { // 6 * 9
	setPos(XX, YY);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"╗" << "    ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"╗";

	setPos(XX, YY + 1);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"║" << "    ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"║";


	setPos(XX, YY + 2);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"║" << "    ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"║";

	setPos(XX + 1, YY + 3);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"╗" << "  ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << u8"╝";

	setPos(XX + 3, YY + 4);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << "";
	setColor(0, 0); cout << " ";
	setColor(co_theme); cout << u8"╝";


	setPos(XX + 3, YY + 5);
	cout << u8"╚" << u8"═" << u8"╝";

}


void drawSAVELOAD(int XX, int YY) {
	drawS(XX, YY);
	drawA(XX + 8, YY);
	drawV(XX + 16, YY);
	drawE(XX + 26, YY);

	drawL(XX + 40, YY);
	drawO(XX + 48, YY);
	drawA(XX + 57, YY);
	drawD(XX + 65, YY);
}

void drawPAUSE(int XX, int YY) {
	drawP(XX, YY);
	drawA(XX + 8, YY);
	drawU(XX + 16, YY);
	drawS(XX + 26, YY);
	drawE(XX + 34, YY);
}
void drawSETTING(int XX, int YY) {
	drawS(XX - 14, YY);
	drawE(XX - 6, YY);
	drawT(XX + 2, YY);
	drawT(XX + 11, YY);
	drawI(XX + 20, YY);
	drawN(XX + 23, YY);
	drawG(XX + 33, YY);
	drawS(XX + 42, YY);
}
void drawCactus(int XX, int YY) {
	const char* A = u8"█ ";
	const char* B = u8"██ ";          // khối 2 ô
	const char* K = u8"████████ ";

	// ======== ROW 8 =========
	setPos(XX + 94, YY + 8); cout << B;
	setPos(XX + 96, YY + 8); cout << B;


	// ======== ROW 9 =========
	setPos(XX + 93, YY + 9); cout << B;
	setPos(XX + 94, YY + 9); cout << B;
	setPos(XX + 96, YY + 9); cout << B;
	setPos(XX + 97, YY + 9); cout << B;


	// ======== ROW 10 =========
	setPos(XX + 93, YY + 10); cout << B;
	setPos(XX + 94, YY + 10); cout << B;
	setPos(XX + 96, YY + 10); cout << B;
	setPos(XX + 97, YY + 10); cout << B;


	// ======== ROW 11 =========
	setPos(XX + 93, YY + 11); cout << B;
	setPos(XX + 94, YY + 11); cout << B;
	setPos(XX + 96, YY + 11); cout << B;
	setPos(XX + 97, YY + 11); cout << B;


	// ======== ROW 12 - canh phai =========
	setPos(XX + 93, YY + 12); cout << B;
	setPos(XX + 94, YY + 12); cout << B;
	setPos(XX + 96, YY + 12); cout << B;
	setPos(XX + 97, YY + 12); cout << B;
	//setPos(XX + 103, YY + 12); cout << B;
	setPos(XX + 104, YY + 12); cout << B;
	setPos(XX + 105, YY + 12); cout << B;


	// ======== ROW 13 - canh trai =========
	setPos(XX + 85, YY + 13); cout << B;
	setPos(XX + 86, YY + 13); cout << B;
	setPos(XX + 93, YY + 13); cout << B;
	setPos(XX + 94, YY + 13); cout << B;
	setPos(XX + 96, YY + 13); cout << B;
	setPos(XX + 97, YY + 13); cout << B;
	setPos(XX + 103, YY + 13); cout << B;
	setPos(XX + 104, YY + 13); cout << B;
	setPos(XX + 105, YY + 13); cout << B;
	setPos(XX + 106, YY + 13); cout << B;

	// ======== ROW 14 =========
	setPos(XX + 84, YY + 14); cout << B;
	setPos(XX + 86, YY + 14); cout << B;
	setPos(XX + 87, YY + 14); cout << B;
	setPos(XX + 93, YY + 14); cout << B;
	setPos(XX + 94, YY + 14); cout << B;
	setPos(XX + 96, YY + 14); cout << B;
	setPos(XX + 97, YY + 14); cout << B;
	setPos(XX + 103, YY + 14); cout << B;
	setPos(XX + 104, YY + 14); cout << B;
	setPos(XX + 105, YY + 14); cout << B;
	setPos(XX + 106, YY + 14); cout << B;


	// ======== ROW 15 =========
	setPos(XX + 84, YY + 15); cout << B;
	setPos(XX + 86, YY + 15); cout << B;
	setPos(XX + 87, YY + 15); cout << B;
	setPos(XX + 93, YY + 15); cout << B;
	setPos(XX + 94, YY + 15); cout << B;
	setPos(XX + 96, YY + 15); cout << B;
	setPos(XX + 97, YY + 15); cout << B;
	setPos(XX + 103, YY + 15); cout << B;
	setPos(XX + 104, YY + 15); cout << B;
	setPos(XX + 105, YY + 15); cout << B;
	setPos(XX + 106, YY + 15); cout << B;

	// ======== ROW 16 =========
	setPos(XX + 84, YY + 16); cout << B;
	setPos(XX + 86, YY + 16); cout << B;
	setPos(XX + 87, YY + 16); cout << B;
	setPos(XX + 93, YY + 16); cout << B;
	setPos(XX + 94, YY + 16); cout << B;
	setPos(XX + 96, YY + 16); cout << B;
	setPos(XX + 97, YY + 16); cout << B;
	setPos(XX + 103, YY + 16); cout << B;
	setPos(XX + 104, YY + 16); cout << B;
	setPos(XX + 105, YY + 16); cout << B;
	setPos(XX + 106, YY + 16); cout << B;

	// ======== ROW 17 =========
	setPos(XX + 84, YY + 17); cout << B;
	setPos(XX + 86, YY + 17); cout << B;
	setPos(XX + 87, YY + 17); cout << B;
	setPos(XX + 93, YY + 17); cout << B;
	setPos(XX + 94, YY + 17); cout << B;
	setPos(XX + 96, YY + 17); cout << B;
	setPos(XX + 97, YY + 17); cout << B;
	setPos(XX + 103, YY + 17); cout << B;
	setPos(XX + 104, YY + 17); cout << B;
	setPos(XX + 105, YY + 17); cout << B;
	setPos(XX + 106, YY + 17); cout << B;


	// ======== ROW 18 - noi =========
	setPos(XX + 84, YY + 18); cout << B;
	setPos(XX + 86, YY + 18); cout << B;
	setPos(XX + 88, YY + 18); cout << B;
	setPos(XX + 90, YY + 18); cout << B;
	setPos(XX + 92, YY + 18); cout << B;
	setPos(XX + 93, YY + 18); cout << B;
	setPos(XX + 94, YY + 18); cout << B;
	setPos(XX + 96, YY + 18); cout << B;
	setPos(XX + 97, YY + 18); cout << B;
	setPos(XX + 99, YY + 18); cout << B;
	setPos(XX + 101, YY + 18); cout << B;
	setPos(XX + 103, YY + 18); cout << B;
	setPos(XX + 104, YY + 18); cout << B;
	setPos(XX + 105, YY + 18); cout << B;
	setPos(XX + 106, YY + 18); cout << B;

	// ======== ROW 19 =========
	setPos(XX + 85, YY + 19); cout << B;
	setPos(XX + 86, YY + 19); cout << B;
	setPos(XX + 88, YY + 19); cout << B;
	setPos(XX + 90, YY + 19); cout << B;
	setPos(XX + 92, YY + 19); cout << B;
	setPos(XX + 93, YY + 19); cout << B;
	setPos(XX + 94, YY + 19); cout << B;
	setPos(XX + 96, YY + 19); cout << B;
	setPos(XX + 97, YY + 19); cout << B;
	setPos(XX + 99, YY + 19); cout << B;
	setPos(XX + 101, YY + 19); cout << B;
	setPos(XX + 103, YY + 19); cout << B;
	setPos(XX + 104, YY + 19); cout << B;
	//setPos(XX + 105, YY + 19); cout << B;

	// ======== ROW 20 =========
	setPos(XX + 87, YY + 20); cout << B;
	setPos(XX + 88, YY + 20); cout << B;
	setPos(XX + 90, YY + 20); cout << B;
	setPos(XX + 92, YY + 20); cout << B;
	setPos(XX + 93, YY + 20); cout << B;
	setPos(XX + 94, YY + 20); cout << B;
	setPos(XX + 96, YY + 20); cout << B;
	setPos(XX + 97, YY + 20); cout << B;
	setPos(XX + 99, YY + 20); cout << B;
	setPos(XX + 101, YY + 20); cout << B;
	setPos(XX + 102, YY + 20); cout << B;
	//setPos(XX + 104, YY + 20); cout << B;



	//========= ROW 21 - only than ======= 
	setPos(XX + 93, YY + 21); cout << B;
	setPos(XX + 94, YY + 21); cout << B;
	setPos(XX + 96, YY + 21); cout << B;
	setPos(XX + 97, YY + 21); cout << B;

	//========= ROW 22  ======= 
	setPos(XX + 93, YY + 22); cout << B;
	setPos(XX + 94, YY + 22); cout << B;
	setPos(XX + 96, YY + 22); cout << B;
	setPos(XX + 97, YY + 22); cout << B;

	//========= ROW 23 ======= 
	setPos(XX + 93, YY + 23); cout << B;
	setPos(XX + 94, YY + 23); cout << B;
	setPos(XX + 96, YY + 23); cout << B;
	setPos(XX + 97, YY + 23); cout << B;

	//========= ROW 24 ======= 
	setPos(XX + 93, YY + 24); cout << B;
	setPos(XX + 94, YY + 24); cout << B;
	setPos(XX + 96, YY + 24); cout << B;
	setPos(XX + 97, YY + 24); cout << B;

	//========= ROW 25 ======= 
	setPos(XX + 93, YY + 25); cout << B;
	setPos(XX + 94, YY + 25); cout << B;
	setPos(XX + 96, YY + 25); cout << B;
	setPos(XX + 97, YY + 25); cout << B;
	//========= ROW 26 ======= 
	setPos(XX + 93, YY + 26); cout << B;
	setPos(XX + 94, YY + 26); cout << B;
	setPos(XX + 96, YY + 26); cout << B;
	setPos(XX + 97, YY + 26); cout << B;

	// ========= ROW 21 mat dat ========
	for (int i = 2; i < 119; i++) {
		setPos(XX + i, YY + 28);
		cout << B;
	}
}

void drawMiniDino(int XX, int YY) {
	const char* A = u8"█ ";
	const char* B = u8"██ ";
	const char* D = u8"▀ ";


	setPos(XX + 68, YY + 11); cout << B;
	setPos(XX + 70, YY + 11); cout << B;
	setPos(XX + 72, YY + 11); cout << B;
	setPos(XX + 74, YY + 11); cout << B;
	setPos(XX + 76, YY + 11); cout << B;


	setPos(XX + 68, YY + 12); cout << B;
	setPos(XX + 70, YY + 12); cout << B;
	setPos(XX + 71, YY + 12); cout << "  ";
	setPos(XX + 72, YY + 12); cout << B;
	setPos(XX + 74, YY + 12); cout << B;
	setPos(XX + 76, YY + 12); cout << B;


	setPos(XX + 68, YY + 13); cout << B;
	setPos(XX + 70, YY + 13); cout << B;
	setPos(XX + 72, YY + 13); cout << B;
	setPos(XX + 74, YY + 13); cout << B;
	setPos(XX + 76, YY + 13); cout << B;


	setPos(XX + 63, YY + 14); cout << B;
	setPos(XX + 68, YY + 14); cout << B;
	setPos(XX + 70, YY + 14); cout << B;
	setPos(XX + 72, YY + 14); cout << B;
	//setPos(XX + 75, YY + 14); cout << A;


	//setPos(XX + 61, YY + 15); cout << B;
	setPos(XX + 63, YY + 15); cout << B;
	setPos(XX + 65, YY + 15); cout << B;
	//setPos(XX + 67, YY + 15); cout << B;
	setPos(XX + 68, YY + 15); cout << B;
	setPos(XX + 70, YY + 15); cout << B;
	setPos(XX + 72, YY + 15); cout << B;
	setPos(XX + 74, YY + 15); cout << B;
	setPos(XX + 75, YY + 15); cout << A;

	setPos(XX + 64, YY + 16); cout << B;
	setPos(XX + 65, YY + 16); cout << B;
	setPos(XX + 67, YY + 16); cout << B;
	setPos(XX + 69, YY + 16); cout << B;
	setPos(XX + 70, YY + 16); cout << B;
	setPos(XX + 72, YY + 16); cout << B;

	setPos(XX + 65, YY + 17); cout << B;
	setPos(XX + 67, YY + 17); cout << B;
	setPos(XX + 69, YY + 17); cout << B;
	setPos(XX + 70, YY + 17); cout << B;
	setPos(XX + 72, YY + 17); cout << A;

	setPos(XX + 66, YY + 18); cout << B;
	setPos(XX + 69, YY + 18); cout << B;

	for (int i = 70; i < 118; i++) {
		setPos(XX - 10 + i, YY + 19);
		cout << D;
	}

}

void drawDino(int XX, int YY) {
	const char* B = u8"██ ";          // khối 2 ô
	const char* K = u8"████████ ";
	/*B[2] = '\0';

	K[8] = '\0';*/


	// ======== ROW 2 ========

	setPos(XX + 9, YY + 2); cout << B;
	setPos(XX + 10, YY + 2); cout << B;
	setPos(XX + 12, YY + 2);  cout << B;
	setPos(XX + 14, YY + 2);  cout << B;
	setPos(XX + 16, YY + 2);  cout << B;
	setPos(XX + 18, YY + 2);  cout << B;
	setPos(XX + 20, YY + 2);  cout << B;
	setPos(XX + 22, YY + 2);  cout << B;
	setPos(XX + 24, YY + 2);  cout << B;
	setPos(XX + 25, YY + 2);  cout << B;

	// ======== ROW 3 ========
	setPos(XX + 8, YY + 3); cout << B;
	setPos(XX + 10, YY + 3); cout << B;

	setPos(XX + 11, YY + 3); cout << "  "; // pixel m?t tr?ng

	setPos(XX + 13, YY + 3);  cout << B;
	setPos(XX + 14, YY + 3);  cout << B;
	setPos(XX + 16, YY + 3);  cout << B;
	setPos(XX + 18, YY + 3);  cout << B;
	setPos(XX + 20, YY + 3);  cout << B;
	setPos(XX + 22, YY + 3);  cout << B;
	setPos(XX + 24, YY + 3);  cout << B;
	setPos(XX + 26, YY + 3);  cout << B;


	// ======== ROW 4 (??nh ??u) ========
	setPos(XX + 8, YY + 4); cout << B;
	setPos(XX + 10, YY + 4); cout << B;
	setPos(XX + 12, YY + 4); cout << B;
	setPos(XX + 14, YY + 4); cout << B;
	setPos(XX + 16, YY + 4); cout << B;
	setPos(XX + 18, YY + 4); cout << B;
	setPos(XX + 20, YY + 4); cout << B;
	setPos(XX + 22, YY + 4); cout << B;
	setPos(XX + 24, YY + 4); cout << B;
	setPos(XX + 26, YY + 4); cout << B;


	// ======== ROW 5 ========
	setPos(XX + 8, YY + 5); cout << B;
	setPos(XX + 10, YY + 5); cout << B;
	setPos(XX + 12, YY + 5); cout << B;
	setPos(XX + 14, YY + 5); cout << B;
	setPos(XX + 16, YY + 5); cout << B;
	setPos(XX + 18, YY + 5); cout << B;
	setPos(XX + 20, YY + 5); cout << B;
	setPos(XX + 22, YY + 5); cout << B;
	setPos(XX + 24, YY + 5); cout << B;
	setPos(XX + 26, YY + 5); cout << B;

	// ======== ROW 6 ========
	setPos(XX + 8, YY + 6); cout << B;
	setPos(XX + 10, YY + 6); cout << B;
	setPos(XX + 12, YY + 6); cout << B;
	setPos(XX + 14, YY + 6); cout << B;
	setPos(XX + 16, YY + 6); cout << B;
	setPos(XX + 18, YY + 6); cout << B;
	setPos(XX + 20, YY + 6); cout << B;
	setPos(XX + 22, YY + 6); cout << B;
	setPos(XX + 24, YY + 6); cout << B;
	setPos(XX + 26, YY + 6); cout << B;

	// ======== ROW 7 ========
	setPos(XX + 8, YY + 7); cout << B;
	setPos(XX + 10, YY + 7); cout << B;
	setPos(XX + 12, YY + 7); cout << B;
	setPos(XX + 14, YY + 7); cout << B;
	setPos(XX + 15, YY + 7); cout << B;
	setPos(XX + 17, YY + 7); cout << B;

	// ======== ROW 8  ========
	setPos(XX + 8, YY + 8); cout << B;
	setPos(XX + 10, YY + 8); cout << B;
	setPos(XX + 12, YY + 8); cout << B;
	setPos(XX + 14, YY + 8); cout << B;
	setPos(XX + 16, YY + 8); cout << B;
	setPos(XX + 18, YY + 8); cout << B;
	setPos(XX + 20, YY + 8); cout << B;
	setPos(XX + 21, YY + 8); cout << B;
	setPos(XX + 23, YY + 8); cout << B;

	// ======== ROW 9  ========
	setPos(XX - 10, YY + 9); cout << B;
	setPos(XX + 6, YY + 9); cout << B;
	setPos(XX + 8, YY + 9); cout << B;
	setPos(XX + 10, YY + 9); cout << B;
	setPos(XX + 12, YY + 9); cout << B;
	setPos(XX + 14, YY + 9); cout << B;
	setPos(XX + 16, YY + 9); cout << B;


	// ======== ROW 10  ========
	setPos(XX - 10, YY + 10); cout << B;
	setPos(XX + 4, YY + 10); cout << B;
	setPos(XX + 6, YY + 10); cout << B;
	setPos(XX + 8, YY + 10); cout << B;
	setPos(XX + 10, YY + 10); cout << B;
	setPos(XX + 12, YY + 10); cout << B;
	setPos(XX + 14, YY + 10); cout << B;
	setPos(XX + 16, YY + 10); cout << B;

	// ======== ROW 11 ========
	setPos(XX - 10, YY + 11); cout << B;
	setPos(XX - 8, YY + 11); cout << B;
	setPos(XX + 2, YY + 11); cout << B;
	setPos(XX + 4, YY + 11); cout << B;
	setPos(XX + 6, YY + 11); cout << B;
	setPos(XX + 8, YY + 11); cout << B;
	setPos(XX + 10, YY + 11); cout << B;
	setPos(XX + 12, YY + 11); cout << B;
	setPos(XX + 14, YY + 11); cout << B;
	setPos(XX + 16, YY + 11); cout << B;
	setPos(XX + 18, YY + 11); cout << B;
	setPos(XX + 20, YY + 11); cout << B;
	setPos(XX + 21, YY + 11); cout << B;

	// ======== ROW 12 ========
	setPos(XX - 10, YY + 12); cout << B;
	setPos(XX - 8, YY + 12); cout << B;
	setPos(XX - 6, YY + 12); cout << B;
	setPos(XX, YY + 12); cout << B;
	setPos(XX + 2, YY + 12); cout << B;
	setPos(XX + 4, YY + 12); cout << B;
	setPos(XX + 6, YY + 12); cout << B;
	setPos(XX + 8, YY + 12); cout << B;
	setPos(XX + 10, YY + 12); cout << B;
	setPos(XX + 12, YY + 12); cout << B;
	setPos(XX + 14, YY + 12); cout << B;
	setPos(XX + 16, YY + 12); cout << B;
	//setPos(XX + 18, YY + 12); cout << B;
	//setPos(XX + 20, YY + 12); cout << B;
	setPos(XX + 21, YY + 12); cout << B;

	// ======== ROW 13 ========
	setPos(XX - 10, YY + 13); cout << B;
	setPos(XX - 8, YY + 13); cout << B;
	setPos(XX - 6, YY + 13); cout << B;
	setPos(XX - 4, YY + 13); cout << B;
	setPos(XX - 2, YY + 13); cout << B;
	setPos(XX - 0, YY + 13); cout << B;
	setPos(XX + 2, YY + 13); cout << B;
	setPos(XX + 4, YY + 13); cout << B;
	setPos(XX + 6, YY + 13); cout << B;
	setPos(XX + 8, YY + 13); cout << B;
	setPos(XX + 10, YY + 13); cout << B;
	setPos(XX + 12, YY + 13); cout << B;
	setPos(XX + 14, YY + 13); cout << B;
	setPos(XX + 16, YY + 13); cout << B;

	// ======== ROW 14 – chân ph?i ========
	setPos(XX - 10, YY + 14); cout << B;
	setPos(XX - 8, YY + 14); cout << B;
	setPos(XX - 6, YY + 14); cout << B;
	setPos(XX - 4, YY + 14); cout << B;
	setPos(XX - 2, YY + 14); cout << B;
	setPos(XX - 0, YY + 14); cout << B;
	setPos(XX + 2, YY + 14); cout << B;
	setPos(XX + 4, YY + 14); cout << B;
	setPos(XX + 6, YY + 14); cout << B;
	setPos(XX + 8, YY + 14); cout << B;
	setPos(XX + 10, YY + 14); cout << B;
	setPos(XX + 12, YY + 14); cout << B;
	setPos(XX + 14, YY + 14); cout << B;
	setPos(XX + 16, YY + 14); cout << B;

	// ======== ROW 15 – chân ph?i dài ========
	setPos(XX - 8, YY + 15); cout << B;
	setPos(XX - 6, YY + 15); cout << B;
	setPos(XX - 4, YY + 15); cout << B;
	setPos(XX - 2, YY + 15); cout << B;
	setPos(XX - 0, YY + 15); cout << B;
	setPos(XX + 2, YY + 15); cout << B;
	setPos(XX + 4, YY + 15); cout << B;
	setPos(XX + 6, YY + 15); cout << B;
	setPos(XX + 8, YY + 15); cout << B;
	setPos(XX + 10, YY + 15); cout << B;
	setPos(XX + 12, YY + 15); cout << B;
	setPos(XX + 14, YY + 15); cout << B;

	// ======== ROW 16 – đuôi ========
	setPos(XX - 6, YY + 16); cout << B;
	setPos(XX - 4, YY + 16); cout << B;
	setPos(XX - 2, YY + 16); cout << B;
	setPos(XX - 0, YY + 16); cout << B;
	setPos(XX + 2, YY + 16); cout << B;
	setPos(XX + 4, YY + 16); cout << B;
	setPos(XX + 6, YY + 16); cout << B;
	setPos(XX + 8, YY + 16); cout << B;
	setPos(XX + 10, YY + 16); cout << B;
	setPos(XX + 12, YY + 16); cout << B;

	// ======== ROW 17 diem cuoi cua than ========
	setPos(XX - 4, YY + 17); cout << B;
	setPos(XX - 2, YY + 17); cout << B;
	setPos(XX - 0, YY + 17); cout << B;
	setPos(XX + 2, YY + 17); cout << B;
	setPos(XX + 4, YY + 17); cout << B;
	setPos(XX + 6, YY + 17); cout << B;
	setPos(XX + 8, YY + 17); cout << B;
	setPos(XX + 10, YY + 17); cout << B;

	// ======== ROW 18 diem cuoi cua than ========
	setPos(XX - 2, YY + 18); cout << B;
	setPos(XX - 0, YY + 18); cout << B;
	setPos(XX + 2, YY + 18); cout << B;
	setPos(XX + 4, YY + 18); cout << B;
	setPos(XX + 6, YY + 18); cout << B;
	setPos(XX + 8, YY + 18); cout << B;


	// ======== ROW 19 2 chan ========
	setPos(XX - 0, YY + 19); cout << B;
	setPos(XX + 6, YY + 19); cout << B;
	setPos(XX - 0, YY + 20); cout << B;
	setPos(XX + 6, YY + 20); cout << B;
}
void drawSTART(int XX, int YY) {
	drawS(XX - 10, YY);
	drawT(XX - 2, YY);
	drawA(XX + 7, YY);
	drawR(XX + 15, YY);
	drawT(XX + 23, YY);
}
void drawSELECT_MODE(int XX, int YY){
	drawS(XX - 22, YY);
	drawE(XX - 14, YY);
	drawL(XX - 6, YY);
	drawE(XX + 2, YY);
	drawC(XX + 10, YY);
	drawT(XX + 18, YY);
	drawM(XX + 33, YY);
	drawO(XX + 44, YY);
	drawD(XX + 53, YY);
	drawE(XX + 61, YY);
}
void drawLEVEL(int XX, int YY) {
	drawL(XX - 18, YY);
	drawE(XX - 10, YY);
	drawV(XX - 2, YY);
	drawE(XX + 8, YY);
	drawL(XX + 16, YY);
}
void drawMinimaDino(int XX, int YY) { 
	const char* A = u8"█ "; // khối 1 ô
	const char* B = u8"██ ";          // khối 2 ô
	const char* C = u8"▄";          // khối nửa ô dưới
	const char* D = u8"▀";          // khối nửa ô trên
	const char* K = u8"████████ "; // khối 8 ô

	// ======== ROW 1 ========

	setPos(XX + 11, YY + 1); cout << C;
	setPos(XX + 12, YY + 1);  cout << C;
	setPos(XX + 13, YY + 1);  cout << C;
	setPos(XX + 14, YY + 1);  cout << C;
	setPos(XX + 15, YY + 1);  cout << C;
	setPos(XX + 16, YY + 1);  cout << C;

	// ======== ROW 2 ========
	setPos(XX + 10, YY + 2); cout << A;
	setPos(XX + 11, YY + 2); cout << B;
	setPos(XX + 13, YY + 2); cout << D;    // vẽ con mắt
	setPos(XX + 14, YY + 2);  cout << B;
	setPos(XX + 16, YY + 2);  cout << B;

	// ======== ROW 3 ========
	setPos(XX + 10, YY + 3); cout << K;

	// ======== ROW 4 ========
	setPos(XX + 10, YY + 4); cout << B;
	setPos(XX + 12, YY + 4); cout << B;
	setPos(XX + 14, YY + 4); cout << A;
	setPos(XX + 15, YY + 4); cout << C;
	setPos(XX + 16, YY + 4); cout << C;

	// ======== ROW 5 ========
	setPos(XX + 1, YY + 5); cout << C;
	setPos(XX + 9, YY + 5); cout << C;
	setPos(XX + 10, YY + 5); cout << B;
	setPos(XX + 12, YY + 5); cout << B;

	// ======== ROW 6 ========
	setPos(XX + 1, YY + 6); cout << A;
	setPos(XX + 2, YY + 6); cout << C;
	setPos(XX + 6, YY + 6); cout << C;
	setPos(XX + 7, YY + 6); cout << B;
	setPos(XX + 9, YY + 6); cout << B;
	setPos(XX + 11, YY + 6); cout << B;
	setPos(XX + 13, YY + 6); cout << A;
	setPos(XX + 14, YY + 6); cout << C;
	setPos(XX + 15, YY + 6); cout << C;

	// ======== ROW 7  ========
	setPos(XX + 1, YY + 7); cout << K;
	setPos(XX + 9, YY + 7); cout << B;
	setPos(XX + 11, YY + 7); cout << B;
	setPos(XX + 13, YY + 7); cout << A;
	setPos(XX + 15, YY + 7); cout << D;  // vẽ tay

	// ======== ROW 8  ========
	setPos(XX + 2, YY + 8); cout << K;
	setPos(XX + 10, YY + 8); cout << B;
	setPos(XX + 12, YY + 8); cout << A;

	// ======== ROW 9  ========
	setPos(XX + 3, YY + 9); cout << K;
	setPos(XX + 11, YY + 9); cout << A;

	// ======== ROW 10 ========
	setPos(XX + 4, YY + 10); cout << A;
	setPos(XX + 5, YY + 10); cout << D;
	setPos(XX + 9, YY + 10); cout << A;
	setPos(XX + 10, YY + 10); cout << D;

	// ======== ROW 11 ========
	setPos(XX + 4, YY + 11); cout << A;
	setPos(XX + 5, YY + 11); cout << C;
	setPos(XX + 9, YY + 11); cout << A;
	setPos(XX + 10, YY + 11); cout << C;
}
void drawMaximaCactus(int XX, int YY) {
	const char* A = u8"█ "; // khối 1 ô
	const char* B = u8"██ ";  // khối 2 ô
	const char* C = u8"▄";  // khối nửa ô dưới
	const char* D = u8"▀";   // khối nửa ô trên
	const char* H = u8"█████ ";   //khối 5 ô
	const char* K = u8"████████ "; // khối 8 ô
	// ======== ROW 1 ========
	setPos(XX + 96, YY + 1); cout << C;
	setPos(XX + 97, YY + 1); cout << C;
	setPos(XX + 98, YY + 1); cout << C;

	// ======== ROW 2 ========
	setPos(XX + 95, YY + 2); cout << H;
	// ======== ROW 3 ========
	setPos(XX + 95, YY + 3); cout << H;
	setPos(XX + 102, YY + 3); cout << C;
	// ======== ROW 4 ========
	setPos(XX + 92, YY + 4); cout << C;
	setPos(XX + 95, YY + 4); cout << H;
	setPos(XX + 101, YY + 4); cout << B;
	setPos(XX + 103, YY + 4); cout << A;
	// ======== ROW 5 ========
	setPos(XX + 91, YY + 5); cout << B;
	setPos(XX + 93, YY + 5); cout << A;
	setPos(XX + 95, YY + 5); cout << H;
	setPos(XX + 101, YY + 5); cout << B;
	setPos(XX + 103, YY + 5); cout << A;
	// ======== ROW 6 ========
	setPos(XX + 91, YY + 6); cout << B;
	setPos(XX + 93, YY + 6); cout << A;
	setPos(XX + 95, YY + 6); cout << K;
	setPos(XX + 103, YY + 6); cout << D;
	// ======== ROW 7 ========
	setPos(XX + 91, YY + 7); cout << D;
	setPos(XX + 92, YY + 7); cout << K;
	setPos(XX + 100, YY + 7); cout << D;
	setPos(XX + 101, YY + 7); cout << D;
	// ======== ROW 8 ========
	setPos(XX + 93, YY + 8); cout << D;
	setPos(XX + 94, YY + 8); cout << D;
	setPos(XX + 95, YY + 8); cout << H;
	// ======== ROW 9 ========
	setPos(XX + 95, YY + 9); cout << H;
	// ======== ROW 10 ========
	setPos(XX + 95, YY + 10); cout << H;
}
void drawMinimaCactus(int XX, int YY) {    
	const char* A = u8"█ "; // khối 1 ô
	const char* B = u8"██ ";  // khối 2 ô
	const char* C = u8"▄"; // khối nửa ô dưới
	const char* D = u8"▀"; // khối nửa ô trên
	const char* P = u8"███"; // khối 3 ô
	//dòng 1
	setPos(XX + 4, YY + 1); cout << C;
	//dòng 2
	setPos(XX + 3, YY + 2); cout << P;
	setPos(XX + 8, YY + 2); cout << C;
	//dòng 3
	setPos(XX + 1, YY + 3); cout << C;
	setPos(XX + 3, YY + 3); cout << P;
	setPos(XX + 7, YY + 3); cout << B;
	//dòng 4
	setPos(XX + 1, YY + 4); cout << P;
	setPos(XX + 4, YY + 4); cout << P;
	setPos(XX + 7, YY + 4); cout << A;
	setPos(XX + 8, YY + 4); cout << D;
	//dòng 5
	setPos(XX + 2, YY + 5); cout << D;
	setPos(XX + 3, YY + 5); cout << P;
	//dòng 6
	setPos(XX + 3, YY + 6); cout << P;
}
void drawDot(int XX, int YY, int co_txt=0) {
	setPos(XX, YY + 4);
	setColor(co_txt, 0); cout << "  ";
	setColor(15, co_txt); cout << u8"╗";
	setPos(XX, YY + 5);
	cout << u8"╚" << u8"═" << u8"╝";
}
void drawLOADING(int XX, int YY) {
	drawL(XX + 1, YY);
	drawO(XX + 9, YY, 0);
	drawA(XX + 18, YY);
	drawD(XX + 26, YY);
	drawI(XX + 34, YY);
	drawN(XX + 37, YY);
	drawG(XX + 47, YY);
	drawDot(XX + 56, YY, 0);
	drawDot(XX + 59, YY, 0);
	drawDot(XX + 62, YY, 0);
}
void drawSpino(int XX, int YY) {
	const char* A = u8"█ "; // khối 1 ô
	const char* B = u8"██ ";          // khối 2 ô
	const char* C = u8"▄";          // khối nửa ô dưới
	const char* D = u8"▀";          // khối nửa ô trên
	const char* K = u8"████████ "; // khối 8 ô
	// ========= ROW 1 ========
	setPos(XX + 37, YY + 1); cout << C;
	// ========= ROW 2 ========
	setPos(XX + 32, YY + 2); cout << C;
	setPos(XX + 33, YY + 2); cout << A;
	setPos(XX + 34, YY + 2); cout << C;
	setPos(XX + 36, YY + 2); cout << B;
	setPos(XX + 38, YY + 2); cout << A;
	setPos(XX + 42, YY + 2); cout << C;
	// ========= ROW 3 ========
	setPos(XX + 30, YY + 3); cout << C;
	setPos(XX + 32, YY + 3); cout << D;
	setPos(XX + 33, YY + 3); cout << B;
	setPos(XX + 36, YY + 3); cout << B;
	setPos(XX + 38, YY + 3); cout << A;
	setPos(XX + 40, YY + 3); cout << C;
	setPos(XX + 41, YY + 3); cout << B;
	setPos(XX + 43, YY + 3); cout << C;
	// ========= ROW 4 ========
	setPos(XX + 29, YY + 4); cout << D;
	setPos(XX + 30, YY + 4); cout << K;
	setPos(XX + 38, YY + 4); cout << B;
	setPos(XX + 40, YY + 4); cout << B;
	setPos(XX + 42, YY + 4); cout << A;
	setPos(XX + 43, YY + 4); cout << C;
	setPos(XX + 44, YY + 4); cout << C;
	setPos(XX + 45, YY + 4); cout << A;
	setPos(XX + 46, YY + 4); cout << C;
	setPos(XX + 47, YY + 4); cout << C;
	// ========= ROW 5 ========
	setPos(XX + 25, YY + 5); cout << C;
	setPos(XX + 28, YY + 5); cout << C;
	setPos(XX + 29, YY + 5); cout << K;
	setPos(XX + 37, YY + 5); cout << K;
	setPos(XX + 45, YY + 5); cout << A;
	setPos(XX + 46, YY + 5); cout << C;
	setPos(XX + 47, YY + 5); cout << B;
	// ========= ROW 6 ========
	setPos(XX + 25, YY + 6); cout << D;
	setPos(XX + 26, YY + 6); cout << A;
	setPos(XX + 27, YY + 6); cout << B;
	setPos(XX + 29, YY + 6); cout << B;
	setPos(XX + 31, YY + 6); cout << D;
	setPos(XX + 32, YY + 6); cout << K;
	setPos(XX + 40, YY + 6); cout << B;
	setPos(XX + 42, YY + 6); cout << B;
	setPos(XX + 44, YY + 6); cout << A;
	setPos(XX + 45, YY + 6); cout << D;
	setPos(XX + 46, YY + 6); cout << D;
	setPos(XX + 47, YY + 6); cout << D;
	setPos(XX + 48, YY + 6); cout << D;
	// ========= ROW 7 ========
	setPos(XX + 32, YY + 7); cout << B;
	setPos(XX + 34, YY + 7); cout << C;
	setPos(XX + 35, YY + 7); cout << B;
	setPos(XX + 37, YY + 7); cout << C;
	setPos(XX + 40, YY + 7); cout << B;
	setPos(XX + 42, YY + 7); cout << C;
	setPos(XX + 43, YY + 7); cout << A;
	setPos(XX + 44, YY + 7); cout << C;
}
void setGround(int i) {    //ký tự ngẫu nhiên cho mặt đất
	int v = rand() % (12 - 1 + 1) + 1;
	switch (v) {
	case 1:
		ground[1][i] = '_';
		ground[2][i] = ' ';
		break;
	case 2:
		ground[1][i] = '-';
		ground[2][i] = ' ';
		break;
	case 3:
		ground[1][i] = '=';
		ground[2][i] = ' ';
		break;
	case 4:
		ground[1][i] = '`';
		ground[2][i] = ' ';
		break;
	case 5:
		ground[1][i] = ' ';
		ground[2][i] = '-';
		break;
	case 6:
		ground[1][i] = ' ';
		ground[2][i] = '`';
		break;
	default:
		ground[1][i] = ' ';
		ground[2][i] = ' ';
		break;
	}
}
void drawGround() {   //khởi tạo mặt đất
	for (int i = 0; i < num_ground; i++) {
		ground[0][i] = '_';
		setGround(i);
	}
	ground[0][num_ground] = '\0';
	ground[1][num_ground] = '\0';
	ground[2][num_ground] = '\0';
}
void renderGround(int XX, int YY) {  //vẽ mặt đất
	for (int i=0;i<3;i++){
		setPos(XX, YY + i);
		cout << ground[i];
	}
}
void drawCloud(int XX, int YY) {
	const char* A = u8"█ "; // khối 1 ô
	const char* B = u8"██ ";          // khối 2 ô
	const char* C = u8"▄";          // khối nửa ô dưới
	const char* D = u8"▀";          // khối nửa ô trên
	const char* F = u8"▄▄▄▄▄▄▄▄"; // khối 8 nửa ô dưới
	// ======== ROW 1 ========
	setPos(XX + 14, YY + 1); cout << C;
	setPos(XX + 15, YY + 1); cout << D;
	setPos(XX + 16, YY + 1); cout << D;
	setPos(XX + 17, YY + 1); cout << D;
	setPos(XX + 18, YY + 1); cout << D;
	setPos(XX + 19, YY + 1); cout << D;
	setPos(XX + 20, YY + 1); cout << C;
	// ======== ROW 2 ========
	setPos(XX + 12, YY + 2); cout << A;
	setPos(XX + 13, YY + 2); cout << D;
	setPos(XX + 14, YY + 2); cout << D;
	setPos(XX + 21, YY + 2); cout << A;
	setPos(XX + 22, YY + 2); cout << C;
	setPos(XX + 23, YY + 2); cout << C;
	setPos(XX + 24, YY + 2); cout << C;
	// ======== ROW 3 ========
	setPos(XX + 9, YY + 3); cout << C;
	setPos(XX + 10, YY + 3); cout << C;
	setPos(XX + 11, YY + 3); cout << A;
	setPos(XX + 12, YY + 3); cout << D;
	setPos(XX + 21, YY + 3); cout << A;
	setPos(XX + 25, YY + 3); cout << A;
	// ======== ROW 4 ========
	setPos(XX + 5, YY + 4); cout << C;
	setPos(XX + 6, YY + 4); cout << D;
	setPos(XX + 7, YY + 4); cout << D;
	setPos(XX + 8, YY + 4); cout << D;
	setPos(XX + 20, YY + 4); cout << D;
	setPos(XX + 26, YY + 4); cout << D;
	setPos(XX + 27, YY + 4); cout << D;
	setPos(XX + 28, YY + 4); cout << D;
	setPos(XX + 29, YY + 4); cout << A;
	setPos(XX + 30, YY + 4); cout << C;
	setPos(XX + 31, YY + 4); cout << C;
	// ======== ROW 5 ========
	setPos(XX + 4, YY + 5); cout << A;
	setPos(XX + 31, YY + 5); cout << A;
	// ======== ROW 6 ========
	setPos(XX + 1, YY + 6); cout << C;
	setPos(XX + 2, YY + 6); cout << A;
	setPos(XX + 3, YY + 6); cout << D;
	setPos(XX + 4, YY + 6); cout << D;
	setPos(XX + 9, YY + 6); cout << D;
	setPos(XX + 10, YY + 6); cout << F;
	setPos(XX + 18, YY + 6); cout << F;
	setPos(XX + 26, YY + 6); cout << C;
	setPos(XX + 27, YY + 6); cout << C;
	setPos(XX + 28, YY + 6); cout << C;
	setPos(XX + 29, YY + 6); cout << C;
	setPos(XX + 30, YY + 6); cout << C;
	setPos(XX + 31, YY + 6); cout << C;
	setPos(XX + 32, YY + 6); cout << A;
}
void drawMiniCloud(int XX, int YY) {
	const char* A = u8"█ "; // khối 1 ô
	const char* B = u8"██ ";          // khối 2 ô
	const char* C = u8"▄";          // khối nửa ô dưới
	const char* D = u8"▀";          // khối nửa ô trên
	const char* F = u8"▄▄▄▄▄▄▄▄"; // khối 8 nửa ô dưới
	//dòng 1
	setPos(XX + 6, YY + 1); cout << C;
	setPos(XX + 7, YY + 1); cout << D;
	setPos(XX + 8, YY + 1); cout << D;
	setPos(XX + 9, YY + 1); cout << D;
	setPos(XX + 10, YY + 1); cout << C;
	//dòng 2
	setPos(XX + 3, YY + 2); cout << C;
	setPos(XX + 4, YY + 2); cout << C;
	setPos(XX + 5, YY + 2); cout << A;
	setPos(XX + 11, YY + 2); cout << A;
	//dòng 3
	setPos(XX + 2, YY + 3); cout << A;
	setPos(XX + 12, YY + 3); cout << D;
	setPos(XX + 13, YY + 3); cout << D;
	setPos(XX + 14, YY + 3); cout << D;
	setPos(XX + 15, YY + 3); cout << C;
	//dòng 4
	setPos(XX + 1, YY + 4); cout << A;
	setPos(XX + 2, YY + 4); cout << C;
	setPos(XX + 3, YY + 4); cout << C;
	setPos(XX + 4, YY + 4); cout << C;
	setPos(XX + 7, YY + 4); cout << F;
	setPos(XX + 15, YY + 4); cout << C;
	setPos(XX + 16, YY + 4); cout << A;
}
void drawTricelatop(int XX, int YY) {   //khủng long 3 sừng
	const char* A = u8"█ "; // khối 1 ô
	const char* B = u8"██ ";          // khối 2 ô
	const char* C = u8"▄";          // khối nửa ô dưới
	const char* D = u8"▀";          // khối nửa ô trên
	const char* K = u8"████████ "; // khối 8 ô
	//dòng 1
	setPos(XX + 4, YY + 1); cout << C;
	setPos(XX + 9, YY + 1); cout << C;
	setPos(XX + 10, YY + 1); cout << A;
	setPos(XX + 11, YY + 1); cout << C;
	//dòng 2
	setPos(XX + 2, YY + 2); cout << C;
	setPos(XX + 5, YY + 2); cout << A;
	setPos(XX + 6, YY + 2); cout << C;
	setPos(XX + 8, YY + 2); cout << B;
	setPos(XX + 10, YY + 2); cout << B;
	setPos(XX + 12, YY + 2); cout << A;
	//dòng 3
	setPos(XX + 2, YY + 3); cout << B;
	setPos(XX + 4, YY + 3); cout << C;
	setPos(XX + 5, YY + 3); cout << A;
	setPos(XX + 6, YY + 3); cout << D;
	setPos(XX + 7, YY + 3); cout << B;
	setPos(XX + 9, YY + 3); cout << B;
	setPos(XX + 11, YY + 3); cout << B;
	setPos(XX + 14, YY + 3); cout << B;
	setPos(XX + 16, YY + 3); cout << B;
	setPos(XX + 18, YY + 3); cout << A;
	//dòng 4
	setPos(XX + 1, YY + 4); cout << K;
	setPos(XX + 9, YY + 4); cout << B;
	setPos(XX + 11, YY + 4); cout << B;
	setPos(XX + 14, YY + 4); cout << B;
	setPos(XX + 16, YY + 4); cout << B;
	setPos(XX + 18, YY + 4); cout << B;
	setPos(XX + 20, YY + 4); cout << A;
	//dòng 5
	setPos(XX + 1, YY + 5); cout << K;
	setPos(XX + 9, YY + 5); cout << B;
	setPos(XX + 11, YY + 5); cout << A;
	setPos(XX + 13, YY + 5); cout << K;
	setPos(XX + 21, YY + 5); cout << B;
	//dòng 6
	setPos(XX + 1, YY + 6); cout << A;
	setPos(XX + 2, YY + 6); cout << D;
	setPos(XX + 3, YY + 6); cout << D;
	setPos(XX + 4, YY + 6); cout << D;
	setPos(XX + 5, YY + 6); cout << D;
	setPos(XX + 6, YY + 6); cout << B;
	setPos(XX + 8, YY + 6); cout << B;
	setPos(XX + 10, YY + 6); cout << A;
	setPos(XX + 11, YY + 6); cout << C;
	setPos(XX + 12, YY + 6); cout << K;
	setPos(XX + 20, YY + 6); cout << B;
	setPos(XX + 22, YY + 6); cout << B;
	setPos(XX + 24, YY + 6); cout << A;
	//dòng 7
	setPos(XX + 3, YY + 7); cout << D;
	setPos(XX + 4, YY + 7); cout << D;
	setPos(XX + 5, YY + 7); cout << D;
	setPos(XX + 6, YY + 7); cout << D;
	setPos(XX + 7, YY + 7); cout << D;
	setPos(XX + 8, YY + 7); cout << D;
	setPos(XX + 9, YY + 7); cout << K;
	setPos(XX + 17, YY + 7); cout << K;
	setPos(XX + 25, YY + 7); cout << B;
	setPos(XX + 27, YY + 7); cout << C;
	setPos(XX + 28, YY + 7); cout << C;
	//dòng 8
	setPos(XX + 10, YY + 8); cout << B;
	setPos(XX + 12, YY + 8); cout << B;
	setPos(XX + 14, YY + 8); cout << D;
	setPos(XX + 15, YY + 8); cout << D;
	setPos(XX + 16, YY + 8); cout << D;
	setPos(XX + 17, YY + 8); cout << D;
	setPos(XX + 18, YY + 8); cout << B;
	setPos(XX + 20, YY + 8); cout << D;
	setPos(XX + 21, YY + 8); cout << D;
	setPos(XX + 22, YY + 8); cout << B;
	//dòng 9
	setPos(XX + 9, YY + 9); cout << C;
	setPos(XX + 10, YY + 9); cout << A;
	setPos(XX + 11, YY + 9); cout << C;
	setPos(XX + 12, YY + 9); cout << B;
	setPos(XX + 17, YY + 9); cout << C;
	setPos(XX + 18, YY + 9); cout << B;
	setPos(XX + 18, YY + 9); cout << B;
	setPos(XX + 21, YY + 9); cout << C;
	setPos(XX + 22, YY + 9); cout << B;
	for (int i = -1; i <= 35; i++) {
		setPos(XX + i, YY + 10); cout << D;
	}
}