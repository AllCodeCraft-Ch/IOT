//slave
#include<Wire.h>

void setup() {
  Wire.begin(8);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
}

void loop() {
  delay(100);

}

void receiveEvent(int x){
  int a = 0;
  a = Wire.read();
  Serial.println(a);
}
