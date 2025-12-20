#include "play.h"
//#include "Library.h"
int difficulty;
char currentPlayer;
string name1;
string name2;
std::string filename;

void resetGameVariables()
{
	first_player = RandomFirstPlayer();
	currentPlayer = first_player;
	count_moves = 0;
	count_O = 0;
	count_X = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			board[i][j] = '-';
}

void drawContinueGameScreen(int iscontiue)
{
	int type = 2;
	if (!iscontiue)
	{
		type = 0;
	}
	if (difficulty == 4)
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
	stopBackgroundMusic();
	playGameplayMusic();

	if (typegame == 0)
	{
		// new game
		//reset
		resetGameVariables();
	}

	system("cls");
	drawGamePlayScreen(currentPlayer, name1, name2, filename);
	char next_player = check_XO(first_player);
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

	setPos(x, y);
	HighlightPos(x, y, 1);
	int type = 0;

	while (true)
	{
		currentPlayer = check_XO(first_player);
		type = isNextMove();
		if (type == -1 || type == 5 || type == 6)break;

		if (type == 0)
		{
			int i, j;
			setPos(x, y);
			if (MakeMove(currentPlayer, x, y) == 0)continue;
			count_moves++;

			getij(i, j, x, y);

			if (check_iswin(i, j, board))
			{
				highlightWinningSequence(i, j, board);
				sleepms(3000);
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
			currentPlayer = check_XO(first_player);
			drawTurnBox(TurnData[0], TurnData[1], TurnData[2], TurnData[3], currentPlayer, name1, name2);
			setPos(x, y);

		}
		else Movexy(x, y, type);
	}
	currentPlayer = check_XO(first_player);
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
	else if (type == -1)
	{
		system("cls");

	}
	sleepms(200);
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
	int x = xbegin;
	int y = ybegin;
	stopBackgroundMusic();
	playGameplayMusic();
	if (typegame == 0)
	{
		// new game
		//reset
		resetGameVariables();
	}

	system("cls");
	drawAiGamePlayScreen(currentPlayer, name1, name2, filename);
	char next_player = check_XO(first_player);
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

	setPos(x, y);
	HighlightPos(x, y, 1);
	int type = 0;
	currentPlayer = check_XO(first_player);
	while (true)
	{
		if (currentPlayer == player_O)
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

			}

			int row, col;
			getxy(row, col, ai_row, ai_col);
			HighlightPos(x, y, 0);
			x = row;
			y = col;
			type = 0;
			sleepms(10);
		}
		else
		{
			type = isNextMove();
			if (type == -1 || type == 5 || type == 6)break;
			if (type != 0)Movexy(x, y, type);
		}
		if (type != 0)continue;

		if (MakeMove(currentPlayer, x, y) == 0)continue;
		int i, j;
		count_moves++;
		getij(i, j, x, y);
		if (check_iswin(i, j, board))
		{
			highlightWinningSequence(i, j, board);
			sleepms(3000);
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
		currentPlayer = check_XO(first_player);
		drawTurnBox(TurnData[0], TurnData[1], TurnData[2], TurnData[3], currentPlayer, name1, name2);
		setPos(x, y);
	}
	currentPlayer = check_XO(first_player);
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
	sleepms(200);
	if (type == -1)AiControlGaming(1);
	else AiControlGaming(0);
	stopGameplayMusic();
	playBackgroundMusic();
	return;
}
// debug 2 AI chơi với nhau
//void AiGamePlay(int typegame)
//{
//	ShowConsoleCursor(true);
//	// Implementation for AI gameplay mode
//	system("cls");
//	int x = xbegin;
//	int y = ybegin;
//	stopBackgroundMusic();
//	playGameplayMusic();
//	if (typegame == 0)
//	{
//		// new game
//		//reset
//		resetGameVariables();
//	}
//
//	system("cls");
//	drawAiGamePlayScreen(currentPlayer, name1, name2, filename);
//	char next_player = check_XO(first_player);
//	drawTurnBox(TurnData[0], TurnData[1], TurnData[2], TurnData[3], next_player, name1, name2);
//
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			if (board[i][j] == '-')continue;
//			count_moves++;
//			int row, col;
//			getxy(row, col, i, j);
//			setPos(row, col);
//			cout << board[i][j];
//		}
//	}
//
//	setPos(x, y);
//	HighlightPos(x, y, 1);
//	int type = 0;
//	currentPlayer = check_XO(first_player);
//	while (true)
//	{
//		//thiết lập độ khó cho 2 AI
//		if (currentPlayer == player_X)difficulty = 2;
//			else difficulty = 2;	
//		//if(currentPlayer == player_O)
//		{
//			int ai_row, ai_col;
//			//if (currentPlayer == player_O) // AI's turn
//			{
//
//				// Choose the brain based on difficulty level
//				if (difficulty == 0) {
//					getEasyMove(board, ai_row, ai_col); // Easy Mode: Random
//				}
//				else if (difficulty == 1) {
//					getBestMove(board, ai_row, ai_col, currentPlayer); // Normal Mode: Heuristic/Greedy
//				}
//				else {
//					getSmartMove(board, ai_row, ai_col, currentPlayer); // Hard Mode: Minimax/Alpha-Beta
//				}
//
//			}
//
//			int row, col;
//			getxy(row, col, ai_row, ai_col);
//			HighlightPos(x, y, 0);
//			x = row;
//			y = col;
//			type = 0;
//			sleepms(10);
//		}
//		/*else
//		{
//			type = isNextMove();
//			if (type == -1 || type == 5 || type == 6)break;
//			if (type != 0)Movexy(x, y, type);
//		}*/
//		if (type != 0)continue;
//
//		if (MakeMove(currentPlayer, x, y) == 0)continue;
//		int i, j;
//		count_moves++;
//		getij(i, j, x, y);
//		if (check_iswin(i, j, board))
//		{
//			highlightWinningSequence(i, j, board);
//			sleepms(3000);
//			updateScore(currentPlayer);
//			system("cls");
//			drawWinStatus(currentPlayer, name1, name2);
//			stopGameplayMusic();
//			playWinSound();
//			typegame = false;
//			break;
//		}
//		else if (check_isdraw(count_moves))
//		{
//			system("cls");
//			drawDrawStatus();
//			stopGameplayMusic();
//			playDrawSound();
//			typegame = false;
//			break;
//		}
//		currentPlayer = check_XO(first_player);
//		drawTurnBox(TurnData[0], TurnData[1], TurnData[2], TurnData[3], currentPlayer, name1, name2);
//		setPos(x, y);
//	}
//	currentPlayer = check_XO(first_player);
//	if (type == 6)
//	{
//		loadGameScreen();
//		return;
//	}
//	else if (type == 5)
//	{
//		saveGameScreen();
//		return;
//	}
//	if (type == -1)
//	{
//		system("cls");
//
//	}
//	sleepms(200);
//	if (type == -1)AiControlGaming(1);
//	else AiControlGaming(0);
//	stopGameplayMusic();
//	playBackgroundMusic();
//	return;
//}
void runcaro()
{
	initializeBGM();
	// phát nhạc nền menu
   // 1. Khởi tạo và Cố định Cửa sổ
	fixConsoleWindow(ConsoleWidth, ConsoleHeight);
	// 2. Định nghĩa các biến cần thiết cho game
	char default_player = 'X';
	int choice;
	std::string load_filename;
	resetGameVariables();
	difficulty = 4;
	drawLoadingScreen();
	playBackgroundMusic();
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
		{
			// Call the mode selection menu
		modescreen:
			setColor(backgroundcolor, fontcolor);
			int mode = ControlGameMode();
			int canplay = 0;
			if (mode == 0) // PvP
			{
				srand((unsigned)time(NULL));
				canplay = drawNameScreen(name1, name2, mode);
				if (canplay == 1)
				{
					difficulty = 4;
					score_O = 0;
					score_X = 0;
					GamePlay(0);
				}
				else
					goto modescreen;
			}
			else if (mode == 1) // PvE Mode
			{
				srand((unsigned)time(NULL));
				canplay = drawNameScreen(name1, name2, mode);
				if (canplay == 1)
				{
					int diff = ControlDifficulty();
					// Nếu chọn Easy(0), Normal(1), hoặc Hard(2) thì vào game
					// Nếu chọn Back(3) thì không làm gì (tự quay lại vòng lặp menu)
					score_O = 0;
					score_X = 0;
					currentPlayer = first_player;
					if (diff != 3)
					{
						difficulty = diff;
						AiGamePlay(0);
					}
				}
				else
					goto modescreen;
			}
		}
		break;

		case 2: // load Files
			system("cls");
			loadGameMenu();
			break;

		case 3: // Settings
			// Vào màn hình Settings và điều khiển (ControlSettings trả về 0 khi nhấn BACK)
			ControlSettings();
			break;

		case 4: // About Us
			system("cls");
			displayHelp(createQAList(), 0);
			ControlHelp();
			break;

		case 5: // Exit
			// Thoát vòng lặp
			break;
		}
	} while (choice != 5);
	system("cls");
	setPos(0, 0);
	cout << "Exit Game. Goodbye!" << endl;
}