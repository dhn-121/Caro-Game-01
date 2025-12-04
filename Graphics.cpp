#include "Library.h"
using namespace std;

int ConsoleWidth = 130;
int ConsoleHeight = 35;

const int backgroundcolor = 15;
const int fontcolor = 0;

int Xi = 5;
int Yi = ConsoleHeight/2 - BoardRealHeight/2;

const int buttonWidth = 20;
const int buttonHeight = 3;

const int Selected_BG = 0;
const int Selected_FG = 15;

void setColor(int bgcolor, int fgcolor)
{
    HANDLE consoleHandler = GetStdHandle(STD_OUTPUT_HANDLE);
    int color = 16 * bgcolor + fgcolor;
    SetConsoleTextAttribute(consoleHandler, color);
}

void getConsoleSize(int& WIDTH, int& HEIGHT) {
    // HWND consoleWindow = GetConsoleWindow();
    HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD size = GetLargestConsoleWindowSize(Handle);

    WIDTH = size.X;
    HEIGHT = size.Y;
}
void fixConsoleWindow(int WIDTH, int HEIGHT)
{
    system("COLOR f0");
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    HWND consoleWindow = GetConsoleWindow();
    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
    DWORD currMode;
    // CONSOLE_FONT_INFOEX fontex;

    // Turn off maximize, resize, horizontal and vertical scrolling
    style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME) & ~(WS_HSCROLL) &
        ~(WS_VSCROLL);
    SetWindowLong(consoleWindow, GWL_STYLE, style);

    // Turn off mouse input
    GetConsoleMode(hOut, &currMode);
    SetConsoleMode(
        hOut,
        ((currMode | ENABLE_EXTENDED_FLAGS) & ~ENABLE_QUICK_EDIT_MODE &
            ~ENABLE_MOUSE_INPUT)
    );

    // Hide scoll bar
    ShowScrollBar(consoleWindow, SB_BOTH, FALSE);

    // Faster UI Update
    std::ios_base::sync_with_stdio(0);
    std::wcout.tie(0);
}


struct STATUS
{
    int Top_Left = 218;
    int Top_Right = 191;
    int Bot_Left = 192;
    int Bot_Right = 217;
    int Hori_Bar = 196;
    int Verti_Bar = 179;
    int Blank = 255;
} symbol;

void drawBox(int x, int y, int w, int h, std::string text)
{
    setPos(x, y);

    cout << char(symbol.Top_Left);
    for (int i = 0; i < w - 2; i++)
        cout << char(symbol.Hori_Bar);
    cout << char(symbol.Top_Right);

    for (int i = 1; i < h - 1; i++) //in các | ở giữa (không tính) 2 bên rìa
    {
        setPos(x, y + i);
        cout << char(symbol.Verti_Bar);
        setPos(x + w - 1, y + i);
        cout << char(symbol.Verti_Bar);
    }

    setPos(x, y + h - 1);
    cout << char(symbol.Bot_Left);
    for (int i = 0; i < w - 2; i++)
        cout << char(symbol.Hori_Bar);
    cout << char(symbol.Bot_Right);

    //Văn bản (nếu có văn bản thì nó sẽ được căn giữ cho đẹp)
    if (!text.empty())
    {
        int txtlength = text.length();
        int blank_width = w - 2; //phần trống theo chiều ngang
        int center = (blank_width - txtlength) / 2;
        int textX = x + 1 + center;

        int blank_height = h - 2; //phần trống theo chiều dọc
        int middle = (blank_height - 1) / 2;
        int textY = y + 1 + middle;

        setPos(textX, textY);
        cout << text;
    }
}

//==================== LOADING... =====================

void drawLoadingScreen()
{
    system("cls");

    std::string message1 = "CO SO LAP TRINH - HCMUS";
    std::string message2 = "GROUP 1 - 25CTT3";
    std::string message3 = "WELCOME TO OUR PROJECT";

    int message1_x = (ConsoleWidth - message1.length()) / 2;
    int message1_y = ConsoleHeight * 40/100;
    int message2_x = (ConsoleWidth - message2.length()) / 2;
    int message2_y = ConsoleHeight / 2;
    int message3_x = (ConsoleWidth - message3.length()) / 2;
    int message3_y = ConsoleHeight * 60/100;

    setPos(message1_x, message1_y);
    cout << message1;
    setPos(message2_x, message2_y);
    cout << message2;
    setPos(message3_x, message3_y);
    cout << message3;

    setColor(0, 15);
}

//==================== MÀN HÌNH CHÍNH ====================

int MenuButton[5];
int button_XX = ConsoleWidth/2 - buttonWidth/2;

void drawMenuScreen()
{
    setColor(backgroundcolor, fontcolor);

    DATA Title;
    Title.Width = 33 ;
    Title.Height = 6 ;
    Title.XX = ConsoleWidth/2 - Title.Width/2;
    Title.YY = 4;
    drawCARO(Title.XX, Title.YY);
    
    int Play_YY = Title.YY + Title.Height + 3;
    MenuButton[0] = Play_YY;
    int Load_YY = Play_YY + buttonHeight + 1;
    MenuButton[1] = Load_YY;
    int Setting_YY = Load_YY + buttonHeight + 1;
    MenuButton[2] = Setting_YY;
    int Help_YY = Setting_YY + buttonHeight + 1;
    MenuButton[3] = Help_YY;
    int Exit_YY = Help_YY + buttonHeight + 1;
    MenuButton[4] = Exit_YY;

    drawBox(button_XX, Play_YY, buttonWidth, buttonHeight, "PLAY GAME");
    drawBox(button_XX, Load_YY, buttonWidth, buttonHeight, "LOAD GAME");
    drawBox(button_XX, Setting_YY, buttonWidth, buttonHeight, "SETTING");
    drawBox(button_XX, Help_YY, buttonWidth, buttonHeight, "HELP");
    drawBox(button_XX, Exit_YY, buttonWidth, buttonHeight, "EXIT");
}

//Nếu được chọn thì ô chọn sẽ có màu đen chữ trắng
void drawIsSelected(int idx, bool isSelected)
{
    if (isSelected)
        setColor(Selected_BG, Selected_FG);
    else
        setColor(backgroundcolor, fontcolor);
    std::string content;

    int Y0 = MenuButton[idx];
    switch (idx)
    {
        case 0:
            content = "    PLAY GAME     ";
            break;
        case 1:
            content = "    LOAD GAME     ";
            break;
        case 2:
            content = "     SETTING      ";
            break;
        case 3:
            content = "       HELP       ";
            break;
        case 4:
            content = "       EXIT       ";
            break;
        default:
            setColor(15,0);
            return;
    }
    drawBox(button_XX, Y0, buttonWidth, buttonHeight, content);
    setColor(backgroundcolor, fontcolor);
}

int ControlMenu()
{
    int present_choice = 0; //Tại nút play

    drawIsSelected(present_choice, true);

    int key;
    while (true)
    {
        key = _getch();
        int past_choice = present_choice;
        if (key == 0 || key == 224)
        {
            key = _getch();
            switch (key)
            {
            case 72:
                key = 'W';
                break;
            case 80:
                key = 'S';
                break;
            default:
                continue;
            }
        }
        switch (toupper(key))
        {
        case 'W':
            present_choice = (present_choice - 1 + 5) % 5; //5 là số nút
            break;
        case 'S':
            present_choice = (present_choice + 1) % 5;
            break;
        case 13: //enter
            return present_choice + 1;
        default:
            continue;
        }
        if (present_choice != past_choice)
        {
            drawIsSelected(past_choice, false);
            drawIsSelected(present_choice, true);
        }
    }
}

//==================== MÀN HÌNH NHẬP TÊN ==========================
//dang duoc cap nhat...


//==================== MÀN HÌNH CHƠI (GamePlayScreen) ====================

void drawTurnBox(int XX, int YY, int Width, int Height, char player, char name1[], char name2[])
{
    setColor(backgroundcolor, fontcolor);
    drawBox(XX, YY, Width, Height, "");
    std::string title = "TURN";
    int title_length = title.length(); 

    setPos(XX + 1 + (Width - 2)/2 - title_length/2, YY + 1);
    cout << title;

    DATA Content;
    Content.Height = 6;
    Content.YY = Yi + 1 + 2;

    if (player == player_X)
    {
        Content.Width = 8;
        Content.XX = XX + 1 + Width/2 - Content.Width/2;
        drawX(Content.XX, Content.YY, 0);
    }
    else
    {
        Content.Width = 9;
        Content.XX = XX + 1 + Width/2 - Content.Width/2;
        drawO(Content.XX, Content.YY, 0);
    }
}

int score_X = 0;
int score_O = 0;

void drawScoreBox(int XX, int YY, int Width, int Height, char player)
{
    setColor(backgroundcolor, fontcolor);
    std::string title = "SCORE OF " + std::string(1, player);
    int title_length = title.length(); 
    setPos(XX + 1 + (Width - 2)/2 - title_length/2, YY + 1);
    cout << title;

    int current_score = (player == player_X) ? score_X : score_O;
    std::string score_content = std::to_string(current_score);
    int content_length = score_content.length();

    int contentY = YY + Height - 2;
    int contentX = XX + 1 + (Width - 2 - content_length)/2;

    //xoá dòng cũ
    setPos(XX + 1, contentY);
    cout << std::string(Width - 2, ' ');

    setPos(contentX, contentY);
    cout << score_content;
}

int TurnData[4] = {0};

void drawGamePlayScreen(char player, char name1[], char name2[], std::string filename)
{
    system("cls");
    setColor(backgroundcolor, fontcolor);

    DATA Board;
    Board.XX = Xi;
    Board.YY = Yi;
    setPos (Board.XX, Board.YY);
    DrawBoard();

    DATA Turn;
    Turn.Width = ConsoleWidth * 40/100;
    Turn.Height = ConsoleHeight * 25/100;
    Turn.YY = Board.YY;
    Turn.XX = ConsoleWidth - Turn.Width - Xi;
    drawTurnBox(Turn.XX, Turn.YY, Turn.Width, Turn.Height, player, name1, name2);

    TurnData[0] = Turn.XX;
    TurnData[1] = Turn.YY;
    TurnData[2] = Turn.Width;
    TurnData[3] = Turn.Height;

    DATA Score;
    Score.Width = Turn.Width/2;
    Score.Height = Turn.Height/2;
    Score.XX = Turn.XX;
    Score.YY = Turn.YY + Turn.Height + 1;

    //Hộp Score của X
    drawBox(Score.XX, Score.YY, Score.Width, Score.Height, "");
    drawScoreBox(Score.XX, Score.YY, Score.Width, Score.Height, player_X);
    
    //Hộp Score của O
    drawBox(Score.XX + Score.Width, Score.YY, Score.Width, Score.Height, "");
    drawScoreBox(Score.XX + Score.Width, Score.YY, Score.Width, Score.Height, player_O);

    int filelength = filename.length();
    int fileX = ConsoleWidth/2 - filelength/2;
    int fileY = ConsoleHeight - 2;
    setPos(fileX, fileY);
    cout << filename;
}

//Hiệu ứng thắng/thua/hoà

void drawWinStatus(char player, char name1[], char name2[])
{
        char name_player[50];
        int length = 0;
        
        DATA Status;
        Status.Height = 6;
        Status.YY = ConsoleHeight * 40 / 100;

        if (player == player_X)
        {
            Status.Width = 35;
            Status.XX = ConsoleWidth/2 - Status.Width/2;
            drawX_WIN(Status.XX, Status.YY);
            std::strcpy(name_player, name1);
            length = std::strlen(name1);
        }
        else if (player == player_O)
        {
            Status.Width = 36;
            Status.XX = ConsoleWidth/2 - Status.Width/2;
            drawO_WIN(Status.XX, Status.YY);
            std::strcpy(name_player, name2);
            length = std::strlen(name2);
        }

        setColor(backgroundcolor, fontcolor);
        setPos(ConsoleWidth / 2 - length / 2, Status.YY + Status.Height + 1);
        std::cout << name_player;

        int Again_X = ConsoleWidth/2 - (2*buttonWidth + 2)/2;
        int Again_Y = ConsoleHeight * 60/100;
        drawBox(Again_X, Again_Y, buttonWidth, buttonHeight, "AGAIN");

        int Exit_X = Again_X + buttonWidth + 2;
        int Exit_Y = Again_Y;
        drawBox(Exit_X, Exit_Y, buttonWidth, buttonHeight, "EXIT");
}

void drawDrawStatus()
{
        DATA Status;
        Status.Width = 34;
        Status.Height = 6;
        Status.XX = ConsoleWidth/2 - Status.Width/2;
        Status.YY = ConsoleHeight * 40/100;
        drawDRAW(Status.XX, Status.YY);

        std::string message = "You two are evenly matched!";
        int messageX = ConsoleWidth/2 - message.length()/2;
        int messageY = Status.YY + Status.Height + 2;
        setColor(backgroundcolor, fontcolor); // Đảm bảo màu sắc hiển thị đúng
        setPos(messageX, messageY);

        int Again_X = ConsoleWidth/2 - (2*buttonWidth + 2)/2;
        int Again_Y = ConsoleHeight * 60/100;
        drawBox(Again_X, Again_Y, buttonWidth, buttonHeight, "AGAIN");

        int Exit_X = Again_X + buttonWidth + 2;
        int Exit_Y = Again_Y;
        drawBox(Exit_X, Exit_Y, buttonWidth, buttonHeight, "EXIT");
}



// LOAD GAME SCREEN

// void drawLoadGameScreen()
// {
//     DATA Title;
//     Title.Height = 6;
//     Title.Width = 73;
//     Title.XX = ConsoleHeight/2 - Title.Width/2;
//     Title.YY = ConsoleHeight * 20/100;
//     drawLOAD_GAME(Title.XX, Title.YY);
// }

// VẼ SETTINGS GREEN

GameSettings Default_Set;

string getToggleStatus(bool isActive)
{
    return isActive ? "ON" : "OFF";
}

int SettingData[3][3];

void drawSettingsScreen()
{
    system("cls");
    setColor(backgroundcolor, fontcolor);
    
    DATA Title;
    Title.Width = 33 ;
    Title.Height = 6 ;
    Title.XX = ConsoleWidth/2 - Title.Width/2;
    Title.YY = 2;
    drawSETTING(Title.XX, Title.YY);

    //Vẽ khung bao quanh (cho no dep)
    DATA ToggleBox;
    ToggleBox.Height = 7;
    ToggleBox.Width = 30;
    ToggleBox.XX = ConsoleWidth/2 - ToggleBox.Width/2;
    ToggleBox.YY = Title.YY + Title.Height + 4;
    drawBox(ToggleBox.XX, ToggleBox.YY, ToggleBox.Width, ToggleBox.Height, "");

    std::string sfx = "SFX:          ";
    std::string music = "MUSIC:        ";

    int sfx_XX = ToggleBox.XX + 5;
    int sfx_YY = ToggleBox.YY + 2;
    setPos(sfx_XX, sfx_YY);
    cout << sfx;

    int status_XX = ToggleBox.XX + ToggleBox.Width - 8;
    setPos(status_XX, sfx_YY);
    cout << getToggleStatus(Default_Set.sfx_active);

    SettingData[0][0] = status_XX;
    SettingData[0][1] = sfx_YY;

    int music_XX = sfx_XX;
    int music_YY = sfx_YY + 2;
    setPos(music_XX, music_YY);
    cout << music;
    setPos(status_XX, music_YY);
    cout << getToggleStatus(Default_Set.music_active);

    SettingData[1][0] = SettingData[0][0];
    SettingData[1][1] = music_YY;

    int Back_XX = ConsoleWidth/2 - buttonWidth/2;
    int Back_YY = ToggleBox.YY + ToggleBox.Height + 2;
    drawBox(Back_XX, Back_YY, buttonWidth, buttonHeight, "       BACK       ");

    SettingData[2][0] = Back_XX;
    SettingData[2][1] = Back_YY;
}

void drawSettingsHighlight(int idx, bool isSelected)
{
    int current_BG = 15;
    int current_FG = 0;

    string content;

    if (isSelected)
    {
        current_BG = Selected_BG;
        current_FG = Selected_FG;
    }

    setColor(current_BG, current_FG);

    if (idx == 0)
    {
        setPos(SettingData[0][0], SettingData[0][1]);
        cout << getToggleStatus(Default_Set.sfx_active) << "   ";
    }
    else if (idx == 1)
    {
        setPos(SettingData[1][0], SettingData[1][1]);
        cout << getToggleStatus(Default_Set.music_active) << "   ";
    }
    else if (idx == 2)
    {
        drawBox(SettingData[2][0], SettingData[2][1], buttonWidth, buttonHeight, "       BACK       ");
    }
    setColor(backgroundcolor, fontcolor);
}

int ControlSettings()
{
    drawSettingsScreen();
    int present_choice = 0; // Bắt đầu ở SFX

    // Highlight lựa chọn ban đầu
    drawSettingsHighlight(present_choice, true);

    int key;
    while (true)
    {
        key = _getch();
        int past_choice = present_choice;

        // Xử lý phím điều hướng
        if (key == 0 || key == 224)
        {
            key = _getch();
            switch (key)
            {
            case 72: key = 'W'; break; // Lên
            case 80: key = 'S'; break; // Xuống
            default: continue;
            }
        }

        switch (toupper(key))
        {
        case 'W':
            present_choice = (present_choice - 1 + 3) % 3 ;
            break;
        case 'S':
            present_choice = (present_choice + 1) % 3; ;
            break;
        case 13: // Enter
            if (present_choice == 0)
            {
                Default_Set.sfx_active = !Default_Set.sfx_active;
                drawSettingsHighlight(present_choice, true);
            }
            else if (present_choice == 1)
            {
                Default_Set.music_active = !Default_Set.music_active;
                drawSettingsHighlight(present_choice, true);

            }
            else if (present_choice == 2) {
                // BACK
                return 0; // Trả về 0 để báo hiệu quay lại Menu chính
            }
            continue;
        default:
            continue;
        }

        if (present_choice != past_choice)
        {
            drawSettingsHighlight(past_choice, false); // Hủy chọn cái cũ
            drawSettingsHighlight(present_choice, true); // Chọn cái mới
        }
    }
}

//HELP SCREEN....

void drawHelpScreen()
{
    setColor(backgroundcolor, fontcolor);
    DATA Title;
    Title.Height = 6;
    Title.Width = 32;
    Title.XX = ConsoleWidth/2 - Title.Width/2;
    Title.YY = ConsoleHeight * 20/100;
    drawHELP(Title.XX, Title.YY);
}