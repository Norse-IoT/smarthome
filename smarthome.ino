#include "megalovania.h"

#include <LiquidCrystal_I2C.h>

// set the LCD number of columns and rows
int lcdColumns = 16;
int lcdRows = 2;

// set LCD address, number of columns and rows
// if you don't know your display address, run an I2C scanner sketch
LiquidCrystal_I2C mylcd(0x27, lcdColumns, lcdRows);

// originally from https://www.hackster.io/isaacnolt331/megalovania-on-piezo-fc263a

const int reedSwitchPin = 18;
const int internalLEDPin = 2;

void setup() {
  // pinMode(reedSwitchPin, INPUT_PULLUP);
  // pinMode(internalLEDPin, OUTPUT);
  mylcd.init();
  mylcd.backlight();
  // initialize LCD
  // turn on LCD backlight
}

void loop() {
  // bool switchState = digitalRead(reedSwitchPin);
  // digitalWrite(internalLEDPin, !switchState);
  // if (switchState == LOW) {
  //   Megalovania::playNextNote();
  // }
  // set cursor to first column, first row
  mylcd.setCursor(0, 0);
  // print message
  mylcd.print("Hello, World!");
  // delay(1000);
  // // clears the display to print new message
  // mylcd.clear();
  // // set cursor to first column, second row
  // mylcd.setCursor(0, 1);
  // mylcd.print("Hello, World!");
  // delay(1000);
  // mylcd.clear();
}

