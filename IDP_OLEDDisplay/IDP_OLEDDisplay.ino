#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "OLEDDisplay.h"

Adafruit_SSD1306 screen(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET_PIN);
void setup() {
  Serial.begin(9600);
  Serial.println("Initializing OLED...");
  
  if (!screen.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println("SSD1306 initialization failed!");
    while (true);
  }
  
  Serial.println("SSD1306 initialization successfully!");
  delay(200);
  screen.display();
  delay(300);
  screen.clearDisplay();
  screen.display();
  screen.setTextSize(1);
  screen.setTextColor(SSD1306_WHITE);
  screen.setCursor(40, 10);

  screen.print("Welcome!");
  screen.display();

  screen.setCursor(15, 45);
  screen.print("Home Audio System");
  screen.display();
  
  delay(3000);

  screen.clearDisplay();
  screen.display();

}

int measurePeakToPeak(int pin) {
  int signalMax = 0;
  int signalMin = 1023;

  unsigned long start = millis();
  while (millis() - start < 50) { // 50 ms sample window
    int val = analogRead(pin);
    if (val > signalMax) signalMax = val;
    if (val < signalMin) signalMin = val;
  }
  return signalMax - signalMin;
}

void loop() {
  int bassP2P = measurePeakToPeak(BASS_PIN);
  int midP2P = measurePeakToPeak(MID_PIN);
  int trebleP2P = measurePeakToPeak(TREBLE_PIN);

  int maxP2P = 1023;
  int barHeight = 35; 

  int bassHeight = map(bassP2P, 0, maxP2P, 0, barHeight);
  int midHeight = map(midP2P, 0, maxP2P, 0, barHeight);
  int trebleHeight = map(trebleP2P, 0, maxP2P, 0, barHeight);

  screen.setTextSize(1);
  screen.setTextColor(SSD1306_WHITE);
  screen.setCursor(20, 0);
  screen.print("Signal Strength");
  screen.setCursor(30, 10);
  screen.print("Spectrogram");

  int barWidth = 20;
  int baseY = 55;             // Bottom of all bars
  int spacing = 10;

  // MID bar centered, others spaced evenly
  int xMid = (SCREEN_WIDTH - barWidth) / 2;
  int xBass = xMid - barWidth - spacing;
  int xTreble = xMid + barWidth + spacing;

  // --- Draw Bars ---
  screen.drawRect(xBass, baseY - barHeight, barWidth, barHeight, SSD1306_WHITE);     // BASS
  screen.fillRect(xBass + 1, baseY - bassHeight + 1, barWidth - 2, bassHeight - 2, SSD1306_WHITE);
  screen.drawRect(xMid, baseY - barHeight, barWidth, barHeight, SSD1306_WHITE);      // MID
  screen.fillRect(xMid + 1, baseY - midHeight + 1, barWidth - 2, midHeight - 2, SSD1306_WHITE);
  screen.drawRect(xTreble, baseY - barHeight, barWidth, barHeight, SSD1306_WHITE);   // TREBLE
  screen.fillRect(xTreble + 1, baseY - trebleHeight + 1, barWidth - 2, trebleHeight - 2, SSD1306_WHITE);

  // --- Labels ---
  screen.setCursor(xBass - 1, baseY + 2);
  screen.print("BASS");

  screen.setCursor(xMid + 1, baseY + 2);
  screen.print("MID");

  screen.setCursor(xTreble - 6, baseY + 2);
  screen.print("TREBLE");

  screen.display();
  
  delay(1000);
}
