#include "USB.h"
#include "USBHIDMouse.h"
USBHIDMouse Mouse;

void setup(){
  Mouse.begin();
  USB.begin();
}

void loop(){
  Mouse.press(MOUSE_LEFT);
  delay(100);
  Mouse.release(MOUSE_LEFT);
  delay(1000);
}