//"Hello World" Arduino sketch to test the LCD1602 wiring and library

#include <LiquidCrystal.h>

// LCD pins: RS, E, D4, D5, D6, D7 (change these for your wiring)
const int rs = 7, en = 8, d4 = 3, d5 = 4, d6 = 5, d7 = 6;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);         // Initialize the LCD with 16 columns and 2 rows
  lcd.print("Hello, World!"); // Print Hello World on the first line
}

void loop() {
  // Optional: Display time since startup on second line
  lcd.setCursor(0, 1);
  lcd.print(millis()/1000);
  delay(1000);
}
