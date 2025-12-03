#include"Library.h"

using namespace std;

void saveGame(const std::string& filename, char board[][15], char currentPlayer, int timeMinutes, int timeSeconds)
{
	//create directory "save" if not exist
	_mkdir("save");

	// add path "save/" to filename
	string fullPath = "save/" + filename;

	ofstream outFile(fullPath.c_str()); // .c_str() to convert string to const char*
	if (!outFile) {
		cerr << "Loi: Khong the tao file tai " << fullPath << endl;
		return;
	}

	for (int i = 0; i < 15; ++i) {
		for (int j = 0; j < 15; ++j) {
			outFile << board[i][j];
		}
		outFile << endl;
	}
	outFile << currentPlayer << endl;
	outFile << timeMinutes << " " << timeSeconds << endl;
	outFile.close();

	cout << "Da luu game tai: " << fullPath << endl;
}

bool loadGame(const std::string& filename, char board[][15], char& currentPlayer, int& timeMinutes, int& timeSeconds)
{
	// when loading, add path "save/" to filename
	string fullPath = "save/" + filename;

	ifstream inFile(fullPath.c_str());
	if (!inFile) {
		cerr << "Khong tim thay file save: " << fullPath << endl;
		return false;
	}

	for (int i = 0; i < 15; ++i) {
		for (int j = 0; j < 15; ++j) {
			inFile >> board[i][j];
		}
	}
	inFile >> currentPlayer;
	inFile >> timeMinutes >> timeSeconds;
	inFile.close();
	return true;
}

void drawSaveLoadScreen(int Width, int Height)
{
	setColor(backgroundcolor, fontcolor);
	int boxWidth = Width - 20;
	int boxHeight = 3;
	int boxX = (ConsoleWidth - boxWidth) / 2;
	int boxY = (ConsoleHeight - boxHeight) / 2;
	drawBox(boxX, boxY, boxWidth, boxHeight, "");
	setPos(boxX + 2, boxY + 1);
}

bool checkFileExists(const std::string& filename)
{
	string fullPath = "save/" + filename;
	ifstream inFile(fullPath.c_str());
	return inFile.good();
}