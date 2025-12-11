#include"Library.h"
int main()
{	
	initializeBGM();
	playBackgroundMusic(); // phát nhạc nền menu
	// 1. Khởi tạo và Cố định Cửa sổ
	fixConsoleWindow(ConsoleWidth,ConsoleHeight);
	// 2. Định nghĩa các biến cần thiết cho game
	char default_player = 'X';
	name1 = "Player 1 (X)";
	name2= "Player 2 (O)";
	// char min[] = "05";
	// char sec[] = "00";
	std::string filename = "caro_save_01.txt";

	int choice;
	// int x = xbegin;
	// int y = ybegin;
	// Vòng lặp chính của chương trình để quay lại Menu
	std::string load_filename;
	score_X = 0;
	score_O = 0;
	difficulty = 4;
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
				difficulty = 4;
				score_O = 0;
				score_X = 0;
				filename = "caro_save_01.txt";
				currentPlayer = player_X;
				name1 = "Player 1 (X)";
				name2 = "Player 2 (O)";
				GamePlay(0);
			}
			else if (mode == 1) // PvE Mode
			{
				//int diff = ControlDifficulty();
				int diff = ControlDifficulty();
				// Nếu chọn Easy(0), Normal(1), hoặc Hard(2) thì vào game
				// Nếu chọn Back(3) thì không làm gì (tự quay lại vòng lặp menu)
				score_O = 0;
				score_X = 0;
				filename = "caro_save_01.txt";
				currentPlayer = player_X;
				name1 = "Player (X)";
				name2 = "Computer (O)";
				if (diff != 3)
				{
					difficulty = diff;
					AiGamePlay(0);
				}
			}
		}
		break;

		case 2: // Saved Files
			system("cls");
			if (loadactive())
			{
				setPos((ConsoleWidth - 20) / 2, (ConsoleHeight) / 2 + 3);
				cout << "Game loaded successfully! Returning to game...";
				Sleep(2000);
				GamePlay(1);
			}
			//cin.ignore();
			//cin.get();
			break;

		case 3: // Settings
			// Vào màn hình Settings và điều khiển (ControlSettings trả về 0 khi nhấn BACK)
			ControlSettings();
			break;

		case 4: // About Us
			displayHelp(createQAList(), 0);
			ControlHelp();
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

