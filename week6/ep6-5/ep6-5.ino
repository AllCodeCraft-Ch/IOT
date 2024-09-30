void setup() {
  Serial.begin(9600);
  analogReadResolution(10); 
  //10 = 1023, 11=2047, 12=4095, 13=8191, 14=16383, 15=32767, 16=65535
  //default is 12 bit

}

void loop() {
  int a = 0; 
  a = analogRead(A0);

  // int b = 0;
  // b = map(a,0,4095,0,10000);

  Serial.println(a);
  delay(500);

} 
