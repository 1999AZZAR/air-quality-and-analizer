void air_sensor()
{
  gasLevel = analogRead(sensor);

  if (gasLevel < 181) {
    quality = "  GOOD!";
  }
  else if (gasLevel > 181 && gasLevel < 225) {
    quality = "  Poor!";
  }
  else if (gasLevel > 225 && gasLevel < 300) {
    quality = "Very bad!";
  }
  else if (gasLevel > 300 && gasLevel < 350) {
    quality = "ur dead!";
  }
  else {
    quality = " Toxic";
  }

  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(1, 5);
  display.setFont();
  display.println("Air Quality:");
  display.setTextSize(1);
  display.setCursor(20, 23);
  display.setFont(&FreeMonoOblique9pt7b);
  display.println(quality);
}
