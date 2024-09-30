#include<Wire.h>
byte a = 0;

void setup() {
  Wire.begin();
  Serial.begin(9600);

}

void loop() {
  int y = 0;
  y = analogRead(A0); //0 - 4095
  a = map(y, 0, 4095, 0, 180);
  Serial.println(a);

  Wire.beginTransmission(10);
  Wire.write(a);
  Wire.endTransmission();
  delay(10);

}
