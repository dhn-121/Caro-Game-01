#include "Library.h"
#include <windows.h>
#include <mmsystem.h>
#include <direct.h>   // Để dùng _getcwd
#include <stdio.h>

#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "shlwapi.lib")

bool g_sfxEnabled = true;
bool g_musicEnabled = true;
bool g_bgmInitialized = false;  // Thêm biến kiểm tra đã khởi tạo chưa

void initializeBGM() {
    // Mở file âm thanh
    MCIERROR error;
    // Thử cả hai cách viết đường dẫn
    error = mciSendString(TEXT("open \"sound\\Menu.wav\" type mpegvideo alias bgm_menu"), NULL, 0, 0);
    if (error != 0) {
        // Thử cách khác
    error = mciSendString(TEXT("open \"Menu.wav\" type mpegvideo alias bgm_menu"), NULL, 0, 0);
    }
    error = mciSendString(TEXT("open \"sound\\GamePlay_2.wav\" type mpegvideo alias bgm_game"), NULL, 0, 0);
    if (error != 0) {
        error = mciSendString(TEXT("open \"GamePlay_2.wav\" type mpegvideo alias bgm_game"), NULL, 0, 0);
    }
    g_bgmInitialized = true;
}

void playBackgroundMusic(){
    if (g_musicEnabled && g_bgmInitialized) {
        stopGameplayMusic();
        mciSendString(TEXT("play bgm_menu from 0"), NULL, 0, 0);  // Phát từ đầu
        mciSendString(TEXT("play bgm_menu repeat"), NULL, 0, 0);  // Lặp lại
    }
}

void playGameplayMusic() {
    if (g_musicEnabled && g_bgmInitialized) {
        stopBackgroundMusic();
        mciSendString(TEXT("play bgm_game from 0"), NULL, 0, 0);  // Phát từ đầu
        mciSendString(TEXT("play bgm_game repeat"), NULL, 0, 0);  // Lặp lại
    }
}

void playMoveSound() {
    if (g_sfxEnabled)
        PlaySound(TEXT("sound\\move.wav"), NULL, SND_FILENAME | SND_ASYNC);
    else
        PlaySound(TEXT("sound\\silent.wav"), NULL, SND_FILENAME | SND_ASYNC);
}
void playMoveXOSound() {
    if (g_sfxEnabled)
        PlaySound(TEXT("sound\\goXO.wav"), NULL, SND_FILENAME | SND_ASYNC);
    else
        PlaySound(TEXT("sound\\silent.wav"), NULL, SND_FILENAME | SND_ASYNC);
}

void playClickSound() {
    if (g_sfxEnabled)
        PlaySound(TEXT("sound\\click.wav"), NULL, SND_FILENAME | SND_ASYNC);
    else
        PlaySound(TEXT("sound\\silent.wav"), NULL, SND_FILENAME | SND_ASYNC);
}

void playEnterXOSound() {
    if (g_sfxEnabled)
        PlaySound(TEXT("sound\\enterXO.wav"), NULL, SND_FILENAME | SND_ASYNC);
    else
        PlaySound(TEXT("sound\\silent.wav"), NULL, SND_FILENAME | SND_ASYNC);
}
void playWinSound() {
    if (g_sfxEnabled)
        PlaySound(TEXT("sound\\win.wav"), NULL, SND_FILENAME | SND_ASYNC);
    else
        PlaySound(TEXT("sound\\silent.wav"), NULL, SND_FILENAME | SND_ASYNC);
}

void playDrawSound() {
    if (g_sfxEnabled)
        PlaySound(TEXT("sound\\lose.wav"), NULL, SND_FILENAME | SND_ASYNC);
    else
        PlaySound(TEXT("sound\\silent.wav"), NULL, SND_FILENAME | SND_ASYNC);
}

void stopBackgroundMusic() {
    if (g_bgmInitialized) {
        mciSendString(TEXT("stop bgm_menu"), NULL, 0, 0);
        mciSendString(TEXT("seek bgm_menu to start"), NULL, 0, 0);  // Quay về đầu
    }
}

void stopGameplayMusic() {
    if (g_bgmInitialized) {
        mciSendString(TEXT("stop bgm_game"), NULL, 0, 0);
        mciSendString(TEXT("seek bgm_game to start"), NULL, 0, 0);  // Quay về đầu
    }
}

void setSFX(bool enabled) {
    g_sfxEnabled = enabled;
}

void setMusic(bool enabled) {
    g_musicEnabled = enabled;
    if (!enabled) {
        stopBackgroundMusic();
        stopGameplayMusic();
    }
    else if (g_bgmInitialized) {
        playBackgroundMusic();
    }
}