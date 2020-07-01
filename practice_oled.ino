#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <Wire.h>

Adafruit_SSD1306 oled = Adafruit_SSD1306(128, 32, &Wire);
void setup()
{
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  oled.begin(0x3C); // Address 0x3C for 128x32
  oled.clearDisplay();
  oled.setCursor(0, 0);
  oled.setTextColor(SSD1306_WHITE);
  oled.setTextSize(1);
  oled.println("Pin ");

  oled.display();
  pinMode(2, OUTPUT); pinMode(3, OUTPUT); pinMode(4, OUTPUT);
  pinMode(5, OUTPUT); pinMode(6, OUTPUT); pinMode(7, OUTPUT);
  pinMode(8, OUTPUT); pinMode(9, OUTPUT); pinMode(10, OUTPUT);
  pinMode(11, OUTPUT); pinMode(12, OUTPUT); pinMode(13, OUTPUT);
  delay(2000);
}
//------------------------------------------------
void loop()
{
  int pin = 0;
  for (pin = 0; pin <= 13; pin++)
  {
    digitalWrite(pin, 1);
    delay(1000);
    digitalWrite(pin, 0);
    oled.clearDisplay();
    oled.setCursor(pin, 0);
    oled.setTextColor(SSD1306_WHITE);
    oled.setTextSize(1);
    oled.print("Pin ");
    oled.print(pin);
    oled.display();
    delay(1000);
  }

}
