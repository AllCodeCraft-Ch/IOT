void setup() {
  pinMode(2, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(16, OUTPUT);

}

void loop() {
  digitalWrite(2, HIGH);
  digitalWrite(13, LOW);
  digitalWrite(14, HIGH);
  //digitalWrite(15, LOW);
  digitalWrite(16, HIGH);
  delay(1000);
  digitalWrite(2, LOW);
  digitalWrite(13, HIGH);
  digitalWrite(14, LOW);
  //digitalWrite(15, HIGH);
  digitalWrite(16, LOW);
  delay(1000);

}
