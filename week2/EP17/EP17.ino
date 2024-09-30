void setup() {
 Serial.begin(9600);

}

void loop() {
  int y = 0;
  y = bas(30);

Serial.println(y);
delay(1000);

}
int bas (int x){
x = x + 20;
return x;
}
