void setup() {

  Serial.begin(9600);

}

void loop() {

  int a = 560;
  double b = 49.87;
  char c = 'E';
  Serial.println(a);
  Serial.println("นัท");
  delay(1000);
  Serial.println(b);
  Serial.println("บาส");
  delay(1000);
  Serial.println(c);
  Serial.println("กาย");
  delay(1000);
}
