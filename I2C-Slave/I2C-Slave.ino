#include <Wire.h>

byte state;

void setup() 
{
  Wire.begin(1);
  Serial.begin(9600);
}

void loop() 
{
  Wire.onReceive(receiveEvent);
  delay(100);
}

void receiveEvent(int numBytes){
  state = Wire.read();
  // Serial.println(state);

  if (state == 1){
    Serial.println("Welcome Michael");
  }
}
