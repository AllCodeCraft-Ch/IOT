//Master
#include<Wire.h>
byte x = 0; //0000 0000
void setup() {
  Wire.begin();

}

void loop() {
  Wire.beginTransmission(8);
  Wire.write(x);
  Wire.endTransmission();

  //x++; //0 - 255

  x = analogRead(A0);
  delay(100);

}
