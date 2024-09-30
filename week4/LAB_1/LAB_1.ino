#include "USB.h"
#include "USBHIDKeyboard.h"
USBHIDKeyboard keybord;

void setup(){
  keyboard.begin();
  USB.begin();
}

void loop(){
  keyboard.press('w');
  delay(100);
  keyboard.releaseAll();
  delay(500);
}