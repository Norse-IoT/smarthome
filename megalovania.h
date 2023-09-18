#pragma once

#include "pitches.h"
#include "megalovania_notes.h"

namespace Megalovania {

int const TEMPO = 1200;

const int buzzerPin = 5;
const int melody_len = sizeof(melody) / sizeof(melody[0]);

namespace { // private namespace
  int currentNote = 0;
  int nextNote() {
    currentNote %= melody_len;
    return currentNote++;
  }
}

void playNextNote() {
  int thisNote = nextNote();
  int noteDuration = TEMPO / noteDurations[thisNote];
  tone(buzzerPin, melody[thisNote], noteDuration);
  int pauseBetweenNotes = noteDuration * 1.45;
  delay(pauseBetweenNotes);
  noTone(buzzerPin);
}

}