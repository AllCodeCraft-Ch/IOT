void setup() {
  
  Serial.begin(9600);

}

void loop() {
  
  int a = 30, b = 35;
Serial.println("Start");
  if(a > b){
  

  Serial.println("a มากกว่า b");
  delay(1000);

  }
  Serial.println("Stop");

}
