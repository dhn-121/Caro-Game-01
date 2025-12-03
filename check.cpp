#include "Library.h"
using namespace std;
bool has_empty_cell = 0;
int count_moves = 0;
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

// Hàm kiểm tra hòa: So sánh số nước đã đi với tổng số ô trên bàn cờ
bool check_isdraw(int count_moves)
{
	// Nếu số nước đi == Tổng số ô (N * N hoặc BOARD_SIZE * BOARD_SIZE)
	if (count_moves == BOARD_SIZE * BOARD_SIZE)
		return true;
	return false;
}

//test xem có ai chiến thắng không
int main()
{	
	playBackgroundMusic();  // phát nhạc nền menu
	// 1. Khởi tạo và Cố định Cửa sổ
	fixConsoleWindow(ConsoleWidth,ConsoleHeight);
	// 2. Định nghĩa các biến cần thiết cho game
	char default_player = 'X';
	char name1[] = "Player 1 (X)";
	char name2[] = "Player 2 (O)";
	char min[] = "05";
	char sec[] = "00";
	std::string filename = "caro_save_01.txt";

	int choice;
	int x = xbegin;
	int y = ybegin;
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
			choice = GamePlay(default_player, name1, name2, min, sec, filename, isload);

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
	return 0;
}
