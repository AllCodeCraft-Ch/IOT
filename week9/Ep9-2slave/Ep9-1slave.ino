//slave
#include<Wire.h>
void setup() {
  Wire.begin(8); //8-127
  Wire.onRequest(requestEvent);


}

void loop() {
  delay(100);
}

void requestEvent():{
  Wire.write("hello/n"); //ถ้าส่งไม่เต็มไบต์ จะทำการเติมตัวสุดท้ายให้เต็มจำนวนที่ Request
}