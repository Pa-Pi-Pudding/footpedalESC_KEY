#define WINDOWS 1
#define UBUNTU 2
#define OSX 0
#include "Keyboard.h"

// change this to match your platform:
int platform = OSX;

void setup() {
  // make pin 2 an input and turn on the pull-up resistor so it goes high unless
  // connected to ground:
  pinMode(2, INPUT_PULLUP);
  Keyboard.begin();
}

void loop() {
  while (digitalRead(2) == HIGH) {
    // do nothing until pin 2 goes low
    delay(50);
  }

  switch (platform) {
    case OSX:
      Keyboard.press(0xb1);
      delay(100);
      Keyboard.releaseAll();
      // enter:
      break;
    case WINDOWS:
      Keyboard.press(0xb1);
      delay(100);
      Keyboard.releaseAll();
      // ALT-l:
      break;
    case UBUNTU:
      Keyboard.press(0xb1);
      delay(1000);
      Keyboard.releaseAll();
      // Enter to confirm logout:
      break;
  }

  // do nothing:
}
