#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);
int temp= 37;
void setup()
{
  lcd.init();
  lcd.backlight();

}


void loop()
{
  lcd.setCursor(2, 0);
  lcd.print("LAB TEMPERATURE");
  lcd.setCursor(4, 1);
  lcd.print("TEMPERATURE");
  lcd.setCursor(9, 2);
  lcd.print(temp);
  lcd.setCursor(3, 3);
  lcd.print("Degree Celsius");
}
