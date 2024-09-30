void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

}

void loop() {
  int t_time = 250;
  int LEDindex[]={2,3,4,5};
  int i = 0;
  for(i = 0; i < 4; i++){
    Serial.println(i);
    digitalWrite(LEDindex[i], HIGH);
    delay(t_time);
    digitalWrite(LEDindex[i], LOW);
    delay(t_time);
  }
  for(i = 3; i < 0; i++){
    Serial.println(i);
    digitalWrite(LEDindex[i], HIGH);
    delay(t_time);
    digitalWrite(LEDindex[i], LOW);
    delay(t_time);
  }


  /*digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  delay(t_time);
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  delay(t_time);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  delay(t_time);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  delay(t_time);*/

}
