#include"Library.h"

using namespace std;

bool saveGame()
{
	//create directory "save" if not exist
	_mkdir("save");

	// add path "save/" to filename
	string fullPath = "save/" + filename+".txt";

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
	string fullPath = "save/" + filename + ".txt";

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
	//setPos((ConsoleWidth - 20) / 2, (ConsoleHeight) / 2 - 2);
	setPos((ConsoleWidth - 20) / 2 - 10, (ConsoleHeight) / 2 - 4);
	cout << "Enter filename (without .txt extension):";
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
// --- HÀM PHỤ TRỢ: Chuyển wstring (Unicode) sang string (UTF-8) ---
std::string WStringToString(const std::wstring & wstr)
{
	if (wstr.empty()) return std::string();
	int size_needed = WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), NULL, 0, NULL, NULL);
	std::string strTo(size_needed, 0);
	WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), &strTo[0], size_needed, NULL, NULL);
	return strTo;
}

// --- HÀM CUSTOM INPUT (Hỗ trợ tiếng Việt) ---
bool customInput(string& result) {
	ShowConsoleCursor(true);

	wstring wResult = L"";
	wint_t ch;
	int index = 0;

	COORD startPos = getCursorPos();

	while (true) {
		ch = _getwch();

		// 1. Xử lý phím chức năng (Mũi tên, Home, End...)
		if (ch == 0 || (ch == 0xE0 && _kbhit())) {
			ch = _getwch(); // Đọc mã phím thực sự phía sau
			playMoveSound();

			switch (ch) {
			case 75: // Left
				if (index > 0) {
					index--;
					setPos(startPos.X + index, startPos.Y);
				}
				break;
			case 77: // Right
				if (index < wResult.length()) {
					index++;
					setPos(startPos.X + index, startPos.Y);
				}
				break;
			}
		}
		// 2. Xử lý ESC và ENTER
		else if (ch == 27) { // ESC
			result = "";
			return false;
		}
		else if (ch == 13) { // Enter
			playClickSound();
			result = WStringToString(wResult);
			return true;
		}
		// 3. Xử lý Backspace
		else if (ch == 8) {
			if (index > 0 && wResult.length() > 0) {
				// Không cần play sound ở đây vì Unikey tự gửi backspace rất nhanh, 
				// nghe tiếng sẽ bị rè.

				wResult.erase(index - 1, 1);
				index--;

				// Vẽ lại chuỗi
				setPos(startPos.X, startPos.Y);
				// In chuỗi mới + khoảng trắng để xóa ký tự thừa cũ
				cout << WStringToString(wResult) << " ";
				setPos(startPos.X + index, startPos.Y);
			}
		}
		// 4. Xử lý ký tự văn bản (Bao gồm cả tiếng Việt 0xE0)
		else {
			// Chỉ nhận các ký tự in được (>= 32)
			if (ch >= 32) {
				playMoveSound();
				wResult.insert(index, 1, (wchar_t)ch);
				index++;

				setPos(startPos.X, startPos.Y);
				cout << WStringToString(wResult);
				setPos(startPos.X + index, startPos.Y);
			}
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