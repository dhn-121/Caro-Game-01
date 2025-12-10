#include "Library.h"
using namespace std;

int ConsoleWidth = 120;
int ConsoleHeight = 35;

const int backgroundcolor = 15;
const int fontcolor = 0;

int Xi = 5;
int Yi = ConsoleHeight/2 - BoardRealHeight/2-2;

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
    HWND consoleWindow = GetConsoleWindow();
    HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD size = GetLargestConsoleWindowSize(Handle);
    WIDTH = size.X;
    HEIGHT = size.Y;
}

// Function to show or hide the console cursor
void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);

    cursorInfo.bVisible = showFlag; // Visible or Hidden

    cursorInfo.dwSize = 20;

    SetConsoleCursorInfo(out, &cursorInfo);
}

void fixConsoleWindow(int WIDTH, int HEIGHT)
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    // BƯỚC 1: ĐẶT KÍCH THƯỚC BUFFER (Bộ đệm)
    COORD bufferSize = { (SHORT)WIDTH, (SHORT)HEIGHT };
    // Lỗi thường xảy ra nếu hàm này được gọi sau khi đặt kích thước cửa sổ
    SetConsoleScreenBufferSize(hOut, bufferSize);

    // BƯỚC 2: ĐẶT KÍCH THƯỚC CỬA SỔ (Viewport)
    SMALL_RECT windowSize = { 0, 0, (SHORT)(WIDTH - 1), (SHORT)(HEIGHT - 1) };
    SetConsoleWindowInfo(hOut, TRUE, &windowSize);

    // ----------------------------------------------------
    // CÁC THIẾT LẬP KHÁC (Giữ nguyên)
    // ----------------------------------------------------

    // Đặt Tiêu đề Console
    SetConsoleTitle(TEXT("Tên Ứng Dụng Của Bạn"));

    // Đặt màu nền và chữ
    system("COLOR F0");

    HWND consoleWindow = GetConsoleWindow();
    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
    DWORD currMode;

    // Tắt maximize, resize, thanh cuộn
    style &= ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME) & ~(WS_HSCROLL) & ~(WS_VSCROLL);
    SetWindowLong(consoleWindow, GWL_STYLE, style);

    // Tắt input chuột (chế độ Quick Edit)
    GetConsoleMode(hOut, &currMode);
    SetConsoleMode(
        hOut,
        ((currMode | ENABLE_EXTENDED_FLAGS) & ~ENABLE_QUICK_EDIT_MODE &
            ~ENABLE_MOUSE_INPUT)
    );

    // Ẩn thanh cuộn
    ShowScrollBar(consoleWindow, SB_BOTH, FALSE);
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
    Title.YY = 2;
    drawCARO(Title.XX, Title.YY);
    
    int Play_YY = Title.YY + Title.Height + 2;
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
    drawDino(15, ConsoleHeight - 25);
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
    ShowConsoleCursor(false);
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
                playMoveSound();
                break;
            case 80:
                key = 'S';
                playMoveSound();
                break;
            default:
                continue;
            }
        }
        switch (toupper(key))
        {
        case 'W':
            present_choice = (present_choice - 1 + 5) % 5;
            playMoveSound(); //5 là số nút
            break;
        case 'S':
            present_choice = (present_choice + 1) % 5;
            playMoveSound();
            break;
        case 13: //enter
            playClickSound();
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

void drawTurnBox(int XX, int YY, int Width, int Height, char player, std::string name1, std::string name2)
{
    setColor(backgroundcolor, fontcolor);
    drawBox(XX, YY, Width, Height, "");
    std::string title = "TURN";
    int title_length = title.length();

    setPos(XX + 1 + (Width - 2) / 2 - title_length / 2, YY + 1);
    cout << title;

    DATA Content;
    Content.Height = 6;
    Content.YY = YY + Height / 2 - Content.Height / 2 + 1;

    int clear_XX = XX + 1 + Width / 2 - 9 / 2;
    int clear_Width = 9;

    setPos(clear_XX, Content.YY);
    for (int i = 0; i <= Content.Height; i++)
    {
        for (int j = 0; j <= (clear_Width); j++)
            cout << " ";
        setPos(clear_XX, Content.YY + i);
    }

    if (player == player_X)
    {
        Content.Width = 8;
        Content.XX = XX + 1 + Width / 2 - Content.Width / 2;
        drawX(Content.XX, Content.YY, 0);
    }
    else
    {
        Content.Width = 9;
        Content.XX = XX + 1 + Width / 2 - Content.Width / 2;
        drawO(Content.XX, Content.YY, 0);
    }
}

int score_X = 0;
int score_O = 0;

void drawScoreBox(int XX, int YY, int Width, int Height)
{
    std::string titleX = "SCORE OF X";
    std::string scoreX_str = std::to_string(score_X);

    std::string titleO = "SCORE OF O";
    std::string scoreO_str = std::to_string(score_O);

    // ===== TÍNH VỊ TRÍ CĂN GIỮA =====
    int titleX_x = XX + 1 + (Width - 2 - titleX.length()) / 2;
    int scoreX_x = XX + 1 + (Width - 2 - scoreX_str.length()) / 2;

    int titleO_x = XX + 1 + (Width - 2 - titleO.length()) / 2;
    int scoreO_x = XX + 1 + (Width - 2 - scoreO_str.length()) / 2;

    // ===== VỊ TRÍ Y =====
    int y_titleX = YY + 2;
    int y_scoreX = y_titleX + 1;

    int y_titleO = YY + Height - 4;
    int y_scoreO = y_titleO + 1;

    // ===== IN NỘI DUNG =====
    setPos(titleX_x, y_titleX);
    cout << titleX;

    setPos(scoreX_x, y_scoreX);
    cout << scoreX_str;

    setPos(titleO_x, y_titleO);
    cout << titleO;

    setPos(scoreO_x, y_scoreO);
    cout << scoreO_str;
}


int TurnData[4] = { 0 };

void drawGamePlayScreen(char player, std::string name1, std::string name2, std::string filename)
{
    system("cls");
    setColor(backgroundcolor, fontcolor);

    DATA Board;
    Board.XX = Xi;
    Board.YY = Yi;
    setPos(Board.XX, Board.YY);
    DrawBoard();

    DATA Turn;
    Turn.Width = ConsoleWidth * 20 / 100;
    Turn.Height = ConsoleHeight * 35 / 100;
    Turn.YY = Board.YY;
    Turn.XX = Board.XX + BoardRealWidth + 4;
    drawTurnBox(Turn.XX, Turn.YY, Turn.Width, Turn.Height, player, name1, name2);

    TurnData[0] = Turn.XX;
    TurnData[1] = Turn.YY;
    TurnData[2] = Turn.Width;
    TurnData[3] = Turn.Height;

    DATA Score;
    Score.Width = Turn.Width;
    Score.Height = Turn.Height;
    Score.XX = Turn.XX + Turn.Width + 2;
    Score.YY = Turn.YY;

    //Hộp Score
    drawBox(Score.XX, Score.YY, Score.Width, Score.Height, "");
    drawScoreBox(Score.XX, Score.YY, Score.Width, Score.Height);

    int filelength = filename.length();
    int fileX = ConsoleWidth / 2 - filelength / 2;
    int fileY = ConsoleHeight - 2;
    setPos(fileX, fileY);
    cout << filename;
}

//Hiệu ứng thắng/thua/hoà

// Hàm cập nhật điểm
void updateScore(char winner) {
    if (winner == 'X') {
        score_X++;
    }
    else if (winner == 'O') {
        score_O++;
    }
}

// Hàm reset điểm (nếu cần)
void resetScores() {
    score_X = 0;
    score_O = 0;
}

void drawWinStatus(char player, std::string name1, std::string name2)
{
	setColor(backgroundcolor, fontcolor);
    char name_player[50];
    int length = 0;

    DATA Status;
    Status.Height = 6;
    Status.YY = 4;

    if (player == player_X)
    {
        Status.Width = 35;
        Status.XX = ConsoleWidth / 2 - Status.Width / 2;
        drawX_WIN(Status.XX, Status.YY);
        strcpy(name_player, name1.c_str());
        length = strlen(name1.c_str());
    }
    else if (player == player_O)
    {
        Status.Width = 36;
        Status.XX = ConsoleWidth / 2 - Status.Width / 2;
        drawO_WIN(Status.XX, Status.YY);
        strcpy(name_player, name2.c_str());
        length = strlen(name2.c_str());
    }

    setColor(backgroundcolor, fontcolor);
    setPos(ConsoleWidth / 2 - length / 2, Status.YY + Status.Height + 1);
    cout << name_player;

    // Hiển thị điểm
    std::string score_display = "Score: " + std::to_string(score_X) + " - " + std::to_string(score_O);
    int score_length = score_display.length();
    setPos(ConsoleWidth / 2 - score_length / 2, Status.YY + Status.Height + 3);
    cout << score_display;
}

void drawDrawStatus()
{
    DATA Status;
    Status.Width = 34;
    Status.Height = 6;
    Status.XX = ConsoleWidth / 2 - Status.Width / 2;
    Status.YY = 4;
    drawDRAW(Status.XX, Status.YY);

    std::string message = "You two are evenly matched!";
    int messageX = ConsoleWidth / 2 - message.length() / 2;
    int messageY = Status.YY + Status.Height + 2;
    setColor(backgroundcolor, fontcolor);
    setPos(messageX, messageY);
    cout << message;

    // Hiển thị điểm
    std::string score_display = "Score: " + std::to_string(score_X) + " - " + std::to_string(score_O);
    int score_length = score_display.length();
    setPos(ConsoleWidth / 2 - score_length / 2, messageY + 2);
    cout << score_display;
}

bool isGameSelected(int idx, bool isSelected,int type)
{
    if (isSelected)
        setColor(Selected_BG, Selected_FG);
    else
        setColor(backgroundcolor, fontcolor);
    std::string content;

    // Tính toán vị trí để căn giữa 3 nút
    // 3 nút * 20 chiều rộng + 2 khoảng cách * 2 ký tự
    int totalWidth = 3 * buttonWidth + 4;
    int startX = ConsoleWidth / 2 - totalWidth / 2;
    int button_Y = ConsoleHeight * 60 / 100;

    int button_X = 0;
    switch (idx)
    {
    case 0:
        content = "    CONTINUE      "; // Giữ điểm, Bàn cờ cũ
        button_X = startX;
        break;
    case 1:
        if(type==1)
            content = "   PLAY AGAIN     "; // Reset điểm, Bàn cờ mới
		else
		    content = "   RESET SCORE    ";
        button_X = startX + buttonWidth + 2;
        break;
    case 2:
        content = "       HOME       "; // Reset điểm, Về Menu
        button_X = startX + 2 * buttonWidth + 4;
        break;
    default:
        setColor(15, 0);
    }
    drawBox(button_X, button_Y, buttonWidth, buttonHeight, content);
    setColor(backgroundcolor, fontcolor);
    return true;
}

// 2. Điều khiển màn hình kết thúc PvP (3 Nút)

int ControlGaming(int type)
{
    ShowConsoleCursor(false);
    // ... (Giữ nguyên phần vẽ tiêu đề Win/Lose/Draw ở trên) ...

    int present_choice = 0; // Mặc định chọn CONTINUE
    // Vẽ 3 nút
    for (int i = 0; i < 3; i++) {
        isGameSelected(i, (i == present_choice),type);
    }

    int key;
    while (true)
    {
        key = _getch();
        int past_choice = present_choice;

        if (key == 0 || key == 224) {
            key = _getch();
            switch (key) {
            case 75: // Trái
                present_choice = (present_choice - 1 + 3) % 3; // Modulo 3 cho 3 nút
                playMoveSound();
                break;
            case 77: // Phải
                present_choice = (present_choice + 1) % 3;
                playMoveSound();
                break;
            }
        }
        else {
            switch (toupper(key)) {
            case 'A':
                present_choice = (present_choice - 1 + 3) % 3;
                playMoveSound();
                break;
            case 'D':
                present_choice = (present_choice + 1) % 3;
                playMoveSound();
                break;
            case 13: // Enter
                playClickSound();
                if (present_choice == 0) // === CONTINUE ===
                {
                    // Ván đã kết thúc -> Tạo ván mới 
                    // KHÔNG reset điểm
					drawContinueGameScreen(type);
                    return 1;
                }
                else if (present_choice == 1) // === PLAY AGAIN ===
                {
                    resetScores(); // Reset điểm
                    // Tạo ván mới
                    /*GamePlay(Default_Set.sfx_active ? player_X : player_O,
                        "Player 1 (X)", "Player 2 (O)",
                        "caro_save_01.txt", 0);*/
					currentPlayer = player_X;
					name1= "Player 1 (X)";
					name2= "Player 2 (O)";
					filename = "caro_save_01.txt";
					GamePlay(0);
                    return 1;
                }
                else if (present_choice == 2) // === HOME ===
                {
                    resetScores(); // Reset điểm
                    return 0;      // Về menu
                }
                break;
            case 27: // ESC -> Về Home
                resetScores();
                playClickSound();
                return 0;
            default: continue;
            }
        }

        if (present_choice != past_choice) {
            isGameSelected(past_choice, false,type);
            isGameSelected(present_choice, true,type);
        }
    }
}

// 3. Điều khiển màn hình kết thúc AI (PvE) (3 Nút)
int AiControlGaming(int type)
{
    ShowConsoleCursor(false);
    // ... (Giữ nguyên phần vẽ tiêu đề Win/Lose/Draw ở trên) ...

    int present_choice = 0;
    // Vẽ 3 nút
    for (int i = 0; i < 3; i++) {
        isGameSelected(i, (i == present_choice),type);
    }

    int key;
    while (true) {
        key = _getch();
        int past_choice = present_choice;

        if (key == 0 || key == 224) {
            key = _getch();
            switch (key) {
            case 75:
                present_choice = (present_choice - 1 + 3) % 3;
                playMoveSound();
                break;
            case 77:
                present_choice = (present_choice + 1) % 3;
                playMoveSound();
                break;
            }
        }
        else {
            switch (toupper(key)) {
            case 'A':
                present_choice = (present_choice - 1 + 3) % 3;
                playMoveSound();
                break;
            case 'D':
                present_choice = (present_choice + 1) % 3;
                playMoveSound();
                break;
            case 13: // Enter
                playClickSound();
                if (present_choice == 0) // === CONTINUE ===
                {
                    // Ván kết thúc -> Bàn cờ mới, GIỮ điểm
                    drawContinueGameScreen(type);
                    return 1;
                }
                else if (present_choice == 1) // === PLAY AGAIN ===
                {
                    resetScores(); // Reset điểm
                    // Bàn cờ mới
					name1 = "Player 1 (X)";
					name2 = "AI (O)";
					filename = "caro_save_ai.txt";
					currentPlayer = player_X;
					AiGamePlay(0);
                    return 1;
                }
                else if (present_choice == 2) // === HOME ===
                {
                    resetScores(); // Reset điểm
                    return 0;      // Về menu
                }
                break;
            case 27: // ESC
                resetScores();
                playClickSound();
                return 0;
            default: continue;
            }
        }
        if (present_choice != past_choice) {
            isGameSelected(past_choice, false,type);
            isGameSelected(present_choice, true,type);
        }
    }
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
    ShowConsoleCursor(false);
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
            case 72: 
                key = 'W'; 
                playMoveSound();
                break; // Lên
            case 80: 
                key = 'S';
                playMoveSound();
                break; // Xuống
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
            playClickSound();
            if (present_choice == 0)
            {
                Default_Set.sfx_active = !Default_Set.sfx_active;
                drawSettingsHighlight(present_choice, true);
                setSFX(Default_Set.sfx_active);
            }
            else if (present_choice == 1)
            {
                Default_Set.music_active = !Default_Set.music_active;
                drawSettingsHighlight(present_choice, true);
                setMusic(Default_Set.music_active);

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

// Function to draw the game mode selection menu
// choice = 0 (PvP), 1 (PvE), 2 (Back)
void drawGameModeScreen(int choice)
{
    system("cls"); // Clear the console screen
    setColor(backgroundcolor, fontcolor);

    // Draw the title
    std::string title = "SELECT GAME MODE";
    int titleX = (ConsoleWidth - title.length()) / 2;
    int titleY = ConsoleHeight * 30 / 100; // Position 30% down from the top
    setPos(titleX, titleY);
    std::cout << title;

    int boxW = 20; // Button width
    int boxH = 3;  // Button height
    int startX = (ConsoleWidth - boxW) / 2;
    int startY = titleY + 3;

    // List of mode buttons
    std::string modes[] = { "     PvP MODE     ", "     PvE MODE     ", "       BACK       " };

    for (int i = 0; i < 3; i++)
    {
        int currentY = startY + i * (boxH + 1); // Calculate Y position for each button

        // Highlight the selected button (Black background, white foreground)
        if (i == choice)
            setColor(Selected_BG, Selected_FG);
        else
            setColor(backgroundcolor, fontcolor);

        drawBox(startX, currentY, boxW, boxH, modes[i]);
    }

    // Restore default colors
    setColor(backgroundcolor, fontcolor);
}

// Function to control the game mode selection menu logic
int ControlGameMode()
{
    ShowConsoleCursor(false);
    int choice = 0; // Default selection is the first button (PvP)
    drawGameModeScreen(choice); // Initial drawing

    int key;
    while (true)
    {
        key = _getch(); // Get user input (key press)
        int old_choice = choice; // Store old choice for comparison

        // Handle arrow keys (Up/Down) or W/S
        if (key == 0 || key == 224)
        {
            key = _getch();
            switch (key)
            {
            case 72: // Up arrow
                choice--;
                playMoveSound();
                break;
            case 80: // Down arrow
                choice++;
                playMoveSound();
                break;
            }
        }
        else
        {
            switch (toupper(key))
            {
            case 'W':
                choice--;
                playMoveSound();
                break;
            case 'S':
                choice++;
                playMoveSound();
                break;
            case 13: // ENTER key -> Confirm selection
                playClickSound();
                return choice; // Returns 0 (PvP), 1 (PvE), or 2 (Back)
            case 27: // ESC key -> Treat as Back
                return 2;
            }
        }

        // Wrap around logic (if moving up from 0, go to 2; if moving down from 2, go to 0)
        if (choice < 0) choice = 2;
        if (choice > 2) choice = 0;

        // If selection changed, redraw the menu to update highlights
        if (choice != old_choice)
        {
            drawGameModeScreen(choice);
        }
    }
}

void drawDifficultyScreen(int selection)
{
    system("cls"); // Clear screen
    setColor(backgroundcolor, fontcolor);
    // 1. Draw Title
    std::string title = "SELECT DIFFICULTY LEVEL";
    int titleX = (ConsoleWidth - title.length()) / 2;
    int titleY = ConsoleHeight * 25 / 100; // 25% from top
    setPos(titleX, titleY);
    std::cout << title;

    // 2. Setup Buttons
    int boxW = 24; // Width of the button
    int boxH = 3;  // Height of the button
    int startX = (ConsoleWidth - boxW) / 2;
    int startY = titleY + 3;

    // Labels for buttons
    std::string levels[] = {
        "        EASY        ",//(RANDOM)
        "       NORMAL       ",//(BASIC)
        "        HARD        ",//(STRATEGY)
        "      << BACK       "
    };

    // 3. Draw Buttons
    for (int i = 0; i < 4; i++)
    {
        int currentY = startY + i * (boxH + 1); // Calculate Y for each button

        // Highlight the selected button
        if (i == selection)
            setColor(Selected_BG, Selected_FG);
        else
            setColor(backgroundcolor, fontcolor);

        drawBox(startX, currentY, boxW, boxH, levels[i]);
    }

    // Reset color
    setColor(backgroundcolor, fontcolor);
}

// Function to control Difficulty Selection
// Returns: 0=Easy, 1=Normal, 2=Hard, 3=Back
int ControlDifficulty()
{
    ShowConsoleCursor(false); // Hide cursor for better UI look
    int selection = 0;
    drawDifficultyScreen(selection);

    int key;
    while (true)
    {
        key = _getch();
        int old_selection = selection;

        // Handle Arrow Keys or W/S
        if (key == 0 || key == 224)
        {
            key = _getch();
            switch (key)
            {
            case 72: // Up
                selection--;
                playMoveSound();
                break;
            case 80: // Down
                selection++;
                playMoveSound();
                break;
            }
        }
        else
        {
            switch (toupper(key))
            {
            case 'W':
                selection--;
                playMoveSound();
                break;
            case 'S':
                selection++;
                playMoveSound();
                break;
            case 13: // Enter
                playClickSound();
                return selection;
            case 27: // Esc -> Back
                return 3;
            }
        }

        // Loop selection (0 -> 3 -> 0)
        if (selection < 0) selection = 3;
        if (selection > 3) selection = 0;

        // Redraw only if selection changed
        if (selection != old_selection)
        {
            drawDifficultyScreen(selection);
        }
    }
}

char getCharAtCursor(int x, int y) {
    char c = ' ';
    DWORD num_read;
    COORD pos = { (SHORT)x, (SHORT)y };
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    ReadConsoleOutputCharacter(hConsole, (LPTSTR)&c, 1, pos, &num_read);
    return c;
}

void HighlightPos(int x, int y, int mode) {
    if (mode == 1) {
        // Nền Trắng (15) - Chữ Đỏ (12)
        setColor(15, 12);
    }
    else if(mode == 2) {
        // Nền Đỏ (12) - Chữ Trắng (15)
        setColor(12, 15);
        cout << getCharAtCursor(x, y);
    }
    else {
        setColor(15, 0);
        setPos(x, y);
        cout << getCharAtCursor(x, y);
    }

    // Trả lại màu mặc định cho hệ thống
    setColor(backgroundcolor, fontcolor);
    setPos(x, y);
}

void highlightWinningSequence(int x, int y, char a[15][15])
{
    char cur = a[x][y];
    if (cur == '-') return;

    // Mảng 2 chiều các hướng đi
    int dmove[4][2] = { {0,1}, {1,0}, {1,1}, {1,-1} };

    for (int k = 0; k < 4; k++)
    {
        // Truy cập phần tử bằng chỉ số k
        int dx = dmove[k][0];
        int dy = dmove[k][1];

        int count = 1;
        std::vector<std::pair<int, int>> winningPositions;
        winningPositions.push_back(std::make_pair(x, y));

        // Duyệt hướng dương
        for (int step = 1; step < 5; step++)
        {
            int nx = x + dx * step;
            int ny = y + dy * step;
            if (nx >= 0 && nx < BOARD_SIZE && ny >= 0 && ny < BOARD_SIZE && a[nx][ny] == cur)
            {
                count++;
                winningPositions.push_back(std::make_pair(nx, ny));
            }
            else break;
        }

        // Duyệt hướng âm
        for (int step = 1; step < 5; step++)
        {
            int nx = x - dx * step;
            int ny = y - dy * step;
            if (nx >= 0 && nx < BOARD_SIZE && ny >= 0 && ny < BOARD_SIZE && a[nx][ny] == cur)
            {
                count++;
                winningPositions.push_back(std::make_pair(nx, ny));
            }
            else break;
        }

        // Nếu đủ 5 quân thì tô màu
        if (count >= 5)
        {
            for (size_t p = 0; p < winningPositions.size(); p++)
            {
                std::pair<int, int> pos = winningPositions[p];

                int row, col;
                getxy(row, col, pos.first, pos.second);
                setPos(row, col);

                // Tô màu: Nền Đỏ (4), Chữ Trắng (15)
                setColor(15, 12);
                std::cout << cur;
            }
            // Trả lại màu mặc định sau khi tô xong
            setColor(backgroundcolor, fontcolor);
            return;
        }
    }
}