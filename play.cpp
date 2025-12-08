#include "Library.h"
void GamePlay(char default_player, char name1[], char name2[], std::string filename,int typegame)
{
	ShowConsoleCursor(true);
	system("cls");
	drawGamePlayScreen(default_player, name1, name2, filename);
	int x = xbegin;
	int y = ybegin;
	char currentPlayer{};
	int timeMinutes, timeSeconds;
	int count_moves = 0;
	int score_X = 0;
	int score_O = 0;
	int type = 0;
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
		currentPlayer = check_XO();
		if (type == 0)
		{
			int i, j;
			count_moves+=MakeMove(currentPlayer, x, y);
			getij(i, j, x, y);
			if (check_iswin(i, j, board))
			{
				updateScore(currentPlayer);
				system("cls");
				drawWinStatus(currentPlayer, name1, name2);
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
		loadGameScreen(filename, board, currentPlayer, score_X, score_O, name1, name2);
	}
	else if(type==5)
	{
		saveGameScreen(filename, board, currentPlayer, score_X, score_O, name1, name2);
	}
	ControlGaming();
	stopGameplayMusic();
	playBackgroundMusic();
}

void AiGamePlay(char default_player, char name1[], char name2[], std::string filename, int typegame)
{
	ShowConsoleCursor(true);
	// Implementation for AI gameplay mode
	system("cls");
	drawGamePlayScreen(default_player, name1, name2, filename);
	int x = xbegin;
	int y = ybegin;
	char currentPlayer{};
	int timeMinutes, timeSeconds;
	int count_moves = 0;
	int score_X = 0;
	int score_O = 0;
	int type = 0;
	stopBackgroundMusic();
	playGameplayMusic();
	if (typegame == 0)
	{
		// new game
		// initialize board
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				board[i][j] = '-';
	}
	else if (typegame == 1)
	{
		// load game
		bool loadSuccess = loadGame(filename, board, currentPlayer, score_X, score_O, name1, name2);
		if (loadSuccess)
		{
			// Redraw the loaded board
			loadproductfile(filename, board, currentPlayer, score_X, score_O, name1, name2);
		}
	}
	else {
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (board[i][j] == '-')continue;
				int row, col;
				getxy(row, col, i, j);
				setPos(row, col);
				cout << board[i][j];
			}
		}
	}
	if (typegame == 1 || typegame == 2)
	{
		char next_player = check_XO();
		drawTurnBox(TurnData[0], TurnData[1], TurnData[2], TurnData[3], next_player, name1, name2);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (board[i][j] != '-')count_moves++;
			}
		}
	}
	setPos(x, y);
	while (true)
	{
		currentPlayer = check_XO();
		if(currentPlayer == player_O)
		{
			int ai_row, ai_col;
			getBestMove(board, ai_row, ai_col, player_O);
			int row, col;
			getxy(row, col, ai_row, ai_col);
			x = row;
			y = col;
			count_moves += MakeMove(player_O, x, y);
			if (check_iswin(ai_row, ai_col, board))
			{
				updateScore(player_O);
				system("cls");
				drawWinStatus(player_O, name1, name2);
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
		else
		{
			type = isNextMove();
			if (type == -1 || type == 5 || type == 6)break;
			if (type == 0)
			{
				int i, j;
				count_moves += MakeMove(currentPlayer, x, y);
				getij(i, j, x, y);
				if (check_iswin(i, j, board))
				{
					updateScore(currentPlayer);
					system("cls");
					drawWinStatus(currentPlayer, name1, name2);
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
	}
	count_moves = 0;
	//cin.ignore();
	if (type == -1)
	{
		ControlGaming();
	}
	else if (type == 6)
	{
		loadGameScreen(filename, board, currentPlayer, score_X, score_O, name1, name2);
	}
	else if (type == 5)
	{
		saveGameScreen(filename, board, currentPlayer, score_X, score_O, name1, name2);
	}
	ControlGaming();
	stopGameplayMusic();
	playBackgroundMusic();
}