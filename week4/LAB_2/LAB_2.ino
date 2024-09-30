void setup() {
  pinMode(17,INPUT);
  Serial.begin(9600);
}

void loop() {
  int a;
  a = digitalRead(17);
  if(a==1){
    Serial.println("มีการกดปุ่ม");
  }
  else{
    Serial.println("ไม่ได้กดปุ่ม");
  }
  delay(10);
}
