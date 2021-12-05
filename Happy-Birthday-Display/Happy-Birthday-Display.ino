#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup(){
  
  lcd.begin();
  lcd.clear();
  lcd.noBacklight();
  
}

void loop(){

  lcd.display();
  
  lcd.blink();
  delay(2000);

  lcd.backlight();
  delay(2000);
  
  lcd.noBlink();
  delay(1000);

  lcd.setCursor(0,0);
  lcd.print("happy birthday !!!");
  delay(1000);

  int scroll = 0;
  
  while(true){
    
    lcd.scrollDisplayLeft();
    delay(1000);
  
    scroll = scroll +1;
    if (scroll == 20) break;
  
  }

  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print("hello kitty");
  delay(1000);

  lcd.noDisplay();
  delay(1000);
  
  lcd.display();
  delay(1000);

  lcd.noDisplay();
  delay(1000);
  
  lcd.display();
  delay(1000);

  lcd.noDisplay();
  delay(1000);
  
  lcd.clear();

  lcd.noBacklight();
  delay(1000);

}
