#include<Wire.h>

void setup() {
  Wire.begin();
  pinMode(17, INPUT);
  pinMode(18, INPUT);
  pinMode(19, INPUT);

}

void loop() {
  int a = 0, b = 0, c = 0,d_time = 250;;
  a = digitalRead(17);
  b = digitalRead(18);
  c = digitalRead(19);
  if (a == 1){
    Wire.beginTransmission(8);
    Wire.write("University of phayao\n");
    Wire.endTransmission();
    delay(d_time);
  }
  if (b == 1){
    Wire.beginTransmission(9);
    Wire.write("University of phayao\n");
    Wire.endTransmission();
    delay(d_time);
  }

  if (c == 1){
    Wire.beginTransmission(10);
    Wire.write("University of phayao\n");
    Wire.endTransmission();
    delay(d_time);
  }
}
