#include"Library.h"
int main()
{	
	initializeBGM();
	playBackgroundMusic(); // phát nhạc nền menu
	// 1. Khởi tạo và Cố định Cửa sổ
	fixConsoleWindow(ConsoleWidth,ConsoleHeight);
	// 2. Định nghĩa các biến cần thiết cho game
	char default_player = 'X';
	char name1[] = "Player 1 (X)";
	char name2[] = "Player 2 (O)";
	// char min[] = "05";
	// char sec[] = "00";
	std::string filename = "caro_save_01.txt";

	int choice;
	// int x = xbegin;
	// int y = ybegin;
	// Vòng lặp chính của chương trình để quay lại Menu
	std::string load_filename;
	int score_X = 0;
	int score_O = 0;
	drawLoadingScreen();
	do
	{
		fixConsoleWindow(ConsoleWidth, ConsoleHeight);
		system("cls");
		drawMenuScreen();
		// Gọi hàm điều khiển Menu và lấy lựa chọn
		choice = ControlMenu();
		
		// 4. Xử lý lựa chọn
		switch (choice) {
		case 1: // Play Game
			// Chuyển sang màn hình chơi game
		{
			// Call the mode selection menu
			int mode = ControlGameMode();

			if (mode == 0) // PvP
			{
				GamePlay(default_player, name1, name2, filename, 0);
			}
			else if (mode == 1) // PvE
			{
				// Call the AI Game Play function
				AiGamePlay(default_player, name1, "COMPUTER", filename, 0);
			}
		}
		break;

		case 2: // Saved Files
			system("cls");
			if (loadactive(load_filename, board, default_player, score_X, score_O,name1,name2))
			{
				setPos((ConsoleWidth - 20) / 2, (ConsoleHeight) / 2 + 3);
				cout << "Game loaded successfully! Returning to game...";
				Sleep(2000);
				GamePlay(default_player, name1, name2, load_filename, 1);
			}
			//cin.ignore();
			//cin.get();
			break;

		case 3: // Settings
			// Vào màn hình Settings và điều khiển (ControlSettings trả về 0 khi nhấn BACK)
			ControlSettings();
			break;

		case 4: // About Us
			system("cls");
			drawHelpScreen();
			cin.ignore();
			cin.get();
			break;

		case 5: // Exit
			// Thoát vòng lặp
			break;
		}
	} while (choice != 5);
	system("cls");
	setPos(0, 0);
	cout << "Exit Game. Goodbye!" << endl;
	return 0;
}

