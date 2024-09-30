void setup() {
  Serial.begin(9600);

}

void loop() {
  //EP12
  /*int i = 0;
  //วนเลข1-10
  for(i=0; i<10;i++){
    Serial.println(i);
    delay(1000);
  }
  //for แบบกลุ่ม
  int a[] = {560,456,945,123};
  double b[] = {49.87,57.89,67.90,11.11};
  char c[] = "ILoU";
  for(int i =0; i<4;i++){
    Serial.println(a[i]);
    delay(1000);
  }*/

  //EP13
  //เพิ่ม
    /*for(int i=0; i<10;i=i+1){
    Serial.print("Universitry of Phayao");
    Serial.println(i);
    delay(1000);
  }
    //ลด
    /*for(int i=10; i>-1;i=i-1){
    Serial.print("Universitry of Phayao");
    Serial.println(i);
    delay(1000);
  }*/

    //EP14
    //การนนับลูป while
    int i = 0;
    while (i>-10){
      Serial.println(i);
      i= i-1;
      delay(1000);
    }
    Serial.println("หลุดลูปแล้วว");



}
