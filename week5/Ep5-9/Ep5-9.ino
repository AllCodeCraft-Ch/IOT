#include "USB.h"
#include "USBHIDMouse.h"
USBHIDMouse Mouse;

void setup(){
  Mouse.begin();
  USB.begin();
}

void loop(){
  Mouse.move(100,0,0);
  delay(500);
  Mouse.move(0,100,0);
  delay(500);
  Mouse.move(-100,0,0);
  delay(500);
  Mouse.move(0,100,0);
  delay(500);
  
}