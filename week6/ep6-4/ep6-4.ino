void setup() {
  Serial.begin(9600);

}

void loop() {
  int a = 0; 
  a = analogRead(A0);

  int b = 0;
  b = map(a,0,4095,0,10000);

  Serial.println(b);
  delay(500);

} 
