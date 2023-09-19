// originally from https://www.hackster.io/isaacnolt331/megalovania-on-piezo-fc263a
#include "megalovania.h"
#include "button.h"
#include <LiquidCrystal_I2C.h>

// set the LCD number of columns and rows
int lcdColumns = 16;
int lcdRows = 2;

// set LCD address, number of columns and rows
// if you don't know your display address, run an I2C scanner sketch
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);

const int musicButtonPin = 18;
const int counterButtonPin = 19;
const int internalLEDPin = 2;

Button counterButton(counterButtonPin);

void setup() {
  counterButton.begin();
  pinMode(musicButtonPin, INPUT_PULLUP);
  pinMode(internalLEDPin, OUTPUT);
  lcd.init();       // initialize LCD
  lcd.backlight();  // turn on LCD backlight
}

uint32_t button_presses = 0;

void loop() {
  bool switchState = digitalRead(musicButtonPin);  // raw input
  digitalWrite(internalLEDPin, !switchState);
  if (switchState == LOW) {
    Megalovania::playNextNote();
  }

  lcd.setCursor(0, 0);
  lcd.print("Button Presses:");
  lcd.setCursor(0, 1);
  lcd.print(button_presses);
  lcd.setCursor(15, 1);

  if (counterButton.isPressed()) {  // debounce input
    button_presses++;
  }
}
