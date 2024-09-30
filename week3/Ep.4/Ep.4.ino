void setup() {
  pinMode(2, OUTPUT);
  pinMode(13, OUTPUT);
  int t_time = 500;
  digitalWrite(14, 0);
  delay(t_time);
  digitalWrite(14, 1);
  delay(t_time);
  digitalWrite(15, 0);
  delay(t_time);
  digitalWrite(15, 1);
  delay(t_time);
  digitalWrite(16, 0);
  delay(t_time);
  digitalWrite(16, 1);
  delay(t_time);
}

void loop() {
  digitalWrite(2, HIGH);
  digitalWrite(13, LOW);
  delay(1000);
  digitalWrite(2, LOW);
  digitalWrite(13, HIGH);
  delay(1000);
}