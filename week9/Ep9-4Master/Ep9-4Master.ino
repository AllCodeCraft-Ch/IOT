//Master
#include <Wire.h>

void setup() {
  Wire.begin();
}

void loop() {
  Wire.beginTransmission(8);
  Wire.write("Liverpool 3-0\n");
  Wire.endTransmission();
  delay(500);

}
