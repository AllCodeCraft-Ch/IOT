 //Receiver
 void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  while(Serial.available() > 0) {
    char a = Serial.read();
    if(a == '1'){
      digitalWrite(13, HIGH);
    }
    else if(a == '0') {
      digitalWrite(13, LOW);
    }
  }
}

//sender
// void setup() {
//   Serial.begin(9600);
//   pinMode(17, INPUT);
// }

// void loop() {
//   if(digitalRead(17) == HIGH) {
//     Serial.println('1');
//   }
//   else if(digitalRead(17) == LOW) {
//     Serial.println('0');
//   }
// }