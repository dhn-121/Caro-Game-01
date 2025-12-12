#include "play.h"

int difficulty;
char currentPlayer;
string name1;
string name2;
std::string filename;
void resetGameVariables()
{
	currentPlayer = 'X';
	/*name1 = "Player 1";
	name2 = "Player 2";*/
	filename = "caro_save_01.txt";
	count_moves = 0;
	count_O = 0;
	count_X = 0;
}
void drawContinueGameScreen(int iscontiue)
{
	int type = 3;
	if(!iscontiue)
	{
		type=0;
	}
	if (difficulty==4)
	{
		GamePlay(type);
	}
	else
	{
		AiGamePlay(type);
	}
}
void GamePlay(int typegame)
{
	difficulty = 4;
	ShowConsoleCursor(true);
	system("cls");
	int x = xbegin;
	int y = ybegin;
	difficulty = 4;
	stopBackgroundMusic();
	playGameplayMusic();
	if (typegame == 0)
	{
		// new game
		// initialize board
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				board[i][j] = '-';
		//reset
		resetGameVariables();
	}else if(typegame==1)
	{
		// load game
		
		bool loadSuccess = loadGame();
		if (loadSuccess)
		{
			// Redraw the loaded board
			loadproductfile();
		}
	}if (typegame == 0)
	{
		// new game
		// initialize board
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				board[i][j] = '-';
		//reset
		resetGameVariables();
	}
	else if (typegame == 1)
	{
		// load game

		bool loadSuccess = loadGame();
		if (loadSuccess)
		{
			// Redraw the loaded board
			loadproductfile();
		}
	}
	system("cls");
	drawGamePlayScreen(currentPlayer, name1, name2, filename);
	if (typegame == 1 || typegame == 2)
	{
		char next_player = check_XO();
		drawTurnBox(TurnData[0], TurnData[1], TurnData[2], TurnData[3], next_player, name1, name2);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (board[i][j] == '-')continue;
				count_moves++;
				int row, col;
				getxy(row, col, i, j);
				setPos(row, col);
				cout << board[i][j];
			}
		}
	}
	//GAME CONTINUE IS TYPEGAME==3
	setPos(x, y);
	HighlightPos(x, y, 1);
	int type = 0;
	while (true)
	{
		type = isNextMove();
		if (type == -1||type== 5||type==6)break;
		currentPlayer = check_XO();
		if (type == 0)
		{
			int i, j;
			setPos(x, y);
			count_moves+=MakeMove(currentPlayer, x, y);
			getij(i, j, x, y);
			if (check_iswin(i, j, board))
			{
				highlightWinningSequence(i, j, board);
				Sleep(3000);
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
			setPos(x, y);
		}
		else Movexy(x, y, type);
	}
	count_moves = 0;
	
	if(type==6)
	{
		loadGameScreen();
		return;
	}
	else if(type==5)
	{
		saveGameScreen();
		return;
	}
	else if (type == -1)
	{
		system("cls");
		
	}
	Sleep(200);
	count_O = 0;
	count_X = 0;
	if (type == -1)ControlGaming(1);
	else ControlGaming(0);
	stopGameplayMusic();
	playBackgroundMusic();
		return;
	
}

void AiGamePlay(int typegame)
{
	ShowConsoleCursor(true);
	// Implementation for AI gameplay mode
	system("cls");
	drawGamePlayScreen(currentPlayer, name1, name2, filename);
	int x = xbegin;
	int y = ybegin;
	stopBackgroundMusic();
	playGameplayMusic();
	if (typegame == 0)
	{
		// new game
		// initialize board
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				board[i][j] = '-';
		//reset
		resetGameVariables();
	}
	else if (typegame == 1)
	{
		// load game

		bool loadSuccess = loadGame();
		if (loadSuccess)
		{
			// Redraw the loaded board
			loadproductfile();
		}
	}if (typegame == 0)
	{
		// new game
		// initialize board
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				board[i][j] = '-';
		//reset
		resetGameVariables();
	}
	else if (typegame == 1)
	{
		// load game

		bool loadSuccess = loadGame();
		if (loadSuccess)
		{
			// Redraw the loaded board
			loadproductfile();
		}
	}
	system("cls");
	drawGamePlayScreen(currentPlayer, name1, name2, filename);
	if (typegame == 1 || typegame == 2)
	{
		char next_player = check_XO();
		drawTurnBox(TurnData[0], TurnData[1], TurnData[2], TurnData[3], next_player, name1, name2);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (board[i][j] == '-')continue;
				count_moves++;
				int row, col;
				getxy(row, col, i, j);
				setPos(row, col);
				cout << board[i][j];
			}
		}
	}
	setPos(x, y);
	HighlightPos(x, y, 1);
	int type = 0;
	while (true)
	{
		currentPlayer = check_XO();
		if(currentPlayer == player_O)
		{
			int ai_row, ai_col;
			if (currentPlayer == player_O) // AI's turn
			{

				// Choose the brain based on difficulty level
				if (difficulty == 0) {
					getEasyMove(board, ai_row, ai_col); // Easy Mode: Random
				}
				else if (difficulty == 1) {
					getBestMove(board, ai_row, ai_col, player_O); // Normal Mode: Heuristic/Greedy
				}
				else {
					getSmartMove(board, ai_row, ai_col, player_O); // Hard Mode: Minimax/Alpha-Beta
				}

				// ... (MakeMove, CheckWin, DrawTurnBox logic follows) ...
			}
			int row, col;
			getxy(row, col, ai_row, ai_col);
			HighlightPos(x, y, 0);
			x = row;
			y = col;
			count_moves += MakeMove(player_O, x, y);
			if (check_iswin(ai_row, ai_col, board))
			{
				highlightWinningSequence(ai_row, ai_col, board);
				Sleep(3000);
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
			setPos(x, y);
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
					highlightWinningSequence(i, j, board);
					Sleep(3000);
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
				setPos(x, y);
			}
			else Movexy(x, y, type);
		}
	}
	count_moves = 0;
	
	if (type == 6)
	{
		loadGameScreen();
		return;
	}
	else if (type == 5)
	{
		saveGameScreen();
		return;
	}
	if (type == -1)
	{
		system("cls");
		
	}
	Sleep(200);
	count_O = 0;
	count_X = 0;
	if (type == -1)AiControlGaming(1);
	else AiControlGaming(0);
	stopGameplayMusic();
	playBackgroundMusic();
		return;
	
}