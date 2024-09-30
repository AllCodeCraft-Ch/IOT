void setup() {
  pinMode(14, OUTPUT);
  pinMode(16, OUTPUT);
  analogWriteResolution(12); //8=0-255 Default, 10=0-1023, 12=0-4095
  //Serial.begin(9600);

}

void loop() {
  int a = 0;
  int b = 0;
  a = analogRead(A0);
  b = analogRead(A1);
  analogWrite(14, a);
  analogWrite(16, b);
  delay(50);


  
  
  
}
