#include"Library.h"

using namespace std;

bool saveGame(const std::string& filename, char board[][15], char currentPlayer, int score_X, int score_O)
{
	//create directory "save" if not exist
	_mkdir("save");

	// add path "save/" to filename
	string fullPath = "save/" + filename;

	ofstream outFile(fullPath.c_str()); // .c_str() to convert string to const char*
	if (!outFile) {
		cerr << "Loi: Khong the tao file tai " << fullPath << endl;
		return 0;
	}

	for (int i = 0; i < 15; ++i) {
		for (int j = 0; j < 15; ++j) {
			outFile << board[i][j];
		}
		outFile << endl;
	}
	outFile << currentPlayer << endl;
	outFile << score_X << " " << score_O << endl;
	outFile.close();

	cout << "Da luu game tai: " << fullPath << endl;
	return true;
}

bool loadGame(const std::string& filename, char board[][15], char& currentPlayer, int& score_X, int& score_O)
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
	inFile >> score_X >> score_O;
	inFile.close();
	return true;
}

void drawSaveLoadScreen(int Width, int Height)
{
	setPos((ConsoleWidth - 20) / 2, (ConsoleHeight) / 2 - 2);
	cout << "Enter the filename to load/save ";
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

bool getfilename(std::string& filename)
{
	setPos((ConsoleWidth - 20) / 2 + 2, (ConsoleHeight) / 2 + 1);
	char ch;
	filename.clear();
	while (true)
	{
		ch = _getch();
		if (ch == 13) // Enter key
			break;
		else if (ch == 8) // Backspace key
		{
			if (!filename.empty())
			{
				filename.pop_back();
				setPos((ConsoleWidth - 20) / 2 + 2 + filename.length(), (ConsoleHeight) / 2 + 1);
				cout << " ";
				setPos((ConsoleWidth - 20) / 2 + 2 + filename.length(), (ConsoleHeight) / 2 + 1);
			}
		}
		else if (isprint(ch) && filename.length() < 18) // Printable characters
		{
			filename += ch;
			cout << ch;
		}else if(ch==27) // ESC key to cancel
		{
			return 0;
		}
	}
	return 1;
}

void loadproductfile(std::string& filename, char board[][15], char& currentPlayer, int score_X, int score_O)
{
	bool loadSuccess = loadGame(filename, board, currentPlayer, score_X, score_O);
	if (loadSuccess)
	{
		// Redraw the loaded board
		for (int i = 1; i <= BOARD_SIZE; i++)
		{
			for (int j = 1; j <= BOARD_SIZE; j++)
			{
				if (board[i][j] != ' ')
				{
					int row, col;
					getij(row, col, Xi + (j - 1) * CellWidth + CellWidth / 2 + 1, Yi + (i - 1) * CellHeight + CellHeight / 2 + 1);
					MakeMove(board[i][j], row, col);
				}
			}
		}
	}
}

bool loadactive(std::string& filename, char board[][15], char& currentPlayer, int score_X, int score_O)
{
	drawSaveLoadScreen(ConsoleWidth, ConsoleHeight);
	//getfilename(filename);
	if(getfilename(filename) == 0)
		return 0;
	while (checkFileExists(filename) == false)
	{
		setPos((ConsoleWidth - 20) / 2, (ConsoleHeight) / 2 + 2);
		cout << "File not found. Try again:          ";
		setPos((ConsoleWidth - 20) / 2, (ConsoleHeight) / 2 + 3);
		cout << "                              ";
		setPos((ConsoleWidth - 20) / 2 + 2, (ConsoleHeight) / 2 + 1);
		cin >> filename;
	}
	return 1;
}