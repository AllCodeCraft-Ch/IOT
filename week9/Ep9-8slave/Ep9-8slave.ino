//slave
#include<Wire.h>

void setup() {
  Wire.begin(8);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  delay(10);

}

void receiveEvent(int x){
  int a = 0;
  a = Wire.read();
  analogWrite(13, a);
  Serial.println(a);
  delay(100);
}
