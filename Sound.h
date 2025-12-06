#pragma once
#ifndef _SOUND_H_
#define _SOUND_H_

#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

void initializeBGM();
void playMoveSound();
void playClickSound();
void playWinSound();
void playDrawSound();
void playBackgroundMusic();
void stopBackgroundMusic();
void playGameplayMusic();
void stopGameplayMusic();
void setSFX(bool enabled);
void setMusic(bool enabled);

#endif
