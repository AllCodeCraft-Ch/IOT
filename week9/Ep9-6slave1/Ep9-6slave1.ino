//slave1
#include<Wire.h>

void setup() {
  Wire.begin(8);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
  pinMode(13, OUTPUT);

}

void loop() {
  delay(100);

}

void receiveEvent(int a){
  while (Wire.available()>0) {
    char c = Wire.read();
    Serial.print(c);
  }
  digitalWrite(13, HIGH);
  delay(250);
  digitalWrite(13, LOW);
  delay(250);
}