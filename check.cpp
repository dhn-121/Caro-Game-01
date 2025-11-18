#include "Library.h"
using namespace std;
bool has_empty_cell = 0;
void getij(int& i,int& j,int x,int y)
{
    i = (x - xbegin) / (CellWidth + 1);
	j = (y - ybegin) / (CellHeight + 1);
}
bool check_iswin(int x, int y, char a[N][N])
{
	char cur = a[x][y];
	int dmove[4][2] = { {0,1}, {1,0}, {1,1}, {1,-1} }; // ngang, dọc, chéo phải-xuống, chéo trái-xuống
	for(auto dir : dmove)
	{
		int count = 1;
		for(int step = 1; step < 5; step++)
		{
			// di chuyển theo hướng dir
			int nx = x + dir[0] * step;
			int ny = y + dir[1] * step;
			if(nx >= 0 && nx < BOARD_SIZE && ny >= 0 && ny < BOARD_SIZE && a[nx][ny] == cur)
				count++;
			else
				break;
		}
		for(int step = 1; step < 5; step++)
		{
			// di chuyển ngược hướng dir
			int nx = x - dir[0] * step;
			int ny = y - dir[1] * step;
			if(nx >= 0 && nx < BOARD_SIZE && ny >= 0 && ny < BOARD_SIZE && a[nx][ny] == cur)
				count++;
			else
				break;
		}
		if(count >= 5)
			return true;
	}
	return false;
}

//test xem có ai chiến thắng không
void main()
{
	// 1. Khởi tạo và Cố định Cửa sổ
	fixConsoleWindow(ConsoleWidth, ConsoleHeight);

	// 2. Định nghĩa các biến cần thiết cho game
	char default_player = 'X';
	char name1[] = "Player 1 (X)";
	char name2[] = "Player 2 (O)";
	char min[] = "05";
	char sec[] = "00";
	std::string filename = "caro_save_01.txt";

	int choice;

	// Vòng lặp chính của chương trình để quay lại Menu
	int x = xbegin;
	int y = ybegin;
	drawLoadingScreen();
	do
	{
		system("cls");
		drawMenuScreen();
		// Gọi hàm điều khiển Menu và lấy lựa chọn
		choice = ControlMenu();

		// 4. Xử lý lựa chọn
		switch (choice) {
		case 1: // Play Game
			// Chuyển sang màn hình chơi game
			fixConsoleWindow(ConsoleWidth, ConsoleHeight);
			drawGamePlayScreen(default_player, name1, name2, min, sec, filename);

			setPos(x, y);
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					board[i][j] = ' ';
				}
			}
			while (true)
			{
				int type = isNextMove();
				if (type == -1)break;
				char player_main = check_XO();
				if (type == 0)
				{
					MakeMove(player_main, x , y);
					int i, j;
					getij(i, j, x, y);
					if (check_iswin(i,j,board))
					{
						system("cls");
						setColor(0, 15);
						cout << player_main << "WIN";
						//return;
						break;
					}
				}
				else Movexy(x, y, type);
			}
			cin.ignore();
			choice = 0; // Exit sau khi kết thúc game
			break;

		case 2: // Saved Files
			system("cls");
			setPos(Xi, Yi);
			cout << "Saved Files: Chuc nang dang phat trien...";
			cin.ignore();
			cin.get();
			break;

		case 3: // Settings
			// Vào màn hình Settings và điều khiển (ControlSettings trả về 0 khi nhấn BACK)
			ControlSettings();
			break;

		case 4: // About Us
			system("cls");
			setPos(Xi, Yi);
			cout << "About Us: Chuc nang dang phat trien...";
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
	return;
}