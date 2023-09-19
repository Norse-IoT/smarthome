/*
 * Example sketch that defines a class for debouncing push buttons.
 * It uses this class to toggle the built-in LED:
 * 
 * Connect a push button between ground and digital pin 2, then upload the 
 * sketch, and push the button.
 * If you press it once, the LED will turn on, if you press it again, the LED
 * will turn off again.
 * 
 * To illustrate the problems with contact bounce, set the `debounceTime` to
 * zero and observe how hard it is to get the LED to turn on/off.
 */

// modified from https://github.com/tttapa/Projects/blob/28f2947e014cd7fc34d274299a9df8dd9e44a117/Arduino/LEDs%2C%20Buttons%2C%20etc./PushButton-debounce/PushButton-debounce.ino
class Button {
public:
  /// Constructor (executes when a PushButton object is created).
  Button(uint8_t pin)
    : pin(pin)  // remember the push button pin (C++ copy constructor)
  {}

  /// Initialize: enable the internal pull-up resistor.
  void begin() {
    pinMode(pin, INPUT_PULLUP);
  }

  /// Read the button state check if the button has been pressed, debounce the
  /// button, and return true on a falling edge (transition from not pressed
  /// to pressed).
  bool isPressed() {
    bool pressed = false;
    // read the button's state
    bool state = digitalRead(pin);
    // calculate the state change since last time
    int8_t stateChange = state - previousState;

    // If the button is pressed (went from high to low)
    if (stateChange == falling) {
      // check if the time since the last bounce is higher than the threshold
      if (millis() - previousBounceTime >= debounceTime) {
        pressed = true;  // the button is pressed
      }
    }
    // if the button is released or bounces
    else if (stateChange == rising) {
      // remember when this happened
      previousBounceTime = millis();
    }

    // remember the current state
    previousState = state;
    // return true if the button was pressed and didn't bounce
    return pressed;
  }

  // get raw button input (can't call it digitalRead because of naming conflicts)
  inline bool digitalReadPin() {
    return digitalRead(pin);
  }

private:
  uint8_t pin;
  bool previousState = HIGH;
  unsigned long previousBounceTime = 0;

  constexpr static unsigned long debounceTime = 25;  // milliseconds
  constexpr static int8_t rising = HIGH - LOW;
  constexpr static int8_t falling = LOW - HIGH;
};

