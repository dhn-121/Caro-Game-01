#include "settings.h"

SoundManager::SoundManager() : sfxEnabled(true), musicEnabled(true) {}

void SoundManager::playMoveSound() {
    if (sfxEnabled) {
        PlaySound(TEXT("SystemExclamation"), NULL, SND_ALIAS_ID | SND_ASYNC);
    }
}

void SoundManager::playClickSound() {
    if (sfxEnabled) {
        PlaySound(TEXT("SystemAsterisk"), NULL, SND_ALIAS_ID | SND_ASYNC);
    }
}

void SoundManager::playWinSound() {
    if (sfxEnabled) {
        PlaySound(TEXT("SystemHand"), NULL, SND_ALIAS_ID | SND_ASYNC);
    }
}

void SoundManager::playBackgroundMusic() {
    if (musicEnabled) {
        // PlaySound(TEXT("background.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    }
}

void SoundManager::stopBackgroundMusic() {
    PlaySound(NULL, NULL, 0);
}

void SoundManager::setSFX(bool enabled) {
    sfxEnabled = enabled;
}

void SoundManager::setMusic(bool enabled) {
    musicEnabled = enabled;
    if (!enabled) {
        stopBackgroundMusic();
    }
    else {
        playBackgroundMusic();
    }
}

bool SoundManager::isSFXEnabled() const {
    return sfxEnabled;
}

bool SoundManager::isMusicEnabled() const {
    return musicEnabled;
}

SoundManager soundManager;
int ControlMenu() {
    VectorInit();
    drawMenu();

    int present_choice = 0;
    drawIsSelected(present_choice, Y_Start_MenuBox, true);

    int key;
    while (true) {
        key = _getch();
        int past_choice = present_choice;

        if (key == 0 || key == 224) {
            key = _getch();
            switch (key) {
            case 72: key = 'W'; break;
            case 80: key = 'S'; break;
            default: continue;
            }
        }

        switch (toupper(key)) {
        case 'W':
            present_choice = (present_choice - 1 + BoxNum) % BoxNum;
            soundManager.playMoveSound();  // Thêm âm thanh di chuyển
            break;
        case 'S':
            present_choice = (present_choice + 1) % BoxNum;
            soundManager.playMoveSound();  // Thêm âm thanh di chuyển
            break;
        case 13:
            soundManager.playClickSound();  // Thêm âm thanh nhấn nút
            return present_choice + 1;
        default:
            continue;
        }

        if (present_choice != past_choice) {
            drawIsSelected(past_choice, Y_Start_MenuBox, false);
            drawIsSelected(present_choice, Y_Start_MenuBox, true);
        }
    }
}
int ControlSettings() {
    drawSettingsScreen();
    int present_choice = 0;
    drawSettingsHighlight(present_choice, true);

    int key;
    while (true) {
        key = _getch();
        int past_choice = present_choice;

        if (key == 0 || key == 224) {
            key = _getch();
            switch (key) {
            case 72: key = 'W'; break;
            case 80: key = 'S'; break;
            default: continue;
            }
        }

        switch (toupper(key)) {
        case 'W':
            present_choice = (present_choice - 1 + SettingsBoxNum) % SettingsBoxNum;
            soundManager.playMoveSound();  // Âm thanh di chuyển
            break;
        case 'S':
            present_choice = (present_choice + 1) % SettingsBoxNum;
            soundManager.playMoveSound();  // Âm thanh di chuyển
            break;
        case 13:
            soundManager.playClickSound();  // Âm thanh nhấn nút
            if (present_choice == 0) {
                Default_Set.sfx_active = !Default_Set.sfx_active;
                soundManager.setSFX(Default_Set.sfx_active);  // Cập nhật trạng thái SFX
                drawSettingsHighlight(present_choice, true);
            }
            else if (present_choice == 1) {
                Default_Set.music_active = !Default_Set.music_active;
                soundManager.setMusic(Default_Set.music_active);  // Cập nhật trạng thái nhạc
                drawSettingsHighlight(present_choice, true);
            }
            else if (present_choice == 2) {
                return 0;
            }
            continue;
        default:
            continue;
        }

        if (present_choice != past_choice) {
            drawSettingsHighlight(past_choice, false);
            drawSettingsHighlight(present_choice, true);
        }
    }
}
