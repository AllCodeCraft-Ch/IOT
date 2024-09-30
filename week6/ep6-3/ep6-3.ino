void setup() {
  Serial.begin(9600); //No need to specify

}

void loop() {
  int val_a = 0; //0 - 4095
  val_a = analogRead(A0);

  Serial.println(val_a);
  delay(500);

} 
