void setup() {
  pinMode(2, OUTPUT); 
  Serial.begin(9600);
}

void loop() {
  int a = 0;
  int b = 0;
  
  a = analogRead(A0); 
  b = map(a, 0, 4095, 0, 255); 

  Serial.print("ค่าตัวแปร a: ");
  Serial.print(a);
  Serial.print(", ค่าตัวแปร b: ");
  Serial.println(b);

  analogWrite(2, b); 
  delay(50);
}
