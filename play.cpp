#include "play.h"
int GamePlay(char default_player, char name1[], char name2[], char min[], char sec[], std::string filename,bool isload)
{
	drawGamePlayScreen(default_player, name1, name2, min, sec, filename);
	int x = xbegin;
	int y = ybegin;
	stopBackgroundMusic();
	/*playGameplayMusic();*/
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
			MakeMove(player_main, x, y);
			int i, j;
			getij(i, j, x, y);
			if (check_iswin(i, j, board))
			{
				system("cls");
				setColor(0, 15);
				cout << player_main << "WIN";
				//return;
				break;
			}
			else if (check_isdraw(count_moves)) 
			{
				system("cls");
				setColor(0, 15);
				cout << "DRAW GAME!" << '\n'; 
				break;
			}
		}
		else Movexy(x, y, type);
	}
	cin.ignore();
	count_moves = 0;
	int choice = 0; // Exit 
	return choice;
}