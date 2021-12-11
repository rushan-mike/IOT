#include <SPI.h>
#include <SD.h>

File myFile;
char myPath[] = "data.txt";

void setup() {

    Serial.begin(9600);

    while (!Serial) {
      ;
    }

    Serial.println("Initializing SD card...");

    if (!SD.begin(10)) {
        Serial.println("Initialization failed!");
        while (1);
    }
    
    Serial.println("Initialization done.");

    
    myFile = SD.open(myPath, FILE_WRITE);

    if (myFile) {
        Serial.print("Writing to ");
        Serial.print(myPath);
        Serial.println("...");

        for (int i = 0; i < 20; i++) {
            myFile.println(i+1);
        }
    
        myFile.close();
        Serial.println("Done.");
    } 
    
    else {
        Serial.println("Error opening ");
        Serial.println(myPath);
    }

    
    myFile = SD.open(myPath, FILE_READ);

    if (myFile) {
        Serial.print("Reading from ");
        Serial.print(myPath);
        Serial.println("...");

        while (myFile.available()) {
            Serial.write(myFile.read());
        }

        myFile.close();
    } 
    
    else {
        Serial.print("Error opening ");
        Serial.println(myPath);
    }


    if (SD.exists(myPath)){
        Serial.println("File exists");
        SD.remove(myPath);
        Serial.println("File removed");
    }
}


void loop() {
// nothing happens after setup
}
