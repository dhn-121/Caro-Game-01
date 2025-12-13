
#include "Language.h"

map<string, string> langEN = {
    {"TITLE", "CARO"},
    {"PLAY_GAME", "PLAY GAME"},
    {"LOAD_GAME", "LOAD GAME"},
    {"SETTING", "SETTING"},
    {"HELP", "HELP"},
    {"EXIT", "EXIT"},
    {"LANGUAGE", "LANGUAGE"},
    {"ENGLISH", "English"},
    {"VIETNAMESE", "Vietnamese"} ,
    { "Welcome! This CARO game is the final project of the Fundamentals of Programming course, presented by Group 1 - 25CTT3, University of Science, VNU-HCM" , "Welcome! This CARO game is the final project of the Fundamentals of Programming course, presented by Group 1 - 25CTT3, University of Science, VNU-HCM" },
    {"There are 6 people in our group" , "There are 6 people in our group"  },
    {"1. Pham Hoang Tuong An" , "1. Pham Hoang Tuong An"},
    {"2. Dinh Ngoc Bich" , "2. Dinh Ngoc Bich"},
    {"3. Phan Van Can" , "3. Phan Van Can"},
    {"4. Nguyen Hoang Chau" , "4. Nguyen Hoang Chau"},
    {"5. Truong Thi Ngoc Ha" ,"5. Truong Thi Ngoc Ha" },
    {"6. Do Xuan Huy" , "6. Do Xuan Huy"} ,
    { "How do I make a move?", "How do I make a move?"} ,
    { "You can use the classic WASD controls to navigate the board:\n* W: Move Up\n* A: Move Left\n* S: Move Down\n* D: Move Right" , "You can use the classic WASD controls to navigate the board:\n* W: Move Up\n* A: Move Left\n* S: Move Down\n* D: Move Right"} ,
    {"How do I pause the game?", "How do I pause the game?"} ,
    {"You can press the ESC key on your keyboard.", "You can press the ESC key on your keyboard."} ,
    {"How do I save or load the game?" ,"How do I save or load the game?"} ,
    {"* To SAVE your current game, press 'L' (Load).\n* To LOAD a saved game, press 'T' (Save).", "* To SAVE your current game, press 'L' (Load).\n* To LOAD a saved game, press 'T' (Save)."} ,
    {"How do I turn on/off the sound?" , "How do I turn on/off the sound?"} ,
    { "On the Menu Screen\n1. Choose 'SETTINGS'.\n2. Use 'W' (Up) and 'S' (Down) to navigate the options.\n3. Press ENTER to toggle the sound on or off.", "On the Menu Screen\n1. Choose 'SETTINGS'.\n2. Use 'W' (Up) and 'S' (Down) to navigate the options.\n3. Press ENTER to toggle the sound on or off."} ,

};

map<string, string> langVI = {
    {"TITLE", "CARO"},
    {"PLAY_GAME", "CHƠI GAME"},
    {"LOAD_GAME", "TẢI GAME"},
    {"SETTING", "CÀI ĐẶT"},
    {"HELP", "HƯỚNG DẪN"},
    {"EXIT", "THOÁT"},
    {"LANGUAGE", "NGÔN NGỮ"},
    {"ENGLISH", "Tiếng Anh"},
    {"VIETNAMESE", "Tiếng Việt"},
    { "Tell me about this game." , "Hãy giới thiệu về trò chơi này."} ,


    { "Welcome! This CARO game is the final project of the Fundamentals of Programming course, presented by Group 1 - 25CTT3, University of Science, VNU-HCM" , " rò chơi CARO này là dự án cuối khóa môn Lập trình cơ bản, do Nhóm 1 - 25CTT3, Đại học Khoa học Tự nhiên, TP.HCM" },
    {"There are 6 people in our group" , " Nhóm chúng tôi gồm 6 người" },
    {"1. Pham Hoang Tuong An" , "1. Phạm Hoàng Tường An"},
    {"2. Dinh Ngoc Bich" , "2. Đinh Ngọc Bích"},
    {"3. Phan Van Can" , "3. Phan Văn Cần"},
    {"4. Nguyen Hoang Chau" , "4. Nguyễn Hoàng Châu"},
    {"5. Truong Thi Ngoc Ha" , " 5. Trương Thị Ngọc Hà"},
    {"6. Do Xuan Huy" , " 6. Đỗ Xuân Huy"} ,
    { "How do I make a move?",  "Làm thế nào để di chuyển?"} ,
    { "You can use the classic WASD controls to navigate the board:\n* W: Move Up\n* A: Move Left\n* S: Move Down\n* D: Move Right" , "Bạn có thể sử dụng các phím WASD cổ điển để di chuyển trên bàn cờ:\n* W: Di chuyển lên\n* A: Di chuyển sang trái\n* S: Di chuyển xuống\n* D: Di chuyển sang phải"} ,
    {"How do I pause the game?", "Làm thế nào để tạm dừng trò chơi?"} ,
    {"You can press the ESC key on your keyboard.", "Bạn có thể nhấn phím ESC trên bàn phím."} ,
    {"How do I save or load the game?" , "Làm thế nào để lưu hoặc tải trò chơi?"} ,
    {"* To SAVE your current game, press 'L' (Load).\n* To LOAD a saved game, press 'T' (Save).", "* Để LƯU trò chơi hiện tại, nhấn phím 'L' (Tải).\n* Để TẢI trò chơi đã lưu, nhấn phím 'T' (Lưu)."} ,
    {"How do I turn on/off the sound?" , "Làm thế nào để bật/tắt âm thanh?"} ,
    { "On the Menu Screen\n1. Choose 'SETTINGS'.\n2. Use 'W' (Up) and 'S' (Down) to navigate the options.\n3. Press ENTER to toggle the sound on or off.", "Trên màn hình Menu\n1. Chọn 'CÀI ĐẶT'.\n2. Sử dụng phím 'W' (Lên) và 'S' (Xuống) để điều hướng các tùy chọn.\n3. Nhấn ENTER để bật hoặc tắt âm thanh."} ,
};

map<string, string>* currentLang = &langEN; // mặc định tiếng Anh

string T(const string& key) {
    return (*currentLang)[key];
}

void SetLanguage(const string& lang) {
    if (lang == "VI")
        currentLang = &langVI;
    else
        currentLang = &langEN;
}

main()
{   
    string s = "VI" ;
    SetLanguage(s) ;
    cout << T("HELP") << '\n' ;
}
s