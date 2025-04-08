#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET_PIN -1
#define SCREEN_ADDRESS 0x3C

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

void loop() {
  // put your main code here, to run repeatedly:
  screen.setTextSize(1);
  screen.setTextColor(SSD1306_WHITE);
  screen.setCursor(20, 0);
  screen.print("Signal Strength");
  screen.setCursor(30, 10);
  screen.print("Spectrogram");

  int barWidth = 20;
  int barHeight = 35;         // All bars same height
  int baseY = 55;             // Bottom of all bars

  // MID bar centered, others spaced evenly
  int xMid = (SCREEN_WIDTH - barWidth) / 2;
  int spacing = 10;
  int xBass = xMid - barWidth - spacing;
  int xTreble = xMid + barWidth + spacing;

  // --- Draw Bars ---
  screen.drawRect(xBass, baseY - barHeight, barWidth, barHeight, SSD1306_WHITE);     // BASS
  screen.drawRect(xMid, baseY - barHeight, barWidth, barHeight, SSD1306_WHITE);      // MID
  screen.drawRect(xTreble, baseY - barHeight, barWidth, barHeight, SSD1306_WHITE);   // TREBLE

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
