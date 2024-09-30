void setup() {
  pinMode(17,INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  int a;
  a = digitalRead(17);
  if(a==1){
  digitalWrite(13,HIGH);
  }
  else{
   digitalWrite(13,LOW);
  }
  delay(10);
}
