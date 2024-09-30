void setup() {
 Serial.begin(9600);

}

void loop() {
  double y = 0;
  y = bas(30.5);
Serial.println(y);
delay(1000);

}
double bas (double x){
x= x+10;
return x+1;
}
