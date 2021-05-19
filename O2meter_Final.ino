/*Oxygen Analyser with OOM202, ADS1115
 * By, Karan Tarade info@anashwartech.com
 * +91 9604541318
 * Connections,
 * LCD I2C SLA- A5, SDA-A4
 * OOM202 - A0 of ADS1115
 * ADS1115 SLA- A5, SDA-A4
 */
 
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
// Set the LCD address to 0x27 or 0x3f for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 20, 4);
#include <Adafruit_ADS1015.h>
Adafruit_ADS1115 ads(0x48);
float Voltage = 0.0;
float Oxy = 0.0;

void setup(void)
{
  lcd.init();
  lcd.backlight();
  ads.setGain(GAIN_SIXTEEN);
  Serial.begin(9600);
  ads.begin();
  
}

void loop(void)
{
int16_t adc0; // 16 bits ADC read of input A0
adc0 = ads.readADC_SingleEnded(0);
Voltage = (float(adc0) * 0.1875 /15.28);
Oxy = float (((Voltage-21)/.97)+21);

  Serial.print("AIN0: ");
  Serial.print(adc0);
  Serial.print("\tVoltage: ");
  Serial.println(Voltage, 2);
  Serial.println();  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("   OXYGEN %   ");
  lcd.setCursor(3,1);
  lcd.print(Oxy,2);
delay(500);
}
