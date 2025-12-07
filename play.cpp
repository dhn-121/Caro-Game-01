#include "Library.h"
int GamePlay(char default_player, char name1[], char name2[], std::string filename,bool isload)
{
	drawGamePlayScreen(default_player, name1, name2, filename);
	int x = xbegin;
	int y = ybegin;
	stopBackgroundMusic();
	playGameplayMusic();
	//cout << Xi << " " << Yi;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			board[i][j] = ' ';
		}
	}
	if(isload)
	{
		// load game
		char currentPlayer;
		int timeMinutes, timeSeconds;
		bool loadSuccess = loadGame(filename, board, currentPlayer, timeMinutes, timeSeconds);
		if (loadSuccess)
		{
			// Redraw the loaded board
			for (int i = 1; i <= BOARD_SIZE; i++)
			{
				for (int j = 1; j <= BOARD_SIZE; j++)
				{
					if (board[i][j] != ' ')
					{
						int row, col;
						getij(row, col, Xi + (j - 1) * CellWidth + CellWidth / 2 + 1, Yi + (i - 1) * CellHeight + CellHeight / 2 + 1);
						MakeMove(board[i][j], row, col);
					}
				}
			}
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
			int i, j;
			MakeMove(player_main, x, y);
			getij(i, j, x, y);
			if (check_iswin(i, j, board))
			{
				system("cls");
				drawWinStatus(player_main, name1, name2);
				stopGameplayMusic();
				playWinSound();
				break;
			}
			else if (check_isdraw(count_moves)) 
			{
				system("cls");
				drawDrawStatus();
				stopGameplayMusic();
				playDrawSound();
				break;
			}
			char next_player = check_XO();
			drawTurnBox(TurnData[0], TurnData[1], TurnData[2], TurnData[3], next_player, name1, name2);
		}
		else Movexy(x, y, type);
	}
	cin.ignore();
	count_moves = 0;
	int choice = 0; // Exit 
	stopGameplayMusic();
	playBackgroundMusic();
	return choice;
}
//// Trong hàm x? lý input c?a gameplay
//void HandleGameInput() {
//	if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
//		// Ng??i dùng nh?n ESC
//		ShowExitConfirmation();
//	}
//}
//void ExitToMainMenu() {
//	// D?ng âm thanh gameplay (n?u ?ang phát)
//	stopGameplayMusic();
//
//	// Phát nh?c menu
//	playBackgroundMusic();
//
//	// Hi?n th? thông báo
//	printf("Tro ve menu chinh...\n");
//	Sleep(1000);  // ??i 1 giây
//
//	// G?i hàm hi?n th? menu chính
//	drawMenuScreen();
//}
//void ShowExitConfirmation() {
//	system("cls");  // Xóa màn hình
//	cout << "B?n mu?n:\n";
//	cout << "1. Thoát v? menu chính\n";
//	cout << "2. Ti?p t?c ch?i\n";
//	cout << "3. Thoát game hoàn toàn\n";
//	int choice;
//	scanf("%d", &choice);
//	switch (choice) {
//	case 1:
//		ExitToMainMenu();
//		break;
//	case 2:
//		break;
//	case 3:
//		exit(0);
//		break;
//	}
//}