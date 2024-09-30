void setup() {
  pinMode(17,INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  int a;
  a = digitalRead(17);
  if(a==1){
  digitalWrite(LED_BUILTIN,HIGH);
  led_pat();
  }
  else{
   digitalWrite(LED_BUILTIN,LOW);
   digitalWrite(LED_RED,HIGH);
   digitalWrite(LED_GREEN,HIGH);
   digitalWrite(LED_BLUE,HIGH);
  }
  delay(10);
}

void led_pat(){
  digitalWrite(LED_RED,LOW);
  delay(500);
  digitalWrite(LED_RED,HIGH);
  digitalWrite(LED_GREEN,LOW);
  delay(500);
  digitalWrite(LED_GREEN,HIGH);
  digitalWrite(LED_BLUE,LOW);
  delay(500);
  digitalWrite(LED_BLUE,HIGH);
}
