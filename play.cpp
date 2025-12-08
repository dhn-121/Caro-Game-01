#include "Library.h"
void GamePlay(char default_player, char name1[], char name2[], std::string filename,int typegame)
{
	system("cls");
	drawGamePlayScreen(default_player, name1, name2, filename);
	int x = xbegin;
	int y = ybegin;
	char currentPlayer{};
	int timeMinutes, timeSeconds;
	int count_moves = 0;
	int score_X = 0;
	int score_O = 0;
	int type;
	stopBackgroundMusic();
	playGameplayMusic();
	if (typegame == 0)
	{
		// new game
		// initialize board
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				board[i][j] = '-';
	}else if(typegame==1)
	{
		// load game
		
		bool loadSuccess = loadGame(filename, board, currentPlayer, score_X, score_O,name1,name2);
		if (loadSuccess)
		{
			// Redraw the loaded board
			loadproductfile(filename, board, currentPlayer, score_X, score_O,name1,name2);
		}
	}else {
		for (int i = 0; i <N; i++)
		{
			for (int j = 0; j <N; j++)
			{
				if (board[i][j] == '-')continue;
					int row, col;
					getxy(row, col,i,j);
					setPos(row, col);
					cout << board[i][j];
			}
		}
	}
	if(typegame==1||typegame==2)
	{
		char next_player = check_XO();
		drawTurnBox(TurnData[0], TurnData[1], TurnData[2], TurnData[3], next_player, name1, name2);
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				if(board[i][j]!='-')count_moves++;
			}
		}
	}
	//GAME CONTINUE IS TYPEGAME==3
	setPos(x, y);
	while (true)
	{
		type = isNextMove();
		if (type == -1||type== 5||type==6)break;
		char player_main = check_XO();
		if (type == 0)
		{
			int i, j;
			count_moves+=MakeMove(player_main, x, y);
			getij(i, j, x, y);
			if (check_iswin(i, j, board))
			{
				updateScore(player_main);
				system("cls");
				drawWinStatus(player_main, name1, name2);
				stopGameplayMusic();
				playWinSound();
				typegame = false;
				break;
			}
			else if (check_isdraw(count_moves)) 
			{
				system("cls");
				drawDrawStatus();
				stopGameplayMusic();
				playDrawSound();
				typegame = false;
				break;
			}
			char next_player = check_XO();
			drawTurnBox(TurnData[0], TurnData[1], TurnData[2], TurnData[3], next_player, name1, name2);
		}
		else Movexy(x, y, type);
	}
	count_moves = 0;
	//cin.ignore();
	if (type == -1)
	{
		ControlGaming();
	}else if(type==6)
	{
		// load game
		std::string load_filename;
		//loadactive(load_filename, board, default_player, score_X, score_O);
		if(loadactive(load_filename, board, default_player, score_X, score_O,name1,name2))
		{
			setPos((ConsoleWidth) / 2-20, (ConsoleHeight) / 2 + 3);
			cout << "Game loaded successfully! Returning to game...";
			Sleep(2000);
			GamePlay(default_player, name1, name2, load_filename, 1);
		}
		else
		{
			setPos((ConsoleWidth) / 2-20, (ConsoleHeight) / 2 + 3);
			cout << "Failed to load game. Returning to current game...";
			Sleep(2000);
			GamePlay(default_player, name1, name2, filename, 3);
		}
	}
	else if(type==5)
	{
		// save game
		std::string save_filename;
		drawSaveLoadScreen(ConsoleWidth, ConsoleHeight);
		//getfilename(save_filename);
		if(getfilename(save_filename) == 0)
		{
			setPos((ConsoleWidth) / 2-20, (ConsoleHeight) / 2 + 5);
			cout << "Save cancelled. Returning to game...";
			Sleep(2000);
			GamePlay(default_player, name1, name2, filename, 3);
		}
		saveGame(save_filename, board, check_XO(), score_X, score_O,name1,name2);
		setPos((ConsoleWidth) / 2-20, (ConsoleHeight) / 2 + 5);
		cout << "Game saved successfully! Returning to menu...";
		Sleep(2000);
		GamePlay(default_player, name1, name2, filename, 3);
	}
	cin.ignore();
	ControlGaming();
	stopGameplayMusic();
	playBackgroundMusic();
}
