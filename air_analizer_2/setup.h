#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"
#define DHTPIN 13
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

#define LCD_I2C_ADDRESS 0x3f
#define LCD_DISP_COLS   16
#define LCD_DISP_ROWS   2
LiquidCrystal_I2C lcd( LCD_I2C_ADDRESS, LCD_DISP_COLS, LCD_DISP_ROWS );

const int mq2   = A0;
const int mq4   = A1;
const int mq5   = A2;
const int mq135 = A3;

float m  = -0.6527;
float b  = 1.30;
float R0 = 21.91;
