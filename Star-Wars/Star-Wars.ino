#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include "pitches.h"
#define melodyPin 3
#define REST    0

LiquidCrystal_I2C lcd(0x27, 16, 2);

int Star_melody[] = {
  
  NOTE_AS4, NOTE_AS4, NOTE_AS4,//1
  NOTE_F5, NOTE_C6,
  NOTE_AS5, NOTE_A5, NOTE_G5, NOTE_F6, NOTE_C6,  
  NOTE_AS5, NOTE_A5, NOTE_G5, NOTE_F6, NOTE_C6,  
  NOTE_AS5, NOTE_A5, NOTE_AS5, NOTE_G5, NOTE_C5, NOTE_C5, NOTE_C5,
  NOTE_F5, NOTE_C6,
  NOTE_AS5, NOTE_A5, NOTE_G5, NOTE_F6, NOTE_C6,  
  
  NOTE_AS5, NOTE_A5, NOTE_G5, NOTE_F6, NOTE_C6, //8  
  NOTE_AS5, NOTE_A5, NOTE_AS5, NOTE_G5, NOTE_C5, NOTE_C5, 
  NOTE_D5, NOTE_D5, NOTE_AS5, NOTE_A5, NOTE_G5, NOTE_F5,
  NOTE_F5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_D5, NOTE_E5, NOTE_C5, NOTE_C5,
  NOTE_D5, NOTE_D5, NOTE_AS5, NOTE_A5, NOTE_G5, NOTE_F5,
  
  NOTE_C6, NOTE_G5, NOTE_G5, REST, NOTE_C5,//13
  NOTE_D5, NOTE_D5, NOTE_AS5, NOTE_A5, NOTE_G5, NOTE_F5,
  NOTE_F5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_D5, NOTE_E5, NOTE_C6, NOTE_C6,
  NOTE_F6, NOTE_DS6, NOTE_CS6, NOTE_C6, NOTE_AS5, NOTE_GS5, NOTE_G5, NOTE_F5,
  NOTE_C6
  
};



int Star_tempo[] = {
  
  8, 8, 8,//1
  2, 2,
  8, 8, 8, 2, 4,  
  8, 8, 8, 2, 4,  
  8, 8, 8, 2, 8, 8, 8,
  2, 2,
  8, 8, 8, 2, 4,  
  
  8, 8, 8, 2, 4, //8  
  8, 8, 8, 2, 8, 16, 
  4, 8, 8, 8, 8, 8,
  8, 8, 8, 4, 8, 4, 8, 16,
  4, 8, 8, 8, 8, 8,
  
  8, 16, 2, 8, 8,//13
  4, 8, 8, 8, 8, 8,
  8, 8, 8, 4, 8, 4, 8, 16,
  4, 8, 4, 8, 4, 8, 4, 8,
  1
  
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

    lightUP(4, 14, true);
    // lightUP(4, 14, false);
    // delay(time*10 - time);

    soundUP();

    // lightUP(14, 4, true);
    lightUP(14, 4, false);
    // delay(time*100 - time);

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
  lcd.print("Star Wars");

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

  int size = sizeof(Star_melody) / sizeof(int);

  for (int thisNote = 0; thisNote < size; thisNote++) {

    int noteDuration = 1400 / Star_tempo[thisNote];
    tone(melodyPin, Star_melody[thisNote], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);

    noTone(melodyPin);

  }
}