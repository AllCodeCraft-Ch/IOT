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

//serder
// void setup() {
//   Serial.begin(9600);
//   //Serial0.begin(9600);
// }

// void loop() {
//   if(Serial.read() == '1') {
//     Serial.println('1');
//     Serial.println("ส่งข้อมูล 1 แล้ว");
//   }
//   else if(Serial.read() == '0') {
//     Serial.println('0');
//     Serial.println("ส่งข้อมูล 0 แล้ว");
//   }
// }
