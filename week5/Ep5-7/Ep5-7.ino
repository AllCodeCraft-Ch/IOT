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
  Keyboard.println(";bL;dt");
  // if you need to input 'Enter'
  // Keyboard.println();
  delay(500);
  }
}
