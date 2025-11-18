#include "Library.h"
using namespace std;

//ham dat vi tri con tro
void setPos(int x, int y)
{
	COORD coord{};
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
//ham kiem tra key nhap vao
int isNextMove()
{
	while (true)
	{
		char key = _getch();
		// Enter
		if (key == 13 || key == ' ') return 0;
		// ESC
		if (key == 27) return -1;
		if (key == -32) {						// Arrow
			key = _getch();
			if (key == 72) return 1;			// Up
			if (key == 75) return 2;			// Left
			if (key == 80) return 3;			// Down
			if (key == 77) return 4;			// Right
		}
		// WASD
		if (key == 'W' || key == 'w') return 1;
		if (key == 'A' || key == 'a') return 2;
		if (key == 'S' || key == 's') return 3;
		if (key == 'D' || key == 'd') return 4;
	}
}
//ham di chuyen
void Movexy(int &x,int &y,int typemove)
{
	/*if (typemove == 0)
	{
		cout << 'x';
		setPos(x, y);
		return;
	}*/
	int DXX = CellWidth +1;//do dai nhay X
	int DXY = CellHeight +1;//do dai nhay Y

	//di chuyen
	x += DXX*dxy[typemove - 1].first;
	y += DXY*dxy[typemove - 1].second;

	//kiem tra vuot bien
	if (x > (DXX) * (BOARD_SIZE - 1) + xbegin)x = xbegin;
	if (x < xbegin)x = (DXX) * (BOARD_SIZE - 1) + xbegin;
	if (y >= DXY * (BOARD_SIZE)+ybegin)y = ybegin;
	if (y < ybegin)y = DXY * (BOARD_SIZE - 1) + ybegin;
	//dat con tro
	setPos(x, y);
}

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
						MakeMove(player_main, y / CellHeight + 1, x / CellWidth + 1);
						if (!test_board(player_main, y / CellHeight + 1, x / CellWidth + 1, board))
						{
							cout << player_main << "WIN";
							return;
						}
					}
					else Movexy(x, y, type);
				}
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
    return ;
}


