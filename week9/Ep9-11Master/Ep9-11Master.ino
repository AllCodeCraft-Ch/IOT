#include <Wire.h>
void setup() {
  Wire.begin();
  while (!Serial) 
  {

  }
  Serial.println();
  Serial.println("การสแกนพอร์ต I2C กำลังสแกน");
  byte count = 0;
  byte i = 0;

  Wire.begin();
  for(i = 8; i < 120; i++){
    Wire.beginTransmission(i);
    if(Wire.endTransmission() == 0){
      Serial.print("เจออุปกรณ์ที่แอดเดรสซ: ");
      Serial.println(i);
      count++;
      delay(1);
    }
  }
  Serial.println("เสร็จแล้ว");
  Serial.print("เจออุปกรณ์ทั้งหมด");
  Serial.print(count);
  Serial.print("ตัว");
}

void loop() {

   

}
