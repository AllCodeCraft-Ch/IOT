void setup() {

  Serial.begin(9600);

}

void loop() {

  int a[] = {567,456,768,657};
  double b[] = {47.98,56.67,45.96,47.39};
  char c[] = "Test";

  Serial.println("variable A");
  Serial.println(a[0]);
  delay(1000);
  Serial.println(a[1]);
  delay(1000);
  Serial.println(a[2]);
  delay(1000);
  Serial.println(a[3]);
  delay(1000);

  Serial.println("variable B");
  Serial.println(b[0]);
  delay(1000);
  Serial.println(b[1]);
  delay(1000);
  Serial.println(b[2]);
  delay(1000);
  Serial.println(b[3]);
  delay(1000);

  Serial.println("variable C");
  Serial.println(c[0]);
  delay(1000);
  Serial.println(c[1]);
  delay(1000);
  Serial.println(c[2]);
  delay(1000);
  Serial.println(c[3]);
  delay(1000);
  



}
