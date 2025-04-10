#ifndef _OLEDDisplay_H    
#define _OLEDDisplay_H

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET_PIN -1
#define SCREEN_ADDRESS 0x3C

#define BASS_PIN A0
#define MID_PIN A1
#define TREBLE_PIN A2

int prevBass = 0;
int prevMid = 0;
int prevTreble = 0;

int measurePeakToPeak(int pin);

#endif // _OLEDDisplay_H