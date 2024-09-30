//Master
#include <Wire.h>

void setup() {
  Wire.begin();

}

void loop() {
  Wire.beginTransmission(8);
  Wire.write("Natthawut Chungam\n");
  Wire.endTransmission();
  delay(500);

  Wire.beginTransmission(9);
  Wire.write("Natthawut Chungam\n");
  Wire.endTransmission();
  delay(500);

  Wire.beginTransmission(10);
  Wire.write("Thanaphachara Chomjan/n");
  Wire.endTransmission();
  delay(500);

}
