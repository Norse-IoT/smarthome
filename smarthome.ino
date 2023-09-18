#include "megalovania.h"

// originally from https://www.hackster.io/isaacnolt331/megalovania-on-piezo-fc263a

const int reedSwitchPin = 17;
const int internalLEDPin = 2;

void setup() {
  pinMode(reedSwitchPin, INPUT_PULLUP);
  pinMode(internalLEDPin, OUTPUT);
}

void loop() {
  bool switchState = digitalRead(reedSwitchPin);
  digitalWrite(internalLEDPin, !switchState);
  if (switchState == LOW) {
    Megalovania::playNextNote();
  }
}