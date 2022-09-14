#include "setup.h"
void setup() {
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();

  lcd.setCursor (0, 0);  lcd.print("                ");
  lcd.setCursor (0, 1);  lcd.print("                ");
  lcd.setCursor (0, 0);  lcd.print("       Air      ");
  lcd.setCursor (0, 1);  lcd.print("    Analyzer    ");
  delay(1000);
  lcd.setCursor (12, 1);  lcd.print(".");
  delay(1000);
  lcd.setCursor (13, 1);  lcd.print(".");
  delay(1000);
  lcd.setCursor (14, 1);  lcd.print(".");
  delay(1000);
  lcd.setCursor (15, 1);  lcd.print(".");
  delay(1000);
  lcd.clear();

  MQ3.init();
  MQ3.setRegressionMethod(1); //_PPM =  a*ratio^b
  MQ3.setR0(0.45);
  MQ4.init();
  MQ4.setRegressionMethod(1); //_PPM =  a*ratio^b
  MQ4.setR0(14.23);
  MQ135.init();
  MQ135.setRegressionMethod(1); //_PPM =  a*ratio^b
  MQ135.setR0(9.03);
  MQ7.init();
  MQ7.setRegressionMethod(1); //_PPM =  a*ratio^b
  MQ7.setR0(5.90);
  MQ8.init();
  MQ8.setRegressionMethod(1); //_PPM =  a*ratio^b
  MQ8.setR0(0.91);
  MQ9.init();
  MQ9.setRegressionMethod(1); //_PPM =  a*ratio^b
  MQ9.setR0(13.93);



  //While calibrating Your sensor Uncomment this calibration portion and calibrate for R0.
  /*****************************  MQ CAlibration ********************************************
    Serial.print("Calibrating please wait.");
    float  MQ3calcR0 = 0,
         MQ4calcR0 = 0,
         MQ135calcR0 = 0,
         MQ7calcR0 = 0,
         MQ8calcR0 = 0,
         MQ9calcR0 = 0;
    for (int i = 1; i <= 10; i ++)
    {
    //Update the voltage lectures
    MQ3.update();
    MQ4.update();
    MQ135.update();
    MQ7.update();
    MQ8.update();
    MQ9.update();

    MQ3calcR0 += MQ3.calibrate(RatioMQ3CleanAir);
    MQ4calcR0 += MQ4.calibrate(RatioMQ4CleanAir);
    MQ135calcR0 += MQ135.calibrate(RatioMQ135CleanAir);
    MQ7calcR0 += MQ7.calibrate(RatioMQ7CleanAir);
    MQ8calcR0 += MQ8.calibrate(RatioMQ8CleanAir);
    MQ9calcR0 += MQ9.calibrate(RatioMQ9CleanAir);

    Serial.print(".");
    }
    MQ3.setR0(MQ3calcR0 / 10);
    MQ4.setR0(MQ4calcR0 / 10);
    MQ135.setR0(MQ135calcR0 / 10);
    MQ7.setR0(MQ7calcR0 / 10);
    MQ8.setR0(MQ8calcR0 / 10);
    MQ9.setR0(MQ9calcR0 / 10);
    Serial.println("  done!.");

    Serial.print("(MQ3 - MQ9):");
    Serial.print(MQ3calcR0 / 10);   Serial.print(" | ");
    Serial.print(MQ4calcR0 / 10);   Serial.print(" | ");
    Serial.print(MQ135calcR0 / 10); Serial.print(" | ");
    Serial.print(MQ7calcR0 / 10);   Serial.print(" | ");
    Serial.print(MQ8calcR0 / 10);   Serial.print(" | ");
    Serial.print(MQ9calcR0 / 10);   Serial.println(" |");

    /*****************************  MQ CAlibration ********************************************/
}

void loop() {
  //Update the voltage lectures
  MQ3.update();
  MQ4.update();
  MQ135.update();
  MQ7.update();
  MQ8.update();
  MQ9.update();


  MQ3.setA(0.3934);
  MQ3.setB(-1.504); //Alcohol
  float Alcohol = MQ3.readSensor();

  MQ3.setA(4.8387);
  MQ3.setB(-2.68); //Benzene
  float Benzene = MQ3.readSensor();

  MQ3.setA(7585.3);
  MQ3.setB(-2.849); //Hexane
  float Hexane = MQ3.readSensor();

  MQ4.setA(1012.7);
  MQ4.setB(-2.786); //CH4
  float CH4 = MQ4.readSensor();

  MQ4.setA(30000000);
  MQ4.setB(-8.308); //smoke
  float smoke = MQ4.readSensor();

  MQ135.setA(110.47);
  MQ135.setB(-2.862); //CO2
  float CO2 = MQ135.readSensor();

  MQ135.setA(44.947);
  MQ135.setB(-3.445); // Toluene
  float Toluene = MQ135.readSensor();

  MQ135.setA(102.2 );
  MQ135.setB(-2.473); //NH4
  float NH4 = MQ135.readSensor();

  MQ135.setA(34.668);
  MQ135.setB(-3.369); //Acetone
  float Acetone = MQ135.readSensor();

  MQ7.setA(99.042);
  MQ7.setB(-1.518); //CO
  float CO = MQ7.readSensor();

  MQ8.setA(976.97);
  MQ8.setB(-0.688); // H2
  float H2 = MQ8.readSensor();

  MQ9.setA(1000.5);
  MQ9.setB(-2.186); //flamable gas
  float FG = MQ9.readSensor();



  Serial.print("Alcohol:  "); Serial.println(Alcohol);
  Serial.print("Benzene:  "); Serial.println(Benzene);
  Serial.print("Hexane:   "); Serial.println(Hexane);
  Serial.print("Methane:  "); Serial.println(CH4);
  Serial.print("Smoke:    "); Serial.println(smoke);
  Serial.print("CO2:      "); Serial.println(CO2);
  Serial.print("Toluene:  "); Serial.println(Toluene);
  Serial.print("NH4:      "); Serial.println(NH4);
  Serial.print("Acetone:  "); Serial.println(Acetone);
  Serial.print("CO:       "); Serial.println(CO);
  Serial.print("H2:       "); Serial.println(H2);
  Serial.print("FG:       "); Serial.println(FG);
  Serial.println("--------------------------------------------------------");

  lcd.clear();
  delay(70);
  lcd.setCursor (0, 0);   lcd.print("Alcohol ");  lcd.print(Alcohol);
  lcd.setCursor (13, 0);  lcd.print("ppm");
  lcd.setCursor (0, 1);   lcd.print("Benzene ");  lcd.print(Benzene);
  lcd.setCursor (13, 1);  lcd.print("ppm");
  delay(3000);

  lcd.clear();
  delay(70);
  lcd.setCursor (0, 0);   lcd.print("Hexane  ");  lcd.print(Hexane);
  lcd.setCursor (13, 0);  lcd.print("ppm");
  lcd.setCursor (0, 1);   lcd.print("CH4     ");  lcd.print(CH4);
  lcd.setCursor (13, 1);  lcd.print("ppm");
  delay(3000);


  lcd.clear();
  delay(70);
  lcd.setCursor (0, 0);   lcd.print("Smoke   ");  lcd.print(smoke);
  lcd.setCursor (13, 0);  lcd.print("ppm");
  lcd.setCursor (0, 1);   lcd.print("CO2     ");  lcd.print(CO2);
  lcd.setCursor (13, 1);  lcd.print("ppm");
  delay(3000);


  lcd.clear();
  delay(70);
  lcd.setCursor (0, 0);   lcd.print("Toluene ");  lcd.print(Toluene);
  lcd.setCursor (13, 0);  lcd.print("ppm");
  lcd.setCursor (0, 1);   lcd.print("NH4     ");  lcd.print(NH4);
  lcd.setCursor (13, 1);  lcd.print("ppm");
  delay(3000);


  lcd.clear();
  delay(70);
  lcd.setCursor (0, 0);   lcd.print("Acetone ");  lcd.print(Acetone);
  lcd.setCursor (13, 0);  lcd.print("ppm");
  lcd.setCursor (0, 1);   lcd.print("CO      ");  lcd.print(CO);
  lcd.setCursor (13, 1);  lcd.print("ppm");
  delay(3000);


  lcd.clear();
  delay(70);
  lcd.setCursor (0, 0);   lcd.print("H2      ");  lcd.print(H2);
  lcd.setCursor (13, 0);  lcd.print("ppm");
  lcd.setCursor (0, 1);   lcd.print("FG      ");  lcd.print(FG);
  lcd.setCursor (13, 1);  lcd.print("ppm");
  delay(3000);

}
