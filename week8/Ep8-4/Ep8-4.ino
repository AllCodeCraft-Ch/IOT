//Receiver
/*void setup() {
  Serial0.begin(9600);
  pinMode(13, OUTPUT);

}

void loop() {
  int b = 0;
  while (Serial0.available > 0) {
    b = Serial0.parseInt();
    analogWrite(13, b);
  }

}*/

//serder
void setup(){
  Serial0.begin(9600);
}

void loop(){
  int a = 0;
  int b =0;
  a = analohRead(A0);
  b = map(a, 0, 4095, 0, 255);

  Serial0.println(b);
  delay(10);
}
