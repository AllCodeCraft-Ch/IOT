#include "USB.h"
#include "USBHIDKeyboard.h"
USBHIDKeyboard Keyboard;

void setup(){
  Keyboard.begin();
  USB.begin();
}

void loop(){
  Keyboard.press(KEY_BACKSPACE);
  delay(100);
  Keyboard.releaseAll();
  delay(500);
}
