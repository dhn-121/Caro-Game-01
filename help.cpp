#include "Library.h"
#include "help.h"
using namespace std;

vector<QAPair> createQAList() {
    vector<QAPair> qaList = {
        {
            "Tell me about this game.",
            "Welcome! This CARO game is the final project of the Fundamentals of Programming course, presented by Group 1 - 25CTT3, University of Science, VNU-HCM.\nThere are 6 people in our group:\n1. Pham Hoang Tuong An\n2. Dinh Ngoc Bich\n3. Phan Van Can\n4. Nguyen Hoang Chau\n5. Truong Thi Ngoc Ha\n6. Do Xuan Huy"
        },
        {
            "How do I make a move?",
            "You can use the classic WASD controls to navigate the board:\n* W: Move Up\n* A: Move Left\n* S: Move Down\n* D: Move Right"
        },
        {
            "How do I pause the game?",
            "You can press the ESC key on your keyboard."
        },
        {
            "How do I save or load the game?",
            "* To SAVE your current game, press 'L' (Load).\n* To LOAD a saved game, press 'T' (Save)."
        },
        {
            "How do I turn on/off the sound?",
            "On the Menu Screen\n1. Choose 'SETTINGS'.\n2. Use 'W' (Up) and 'S' (Down) to navigate the options.\n3. Press ENTER to toggle the sound on or off."
        }
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

void displayHelp(const vector<QAPair>& qaList, int selectedIndex) {
    system("cls");
    drawHelpScreen();
    
    // Tính toán vị trí và kích thước dựa trên ConsoleWidth và ConsoleHeight
    int consoleW = ConsoleWidth > 0 ? ConsoleWidth : 120;
    int consoleH = ConsoleHeight > 0 ? ConsoleHeight : 35;

    // Vẽ chữ HELP ở trên cùng, giữa màn hình
    int helpHeight = 6;
    int helpWidth = 32;
    // Tính vị trí cho chữ HELP
    int helpX = consoleW / 2 - helpWidth / 2;
    int helpY = 2;  // Cách mép trên 2 dòng

    // Tính toán vị trí bắt đầu của khung (dưới chữ HELP)
    int boxStartY = helpY + helpHeight + 1;  // Cách chữ HELP 1 dòng

    // Tính toán kích thước cho hai khung
    int availableHeight = consoleH - boxStartY - 6;  // Trừ không gian cho hướng dẫn ở dưới
    int boxHeight = min(20, 14);  // Chiều cao tối đa 20 hoặc chiều cao khả dụng

    int leftBoxWidth = 40;  // Chiều rộng cố định cho khung câu hỏi
    int rightBoxWidth = 60;  // Chiều rộng cố định cho khung câu trả lời

    // Tính toán vị trí ngang cho các khung
    int leftBoxX = 9;  // Cách lề trái 9 cột
    int rightBoxX = consoleW - rightBoxWidth - 9;  // Cách lề phải 5 cột

    // Vẽ khung câu hỏi (bên trái)
    drawBorderOnly(leftBoxX, boxStartY, leftBoxWidth, boxHeight);

    // Vẽ khung câu trả lời (bên phải)
    drawBorderOnly(rightBoxX, boxStartY, rightBoxWidth, boxHeight);

    // Hiển thị danh sách câu hỏi trong khung bên trái
    int maxQuestions = min((int)qaList.size(), boxHeight - 3);
    int maxQuestionDisplayWidth = leftBoxWidth - 4;  // Trừ 2 cho mỗi bên viền

    // Tính toán vị trí bắt đầu để luôn hiển thị câu hỏi được chọn
    int startIndex = 0;
    if (qaList.size() > maxQuestions) {
        if (selectedIndex >= maxQuestions) {
            startIndex = selectedIndex - maxQuestions + 1;
        }
        // Đảm bảo startIndex không vượt quá
        if (startIndex + maxQuestions > qaList.size()) {
            startIndex = qaList.size() - maxQuestions;
        }
    }
    startIndex = max(0, startIndex);

    for (int i = 0; i < maxQuestions; i++) {
        int questionIndex = startIndex + i;
        if (questionIndex >= qaList.size()) break;

        setPos(leftBoxX + 2, boxStartY + 1 + i);

        // Chuẩn bị chuỗi hiển thị
        string displayStr;
        if (questionIndex == selectedIndex) {
            displayStr = "> " + safeTruncate(qaList[questionIndex].question, maxQuestionDisplayWidth - 2);
        }
        else {
            displayStr = "  " + safeTruncate(qaList[questionIndex].question, maxQuestionDisplayWidth - 2);
        }

        // In chuỗi
        cout << displayStr;

        // Xóa phần còn lại của dòng
        int spacesNeeded = maxQuestionDisplayWidth - displayStr.length();
        for (int j = 0; j < spacesNeeded; j++) {
            cout << " ";
        }
    }
    
    // Hiển thị câu trả lời trong khung bên phải
    int maxAnswerWidth = rightBoxWidth - 4;

    // Tách câu trả lời thành các dòng
    string answer = qaList[selectedIndex].answer;
    vector<string> lines;
    string currentLine;

    // Xử lý ngắt dòng thủ công
    for (size_t i = 0; i < answer.length(); i++) {
        char c = answer[i];

        if (c == '\n') {
            lines.push_back(currentLine);
            currentLine.clear();
        }
        else {
            currentLine += c;
            // Tự động xuống dòng nếu quá dài
            if (currentLine.length() >= maxAnswerWidth) {
                // Tìm vị trí ngắt từ tốt nhất
                size_t lastSpace = currentLine.find_last_of(' ', maxAnswerWidth);
                if (lastSpace != string::npos && lastSpace > maxAnswerWidth * 2 / 3) {
                    lines.push_back(currentLine.substr(0, lastSpace));
                    currentLine = currentLine.substr(lastSpace + 1);
                }
                else {
                    lines.push_back(currentLine.substr(0, maxAnswerWidth));
                    currentLine = currentLine.substr(maxAnswerWidth);
                }
            }
        }
    }
    if (!currentLine.empty()) {
        lines.push_back(currentLine);
    }

    // Hiển thị các dòng câu trả lời
    int maxAnswerLines = boxHeight - 2;

    for (int i = 0; i < min(maxAnswerLines, (int)lines.size()); i++) {
        setPos(rightBoxX + 2, boxStartY + 1 + i);
        string lineToDisplay = safeTruncate(lines[i], maxAnswerWidth);
        cout << lineToDisplay;

        // Xóa phần còn lại của dòng
        int spacesNeeded = maxAnswerWidth - lineToDisplay.length();
        for (int j = 0; j < spacesNeeded; j++) {
            cout << " ";
        }
    }

    // Xóa các dòng còn lại trong khung
    for (int i = lines.size(); i < maxAnswerLines; i++) {
        setPos(rightBoxX + 2, boxStartY + 1 + i);
        for (int j = 0; j < maxAnswerWidth; j++) {
            cout << " ";
        }
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
            if (k == 72) { // up
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
                Sleep(100); // Hiệu ứng delay
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