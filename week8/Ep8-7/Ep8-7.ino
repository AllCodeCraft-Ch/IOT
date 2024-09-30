//Sender
/*void setup() {
  Serial1.begin(9600);
  pinMode(17, INPUT);
  pinMode(13, OUTPUT);

}

void loop() {
  while (Serial0.available() > 0 ){
    char b = Serial0. read();
    if (b == '1'){
      digitalWrite(13, HIGH);
    }
    else if (b == '0'){
      digitalWrite(13, LOW);
  }

}
  int a = 0;
  a = digitalRead(17);
  if (a == 1){
    Serial0.println('1');
  }
  else if (a == 0){
  Serial0.println('0');
  }
  delay (100);
}*/

//Receiver
void setup() {
  Serial1.begin(9600);
  pinMode(2, INPUT);
  pinMode(13, OUTPUT);

}

void loop() {
  while (Serial1.available() > 0 ){
    char b = Serial0. read();
    if (b == '1'){
      digitalWrite(13, HIGH);
    }
    else if (b == '0'){
      digitalWrite(13, LOW);
  }

}
  int a = 0;
  a = digitalRead(2);
  if (a == 1){
    Serial1.println('1');
  }
  else if (a == 0){
  Serial1.println('0');
  }
  delay (100);
}


  
