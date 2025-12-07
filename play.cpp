#include "Library.h"
void GamePlay(char default_player, char name1[], char name2[], std::string filename,int typegame)
{
	drawGamePlayScreen(default_player, name1, name2, filename);
	int x = xbegin;
	int y = ybegin;
	char currentPlayer;
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
				board[i][j] = ' ';
	}else if(typegame==1)
	{
		// load game
		
		bool loadSuccess = loadGame(filename, board, currentPlayer, score_X, score_O);
		if (loadSuccess)
		{
			// Redraw the loaded board
			loadproductfile(filename, board, currentPlayer, score_X, score_O);
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
			count_moves++;
			int i, j;
			MakeMove(player_main, x, y);
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
	//cin.ignore();
	if (type == -1)
	{
		ControlGaming();
	}else if(type==5)
	{
		// load game
		std::string load_filename;
		//loadactive(load_filename, board, default_player, score_X, score_O);
		if(loadactive(load_filename, board, default_player, score_X, score_O))
		{
			setPos((ConsoleWidth - 20) / 2, (ConsoleHeight) / 2 + 3);
			cout << "Game loaded successfully! Returning to game...";
			Sleep(2000);
			GamePlay(default_player, name1, name2, load_filename, 1);
		}
		else
		{
			setPos((ConsoleWidth - 20) / 2, (ConsoleHeight) / 2 + 3);
			cout << "Failed to load game. Returning to current game...";
			Sleep(2000);
			GamePlay(default_player, name1, name2, filename, 3);
		}
	}
	else if(type==6)
	{
		// save game
		std::string save_filename;
		drawSaveLoadScreen(ConsoleWidth, ConsoleHeight);
		//getfilename(save_filename);
		if(getfilename(save_filename) == 0)
		{
			setPos((ConsoleWidth - 20) / 2, (ConsoleHeight) / 2 + 3);
			cout << "Save cancelled. Returning to game...";
			Sleep(2000);
			GamePlay(default_player, name1, name2, filename, 3);
		}
		saveGame(save_filename, board, check_XO(), score_X, score_O);
		setPos((ConsoleWidth - 20) / 2, (ConsoleHeight) / 2 + 3);
		cout << "Game saved successfully! Returning to menu...";
		Sleep(2000);
		GamePlay(default_player, name1, name2, filename, 3);
	}
	cin.ignore();
	ControlGaming();
	stopGameplayMusic();
	playBackgroundMusic();
}
