#include"Library.h"

using namespace std;

bool saveGame()
{
	//create directory "save" if not exist
	_mkdir("save");

	// add path "save/" to filename
	string fullPath = "save/" + filename + ".txt";

	ofstream outFile(fullPath.c_str()); // .c_str() to convert string to const char*
	setPos((ConsoleWidth) / 2 - 20, (ConsoleHeight) / 2 + 3);

	if (!outFile) {
		cerr << T("Error creating file ") << fullPath << endl;
		return 0;
	}

	for (int i = 0; i < N; ++i) {
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
	cout << T("Game saved successfully to ") << fullPath << endl;
	return true;
}

bool loadGame()
{
	// when loading, add path "save/" to filename
	string fullPath = "save/" + filename + ".txt";

	ifstream inFile(fullPath.c_str());
	if (!inFile) {
		cerr << T("file not found") << fullPath << endl;
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
	setColor(backgroundcolor, fontcolor);
	drawSAVELOAD((ConsoleWidth - 65) / 2, ConsoleHeight * 7 / 100);
	setPos((ConsoleWidth - 53) / 2, (ConsoleHeight) / 2 - 4);
	cout << T("Enter filename (without .txt extension) ");
	cout << T("max 100 characters");
	setColor(backgroundcolor, fontcolor);
	int boxWidth = Width - 18;
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
std::string WStringToString(const std::wstring& wstr)
{
	if (wstr.empty()) return std::string();
	int size_needed = WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), NULL, 0, NULL, NULL);
	std::string strTo(size_needed, 0);
	WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), &strTo[0], size_needed, NULL, NULL);
	return strTo;
}

// --- HÀM PHỤ TRỢ: Chuyển string (UTF-8) sang wstring (Unicode) ---
std::wstring StringToWString(const std::string& str)
{
	if (str.empty()) return std::wstring();
	int size_needed = MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), NULL, 0);
	std::wstring wstrTo(size_needed, 0);
	MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), &wstrTo[0], size_needed);
	return wstrTo;
}

// --- HÀM CUSTOM INPUT (Hỗ trợ tiếng Việt) ---
bool customInput(string& result, int maxsize)
{
	ShowConsoleCursor(true);
	result = "";
	wstring wResult = StringToWString(result);
	int index = wResult.length();
	COORD startPos = getCursorPos();

	HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);
	INPUT_RECORD InRec;
	DWORD NumRead;

	setPos(startPos.X, startPos.Y);
	cout << WStringToString(wResult);

	while (true) {
		ReadConsoleInputW(hIn, &InRec, 1, &NumRead);

		if (InRec.EventType == KEY_EVENT && InRec.Event.KeyEvent.bKeyDown) {

			WORD vk = InRec.Event.KeyEvent.wVirtualKeyCode;
			WCHAR wc = InRec.Event.KeyEvent.uChar.UnicodeChar;

			if (vk == VK_SHIFT || vk == VK_CONTROL || vk == VK_MENU ||
				vk == VK_CAPITAL || vk == VK_LWIN || vk == VK_RWIN)
				continue;

			if (vk == VK_ESCAPE) {
				result = "";
				return false;
			}
			else if (vk == VK_RETURN) {
				playClickSound();
				result = WStringToString(wResult);
				return true;
			}
			else if (vk == VK_BACK) {
				if (index > 0) {
					wResult.erase(index - 1, 1);
					index--;
					setPos(startPos.X, startPos.Y);
					cout << WStringToString(wResult) << " ";
					setPos(startPos.X + index, startPos.Y);
				}
			}
			else if (vk == VK_LEFT && index > 0) {
				index--;
				setPos(startPos.X + index, startPos.Y);
			}
			else if (vk == VK_RIGHT && index < wResult.length()) {
				index++;
				setPos(startPos.X + index, startPos.Y);
			}
			else if (wc != 0 && iswprint(wc)) {
				if (maxsize > 0 && wResult.length() >= maxsize)
					continue;

				wResult.insert(index, 1, wc);
				index++;
				setPos(startPos.X, startPos.Y);
				cout << WStringToString(wResult);
				setPos(startPos.X + index, startPos.Y);
			}
		}
	}
}

bool customInput2(string& result, int maxsize)
{
	ShowConsoleCursor(true);

	wstring wResult = StringToWString(result);
	int index = wResult.length();
	COORD startPos = getCursorPos();

	HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);
	INPUT_RECORD InRec;
	DWORD NumRead;

	setPos(startPos.X, startPos.Y);
	cout << WStringToString(wResult);

	while (true) {
		ReadConsoleInputW(hIn, &InRec, 1, &NumRead);

		if (InRec.EventType == KEY_EVENT && InRec.Event.KeyEvent.bKeyDown) {

			WORD vk = InRec.Event.KeyEvent.wVirtualKeyCode;
			WCHAR wc = InRec.Event.KeyEvent.uChar.UnicodeChar;

			if (vk == VK_SHIFT || vk == VK_CONTROL || vk == VK_MENU ||
				vk == VK_CAPITAL || vk == VK_LWIN || vk == VK_RWIN)
				continue;

			if (vk == VK_ESCAPE) {
				result = "";
				return false;
			}
			else if (vk == VK_RETURN) {
				playClickSound();
				result = WStringToString(wResult);
				return true;
			}
			else if (vk == VK_BACK) {
				if (index > 0) {
					wResult.erase(index - 1, 1);
					index--;
					setPos(startPos.X, startPos.Y);
					cout << WStringToString(wResult) << " ";
					setPos(startPos.X + index, startPos.Y);
				}
			}
			else if (vk == VK_LEFT && index > 0) {
				index--;
				setPos(startPos.X + index, startPos.Y);
			}
			else if (vk == VK_RIGHT && index < wResult.length()) {
				index++;
				setPos(startPos.X + index, startPos.Y);
			}
			else if (wc != 0 && iswprint(wc)) {
				if (maxsize > 0 && wResult.length() >= maxsize)
					continue;

				wResult.insert(index, 1, wc);
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
	setPos(10, (ConsoleHeight - 3) / 2 + 1);
	filename.clear();
	return customInput(filename, 100);
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
				if (board[i][j] == 'X')
					count_X++;
				else if (board[i][j] == 'O')
					count_O++;
			}
		}
	}
}

bool loadactive()
{
	drawSaveLoadScreen(ConsoleWidth, ConsoleHeight);
	if (getfilename(filename) == 0)
		return 0;
	while (checkFileExists(filename) == false)
	{
		setPos((ConsoleWidth - 20) / 2, (ConsoleHeight) / 2 + 2);
		cout << T("File not found. Try again:          ");
		setPos(22, (ConsoleHeight - 3) / 2 + 1);
		cout << "                                                                                       ";
		if (getfilename(filename) == 0)
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
		cout << T("Game loaded successfully! Returning to game...");
		Sleep(2000);
		if (difficulty == 4)
			GamePlay(1);
		else
			AiGamePlay(1);
	}
	else
	{
		setPos((ConsoleWidth) / 2 - 20, (ConsoleHeight) / 2 + 2);
		cout << T("Failed to load game. Returning to current game...");
		Sleep(2000);
		if (difficulty == 4)
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
		cout << T("Game loaded successfully! Returning to game...");
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
		cout << T("Save cancelled. Returning to game...");
		Sleep(2000);
		GamePlay(3);
	}
	saveGame();
	setPos((ConsoleWidth) / 2 - 20, (ConsoleHeight) / 2 + 5);
	cout << T("Game saved successfully! Returning to menu...");
	Sleep(2000);
	//GamePlay(currentPlayer, name1, name2, filename, 3);
	if (difficulty == 4)
		GamePlay(3);
	else
		AiGamePlay(3);
}