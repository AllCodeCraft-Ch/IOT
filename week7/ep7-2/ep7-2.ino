void setup() {
  pinMode(2, OUTPUT);

}

void loop() {
  analogWrite(2, 128);  //0% is 0, 25% is 64, 50% is 127, 75% is 191, 100% is 255 (resister 150 Ohm)
  delay(100);

}
