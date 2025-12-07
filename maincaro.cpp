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
	bool isload = false;
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
			GamePlay(default_player, name1, name2,filename, isload);
			break;

		case 2: // Saved Files
			system("cls");
			setPos(Xi, Yi);
			cout << "Load Files: Chuc nang dang phat trien...";
			drawSaveLoadScreen(ConsoleWidth, ConsoleHeight);
			cin >> filename;
			while(checkFileExists(filename) == false)
			{
				setPos((ConsoleWidth - 20) / 2, (ConsoleHeight) / 2 + 2);
				cout << "File not found. Try again:          ";
				setPos((ConsoleWidth - 20) / 2, (ConsoleHeight) / 2 + 3);
				cout << "                              ";
				setPos((ConsoleWidth - 20) / 2, (ConsoleHeight) / 2 + 2);
				cin >> filename;
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

