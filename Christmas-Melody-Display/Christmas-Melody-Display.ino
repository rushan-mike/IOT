#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include "pitches.h"
#define melodyPin 3

LiquidCrystal_I2C lcd(0x27, 16, 2);

int Merry_melody[] = {

  NOTE_C5, //1
  NOTE_F5, NOTE_F5, NOTE_G5, NOTE_F5, NOTE_E5,
  NOTE_D5, NOTE_D5, NOTE_D5,
  NOTE_G5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_F5,
  NOTE_E5, NOTE_C5, NOTE_C5,
  NOTE_A5, NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_G5,
  NOTE_F5, NOTE_D5, NOTE_C5, NOTE_C5,
  NOTE_D5, NOTE_G5, NOTE_E5,

  NOTE_F5, NOTE_C5, //8 
  NOTE_F5, NOTE_F5, NOTE_G5, NOTE_F5, NOTE_E5,
  NOTE_D5, NOTE_D5, NOTE_D5,
  NOTE_G5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_F5,
  NOTE_E5, NOTE_C5, NOTE_C5,
  NOTE_A5, NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_G5,
  NOTE_F5, NOTE_D5, NOTE_C5, NOTE_C5,
  NOTE_D5, NOTE_G5, NOTE_E5,
  NOTE_F5, NOTE_C5,

  NOTE_F5, NOTE_F5, NOTE_F5,//17
  NOTE_E5, NOTE_E5,
  NOTE_F5, NOTE_E5, NOTE_D5,
  NOTE_C5, NOTE_A5,
  NOTE_AS5, NOTE_A5, NOTE_G5,
  NOTE_C6, NOTE_C5, NOTE_C5, NOTE_C5,
  NOTE_D5, NOTE_G5, NOTE_E5,
  NOTE_F5, NOTE_C5, 
  NOTE_F5, NOTE_F5, NOTE_G5, NOTE_F5, NOTE_E5,
  NOTE_D5, NOTE_D5, NOTE_D5,
  
  NOTE_G5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_F5, //27
  NOTE_E5, NOTE_C5, NOTE_C5,
  NOTE_A5, NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_G5,
  NOTE_F5, NOTE_D5, NOTE_C5, NOTE_C5,
  NOTE_D5, NOTE_G5, NOTE_E5,
  NOTE_F5, NOTE_C5,
  NOTE_F5, NOTE_F5, NOTE_F5,
  NOTE_E5, NOTE_E5,
  NOTE_F5, NOTE_E5, NOTE_D5,
  
  NOTE_C5, NOTE_A5,//36
  NOTE_AS5, NOTE_A5, NOTE_G5,
  NOTE_C6, NOTE_C5, NOTE_C5, NOTE_C5,
  NOTE_D5, NOTE_G5, NOTE_E5,
  NOTE_F5, NOTE_C5, 
  NOTE_F5, NOTE_F5, NOTE_G5, NOTE_F5, NOTE_E5,
  NOTE_D5, NOTE_D5, NOTE_D5,
  NOTE_G5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_F5, 
  NOTE_E5, NOTE_C5, NOTE_C5,
  
  NOTE_A5, NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_G5,//45
  NOTE_F5, NOTE_D5, NOTE_C5, NOTE_C5,
  NOTE_D5, NOTE_G5, NOTE_E5,
  NOTE_F5, NOTE_C5,
  NOTE_F5, NOTE_F5, NOTE_G5, NOTE_F5, NOTE_E5,
  NOTE_D5, NOTE_D5, NOTE_D5,
  NOTE_G5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_F5,
  NOTE_E5, NOTE_C5, NOTE_C5,
  
  NOTE_A5, NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_G5, //53
  NOTE_F5, NOTE_D5, NOTE_C5, NOTE_C5,
  NOTE_D5, NOTE_G5, NOTE_E5,
  NOTE_F5
};



int Merry_tempo[] = {
  
  4, //1
  4, 8, 8, 8, 8,
  4, 4, 4,
  4, 8, 8, 8, 8,
  4, 4, 4,
  4, 8, 8, 8, 8,
  4, 4, 8, 8,
  4, 4, 4,

  2, 4, //8 
  4, 8, 8, 8, 8,
  4, 4, 4,
  4, 8, 8, 8, 8,
  4, 4, 4,
  4, 8, 8, 8, 8,
  4, 4, 8, 8,
  4, 4, 4,
  2, 4,

  4, 4, 4,//17
  2, 4,
  4, 4, 4,
  2, 4,
  4, 4, 4,
  4, 4, 8, 8,
  4, 4, 4,
  2, 4, 
  4, 8, 8, 8, 8,
  4, 4, 4,
  
  4, 8, 8, 8, 8, //27
  4, 4, 4,
  4, 8, 8, 8, 8,
  4, 4, 8, 8,
  4, 4, 4,
  2, 4,
  4, 4, 4,
  2, 4,
  4, 4, 4,
  
  2, 4,//36
  4, 4, 4,
  4, 4, 8, 8,
  4, 4, 4,
  2, 4, 
  4, 8, 8, 8, 8,
  4, 4, 4,
  4, 8, 8, 8, 8, 
  4, 4, 4,
  
  4, 8, 8, 8, 8,//45
  4, 4, 8, 8,
  4, 4, 4,
  2, 4,
  4, 8, 8, 8, 8,
  4, 4, 4,
  4, 8, 8, 8, 8,
  4, 4, 4,
  
  4, 8, 8, 8, 8, //53
  4, 4, 8, 8,
  4, 4, 4,
  2
};

int brightness = 0;
int time = 5;
int fade = 5;

void setup(){
  
  lcd.begin();
  lcd.clear();
  
  lcd.blink();
  delay(2000);
  
  lcd.noBlink();
  delay(1000);
  
  lcd.noBacklight();

    int pin = 2;

  while (true){

    pin = pin + 1;
    pinMode(pin, OUTPUT);
    if (pin == 14 ) break;

  }

  pinMode(15, INPUT_PULLUP);
  
}

void loop(){

  if (digitalRead(15) == HIGH){

    displayUP();

    // lightUP(4, 14, true);
    // lightUP(4, 14, false);
    // delay(time*10 - time);

    // lightUP(14, 4, true);
    // lightUP(14, 4, false);
    // delay(time*100 - time);

    soundUP();

    displayDOWN(); 
  }

}


void lightUP(int start, int end, bool state){

  while (true){
    
    delay(time);
    if (state == true) brightness = 0;
    if (state == false) brightness = 255;

    while (true){

      delay(time/5);
      analogWrite(start, brightness);

      if (state == true && brightness == 255) break;
      if (state == false && brightness == 0) break;
      if (state == true) brightness = brightness + fade;
      if (state == false) brightness = brightness - fade;
    }

    if (start == end) break;
    if (start < end) start = start + 1; 
    if (start > end) start = start - 1; 
  }

}


void displayUP(){

  lcd.display();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Merry Christmas");

  // int scroll = 0;
  
  // while(true){
    
  //   lcd.scrollDisplayLeft();
  //   delay(1000);
  
  //   scroll = scroll +1;
  //   if (scroll == 20) break;
  
  // }

}

void displayDOWN(){

  lcd.noDisplay();
  delay(1000);
  
  lcd.noBacklight();
  lcd.clear();

}


void soundUP() {

  int size = sizeof(Merry_melody) / sizeof(int);

  for (int thisNote = 0; thisNote < size; thisNote++) {

    int noteDuration = 1400 / Merry_tempo[thisNote];
    tone(melodyPin, Merry_melody[thisNote], noteDuration);

    int random_number = random(4, 14);
    digitalWrite(random_number, HIGH);

    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);

    noTone(melodyPin);
    digitalWrite(random_number, LOW);

  }
}