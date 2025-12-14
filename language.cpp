#include "Library.h"

map<string, string> langEN = {
    //MENU
    // {"TITLE", "CARO"},
    {"PLAY GAME", "PLAY GAME"},
    {"LOAD GAME", "LOAD GAME"},
    {"SETTING", "SETTING"},
    {"HELP", "HELP"},
    {"EXIT", "EXIT"},

    //nút BACK
    {"BACK", "BACK"},

    //GAME MODE
    {"SELECT GAME MODE", "SELECT GAME MODE"},
    {"PvP MODE","PvP MODE"},
    {"PvE MODE","PvE MODE"},

    //INPUT NAME
    {"INPUT YOUR NAME", "INPUT YOUR NAME"},
    {"Player", "Player"},
    {"Please input your name!", "Please input your name!"},
    {"Computer", "Computer"},

    //LEVEL
    {"SELECT DIFFICULTY LEVEL", "SELECT DIFFICULTY LEVEL"},
    {"EASY", "EASY"},
    {"NORMAL", "NORMAL"},
    {"HARD","HARD"},

    //GAME PLAY
    {"TURN", "TURN"},
    {"SCORE OF", "SCORE OF"},

    //WIN
    {"Score", "Score"},

    //DRAW
    {"You two are evenly matched!", "You two are evenly matched!"},

    //GAME OVER
    {"CONTINUE", "CONTINUE"},
    {"PLAY AGAIN", "PLAY AGAIN"},
    {"RESET SCORE", "RESET SCORE"},
    {"HOME", "HOME"},

    //LOAD/SAVE GAME
    {"Error creating file ", "Error creating file "},
    {"Game saved successfully to ", "Game saved successfully to "},
    {"file not found", "file not found"},
    {"Enter filename (without .txt extension) ", "Enter filename (without .txt extension) "},
    {"max 100 characters", "max 100 characters"},
    {"File not found. Try again:          ", "File not found. Try again:          "},
    {"Game loaded successfully! Returning to game...", "Game loaded successfully! Returning to game..."},
    {"Failed to load game. Returning to current game...","Failed to load game. Returning to current game..."},
    {"Save cancelled. Returning to game...", "Save cancelled. Returning to game..."},
    {"Game saved successfully! Returning to menu...", "Game saved successfully! Returning to menu..."},

    //SETTING:
    {"MUSIC", "MUSIC"},
    {"ON ", "ON "},
    {"OFF", "OFF"},
    {"LANGUAGE", "LANGUAGE"},
    {"ENGLISH", "ENGLISH"},
    {"VIETNAMESE", "VIETNAMESE"},

    //HELP - Sử dụng key đồng nhất
    {"HELP_Q1", "Tell me about this game."},
    {"HELP_A1", "Welcome! This CARO game is the final project of the Fundamentals of Programming course, presented by Group 1 - 25CTT3, University of Science, VNU-HCM.\nThere are 6 people in our group:\n1. Pham Hoang Tuong An\n2. Dinh Ngoc Bich\n3. Phan Van Can\n4. Nguyen Hoang Chau\n5. Truong Thi Ngoc Ha\n6. Do Xuan Huy"},

    {"HELP_Q2", "How do I make a move?"},
    {"HELP_A2", "You can use the classic WASD controls to navigate the board:\n* W: Move Up\n* A: Move Left\n* S: Move Down\n* D: Move Right"},

    {"HELP_Q3", "How do I pause the game?"},
    {"HELP_A3", "You can press the ESC key on your keyboard."},

    {"HELP_Q4", "How do I save or load the game?"},
    {"HELP_A4", "* To SAVE your current game, press 'L' (Save).\n* To LOAD a saved game, press 'T' (Load)."},

    {"HELP_Q5", "How do I turn on/off the sound?"},
    {"HELP_A5", "On the Menu Screen\n1. Choose 'SETTINGS'.\n2. Use 'W' (Up) and 'S' (Down) to navigate the options.\n3. Press ENTER to toggle the sound on or off."},
};

map<string, string> langVI = {
    //MENU
    // {"TITLE", "CARO"},
    {"PLAY GAME", "CHƠI GAME"},
    {"LOAD GAME", "TẢI GAME"},
    {"SETTING", "CÀI ĐẶT"},
    {"HELP", "HƯỚNG DẪN"},
    {"EXIT", "THOÁT"},

    //nút BACK
    {"BACK", "TRỞ LẠI"},

    //GAME MODE
    {"SELECT GAME MODE", "CHỌN CHẾ ĐỘ CHƠI"},
    {"PvP MODE","CHẾ ĐỘ PvP"},
    {"PvE MODE","CHẾ ĐỘ PvE"},

    //INPUT NAME
    {"INPUT YOUR NAME", "NHẬP TÊN BẠN"},
    {"Player", "Người chơi"},
    {"Please input your name!", "HÃY NHẬP TÊN CỦA BẠN!"},
    {"Computer", "Máy tính"},

    //LEVEL
    {"SELECT DIFFICULTY LEVEL", "CHỌN MỨC ĐỘ KHÓ"},
    {"EASY", "DỄ"},
    {"NORMAL", "BÌNH THƯỜNG"},
    {"HARD","KHÓ"},

    //GAME PLAY
    {"TURN", "LƯỢT"},
    {"SCORE OF", "ĐIỂM CỦA"},

    //WIN
    {"Score", "Điểm"},

    //DRAW
    {"You two are evenly matched!", "Hai bạn đang hoà nhau!"},

    //GAME OVER
    {"CONTINUE", "TIẾP TỤC"},
    {"PLAY AGAIN", "CHƠI LẠI"},
    {"RESET SCORE", "ĐẶT LẠI SỐ ĐIỂM"},
    {"HOME", "VỀ MENU"},

    //LOAD/SAVE GAME
    {"Error creating file ", "Tạo file thất bại "},
    {"Game saved successfully to ", "Game được lưu thành công vào "},
    {"file not found", "không tìm thấy file"},
    {"Enter filename (without .txt extension) ", "Nhập tên file (không cần phần đuôi .txt) "},
    {"max 100 characters", "tối đa 100 ký tự"},
    {"File not found. Try again:          ", "Không tìm thấy file. Thử lại:          "},
    {"Game loaded successfully! Returning to game...", "Tải game thành công! Đang trở lại game..."},
    {"Failed to load game. Returning to current game...","Tải game thất bại. Trở về game hiện tại..."},
    {"Save cancelled. Returning to game...", "Lưu game đã bị huỷ. Trở lại game..."},
    {"Game saved successfully! Returning to menu...", "Lưu game thành công! Trở về menu..."},

    //SETTING
    {"MUSIC", "NHẠC NỀN"},
    {"ON ", "BẬT"},
    {"OFF", "TẮT"},
    {"LANGUAGE", "NGÔN NGỮ"},
    {"ENGLISH", "TIẾNG ANH"},
    {"VIETNAMESE", "TIẾNG VIỆT"},

    //HELP - Sử dụng key đồng nhất với langEN
    {"HELP_Q1", "Giới thiệu về trò chơi"},
    {"HELP_A1", "Chào mừng! Trò chơi CARO này là dự án cuối khóa môn Lập trình cơ bản, do Nhóm 1 - 25CTT3, Đại học Khoa học Tự nhiên, ĐHQG-HCM thực hiện.\nNhóm chúng tôi gồm 6 người:\n1. Phạm Hoàng Tường An\n2. Đinh Ngọc Bích\n3. Phan Văn Cần\n4. Nguyễn Hoàng Châu\n5. Trương Thị Ngọc Hà\n6. Đỗ Xuân Huy"},

    {"HELP_Q2", "Làm thế nào để di chuyển?"},
    {"HELP_A2", "Bạn có thể sử dụng các phím WASD cổ điển để di chuyển trên bàn cờ:\n* W: Di chuyển lên\n* A: Di chuyển sang trái\n* S: Di chuyển xuống\n* D: Di chuyển sang phải"},

    {"HELP_Q3", "Làm thế nào để tạm dừng trò chơi?"},
    {"HELP_A3", "Bạn có thể nhấn phím ESC trên bàn phím."},

    {"HELP_Q4", "Làm thế nào để lưu hoặc tải trò chơi?"},
    {"HELP_A4", "* Để LƯU trò chơi hiện tại, nhấn phím 'L' (Lưu).\n* Để TẢI trò chơi đã lưu, nhấn phím 'T' (Tải)."},

    {"HELP_Q5", "Làm thế nào để bật/tắt âm thanh?"},
    {"HELP_A5", "Trên màn hình Menu\n1. Chọn 'CÀI ĐẶT'.\n2. Sử dụng phím 'W' (Lên) và 'S' (Xuống) để điều hướng các tùy chọn.\n3. Nhấn ENTER để bật hoặc tắt âm thanh."},
};

map<string, string>* currentLang = &langEN; // mặc định tiếng Anh

string T(const string& key) {
    auto it = currentLang->find(key);
    if (it != currentLang->end()) {
        return it->second;
    }
    // Nếu không tìm thấy key, trả về key gốc
    return "[" + key + "]";
}

void SetLanguage(const string& lang) {
    if (lang == "VI") {
        currentLang = &langVI;
    }
    else {
        currentLang = &langEN;
    }
}