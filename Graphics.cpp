#include "Library.h"

using namespace std;

#define backgroundcolor 7 //màu nền xám nhẹ
#define fontcolor 0 //màu chữ đen

void setColor(int bgcolor, int fgcolor)
{
    HANDLE consoleHandler = GetStdHandle(STD_OUTPUT_HANDLE);
    int color = 16 * bgcolor + fgcolor;
    SetConsoleTextAttribute(consoleHandler, color);
}

// VẼ KHUNG //

struct STATUS 
{
    int Top_Left = 218;
    int Top_Right = 191;
    int Bot_Left = 192;
    int Bot_Right = 217;
    int Hori_Bar = 196;
    int Verti_Bar = 179;
    int Blank = 255;
    int Dot_Square = 176; //Để vẽ mấy cái nhạt nhạt
    int Bold_Dot_Square = 176; //Để vẽ mấy cái đậm đạm

} symbol;

void drawBox(int x, int y, int w, int h, string text)
{
    setPos(x, y);

    cout << char(symbol.Top_Left);
    for (int i = 0; i < w-2; i++)
        cout << char(symbol.Hori_Bar);
    cout << char(symbol.Top_Right);

    for (int i = 1; i < h-1; i++) //in các | ở giữa (không tính) 2 bên rìa
    {
        setPos(x, y+i);
        cout << char(symbol.Verti_Bar);
        setPos(x+w-1, y+i);
        cout << char(symbol.Verti_Bar);
    }

    setPos(x, y + h - 1);
    cout << char(symbol.Bot_Left);
    for (int i = 0; i < w-2; i++)
        cout << char(symbol.Hori_Bar);
    cout << char(symbol.Bot_Right);

    //Văn bản (nếu có văn bản thì nó sẽ được căn giữ cho đẹp)
    if (!text.empty())
    {
        int txtlength = text.length(); 
        int blank_width = w - 2; //phần trống theo chiều ngang
        int center = (blank_width - txtlength)/2;
        int textX = x + 1 + center;

        int blank_height = h - 2; //phần trống theo chiều dọc
        int middle = (blank_height - 1)/2;
        int textY = y + 1 +  middle;

        setPos(textX, textY);
        cout << text;
    }
}



void fixConsoleWindow(int WIDTH, int HEIGHT) {
    // Thường cần #include <windows.h> và #include <iostream> cho system()
    system("COLOR f0");
    HWND consoleWindow = GetConsoleWindow();

    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
    style = style & ~(WS_MAXIMIZEBOX | WS_THICKFRAME);
    SetWindowLong(consoleWindow, GWL_STYLE, style);

    SMALL_RECT r{};
    r.Top = r.Left = 0;
    r.Right = WIDTH - 1;
    r.Bottom = HEIGHT - 1;

    COORD NewSize{};
    NewSize.X = WIDTH;
    NewSize.Y = HEIGHT;

    HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);

    MoveWindow(consoleWindow, 248, 10, NewSize.X, NewSize.Y, TRUE);
    SetConsoleScreenBufferSize(Handle, NewSize);
    SetConsoleWindowInfo(Handle, TRUE, &r);
    ShowScrollBar(consoleWindow, SB_VERT, FALSE);
    ShowScrollBar(consoleWindow, SB_HORZ, FALSE);
}



//==================== Các thông số của bảng (đơn vị: ký tự) ====================

//Các thông số ô cờ được lấy từ board.cpp
#define CellWidth 8
#define CellHeight 3

//Kích thước thực của bảng cờ được tính theo dạng ký tự (BOARD_SIZE = 15, 16 là viền dọc, ngang )
const int BoardRealWidth = BOARD_SIZE * CellWidth + 16; 
const int BoardRealHeight = BOARD_SIZE * CellHeight + 16;

//Khoảng cách giữa viền bảng cờ và Console
const int paddingX = (ConsoleWidth - BoardRealWidth)/2;
const int paddingY = (ConsoleHeight - BoardRealHeight)/2;

// Toạ độ điểm neo được thay đổi thành chỗ bắt đầu vẽ bảng cờ 
const int Xi = paddingX;
const int Yi = paddingY;

//==================== LOADING... =====================

void drawLoadingScreen()
{
    system("cls");
    setColor(0, 15);

    string message = "It can takes some seconds";
    int message_x = (ConsoleWidth - message.length())/2;
    int message_y = ConsoleHeight/2;

    const int total_cycles = 5 * 5;

    for (int i = 0; i < total_cycles; i++)
    {
        setPos(message_x, message_y);
        cout << message;

        int num_dots = (i % 3) + 1;

        setPos(message_x + message.length(), message_y);
        string dots = "";

        for (int j = 0; j < num_dots; j++)
        {
            dots += ".";
        }
        cout << dots;

        if (num_dots == 1)
            cout << "  "; 
        else if (num_dots == 2)
            cout << " ";
        Sleep(100);
    }
    setColor(backgroundcolor,fontcolor);
}

//==================== MÀN HÌNH CHÍNH ====================

    /*
    Các đối tượng cơ bản:
    + Tiêu đề (theo tính toán có kích cỡ rơi vào khoảng cao 5 ký tự, dài 72 ký tự -> dài nhất trong số các đối tượng)
    + Các nút (cao 3 dài 20):
        - Play game
        - Saved Files
        - Settings
        - About Us
        - Exit
    Khoảng cách:
        - Giữa các nút là 1 ký tự
        - Giữa tiêu đề với nút là 2 ký tự
    Hướng làm: tôi sẽ nhóm các đối tượng lại thành một khối lớn để dễ căn chỉnh
    */

const  int Title_Width = 72;
const  int Title_Height = 5;
const  int Title_Box_Gap = 2; //

const  int MenuBox_Width = 20;
const  int MenuBox_Height = 3;
const  int MenuBox_Gap = 1;

const  int Group_Width = Title_Width;
const  int Group_Height = Title_Height + Title_Box_Gap + 5 * MenuBox_Height + 4 * MenuBox_Gap;

const int X_Start_Group = (ConsoleWidth - Group_Width)/2;
const int Y_Start_Group = (ConsoleHeight - Group_Height)/2;

const int X_Start_Box = X_Start_Group + (Group_Width - MenuBox_Width)/2;

const int MenuBoxNum = 5;
int Y_Start_MenuBox[MenuBoxNum];

void drawTitle()
{
    setColor(backgroundcolor, fontcolor);
    string title = "CARO GAME";
    setPos(X_Start_Group, Y_Start_Group);
    cout << title;
}

const int Y_Start_Play = Y_Start_Group + Title_Height + Title_Box_Gap;
void drawPlayBox()
{
    Y_Start_MenuBox[0] = Y_Start_Play;
    drawBox(X_Start_Box, Y_Start_Play, MenuBox_Width, MenuBox_Height, "Play Game");
}

const int Y_Start_Saved = Y_Start_Group + Title_Height + Title_Box_Gap + MenuBox_Height + MenuBox_Gap;
void drawSavedBox()
{
    Y_Start_MenuBox[1] = Y_Start_Saved;
    drawBox(X_Start_Box, Y_Start_Saved, MenuBox_Width, MenuBox_Height, "Saved File");
}

const int Y_Start_Settings = Y_Start_Group + Title_Height + Title_Box_Gap + 2 * MenuBox_Height + 2 * MenuBox_Gap;
void drawSettingsBox()
{
    Y_Start_MenuBox[2] = Y_Start_Settings;
    drawBox(X_Start_Box, Y_Start_Settings, MenuBox_Width, MenuBox_Height, "Settings");
}

const int Y_Start_About = Y_Start_Group + Title_Height + Title_Box_Gap + 3 * MenuBox_Height + 3 * MenuBox_Gap;
void drawAboutBox()
{
    Y_Start_MenuBox[3] = Y_Start_About;
    drawBox(X_Start_Box, Y_Start_About, MenuBox_Width, MenuBox_Height, "About Us");
}

const int Y_Start_Exit = Y_Start_Group + Title_Height + Title_Box_Gap + 4 * MenuBox_Height + 4 * MenuBox_Gap;
void drawExitBox()
{
    Y_Start_MenuBox[4] = Y_Start_Exit;
    drawBox(X_Start_Box, Y_Start_Exit, MenuBox_Width, MenuBox_Height, "Exit");
}

void drawMenuScreen()
{
    drawTitle();
    drawPlayBox();
    drawSavedBox();
    drawSettingsBox();
    drawAboutBox();
    drawExitBox();
    setColor(backgroundcolor, fontcolor);
}

const int Selected_BG = 8;
const int Selected_FG = 7;
const int Default_BG = backgroundcolor;
const int Default_FG = fontcolor;

//Nếu được chọn thì ô chọn sẽ có màu đen chữ trắng
void drawIsSelected(int idx, bool isSelected)
{
    if (isSelected)
        setColor(Selected_BG, Selected_FG);
    else
        setColor(Default_BG, Default_FG);
    string content;
    int Y0 = Y_Start_MenuBox[idx];
    switch (idx)
    {
        case 0: 
            content = "Play Game"; 
            break;
        case 1: 
            content = "Saved File"; 
            break;
        case 2: 
            content = "Settings"; 
            break;
        case 3: 
            content = "About Us"; 
            break;
        case 4: 
            content = "Exit"; 
            break;
        default: 
            setColor(Default_BG, Default_FG);
            return;
    }
    drawBox(X_Start_Box, Y0, MenuBox_Width, MenuBox_Height, content);
    setColor(Default_BG, Default_FG);
}

int ControlMenu()
{
    int present_choice = 0; //Tại nút play

    drawIsSelected(present_choice, true);

    int key;
    while(true)
    {
        key = _getch();
        int past_choice = present_choice;
        if (key == 0 || key == 224)
        {
            key = _getch();
            switch(key)
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
        switch(toupper(key))
        {
            case 'W': 
                present_choice = (present_choice - 1 + MenuBoxNum) % MenuBoxNum;
                break;
            case 'S': 
                present_choice = (present_choice + 1) % MenuBoxNum;
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

    /*
    Các đối tượng cơ bản:
    + Bảng cờ ở chính giữa
    + Bên trái bảng cờ: hộp Turn
    + Bên phải bảng cờ: hộp TimesSet
    + Phía trên bảng cờ lần lượt là: các nút Exit và Play Again (Tui tham khảo thấy hai nút này chỉ hiện lên khi trò chơi kết thúc)
    + Phía dưới bảng cò là tên file game đang chơi
    +––––––––––––––––––––––––––––––––––––––––––––––––+
    |           |  Exit  |    |  Again   |           |
    |                                                |
    |                +–––––––––––+                   |
    |   +––––––––+   |           |   +–––––––––+     |
    |   | Turn   |   |           |   |  Time.  |     |
    |   +––––––––+   |           |   +–––––––––+     |
    |                |           |                   |
    |                +–––––––––––+                   |
    |                file_name.txt                   |
    +––––––––––––––––––––––––––––––––––––––––––––––––+
    */

void drawCaroBoard()
{
    setColor(backgroundcolor, fontcolor);
    // setPos(Xi, Yi);
    DrawBoard();
}

const int buttonWidth = 20;
const int buttonHeight = 3;

bool isClickedButton(int xx, int yy, int X_start, int Y_start)
{
    int X_end = X_start + buttonWidth;
    int Y_end = Y_start + buttonHeight;
    if (xx >= X_start && xx <= X_end && yy >= Y_start && yy <= Y_end)
        return true;
    return false;
}

void drawExitButton()
{
    setColor(backgroundcolor, fontcolor);
    int X_start = Xi + (BoardRealWidth/2 - buttonWidth)/2 ;
    int Y_start = Yi - (paddingY + buttonHeight)/2;
    setPos(X_start, Y_start);
    drawBox(X_start, Y_start, buttonWidth, buttonHeight, "Exit");
}

void drawAgainButton()
{
    setColor(backgroundcolor, fontcolor);
    int X_start = Xi + BoardRealWidth/2 + (BoardRealWidth/2 - buttonWidth)/2;
    int Y_start = Yi - (paddingY + buttonHeight)/2;
    setPos(X_start, Y_start);
    drawBox(X_start, Y_start, buttonWidth, buttonHeight, "Play Again");
}

int checkClicked(int xx, int yy)
{
    const int Exit_X = Xi + (BoardRealWidth/2 - buttonWidth)/2;
    const int Exit_Y = Yi - (paddingY + buttonHeight)/2;
    const int Again_X = Xi + BoardRealWidth/2 + (BoardRealWidth/2 - buttonWidth)/2;
    const int Again_Y = Yi - (paddingY + buttonHeight)/2;
    if (isClickedButton(xx, yy, Exit_X, Exit_Y))
        return 6;
    else if (isClickedButton(xx, yy, Again_X, Again_Y))
        return 7;
    return 0;
}


const int boxWidth = 15;
const int boxHeight = 5;

void drawTurnBox(char player, char name1[], char name2[])
{
    setColor(backgroundcolor, fontcolor);
    int X_start = Xi - (paddingX + boxWidth)/2;
    int Y_start = Yi + (BoardRealHeight - boxHeight )/2;
    string name_player;
    player = check_XO();
    if (player == 'X')
        name_player = name1;
    else
        name_player = name2;
    string content = "Turn (" + std::string(1, player) + "): " + name_player;
    setPos(X_start, Y_start);
    drawBox(X_start, Y_start, boxWidth, boxHeight, content);
}

void drawTimeBox(char min[], char sec[])
{
    setColor(backgroundcolor, fontcolor);
    int X_start = Xi + BoardRealWidth + (paddingX - boxWidth)/2;
    int Y_start = Yi + (BoardRealHeight - boxHeight)/2;
    string content = "Time Set: " + string(min) + ":" + string(sec);
    setPos(X_start, Y_start);
    drawBox(X_start, Y_start, boxWidth, boxHeight, content);
}

void drawFilename(std::string filename)
{
    int length = filename.length();
    int X_start = Xi + ConsoleWidth/2 - length/2;
    int Y_start = Yi + BoardRealHeight + paddingY - 1;
    setPos(X_start, Y_start);
    cout << filename;
}

void drawGamePlayScreen(char player, char name1[], char name2[], char min[], char sec[], std::string filename)
{
    system("cls");
    setColor(backgroundcolor, fontcolor);
    drawCaroBoard();
    drawExitButton();
    drawAgainButton();
    drawTurnBox(player, name1, name2);
    drawTimeBox(min, sec);
    drawFilename(filename);
}

// SAVED GAME SCREEN
    //dang duoc cap nhat...

// VẼ SETTINGS GREEN
const int ToggleBox_Width = 30;
const int ToggleBox_Height = 7;
const int BackBox_Height = 3;
const int Toggle_Back_Gap = 3;

const int SettingsGroup_Height = Title_Height + Title_Box_Gap + ToggleBox_Height + Toggle_Back_Gap + BackBox_Height;
const int Y_Start_Settings_Group = (ConsoleHeight - SettingsGroup_Height) / 2;
const int X_Start_ToggleBox = (ConsoleWidth - ToggleBox_Width) / 2;

GameSettings Default_Set;

string getToggleStatus(bool isActive)
{
    return isActive ? "ON" : "OFF";
}

const int Content_X = X_Start_ToggleBox + 3;
const int SFX_Y = Y_Start_Settings_Group + Title_Height + Title_Box_Gap + 1;
const int MUSIC_Y = SFX_Y + 2;

 void drawSettingsTitle()
{
    string title = "SETTINGS";
    int TitleX = X_Start_Group + (Group_Width - 70)/2;
    setPos(TitleX, Y_Start_Settings_Group);
    cout << title;
}

void drawSettingsToggleBox()
{
    drawBox(X_Start_ToggleBox, Y_Start_Settings_Group + Title_Height + Title_Box_Gap, ToggleBox_Width, ToggleBox_Height, "");
    setColor(backgroundcolor, fontcolor);
    setPos(Content_X, SFX_Y);
    cout << "SFX:           ";

    setPos(Content_X + 15, SFX_Y);
    cout << getToggleStatus(Default_Set.sfx_active);

    setPos(Content_X, MUSIC_Y);
    cout << "MUSIC:         ";

    setPos(Content_X + 15, MUSIC_Y);
    cout << getToggleStatus(Default_Set.music_active);

    drawSettingsHighlight(0, false);
    drawSettingsHighlight(1, true);

    setColor(backgroundcolor, fontcolor);
}

const int BackY = Y_Start_Settings_Group + Title_Height + Title_Box_Gap + ToggleBox_Height + Toggle_Back_Gap;
void drawSettingsBackBox()
{
    drawBox(X_Start_Box, BackY, MenuBox_Width, BackBox_Height, "BACK");
}

void drawSettingsScreen()
{
    system("cls");
    setColor(backgroundcolor, fontcolor);
    drawSettingsTitle();
    drawSettingsToggleBox();
    drawSettingsBackBox();
}

const int STATUS_X = Content_X + 15;
void drawSettingsHighlight(int idx, bool isSelected)
{
    int current_BG = Default_BG;
    int current_FG = Default_FG;

    string content;

    if (isSelected)
    {
        current_BG = Selected_BG;
        current_FG = Selected_FG;
    }
    setColor(current_BG, current_FG);

    if (idx == 0)
    {
        setColor(Default_BG, Default_FG);
        setPos(Content_X, SFX_Y);
        cout << "SFX:           ";
        setColor(current_BG, current_FG);
        setPos(STATUS_X, SFX_Y);
        cout << getToggleStatus(Default_Set.sfx_active) << "   ";
    }
    else if (idx == 1)
    {
        setColor(Default_BG, Default_FG);
        setPos(Content_X, MUSIC_Y);
        cout << "MUSIC:           ";
        setColor(current_BG, current_FG);
        setPos(STATUS_X, MUSIC_Y);
        cout << getToggleStatus(Default_Set.music_active) << "   ";
    }
    else if (idx == 2)
    {
        setColor(current_BG, current_FG);
        drawBox(X_Start_Box, BackY, MenuBox_Width, BackBox_Height, "BACK");
    }
    setColor(Default_BG, Default_FG);
}

#define SettingsBoxNum 3

int ControlSettings()
{
    drawSettingsScreen();
    int present_choice = 0; // Bắt đầu ở SFX

    // Highlight lựa chọn ban đầu
    drawSettingsHighlight(present_choice, true);

    int key;
    while(true)
    {
        key = _getch();
        int past_choice = present_choice;
        
        // Xử lý phím điều hướng
        if (key == 0 || key == 224)
        {
            key = _getch();
            switch(key)
            {
                case 72: key = 'W'; break; // Lên
                case 80: key = 'S'; break; // Xuống
                default: continue;
            }
        }

        switch(toupper(key))
        {
            case 'W': 
                present_choice = (present_choice - 1 + SettingsBoxNum) % SettingsBoxNum; ;
                break;
            case 'S': 
                present_choice = (present_choice + 1) % SettingsBoxNum; ;
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

                } else if (present_choice == 2) {
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

//ABOUT US SCREEN....
    // dang duoc cap nhat...

//TEST

 //int main() 
 //{
 //    // 1. Khởi tạo và Cố định Cửa sổ
 //    fixConsoleWindow(ConsoleWidth, ConsoleHeight); 
 //   
 //    // 2. Định nghĩa các biến cần thiết cho game
 //    char default_player = 'X';
 //    char name1[] = "Player 1 (X)";
 //    char name2[] = "Player 2 (O)";
 //    char min[] = "05";
 //    char sec[] = "00";
 //    std::string filename = "caro_save_01.txt";

 //    int choice;
 //   
 //    // Vòng lặp chính của chương trình để quay lại Menu
 //    drawwLoadingScreen();
 //    do 
 //    {
 //        system("cls");
 //        drawMenuScreen();
 //        // Gọi hàm điều khiển Menu và lấy lựa chọn
 //        choice = ControlMenu();
 //       
 //        // 4. Xử lý lựa chọn
 //        switch (choice) {
 //            case 1: // Play Game
 //                // Chuyển sang màn hình chơi game
 //                drawGamePlayScreen(default_player, name1, name2, min, sec, filename);
 //                break;
 //               
 //            case 2: // Saved Files
 //                system("cls");
 //                setPos(Xi, Yi); 
 //                cout << "Saved Files: Chuc nang dang phat trien...";
 //                cin.ignore(); 
 //                cin.get();
 //                break;
 //               
 //            case 3: // Settings
 //                // Vào màn hình Settings và điều khiển (ControlSettings trả về 0 khi nhấn BACK)
 //                ControlSettings();
 //                break;
 //               
 //            case 4: // About Us
 //                system("cls");
 //                setPos(Xi, Yi); 
 //                cout << "About Us: Chuc nang dang phat trien...";
 //                cin.ignore(); 
 //                cin.get();
 //                break;

 //            case 5: // Exit
 //                // Thoát vòng lặp
 //                break;
 //        }
 //    } while (choice != 5); 

 //    system("cls");
 //    setPos(0, 0);
 //    cout << "Exit Game. Goodbye!" << endl;
 //    return 0;
 //}



//}


