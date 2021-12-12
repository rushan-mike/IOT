#include <Wire.h>

int brightness = 0;
int time = 5;
int fade = 5;
byte state = 1;

void setup(){
  int pin = 2;

  while (true){

    pin = pin + 1;
    pinMode(pin, OUTPUT);
    if (pin == 14 ) break;

  }

  pinMode(15, INPUT_PULLUP);

  Wire.begin();
}


void loop(){

  if (digitalRead(15) == HIGH){

    Wire.beginTransmission(1);
    Wire.write(state);
    Wire.endTransmission();

    lightUP(4, 14, true);
    lightUP(4, 14, false);
    delay(time*10 - time);

    lightUP(14, 4, true);
    lightUP(14, 4, false);
    delay(time*100 - time);
    
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