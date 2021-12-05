#include "pitches.h"

// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4, 
  NOTE_F4, NOTE_E4, NOTE_C4, NOTE_C4, 
  NOTE_D4, NOTE_C4, NOTE_G4, NOTE_F4, 
  NOTE_C4, NOTE_C4, NOTE_C5, NOTE_A4, 
  NOTE_F4, NOTE_E4, NOTE_D4, NOTE_AS4, 
  NOTE_AS4, NOTE_A4, NOTE_F4, NOTE_G4, 
  NOTE_F4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  8, 8, 4, 4, 
  4, 2, 8, 8, 
  4, 4, 4, 2, 
  8, 8, 4, 4, 
  4, 4, 4, 8, 
  8, 4, 4, 4, 
  2
};

void setup() {
  
  // iterate over the notes of the melody:

  for (int thisNote = 0 ; thisNote < 25 ; thisNote++) { 
    
    // to calculate the note duration, take one second divided by the note type.

    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.

    int noteDuration = 1130/noteDurations[thisNote];

    tone (3, melody[thisNote], noteDuration);

     // to distinguish the notes, set a minimum time between them.

    // the note's duration + 30% seems to work well:
    
    int pauseBetweenNotes = noteDuration * 1.275;

    delay (pauseBetweenNotes);

    // stop the tone playing:

    noTone(3);
    
  }
}

void loop() {
  // no need to repeat the melody.
}