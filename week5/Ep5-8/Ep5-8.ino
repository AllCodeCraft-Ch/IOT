#include "USB.h"
#include "USBHIDKeyboard.h"
USBHIDKeyboard Keyboard;

void setup(){
  Keyboard.begin();
  USB.begin();
  pinMode(17, INPUT);
  pinMode(18, INPUT);
  pinMode(19, INPUT);
  pinMode(20, INPUT);
}

void loop(){
  int kb_1 = digitalRead(17), kb_2 = digitalRead(18), kb_3 = digitalRead(19), kb_4 = digitalRead(20);
  if (kb_1 == 1){
  Keyboard.press(KEY_LEFT_ARROW);
  delay(100);
  Keyboard.releaseAll();
  delay(100);
  }
  else if (kb_2 == 1){
  Keyboard.press(KEY_UP_ARROW);
  delay(100);
  Keyboard.releaseAll();
  delay(100);
  }
  else if (kb_3 == 1){
  Keyboard.press(KEY_DOWN_ARROW);
  delay(100);
  Keyboard.releaseAll();
  delay(100);
  }
  else if (kb_4 == 1){
  Keyboard.press(KEY_RIGHT_ARROW );
  delay(100);
  Keyboard.releaseAll();
  delay(100);
  }
  
}
