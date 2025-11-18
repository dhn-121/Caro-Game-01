#include "Library.h"
#include "Sound.h"
void initializeSound() {
    g_sfxEnabled = true;
    g_musicEnabled = true;
}

void playMoveSound() {
    if (g_sfxEnabled) {
        PlaySound(TEXT("SystemExclamation"), NULL, SND_ALIAS_ID | SND_ASYNC);
    }
}

void playClickSound() {
    if (g_sfxEnabled) {
        PlaySound(TEXT("SystemAsterisk"), NULL, SND_ALIAS_ID | SND_ASYNC);
    }
}

void playWinSound() {
    if (g_sfxEnabled) {
        PlaySound(TEXT("SystemHand"), NULL, SND_ALIAS_ID | SND_ASYNC);
    }
}

void playBackgroundMusic() {
    if (g_musicEnabled) {
         PlaySound(TEXT("background.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    }
}

void stopBackgroundMusic() {
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
