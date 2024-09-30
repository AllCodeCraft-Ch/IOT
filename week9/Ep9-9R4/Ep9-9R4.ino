#include<Servo.h>
#include<Wire.h>
Servo myservo;

void setup() {
  Wire.begin(10);
  Wire.onReceive(receiveEvent);
  myservo.attach(9);

}

void loop() {
  delay(10);

}

void receiveEvent(int x){
  x = Wire.read(); //0-180
  myservo.write(x); //drive motor
  Serial.println(x);

}
