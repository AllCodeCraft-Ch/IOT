void setup() {

  Serial.println(9600);

}

void loop() {

  while (Serial.available()==0){}

  int a;
  a = Serial.parseInt();
  Serial.println(a);
  double b = Serial.parseFloat();
  Serial.println(b);
  String c = Serial.readString();
  Serial.println(c);

}
