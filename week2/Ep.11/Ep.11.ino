void setup() {
  
  Serial.begin(9600);

}

void loop() {
  
  int a = 10, b = 5;

  if(a > b){
    Serial.println("Start");

    Serial.println("a มากกว่า b");
    delay(1000);
  }
  else if (a < b){
    Serial.println("a น้อยกว่า b");
    delay(1000);
  }
  else if (a <= b){
    Serial.println("a น้อยกว่หรือเท่ากับ b");
    delay(1000);
  }
  else {
    Serial.println("a เท่ากับ b");
    delay(1000);
  }

  Serial.println("Stop");

}
