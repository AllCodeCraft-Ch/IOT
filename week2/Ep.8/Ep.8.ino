void setup() {
  
  Serial.begin(9600);

}

void loop() {
  
  int a = 10, b = 20,c,d,e,f;

  c = a+b;
  d = a-b;
  e = a*b;
  f = a/b;
  
  Serial.println(c);
  delay(1000);
  Serial.println(d);
  delay(1000);
  Serial.println(e);
  delay(1000);
  Serial.println(f);
  delay(1000);



}
