//slave3
#include<Wire.h>
void setup() {
  Wire.begin(10); //8-127
  Wire.onRequest(requestEvent);


}

void loop() {
  delay(100);
}

void requestEvent():{
  Wire.write("Thanaphachara Chomjan/n"); //ถ้าส่งไม่เต็มไบต์ จะทำการเติมตัวสุดท้ายให้เต็มจำนวนที่ Request
}