#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

byte dino[8]={
  B01110,  
  B01110,  
  B01100,  
  B01111,  
  B11101,  
  B01010,  
  B01010,  
  B01010
};

byte heart[8] = {
  B00000,
  B01010,
  B10101,
  B10001,
  B01010,
  B00100,
  B00000,
  B00000
};

byte smiley[8] = {
  B00000,
  B10001,
  B00000,
  B00000,
  B10001,
  B01110,
  B00000,
};

byte man[8] = {
  B01110,
  B01110,
  B00100,
  B01110,
  B10101,
  B00100,
  B01010,
  B10001
};

void setup(){
  
  lcd.begin();
  lcd.clear();
  lcd.noBacklight();
  lcd.createChar(0, dino);
  lcd.createChar(1, heart);
  lcd.createChar(2, smiley);
  lcd.createChar(3, man);
  
}

void loop(){

  lcd.display();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.write(byte(0));
  delay(1000);

  lcd.setCursor(4,0);
  lcd.write(byte(1));
  delay(1000);

  lcd.setCursor(8,0);
  lcd.write(byte(2));
  delay(1000);

  lcd.setCursor(12,0);
  lcd.write(byte(3));
  delay(1000);

  // int scroll = 0;
  
  // while(true){
    
  //   lcd.scrollDisplayLeft();
  //   delay(1000);
  
  //   scroll = scroll +1;
  //   if (scroll == 20) break;
  
  // }

  lcd.noDisplay();
  delay(1000);

  // lcd.noBacklight();
  lcd.clear();

}
