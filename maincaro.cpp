#include"Library.h"
#include "board.cpp"
#include "Console.cpp"
#include "Graphics.cpp"
#include "TicTacToe.cpp"
#include "checkcaro.cpp"
using namespace std;

int main()
{
    fixConsoleWindow(ConsoleWidth, ConsoleHeight);

    char default_player = 'X';
    char name1[] = "Player 1 (X)";
    char name2[] = "Player 2 (O)";
    char min[] = "05";
    char sec[] = "00";
    std::string filename = "caro_save_01.txt";

    int choice;
    int x = xbegin;
    int y = ybegin;
    drawLoadingScreen();
    do
    {
        system("cls");
        drawMenuScreen();
        choice = ControlMenu();

        switch (choice) {
        case 1: // Play Game
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
                    MakeMove(player_main, x, y);
                    int i, j;
                    getij(i, j, x, y);
                    if (check_iswin(i, j, board))
                    {
                        system("cls");
                        setColor(0, 15);
                        cout << player_main << " " << "WIN" << '\n';
                        //return;
                        break;
                    }
                }
                else Movexy(x, y, type);
            }
            cin.ignore();
            choice = 0; // Exit 
            break;

        case 2: // Saved Files
            system("cls");
            setPos(Xi, Yi);
            cout << "Saved Files: Chuc nang dang phat trien...";
            cin.ignore();
            cin.get();
            break;

        case 3: // Settings
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
            break;
        }
    } while (choice != 5);

    system("cls");
    setPos(0, 0);
    cout << "Exit Game. Goodbye!" << endl;
    return 0;
}
