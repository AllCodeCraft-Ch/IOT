//Sensor แสง
int sensorPin = A0;
int value = 0;
void setup() {
  Serial.begin(9600);

}

void loop() {
  value = analogRead(sensorPin);
  Serial.println(value, DEC);
  ldr_value = value;
  delay(500); //ไม่เอาไป
}
