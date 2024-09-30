void setup() {
  Serial.begin(9600);

}

void loop() {
  bas();
  delay(1000);

}
void bas(){
  Serial.println("-------------");
  Serial.println("Bas");
  Serial.println("Kay");
  Serial.println("Nut");
  Serial.println("-------------");
}