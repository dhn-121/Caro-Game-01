#include "Library.h"
#include "help.h"
using namespace std;

vector<QAPair> createQAList() {
    vector<QAPair> qaList = {
        { T("HELP_Q1"), T("HELP_A1") },
        { T("HELP_Q2"), T("HELP_A2") },
        { T("HELP_Q3"), T("HELP_A3") },
        { T("HELP_Q4"), T("HELP_A4") },
        { T("HELP_Q5"), T("HELP_A5") }
    };
    return qaList;
}
struct STATUS
{
    const char* Top_Left = u8"\u250C"; // ┌
    const char* Top_Right = u8"\u2510"; // ┐
    const char* Bot_Left = u8"\u2514"; // └
    const char* Bot_Right = u8"\u2518"; // ┘
    const char* Hori_Bar = u8"\u2500"; // ─
    const char* Verti_Bar = u8"\u2502"; // │
} sym;
// Hàm vẽ khung chỉ viền, không tô màu (Dùng ký tự ASCII mở rộng - CP437)
void drawBorderOnly(int x, int y, int width, int height) {
    // Vẽ góc trên bên trái
    setPos(x, y);
    cout << sym.Top_Left; // ┌

    // Vẽ đường ngang trên
    for (int i = 1; i < width - 1; i++) {
        setPos(x + i, y);
        cout << sym.Hori_Bar; // ─
    }

    // Vẽ góc trên bên phải
    setPos(x + width - 1, y);
    cout << sym.Top_Right; // ┐

    // Vẽ hai đường dọc
    for (int i = 1; i < height - 1; i++) {
        setPos(x, y + i);
        cout << sym.Verti_Bar; // │
        setPos(x + width - 1, y + i);
        cout << sym.Verti_Bar; // │
    }

    // Vẽ góc dưới bên trái
    setPos(x, y + height - 1);
    cout << sym.Bot_Left; // └

    // Vẽ đường ngang dưới
    for (int i = 1; i < width - 1; i++) {
        setPos(x + i, y + height - 1);
        cout << sym.Hori_Bar; // ─
    }

    // Vẽ góc dưới bên phải
    setPos(x + width - 1, y + height - 1);
    cout << sym.Bot_Right; // ┘
}

// Hàm cắt chuỗi an toàn
string safeTruncate(const string& str, int maxWidth) {
    if (maxWidth <= 0) return "";
    if (str.length() <= maxWidth) return str;
    return str.substr(0, maxWidth);
}
vector<string> wrapText(const string& text, int maxWidth)
{
    vector<string> lines;
    string current;

    for (char c : text) {
        if (c == '\n') {
            lines.push_back(current);
            current.clear();
            continue;
        }

        current += c;

        if ((int)current.length() >= maxWidth) {
            size_t lastSpace = current.find_last_of(' ');
            if (lastSpace != string::npos && lastSpace > maxWidth / 2) {
                lines.push_back(current.substr(0, lastSpace));
                current = current.substr(lastSpace + 1);
            }
            else {
                lines.push_back(current.substr(0, maxWidth));
                current = current.substr(maxWidth);
            }
        }
    }

    if (!current.empty())
        lines.push_back(current);

    return lines;
}

void clearLine(int x, int y, int width) {
    setPos(x, y);
    cout << string(width, ' ');
}

void displayHelp(const vector<QAPair>& qaList, int selectedIndex)
{
    if (qaList.empty() || selectedIndex < 0 || selectedIndex >= qaList.size())
        return;

    drawHelpScreen();

    int consoleW = ConsoleWidth > 0 ? ConsoleWidth : 120;
    int consoleH = ConsoleHeight > 0 ? ConsoleHeight : 35;

    // ===== HEADER =====
    int helpWidth = 32;
    int helpHeight = 6;
    int helpX = consoleW / 2 - helpWidth / 2;
    int helpY = 2;

    int boxStartY = helpY + helpHeight+1;

    // ===== BOX SIZE =====
    int availableHeight = consoleH - boxStartY - 6;
    int boxHeight = min(14, availableHeight);
    boxHeight = max(boxHeight, 8);

    int leftBoxW = 40;
    int rightBoxW = 60;

    int leftBoxX = 9;
    int rightBoxX = consoleW - rightBoxW - 9;

    drawBorderOnly(leftBoxX, boxStartY, leftBoxW, boxHeight);
    drawBorderOnly(rightBoxX, boxStartY, rightBoxW, boxHeight);

    // ===== CLEAR BOXES =====
    for (int i = 0; i < boxHeight - 2; i++) {
        setPos(leftBoxX + 1, boxStartY + 1 + i);
        cout << string(leftBoxW - 2, ' ');
        setPos(rightBoxX + 1, boxStartY + 1 + i);
        cout << string(rightBoxW - 2, ' ');
    }

    // ===== QUESTIONS LIST =====
    int maxQuestions = boxHeight - 2;
    int qWidth = leftBoxW;

    int startIndex = 0;
    if (selectedIndex >= maxQuestions)
        startIndex = selectedIndex - maxQuestions + 1;
    int textWidth = leftBoxW+5; 
    int y = boxStartY + 1;

    for (int qi = startIndex; qi < qaList.size(); qi++) {

        vector<string> lines = wrapText(qaList[qi].question, textWidth);

        for (int li = 0; li < lines.size(); li++) {
            if (y >= boxStartY + boxHeight - 1)
                break;

            setPos(leftBoxX + 1, y);
            cout << string(leftBoxW - 2, ' '); // clear dòng

            setPos(leftBoxX + 2, y);

            if (li == 0) {
                if (qi == selectedIndex)
                    cout << "> " << lines[li];
                else
                    cout << "  " << lines[li];
            }
            else {
                cout << "  " << lines[li];
            }

            y++;
        }

        if (y >= boxStartY + boxHeight - 1)
            break;
    }

    // ===== ANSWER =====
    int answerWidth = rightBoxW -2;
    int answerHeight = boxHeight - 2;

    vector<string> lines = wrapText(qaList[selectedIndex].answer, answerWidth);

    for (int i = 0; i < min(answerHeight, (int)lines.size()); i++) {
        setPos(rightBoxX + 2, boxStartY + 1 + i);
        cout << safeTruncate(lines[i], answerWidth);
    }
}


void ControlHelp() {
    vector<QAPair> qaList = createQAList();
    int selectedIndex = 0;
    displayHelp(qaList, selectedIndex);
    while (true) {
        int key = _getch();
        if (key == 0 || key == 224 || key == -32) {
            int k = _getch();
            if (k == 72) { // 

                selectedIndex--;
                if (selectedIndex < 0) selectedIndex = qaList.size() - 1;
                displayHelp(qaList, selectedIndex);
            }
            else if (k == 80) { // down
                selectedIndex++;
                if (selectedIndex >= (int)qaList.size()) selectedIndex = 0;
                displayHelp(qaList, selectedIndex);
            }
            else if (k == 27) // ESC
                break;
            else if (k == 13) { // ENTER
                sleepms(100); // Hiệu ứng delay
                break; // Thoát khỏi Help
            }
        }
        else {
            switch (toupper(key)) {
            case 'W':
                selectedIndex--;
                if (selectedIndex < 0) selectedIndex = (int)qaList.size() - 1;
                displayHelp(qaList, selectedIndex);
                break;
            case 'S':
                selectedIndex++;
                if (selectedIndex >= (int)qaList.size()) selectedIndex = 0;
                displayHelp(qaList, selectedIndex);
                break;
            case 27:
                return;
            default:
                break;
            }
        }
    }
}