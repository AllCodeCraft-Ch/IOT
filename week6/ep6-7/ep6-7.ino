void setup() {
  Serial.begin(9600);
  analogWriteResolution(12); 
  //10 = 1023, 11=2047, 12=4095, 13=8191, 14=16383, 15=32767, 16=65535
  //default is 12 bit

}

void loop() {
  int a = 0; 
  a = analogRead(A0);
  double b = 0;

  b = (3.3/4096) * a;

  Serial.print("แรงดันอินพุตที่ขา A0: ");
  Serial.print(b);
  Serial.println("โวลต์");
  delay(500);

} 
  //สูตรการคำนวณ ค่าแรงดันสูงสุดของอินพุต/ระดับความระเอียดของ ADC * ตัวเลขที่ได้จาก analogRead();
