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
	cout << "Enter filename (without .txt extension) ";
	cout << "max 100 characters";
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
std::string WStringToString(const std::wstring & wstr)
{
	if (wstr.empty()) return std::string();
	int size_needed = WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), NULL, 0, NULL, NULL);
	std::string strTo(size_needed, 0);
	WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), &strTo[0], size_needed, NULL, NULL);
	return strTo;
}

// --- HÀM CUSTOM INPUT (Hỗ trợ tiếng Việt) ---
bool customInput(string& result,int maxsize) {
	ShowConsoleCursor(true);

	wstring wResult = L"";
	int index = 0;
	COORD startPos = getCursorPos();

	HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);
	INPUT_RECORD InRec;
	DWORD NumRead;

	while (true) {
		// Đọc sự kiện bàn phím
		ReadConsoleInputW(hIn, &InRec, 1, &NumRead);

		// Chỉ xử lý khi phím được NHẤN XUỐNG
		if (InRec.EventType == KEY_EVENT && InRec.Event.KeyEvent.bKeyDown) {

			WORD vk = InRec.Event.KeyEvent.wVirtualKeyCode; // Mã phím ảo
			WCHAR wc = InRec.Event.KeyEvent.uChar.UnicodeChar; // Ký tự văn bản

			// --- QUAN TRỌNG: Bỏ qua các phím chức năng đơn lẻ ---
			// Nếu chỉ bấm Shift/Ctrl/Alt/CapsLock mà không kèm ký tự, bỏ qua ngay
			// để tránh nó lọt xuống dưới làm nhiễu logic.
			if (vk == VK_SHIFT || vk == VK_CONTROL || vk == VK_MENU || vk == VK_CAPITAL || vk == VK_LWIN || vk == VK_RWIN) {
				continue;
			}

			// 1. ESC: Hủy bỏ
			if (vk == VK_ESCAPE) {
				result = "";
				return false;
			}
			// 2. ENTER: Xác nhận
			else if (vk == VK_RETURN) {
				playClickSound();
				result = WStringToString(wResult);
				return true;
			}
			// 3. BACKSPACE: Xóa ký tự
			// Thêm điều kiện (wc == 8) để bắt được Backspace do Unikey gửi kể cả khi đang đè Shift
			else if (vk == VK_BACK || wc == 8) {
				if (index > 0 && wResult.length() > 0) {
					wResult.erase(index - 1, 1);
					index--;

					setPos(startPos.X, startPos.Y);
					cout << WStringToString(wResult) << " "; // Xóa ký tự thừa
					setPos(startPos.X + index, startPos.Y);
				}
			}
			// 4. MŨI TÊN TRÁI
			else if (vk == VK_LEFT) {
				playMoveSound();
				if (index > 0) {
					index--;
					setPos(startPos.X + index, startPos.Y);
				}
			}
			// 5. MŨI TÊN PHẢI
			else if (vk == VK_RIGHT) {
				playMoveSound();
				if (index < wResult.length()) {
					index++;
					setPos(startPos.X + index, startPos.Y);
				}
			}
			// 6. KÝ TỰ VĂN BẢN (Tiếng Việt, In hoa, Thường...)
			else if (wc >= 32) {
				playMoveSound();
				if(maxsize>0 && wResult.length()>=maxsize)
					continue;
				wResult.insert(index, 1, wc);
				index++;
				if(wResult.length()>maxsize)
				{
					wResult.erase(index - 1, 1);
					index--;
					continue;
				}
				setPos(startPos.X, startPos.Y);
				cout << WStringToString(wResult);
				setPos(startPos.X + index, startPos.Y);
			}
		}
	}
}
bool customInput2(string& result, int maxsize) {
	ShowConsoleCursor(true);

	wstring wResult = L"";
	int index = 0;
	COORD startPos = getCursorPos();

	HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);
	INPUT_RECORD InRec;
	DWORD NumRead;
	for (int i = 0; i < result.length(); i++)
	{
		wchar_t wc = (wchar_t)result[i];
		wResult.insert(index, 1, wc);
		index++;
		setPos(startPos.X, startPos.Y);
		cout << WStringToString(wResult);
	}
	setPos(startPos.X + index, startPos.Y);
	while (true) {
		// Đọc sự kiện bàn phím
		ReadConsoleInputW(hIn, &InRec, 1, &NumRead);

		// Chỉ xử lý khi phím được NHẤN XUỐNG
		if (InRec.EventType == KEY_EVENT && InRec.Event.KeyEvent.bKeyDown) {

			WORD vk = InRec.Event.KeyEvent.wVirtualKeyCode; // Mã phím ảo
			WCHAR wc = InRec.Event.KeyEvent.uChar.UnicodeChar; // Ký tự văn bản

			// --- QUAN TRỌNG: Bỏ qua các phím chức năng đơn lẻ ---
			// Nếu chỉ bấm Shift/Ctrl/Alt/CapsLock mà không kèm ký tự, bỏ qua ngay
			// để tránh nó lọt xuống dưới làm nhiễu logic.
			if (vk == VK_SHIFT || vk == VK_CONTROL || vk == VK_MENU || vk == VK_CAPITAL || vk == VK_LWIN || vk == VK_RWIN) {
				continue;
			}

			// 1. ESC: Hủy bỏ
			if (vk == VK_ESCAPE) {
				result = "";
				return false;
			}
			// 2. ENTER: Xác nhận
			else if (vk == VK_RETURN) {
				playClickSound();
				result = WStringToString(wResult);
				return true;
			}
			// 3. BACKSPACE: Xóa ký tự
			// Thêm điều kiện (wc == 8) để bắt được Backspace do Unikey gửi kể cả khi đang đè Shift
			else if (vk == VK_BACK || wc == 8) {
				if (index > 0 && wResult.length() > 0) {
					wResult.erase(index - 1, 1);
					index--;

					setPos(startPos.X, startPos.Y);
					cout << WStringToString(wResult) << " "; // Xóa ký tự thừa
					setPos(startPos.X + index, startPos.Y);
				}
			}
			// 4. MŨI TÊN TRÁI
			else if (vk == VK_LEFT) {
				playMoveSound();
				if (index > 0) {
					index--;
					setPos(startPos.X + index, startPos.Y);
				}
			}
			// 5. MŨI TÊN PHẢI
			else if (vk == VK_RIGHT) {
				playMoveSound();
				if (index < wResult.length()) {
					index++;
					setPos(startPos.X + index, startPos.Y);
				}
			}
			// 6. KÝ TỰ VĂN BẢN (Tiếng Việt, In hoa, Thường...)
			else if (wc >= 32) {
				playMoveSound();
				if (maxsize > 0 && wResult.length() >= maxsize)
					continue;
				wResult.insert(index, 1, wc);
				index++;
				if (wResult.length() > maxsize)
				{
					wResult.erase(index - 1, 1);
					index--;
					continue;
				}
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
	return customInput(filename,100);
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