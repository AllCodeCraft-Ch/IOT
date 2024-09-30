#include "USB.h"
#include "USBHIDMouse.h"
USBHIDMouse Mouse;

void setup(){
  Mouse.begin();
  USB.begin();
}

void loop(){
  Mouse.move(0,0,3000);
  delay(200);
  //Mouse new gen have 4 set of number

}