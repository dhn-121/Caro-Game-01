#pragma once
#ifndef _SOUND_H_
#define _SOUND_H_

#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

class SoundManager {
private:
    bool sfxEnabled;
    bool musicEnabled;

public:
    SoundManager();
    void playMoveSound();
    void playClickSound();
    void playWinSound();
    void playBackgroundMusic();
    void stopBackgroundMusic();
    void setSFX(bool enabled);
    void setMusic(bool enabled);
    bool isSFXEnabled() const;
    bool isMusicEnabled() const;
};

extern SoundManager soundManager;

#endif