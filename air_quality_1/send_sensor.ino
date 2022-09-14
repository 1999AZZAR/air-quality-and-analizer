void sendSensor()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setFont();
  display.setCursor(0, 43);    display.println("Temp  :");
  display.setCursor(80, 43);   display.println(t);
  display.setCursor(114, 43);  display.println("C");
  display.setCursor(0, 56);    display.println("RH    :");
  display.setCursor(80, 56);   display.println(h);
  display.setCursor(114, 56);  display.println("%");
}
