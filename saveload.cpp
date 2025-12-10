#include"Library.h"

using namespace std;

bool saveGame()
{
	//create directory "save" if not exist
	_mkdir("save");

	// add path "save/" to filename
	string fullPath = "save/" + filename;

	ofstream outFile(fullPath.c_str()); // .c_str() to convert string to const char*
	setPos((ConsoleWidth) / 2-20, (ConsoleHeight) / 2 + 3);

	if (!outFile) {
		cerr << "Error creating file " << fullPath << endl;
		return 0;
	}

	for (int i = 0; i <N; ++i) {
		for (int j = 0; j < N; ++j) {
			outFile << board[i][j];
		}
		outFile << endl;
	}
	outFile << currentPlayer << endl;
	outFile << score_X << " " << score_O << endl;
	outFile << name1 << endl;
	outFile << name2 << endl;
	outFile << difficulty << endl;
	outFile.close();
	cout << "Game saved successfully to " << fullPath << endl;
	return true;
}

bool loadGame()
{
	// when loading, add path "save/" to filename
	string fullPath = "save/" + filename;

	ifstream inFile(fullPath.c_str());
	if (!inFile) {
		cerr << "file not found" << fullPath << endl;
		return false;
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			inFile >> board[i][j];
		}
	}
	inFile >> currentPlayer;
	inFile >> score_X >> score_O;
	inFile.ignore(); // ignore the newline character after score_O
	std::getline(inFile, name1);
	std::getline(inFile, name2);
	inFile >> difficulty;
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

bool checkFileExists(std::string& filename)
{
	string fullPath = "save/" + filename;
	ifstream inFile(fullPath.c_str());
	return inFile.good();
}
bool customInput(string& result) {
	ShowConsoleCursor(true);
	char ch;
	result = ""; 
	int index = 0; // positions in the string

	//save starting cursor position
	COORD startPos = getCursorPos();

	while (true) {
		ch = _getch(); // get character without echoing
		playMoveSound();
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
	filename.clear();
	return customInput(filename);
}

void loadproductfile()
{
	bool loadSuccess = loadGame();
	if (loadSuccess)
	{
		// Redraw the loaded board
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (board[i][j] == '-')continue;
				int row, col;
				getxy(row, col, i, j);
				setPos(row, col);
				cout << board[i][j];
				if(board[i][j]=='X')
					count_X++;
				else if(board[i][j]=='O')
					count_O++;
			}
		}
	}
}

bool loadactive()
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

void loadGameScreen()
{
	// load game
	std::string load_filename;
	//loadactive(load_filename, board, default_player, score_X, score_O);
	if (loadactive())
	{
		setPos((ConsoleWidth) / 2 - 20, (ConsoleHeight) / 2 + 2);
		cout << "                                                   ";
		setPos((ConsoleWidth) / 2 - 20, (ConsoleHeight) / 2 + 3);
		cout << "Game loaded successfully! Returning to game...";
		Sleep(2000);
		if(difficulty==4)
			GamePlay(1);
		else
			AiGamePlay(1);
	}
	else
	{
		setPos((ConsoleWidth) / 2 - 20, (ConsoleHeight) / 2 + 2);
		cout << "Failed to load game. Returning to current game...";
		Sleep(2000);
		if(difficulty==4)
			GamePlay(3);
		else
			AiGamePlay(3);
	}
}
void loadGameMenu()
{
	// load game
	std::string load_filename;
	//loadactive(load_filename, board, default_player, score_X, score_O);
	if (loadactive())
	{
		setPos((ConsoleWidth) / 2 - 20, (ConsoleHeight) / 2 + 2);
		cout << "                                                   ";
		setPos((ConsoleWidth) / 2 - 20, (ConsoleHeight) / 2 + 3);
		cout << "Game loaded successfully! Returning to game...";
		Sleep(2000);
		if (difficulty == 4)
			GamePlay(1);
		else
			AiGamePlay(1);
	}
}

void saveGameScreen()
{
	// save game
	std::string save_filename;
	drawSaveLoadScreen(ConsoleWidth, ConsoleHeight);
	//getfilename(save_filename);
	if (getfilename(save_filename) == 0)
	{
		setPos((ConsoleWidth) / 2 - 20, (ConsoleHeight) / 2 + 5);
		cout << "Save cancelled. Returning to game...";
		Sleep(2000);
		GamePlay(3);
	}
	saveGame();
	setPos((ConsoleWidth) / 2 - 20, (ConsoleHeight) / 2 + 5);
	cout << "Game saved successfully! Returning to menu...";
	Sleep(2000);
	//GamePlay(currentPlayer, name1, name2, filename, 3);
	if(difficulty==4)
		GamePlay(3);
	else
		AiGamePlay(3);
}