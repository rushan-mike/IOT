#include <Wire.h>

#define MQ2pin1 0
#define MQ2pin2 1

float sensor1Value;  //variable to store sensor1 value
float sensor2Value;  //variable to store sensor2 value

//variables to store I2C data
byte writeDataBytes[2];
int writeData;
int MQ2pin;

void setup()
{
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register receive event
  Wire.onRequest(requestEvent); // register request event

  Serial.begin(9600); // sets the serial port to 9600
  Serial.println("Gas sensor warming up!");
  // delay(20000); // allow the MQ-6 to warm up
}

void loop()
{
  sensor1Value = analogRead(MQ2pin1); // read analog input pin 0
  sensor2Value = analogRead(MQ2pin2); // read analog input pin 1
  
  Serial.print("Sensor1 Value: ");
  Serial.print(sensor1Value);
  
  if(sensor1Value > 300)
  {
    Serial.print(" | Smoke detected!");
  }
  else
  {
    Serial.print("                  ");
  }

  Serial.print("    Sensor2 Value: ");
  Serial.print(sensor2Value);
  
  if(sensor2Value > 300)
  {
    Serial.print(" | Smoke detected!");
  }
  
  Serial.println("");
  // delay(2000); // wait 2s for next reading
}

void receiveEvent(int howMany)
{
  MQ2pin = Wire.read();    // receive byte as an integer
  
  if (MQ2pin == 1){
    writeData = sensor1Value;
    // Serial.println(sensor1Value);
    // Serial.println("");
  }

  if (MQ2pin == 2){
    writeData = sensor2Value;
    // Serial.println(sensor2Value);
    // Serial.println("");
  }
}

void requestEvent() {

  writeDataBytes[0] = (writeData >> 8) & 0xFF;
  writeDataBytes[1] = (writeData >> 0) & 0xFF;

  // Serial.print(writeDataBytes[0]);
  // Serial.print("    ");
  // Serial.print(writeDataBytes[1]);
  // Serial.println("");

  Wire.write(writeDataBytes,2); // respond with message of 2 bytes
  // Serial.println(writeData);
  // Serial.println("");
}
