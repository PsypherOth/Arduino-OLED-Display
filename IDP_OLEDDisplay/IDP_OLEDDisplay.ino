#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET_PIN -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 screen(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET_PIN);
void setup() {
  /*
  Wire.begin();
  Serial.begin(9600);
  Serial.println("Scanning...");
  for (byte i = 8; i < 120; i++) {
    Wire.beginTransmission(i);
    if (Wire.endTransmission() == 0) {
      Serial.print("I2C device found at 0x");
      Serial.println(i, HEX);
    }
    delay(10);
  }
  */
  
  Serial.begin(9600);
  Serial.println("Initializing OLED...");
  /*
  if (!screen.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println("SSD1306 initialization failed!");
    while (true);
  }
  */
  screen.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  Serial.println("SSD1306 initialization successfully!");
  delay(100);
  delay(100);
  screen.display();
  delay(300);
  screen.clearDisplay();
  screen.display();
  screen.setTextSize(1);
  screen.setTextColor(SSD1306_WHITE);
  screen.setCursor(0, 0);

  screen.print("Tempurature:");
  screen.display();
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
