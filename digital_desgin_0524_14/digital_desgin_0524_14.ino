

#include "pitches.h"

// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

int star[] = {
  NOTE_E5,NOTE_E5, NOTE_F5, NOTE_G5, NOTE_G5, NOTE_F5, NOTE_E5,NOTE_D5
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

int notes[] = {
  4, 4, 4, 4, 4, 4, 4, 4
};

int BUTTON_PIN = 9;


void setup() {
  
  pinMode(BUTTON_PIN,INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
 
  int btn_state = digitalRead(BUTTON_PIN);
  Serial.println(btn_state);
  if(btn_state == HIGH) {
    for (int thisNote = 0; thisNote < 8; thisNote++) {
      int noteDuration = 1000 / noteDurations[thisNote];
      tone(8, melody[thisNote], noteDuration);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      noTone(8);
    }
    delay(200);
  } 
  else {
    for (int thisNote = 0; thisNote < 8; thisNote++) {
      int note = 1000 / notes[thisNote];
      tone(8, star[thisNote], note);
      int pauseBetweenNotes = note * 1.30;
      delay(pauseBetweenNotes);
      noTone(8);
    }
    delay(200);
  }
}
