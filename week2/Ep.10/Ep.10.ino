void setup() {
  
  Serial.begin(9600);

}

void loop() {
  
  int a = 78, b = 90;

  Serial.println("Start");

  if(a > b){
    

    Serial.println("a มากกว่า b");
    delay(1000);
  }
  else {
    Serial.println("a น้อยกว่า b");
    delay(1000);
  }

  Serial.println("Stop");

}
