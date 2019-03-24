#include <LiquidCrystal_I2C.h>
#include "MAX6675.h"
esl::MAX6675 thermocouple( 12, 11, 13 );
LiquidCrystal_I2C lcd(0x27, 20, 4);
float temp = 0;
float sentem =0;
void setup()
{
  Serial.begin(115200);
  Serial.println( "Reading Temperature from K-type Thermocouple..." );
  pinMode(10,OUTPUT);
  lcd.init();
  lcd.backlight();

}


void loop()
{
  if ( thermocouple.isInputOpen() ) {
    Serial.println( "Please check the thermocouple." );
    delay( 2000 );
  } else {
    Serial.println( thermocouple.readTemperature() );
    delay( 500 );
  }
  //temp = 0;
  temp = thermocouple.readTemperature();
  sentem = ((temp*256)/200);
  Serial.println( sentem);
  analogWrite(10, sentem);
  lcd.setCursor(2, 0);
  lcd.print("LAB TEMPERATURE");
  lcd.setCursor(4, 1);
  lcd.print("TEMPERATURE");
  lcd.setCursor(7, 2);
  lcd.print(temp);
  lcd.setCursor(3, 3);
  lcd.print("Degree Celsius");
 Serial.println("//////////////////////////////////////////////////////");
}
