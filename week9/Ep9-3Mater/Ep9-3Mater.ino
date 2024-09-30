//Master
#include<Wire.h>

void setup() {
  Wire.begin();
  Serial.begin(9600);
}

void loop() {
  int i = 0;
  for (i=8; i<11; i++){
    Wire.requestFrom(i,21);
    while(Wire.available()){
      char c = Wire.read();
      Serial.print(c);
    }
    delay(500);
  }

}
