#include <Wire.h>
#include <LiquidCrystal_I2C.h>


#define LCD_I2C_ADDRESS 0x3f
#define LCD_DISP_COLS   16
#define LCD_DISP_ROWS   2

#include <MQUnifiedsensor.h>

#define         Board                    ("Arduino NANO")
#define         Pin3                     (A0)  //Analog input 0 of your arduino
#define         Pin4                     (A1)  //Analog input 1 of your arduino
#define         Pin135                   (A2)  //Analog input 2 of your arduino
#define         Pin7                     (A3)  //Analog input 3 of your arduino
#define         Pin8                     (A6)  //Analog input 6 of your arduino
#define         Pin9                     (A7)  //Analog input 7 of your arduino

LiquidCrystal_I2C lcd( LCD_I2C_ADDRESS, LCD_DISP_COLS, LCD_DISP_ROWS );


#define         RatioMQ3CleanAir          (60) //RS / R0 = 60 ppm 
#define         RatioMQ4CleanAir          (4.4) //RS / R0 = 4.4 ppm 
#define         RatioMQ135CleanAir        (3.6) //RS / R0 = 10 ppm 
#define         RatioMQ7CleanAir          (27.5) //RS / R0 = 27.5 ppm  
#define         RatioMQ8CleanAir          (70) //RS / R0 = 70 ppm   
#define         RatioMQ9CleanAir          (9.6) //RS / R0 = 9.6 ppm 
#define         ADC_Bit_Resolution        (10) // 10 bit ADC 
#define         Voltage_Resolution        (5) // Volt resolution to calc the voltage
#define         Type                      ("Arduino NANO") //Board used
//Declare Sensor
MQUnifiedsensor MQ3(Board, Voltage_Resolution, ADC_Bit_Resolution, Pin3, Type);
MQUnifiedsensor MQ4(Board, Voltage_Resolution, ADC_Bit_Resolution, Pin4, Type);
MQUnifiedsensor MQ135(Board, Voltage_Resolution, ADC_Bit_Resolution, Pin135, Type);
MQUnifiedsensor MQ7(Board, Voltage_Resolution, ADC_Bit_Resolution, Pin7, Type);
MQUnifiedsensor MQ8(Board, Voltage_Resolution, ADC_Bit_Resolution, Pin8, Type);
MQUnifiedsensor MQ9(Board, Voltage_Resolution, ADC_Bit_Resolution, Pin9, Type);
