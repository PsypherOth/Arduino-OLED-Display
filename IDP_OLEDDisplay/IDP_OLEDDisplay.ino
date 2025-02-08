#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET_PIN -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 screen(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET_PIN);
void setup() {
  // put your setup code here, to run once:
  screen.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);

  screen.clearDisplay();
}

void loop() {
  // put your main code here, to run repeatedly:

}
