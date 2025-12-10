#include "Library.h"

using namespace std;

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

void drawSETTING(int XX, int YY) {
	//drawS(XX, YY);
	drawE(XX + 5, YY);
	drawT(XX + 13, YY);
	drawT(XX + 22, YY);
	drawI(XX + 31, YY);
	drawN(XX + 34, YY);
	drawG(XX + 44, YY);
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



	// ======== ROW 16 – ?uôi ========
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


	// ========= ROW 21 mat dat ========
	/*for (int i = 0; i < 120; i++) {
		setPos(XX - 10 + i, YY + 21);
		cout << B;
	}*/

}