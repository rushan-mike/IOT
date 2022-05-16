#include <SoftwareSerial.h>

// SoftwareSerial mySerial(7, 8); // RX, TX
SoftwareSerial mySerial(3, 2); // RX, TX

void setup()
{
  // Open serial communications and wait for port to open:
  // Serial.begin(9600);
  Serial.begin(38400);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Native USB only
  }

  Serial.println("TEST");
  
  // set the data rate for the SoftwareSerial port
  // mySerial.begin(38400); // Bluetooth
  mySerial.begin(9600);

  //Bluetooth test command
  mySerial.println("AT");
}

void loop() // run over and over
{
  updateSerial();
}

void updateSerial()
{
  delay(500);
  while (Serial.available()) 
  {
    mySerial.write(Serial.read());//Forward what Serial received to Software Serial Port
  }
  while(mySerial.available()) 
  {
    Serial.write(mySerial.read());//Forward what Software Serial received to Serial Port
  }
}
