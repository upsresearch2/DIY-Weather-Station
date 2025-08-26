//Indoor weather station
//Arduino, DHT11, LCD1602 without I2C, potentiometer

#include <DHT.h>
#include <LiquidCrystal.h>

// Pin definitions - change if you use different wiring!
#define DHTPIN 2           // DHT11 data pin connected to digital pin 2
#define DHTTYPE DHT11      // DHT 11

DHT dht(DHTPIN, DHTTYPE);

// LCD pins: RS, E, D4, D5, D6, D7 (change these for your wiring)
LiquidCrystal lcd(7, 8, 3, 4, 5, 6);

void setup() {
  lcd.begin(16, 2);  // 16 columns, 2 rows
  dht.begin();
  lcd.print("DHT11 Weather");
  delay(2000);
  lcd.clear();
}

void loop() {
  float h = dht.readHumidity();
  float c = dht.readTemperature(); // Celsius
  float f = c * 9 / 5 + 32;        // Convert to Fahrenheit

  lcd.setCursor(0, 0);
    lcd.print("Temp: ");
  lcd.print(c, 0);
  lcd.print((char)223); // degree symbol
  lcd.print("C ");
  lcd.print(f, 1);
  lcd.print((char)223); // degree symbol
  lcd.print("F");
  

  lcd.setCursor(0, 1);
  lcd.print("Humidity:  ");
  lcd.print(h, 1); // 1 decimal place
  lcd.print("%   ");

  delay(2000);
}
