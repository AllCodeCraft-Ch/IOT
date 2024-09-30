void setup() {
 Serial.begin(9600);

}

void loop() {
bas("University of phayao");
bas("Computer Engineering Department");
delay(1000);

}
void bas (String a){
Serial.println(a);
}
