#pragma once
#ifndef _SOUND_H_
#define _SOUND_H_

#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

void playMoveSound();
void playClickSound();
void playWinSound();
void playBackgroundMusic();
void stopBackgroundMusic();
void playGameplayMusic();
void stopGameplayMusic();
void setSFX(bool enabled);
void setMusic(bool enabled);
bool isSFXEnabled();
bool isMusicEnabled();

#endif
