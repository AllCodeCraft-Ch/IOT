#include "USB.h"
#include "USBHIDKeyboard.h"
USBHIDKeyboard Keyboard;

void setup(){
  Keyboard.begin();
  USB.begin();
  pinMode(17, INPUT);
}

void loop(){
  int kb_1 = digitalRead(17);
  if (kb_1 == 1){
  Keyboard.press('S');
  delay(100);
  Keyboard.releaseAll();
  delay(500);
  }
}
