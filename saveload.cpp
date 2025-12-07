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
		cerr << "Error creating file " << fullPath << endl;
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

	cout << "Game saved successfully to " << fullPath << endl;
	return true;
}

bool loadGame(const std::string& filename, char board[][15], char& currentPlayer, int& score_X, int& score_O)
{
	// when loading, add path "save/" to filename
	string fullPath = "save/" + filename;

	ifstream inFile(fullPath.c_str());
	if (!inFile) {
		cerr << "file not found" << fullPath << endl;
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
	system("cls");
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
bool customInput(string& result) {
	char ch;
	result = ""; 
	int index = 0; // positions in the string

	//save starting cursor position
	COORD startPos = getCursorPos();

	while (true) {
		ch = _getch(); // get character without echoing

		// escape key to cancel 
		if (ch == 27) {
			return false; 
		}

		// enter key to finish input
		else if (ch == 13) {
			return true;
		}

		// 3. backspace key to delete
		else if (ch == 8) {
			if (index > 0 && result.length() > 0) {
				// delete character before index
				result.erase(index - 1, 1);
				index--;

				// update display
				// step a: clear and reprint
				setPos(startPos.X, startPos.Y);
				cout << result << " "; // print extra space to clear last char

				// step b: reposition cursor
				setPos(startPos.X + index, startPos.Y);
			}
		}

		// arrow keys for left/right movement
		// and other special keys
		else if (ch == -32 || ch == 0 || ch == 224) {
			ch = _getch(); 

			switch (ch) {
			case 75: // arrow left
				if (index > 0) {
					index--;
					setPos(startPos.X + index, startPos.Y);
				}
				break;
			case 77: // arrow right
				if (index < result.length()) {
					index++;
					setPos(startPos.X + index, startPos.Y);
				}
				break;
			}
		}

		// printable characters
		else if (isprint(ch)) {
			// insert character at current index
			result.insert(index, 1, ch);
			index++;

			// print updated string
			setPos(startPos.X, startPos.Y);
			cout << result;

			// move cursor back to correct position
			setPos(startPos.X + index, startPos.Y);
		}
	}
}
bool getfilename(std::string& filename)
{
	setPos(22, (ConsoleHeight-3) / 2 + 1);
	char ch;
	filename.clear();
	return customInput(filename);
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
	if(getfilename(filename) == 0)
		return 0;
	while (checkFileExists(filename) == false)
	{
		setPos((ConsoleWidth - 20) / 2, (ConsoleHeight) / 2 + 2);
		cout << "File not found. Try again:          ";
		setPos(22, (ConsoleHeight - 3) / 2 + 1);
		cout << "                                                                                       ";
		if(getfilename(filename) == 0)
			return 0;
	}
	return 1;
}
