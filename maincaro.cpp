#include "Library.h"
//test xem có ai chiến thắng không
int main()
{
	playBackgroundMusic();  // music background
	// 1. create fixed console window
	fixConsoleWindow(ConsoleWidth, ConsoleHeight);
	// 2. the default values
	char default_player = 'X';
	char name1[] = "Player 1 (X)";
	char name2[] = "Player 2 (O)";
	char min[] = "05";
	char sec[] = "00";
	std::string filename = "caro_save_01.txt";

	int choice;
	int x = xbegin;
	int y = ybegin;
	//the flag to check load game or not
	bool isload = false;
	drawLoadingScreen();
	// the main loop for menu
	do
	{
		fixviewConsoleWindow();
		system("cls");
		drawMenuScreen();
		// Gọi hàm điều khiển Menu và lấy lựa chọn
		choice = ControlMenu();

		// 4. Xử lý lựa chọn
		switch (choice) {
		case 1: // Play Game
		{
			// Chuyển sang màn hình chơi game
			fixviewConsoleWindow();
			drawGamePlayScreen(default_player, name1, name2, min, sec, filename);
			calculateStartPos();
			x = xbegin;
			y = ybegin;
			stopBackgroundMusic(); // tắt nhạc menu
			playGameplayMusic();
			//cout << Xi << " " << Yi;
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					board[i][j] = ' ';
				}
			}
			int count_moves = 0;
			while (true)
			{
				int type = isNextMove();
				if (type == -1)break;
				char player_main = check_XO();
				if (type == 0)
				{
					count_moves++;
					MakeMove(player_main, x, y);
					int i, j;
					getij(i, j, x, y);
					if (check_iswin(i, j, board))
					{
						system("cls");
						setColor(0, 15);
						if (player_main == 'X') {
							drawX_WIN(Xi + 9, Yi - 1);
							stopGameplayMusic();
							playWinSound();
						}
						else {
							drawO_WIN(Xi + 9, Yi - 1);
							stopGameplayMusic();
							playWinSound();
						}
						//return;
						break;
					}
					else if (check_isdraw(count_moves)) // <--- THÊM KHỐI NÀY
					{
						system("cls");
						drawDRAW(Xi + 9, Yi - 1);
						stopGameplayMusic();
						playDrawSound();
						break; // Thoát game
					}
				}
				else Movexy(x, y, type);
			}
			cin.ignore();
			count_moves = 0;
			choice = 0; // Exit sau khi kết thúc game
			stopGameplayMusic();
			playBackgroundMusic();
			break;
		}

		case 2: // Saved Files
			system("cls");
			drawLOAD_GAME(Xi - 8, Yi - 1);
			cin.ignore();
			cin.get();
			break;

		case 3: // Settings
			// Vào màn hình Settings và điều khiển (ControlSettings trả về 0 khi nhấn BACK)
			ControlSettings();
			break;

		case 4: // About Us
			drawAboutUsScreen();
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
