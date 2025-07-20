
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

// Define pins
#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
Adafruit_SSD1306 display(128, 64, &Wire, -1); // For 128x32, use (128, 32, ...)

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
  // Initialize display
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C typical
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Halt
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
}

void loop() {
  // put your main code here, to run repeatedly:
  float h = dht.readHumidity();
  float tempC = dht.readTemperature(); //celsius
  float t = tempC * 1.8 + 32;          // Fahrenheit

  display.clearDisplay();
  display.setTextSize(1);

  //Banner in small text size of 5 px
  display.setCursor(0, 0);
  display.print((char)1);
  display.print((char)1);
  display.print(" Weather Station ");
  display.print((char)1);
  display.print((char)1);

  //Weather data in large text size 3=15px
  display.setTextSize(3);

  display.setCursor(0, 15);
  display.print("");
  if (isnan(t)) {
    display.print("Err");
  } else {
    display.print(t);
    display.print((char)247); 
    display.print("F");
  }
  display.setCursor(0, 45);
  display.print("");
  if (isnan(h)) {
    display.print("Err");
  } else {
    display.print(h);
    display.print(" %");
  }
//   display.setCursor(0, 50);
  display.display();
  delay(2000);
}
