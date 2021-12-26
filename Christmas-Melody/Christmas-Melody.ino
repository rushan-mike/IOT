#include "pitches.h"
#define melodyPin 5

// Jingle Bells

int Jingle_melody[] = {
  NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_G5, NOTE_C5, NOTE_D5,
  NOTE_E5,
  NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5,
  NOTE_F5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_D5, NOTE_D5, NOTE_E5,
  NOTE_D5, NOTE_G5
};

int Jingle_tempo[] = {
  8, 8, 4,
  8, 8, 4,
  8, 8, 8, 8,
  2,
  8, 8, 8, 8,
  8, 8, 8, 16, 16,
  8, 8, 8, 8,
  4, 4
};

// Santa Claus is coming to town

int santa_melody[] = {
  NOTE_G4,
  NOTE_E4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_G4,
  NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, NOTE_C5,
  NOTE_E4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_G4,
  NOTE_A4, NOTE_G4, NOTE_F4, NOTE_F4,
  NOTE_E4, NOTE_G4, NOTE_C4, NOTE_E4,
  NOTE_D4, NOTE_F4, NOTE_B3,
  NOTE_C4
};

int santa_tempo[] = {
  8,
  8, 8, 4, 4, 4,
  8, 8, 4, 4, 4,
  8, 8, 4, 4, 4,
  8, 8, 4, 2,
  4, 4, 4, 4,
  4, 2, 4,
  1
};

// We wish you a merry Christmas

int wish_melody[] = {
  NOTE_B3, 
  NOTE_F4, NOTE_F4, NOTE_G4, NOTE_F4, NOTE_E4,
  NOTE_D4, NOTE_D4, NOTE_D4,
  NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_F4,
  NOTE_E4, NOTE_E4, NOTE_E4,
  NOTE_A4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_G4,
  NOTE_F4, NOTE_D4, NOTE_B3, NOTE_B3,
  NOTE_D4, NOTE_G4, NOTE_E4,
  NOTE_F4
};

int wish_tempo[] = {
  4,
  4, 8, 8, 8, 8,
  4, 4, 4,
  4, 8, 8, 8, 8,
  4, 4, 4,
  4, 8, 8, 8, 8,
  4, 4, 8, 8,
  4, 4, 4,
  2
};

int intNumber = 0;
String stringNumber = "0";

void setup(void) {
  Serial.begin(57600);
  Serial.println("Welcome");
  Serial.println();
}

void loop() {

  if (Serial.available() > 0) {

    stringNumber = Serial.readString();
    Serial.println(stringNumber);
    Serial.println();
    intNumber = stringNumber.toInt();

    if (intNumber == 0) {
        
        Serial.print("----- Exit -----");
        Serial.println();
        Serial.end();
    }

    Serial.print("Playing song : " + String(intNumber));
    Serial.println();
    Serial.println();
    
  }
  
  if (intNumber == 1) sing(1); 
  if (intNumber == 2) sing(2);
  if (intNumber == 3) sing(3);
}

int song = 0;

void sing(int s) {

  song = s;
  if (song == 1) {
    Serial.println("'Jingle Bells'");
    Serial.println();
    int size = sizeof(Jingle_melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {
      int noteDuration = 1200 / Jingle_tempo[thisNote];
      tone(melodyPin, Jingle_melody[thisNote], noteDuration);
    //   buzz(melodyPin, Jingle_melody[thisNote], noteDuration);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      noTone(melodyPin);
    //   buzz(melodyPin, 0, noteDuration);
    }
    intNumber = 0;
  }

  if (song == 2) {
    Serial.println("'Santa Claus is coming to town'");
    Serial.println();
    int size = sizeof(santa_melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {
      int noteDuration = 900 / santa_tempo[thisNote];
      tone(melodyPin, santa_melody[thisNote], noteDuration);
    //   buzz(melodyPin, santa_melody[thisNote], noteDuration);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      noTone(melodyPin);
    //   buzz(melodyPin, 0, noteDuration);
    }
    intNumber = 0;
  }

  if (song == 3) {
    Serial.println("'We wish you a Merry Christmas'");
    Serial.println();
    int size = sizeof(wish_melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {
      int noteDuration = 900 / wish_tempo[thisNote];
      tone(melodyPin, wish_melody[thisNote], noteDuration);
    //   buzz(melodyPin, wish_melody[thisNote], noteDuration);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      noTone(melodyPin);
    //   buzz(melodyPin, 0, noteDuration);
    }
    intNumber = 0;
  } 
}

// void buzz(int targetPin, long frequency, long length) {
//   digitalWrite(targetPin, HIGH);
//   long delayValue = 1000000 / frequency / 2;
//   long numCycles = frequency * length / 1000;
//   for (long i = 0; i < numCycles; i++) {
//     digitalWrite(targetPin, HIGH);
//     delayMicroseconds(delayValue);
//     digitalWrite(targetPin, LOW);
//     delayMicroseconds(delayValue);
//   }
//   digitalWrite(targetPin, LOW);
// }