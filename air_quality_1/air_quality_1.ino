#include "setup.h"
void setup() {
  Serial.begin(9600);

  pinMode(sensor, INPUT);
  dht.begin();
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3c)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
  }
  display.clearDisplay();
  display.setTextColor(WHITE);

  display.setTextSize(2);  display.setCursor(50, 0);   display.println("Air");
  display.setTextSize(1);  display.setCursor(23, 20);  display.println("Qulaity monitor");
  display.display();
  delay(1200);
  display.clearDisplay();
}

void loop() {
  display.clearDisplay();
  air_sensor();
  sendSensor();
  display.display();
}
