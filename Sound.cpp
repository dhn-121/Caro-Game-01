#include "Library.h"
bool g_sfxEnabled = true;
bool g_musicEnabled = true;
bool sfx_active = true;
bool music_active = true;

void playMoveSound() {   //phát hiệu ứng âm thanh khi di chuyển
    if (g_sfxEnabled) {
        PlaySound(TEXT("sound//move.wav"), NULL, SND_FILENAME | SND_ASYNC);
    }
}

void playClickSound() {  //phát hiệu ứng âm thanh khi click
    if (g_sfxEnabled) {
        PlaySound(TEXT("sound//click.wav"), NULL, SND_FILENAME | SND_ASYNC);
    }
}

void playWinSound() {   //phát hiệu ứng âm thanh khi người chơi thắng
    if (g_sfxEnabled) {
        PlaySound(TEXT("sound//win.wav"), NULL, SND_FILENAME | SND_ASYNC);
    }
}

void playBackgroundMusic() {  //phát nhạc nền ở menu chính
    if (g_musicEnabled) {
        PlaySound(TEXT("sound//Menu.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_NOSTOP);
    }
}

void playGameplayMusic() {  //phát nhạc nền khi vào gameplay
    if (g_musicEnabled) {
         PlaySound(TEXT("sound//GamePlay_2.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    }
}

void stopBackgroundMusic() {   
    PlaySound(NULL, NULL, 0);
}

void stopGameplayMusic() {
    PlaySound(NULL, NULL, 0);
}

void setSFX(bool enabled) {
    g_sfxEnabled = enabled;
}

void setMusic(bool enabled) {
    g_musicEnabled = enabled;
    if (!enabled) {
        stopBackgroundMusic();
    }
    else {
        playBackgroundMusic();
    }
}

bool isSFXEnabled() {
    return g_sfxEnabled;
}

// Hàm kiểm tra trạng thái Nhạc nền
bool isMusicEnabled() {
    return g_musicEnabled;
}
