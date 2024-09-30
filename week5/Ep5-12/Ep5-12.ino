#if ARDUINO_USB_MODE
#warning This sketch should be used when USB is in OTG mode
void setup(){}
void loop(){}
#else

#include "USB.h"
#include "USBHIDMouse.h"
USBHIDMouse Mouse;

const int upButton = 17;
const int downButton = 18;
const int leftButton = 19;
const int rightButton = 20;
const int mouseButton = 2;

int range = 5;
int responseDelay = 10;

void setup(){
  pinMode(upButton, INPUT);
  pinMode(downButton, INPUT);
  pinMode(leftButton, INPUT);
  pinMode(rightButton, INPUT);
  pinMode(mouseButton, INPUT);

  Mouse.begin();
  USB.begin();
}

void loop(){
  int upState = digitalRead(upButton);
  int downState = digitalRead(downButton);
  int leftState = digitalRead(leftButton);
  int rightState = digitalRead(rightButton);
  int clickState = digitalRead(mouseButton);

int xDistance = (leftState - rightState) * range;
int yDistance = (upState - downState) * range;

if((xDistance != 0) || (yDistance != 0)){
  Mouse.move(xDistance, yDistance, 0);
}

if(clickState == HIGH){
  if(!Mouse.isPressed(MOUSE_LEFT)){
    Mouse.press(MOUSE_LEFT);
  }
}
else{
  if(Mouse.isPressed(MOUSE_LEFT)){
    Mouse.release(MOUSE_LEFT);
  }
}

delay(responseDelay);

}

#endif





















