//Sender
/*void setup() {
  Serial0.begin(9600);
  pinMode(17, INPUT);
  pinMode(18, INPUT);
  pinMode(19, INPUT);
  pinMode(13, OUTPUT);

}

void loop() {
  while (Serial0.available() > 0 ){
    char d = Serial0. read();
    if (d == '1'){
      digitalWrite(13, HIGH);
      delay(250);
    }
    else if (d == '0'){
      digitalWrite(13, LOW);
  }
}
  int a = 0;
  int b = 0;
  int c = 0;
  if (a == 1){
    Serial0.println('b');
  }
  else if (c == 1){
  Serial0.println('c');
  }
  else {
    Serial0.println('0');
  }
  delay (100);
}*/

//Receiver
int time_d = 500;
void setup(){
  Serial0.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop(){
  while (Serial0.available() > 0){
    char e = Serial0.read();
    if (e == 'a'){
      p1();
      Serial0.println('1');
    }
    else if (e == 'b'){
      p2();
      Serial0.println('1');
    }
    else if (e == 'c'){
      p3();
      Serial0.println('1');
    }
    else {
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      Serial0.println('0');

    }
  }
}

void p1(){
  digitalWrite(2, HIGH);
  delay(time_d);
  digitalWrite(2, LOW);
  delay(time_d);
  digitalWrite(3, HIGH);
  delay(time_d);
  digitalWrite(3, LOW);
  delay(time_d);
  digitalWrite(4, HIGH);
  delay(time_d);
  digitalWrite(4, LOW);
  delay(time_d);
  digitalWrite(5, HIGH);
  delay(time_d);
  digitalWrite(5, LOW);
  delay(time_d);
  digitalWrite(6, HIGH);
  delay(time_d);
  digitalWrite(6, LOW);
  delay(time_d);
}

void p2(){
  digitalWrite(6, HIGH);
  delay(time_d);
  digitalWrite(6, LOW);
  delay(time_d);
  digitalWrite(5, HIGH);
  delay(time_d);
  digitalWrite(5, LOW);
  delay(time_d);
  digitalWrite(4, HIGH);
  delay(time_d);
  digitalWrite(4, LOW);
  delay(time_d);
  digitalWrite(3, HIGH);
  delay(time_d);
  digitalWrite(3, LOW);
  delay(time_d);
  digitalWrite(2, HIGH);
  delay(time_d);
  digitalWrite(2, LOW);
  delay(time_d);
}

void p3(){
  digitalWrite(2, HIGH);
  delay(time_d);
  digitalWrite(2, LOW);
  delay(time_d);
  digitalWrite(3, HIGH);
  delay(time_d);
  digitalWrite(3, LOW);
  delay(time_d);
  digitalWrite(4, HIGH);
  delay(time_d);
  digitalWrite(4, LOW);
  delay(time_d);
  digitalWrite(5, HIGH);
  delay(time_d);
  digitalWrite(5, LOW);
  delay(time_d);
  digitalWrite(6, HIGH);
  delay(time_d);
  digitalWrite(6, LOW);
  delay(time_d);
  digitalWrite(5, HIGH);
  delay(time_d);
  digitalWrite(5, LOW);
  delay(time_d);
  digitalWrite(4, HIGH);
  delay(time_d);
  digitalWrite(4, LOW);
  delay(time_d);
  digitalWrite(3, HIGH);
  delay(time_d);
  digitalWrite(3, LOW);
  delay(time_d);
  digitalWrite(2, HIGH);
  delay(time_d);
  digitalWrite(2, LOW);
  delay(time_d);
}




















