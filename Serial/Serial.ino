//#include <SoftwareSerial.h>

char WriteData[5] = "AT"; //String data
char ReadData[10]; //Initialized variable to store recieved data

void setup() {
  //GPIO 1 (TX) swap the pin to a TX.
  //pinMode(1, FUNCTION_0); 
  //GPIO 3 (RX) swap the pin to a RX.
  //pinMode(3, FUNCTION_0);
  // Begin the Serial at 9600 Baud
  Serial.begin(9600);
  Serial.println("TEST");
}

void loop() {
  Serial.write(WriteData,5); //Write the serial data
  delay(1000);
  Serial.readBytes(ReadData,5); //Read the serial data and store in var
  Serial.println(ReadData); //Print data on Serial Monitor
  delay(1000);
}
