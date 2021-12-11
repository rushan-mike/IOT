#include <SoftwareSerial.h>

SoftwareSerial mySerial(7, 8); // RX, TX

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Native USB only
  }

  Serial.println("TEST");
  
  // set the data rate for the SoftwareSerial port
  mySerial.begin(38400);

  //Bluetooth test command
  mySerial.println("AT");
}

void loop() // run over and over
{
  if (mySerial.available()){
    Serial.println(mySerial.readString());
  };
  
  if (Serial.available()){
    mySerial.println(Serial.readString());
    Serial.println();
  };
}
