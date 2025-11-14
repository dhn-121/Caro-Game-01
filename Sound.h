#pragma once
#ifndef _SOUND_H_
#define _SOUND_H_

#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

bool g_sfxEnabled = true;
bool g_musicEnabled = true;

void initializeSound();
void playMoveSound();
void playClickSound();
void playWinSound();
void playBackgroundMusic();
void stopBackgroundMusic();
void setSFX(bool enabled);
void setMusic(bool enabled);
bool isSFXEnabled();
bool isMusicEnabled();

#endif
