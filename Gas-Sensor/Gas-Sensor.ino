#define MQ2pin1 0
#define MQ2pin2 1

float sensor1Value;  //variable to store sensor1 value
float sensor2Value;  //variable to store sensor2 value

void setup()
{
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
  delay(2000); // wait 2s for next reading
}