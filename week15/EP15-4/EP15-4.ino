#include <WiFi.h> //ไลบารี่ไวไฟ
#include <Firebase_ESP_Client.h> //ไลบารี่ไฟล์เบส
#include "addons/TokenHelper.h" // ตัวแอดออน (เพิ่ม) ของไฟล์เบสเพื่อสร้างโทเคน
#include "addons/RTDBHelper.h" // ตัวแอดออน (เพิ่ม) ของไฟล์เบสเพื่อเพย์โหลดเก็บข้อมูล (Printing) ลงในดาต้าเบสแบบเรียล์ไทม์ (Realtime Database: RTDB) และการช่วยเหลืออื่น ๆ
#include "DHT.h" //ไลบารี่ของเซ็นเซอร์ DHT

#define DHTTYPE DHT11   // ระบุรุ่นของเซ็นเซอร์ DHT ในที่นี้ใช้เป็น DHT 11
const int DHTPin = 7; // ระบุขาที่ใช้ต่อกับเซ็นเซอร์ DHT11
DHT dht(DHTPin, DHTTYPE);

#define WIFI_SSID "3BB_5GHz" //กำหนดชื่อเราเตอร์ไวไฟที่ใช้งาน
#define WIFI_PASSWORD "12345678" //กำหนดพาสเวิร์ดเราเตอร์ไวไฟที่ใช้งาน

#define API_KEY "AIzaSyBy7UojChKWtgMJNC4zUvEidUFuy7c5u2I" //ค่า Web API Key ที่ได้จากการสร้างบนไฟล์เบส
#define DATABASE_URL "https://episode15-b79dd-default-rtdb.asia-southeast1.firebasedatabase.app/" //ลิงค์ URL ของดาต้าเบส ได้จากการสร้างบนไฟล์เบส

//#define LED1_PIN 2 //กำหนดใช้งานขาเอาต์พุตแอลอีดีที่ขา 2
//#define LED2_PIN 3 //กำหนดใช้งานขาเอาต์พุตแอลอีดีที่ขา 3
//#define ANA_PIN A0 //กำหนดขาอินพุตที่เป็นแอนาล็อกไว้ที่ขา A0

FirebaseData fbdo; //สร้างอ็อปเจ็คที่ชื่อว่า fbdo (FireBase Data Output)สำหรับค่าเอาต์พุตดาต้าที่ไมโครเมื่อมีการเปลี่ยนแปลงค่าที่เซ็นเซอร์
FirebaseAuth auth; //สร้างอ็อปเจ็คที่ชื่อว่า auth (Firebase Authentication) เพื่อใช้สำหรับการยืนยันตัวตนในกรณีที่เข้าใช้งาน Firebase
FirebaseConfig config; //สร้างอ็อปเจ็คที่ชื่อว่า config เพื่อใช้สำหรับการตั้งค่าต่าง ๆ ระหว่างไมโครคอนโทรเลอร์และไฟล์เบส

unsigned long sendDataPreMillis = 0; //สร้างตัวแปรชนิด unsigned long เพื่อใช้กับฟังก์ชั่น millis() สำหรับการส่งข้อมูลไปกลับระหว่างไมโครคอนโทรเลอร์และไฟล์เบส
boolean signupOK = false; //ตัวแปรแบบ bool ใช้เพื่อเก็บค่าการ sing up ของไฟล์เบสว่าสำเร็จหรือไม่ ถ้าสำเร็จให้เก็บค่า 1 ถ้าไม่สำเร็จให้เก็บค่า 0
//int analogData = 0; //ตัวแปรแบบ int ใช้เก็บข้อมูลขาแอนาล็อกที่ขา A0 โดยมีค่าระหว่าง 0 ถึง 4095
//float voltage = 0.0; //ตัวแปรแบบ float ใช้เพื่อแปลงค่า analogData ให้เป็นค่าแรงดันไฟฟ้าที่ป้อนเข้ามาที่ขา A0

void setup() {
  Serial.begin(115200); //กำหนดอัตราบอร์ดเรตสำหรับติดต่อกับ Serial Monitor อยู่ที่ 115200 บิตต่อวินาที
  dht.begin(); 
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD); //สั่งให้ไวไฟทำงาน โดยอ้างอิงชื่อเราเตอร์และพาสเวิร์ดจาก WIFI_SSID และ WIFI_PASSWORD ที่สร้างจากข้างบน
  Serial.print("กำลังเชื่อมต่อไวไฟ..."); //แสดงข้อความขณะกำลังเชื่อมต่อไวไฟ
  while(WiFi.status() != WL_CONNECTED){ // ทำการตรวจสอบการเชื่อมต่อไวไฟว่าเชื่อมต่อแล้วหรือยัง ถ้ายังให้ทำงานในเงื่อนไขข้างล่างในวงเล็บ แต่ถ้าเชื่อมต่อสำเร็จก็ให้หลุดลูปไป
    Serial.print("."); //พิมพ์จุดไป 1 จุด
    delay(300); //ดีเลย์ไป 300 มิลลิวินาที
  }
  Serial.println(); //ขึ้นบรรทัดใหม่
  Serial.print("เชื่อมต่อไวไฟสำเร็จ และมีเบอร์ IP คือ "); //แสดงข้อความเมื่อเชื่อมต่อไวไฟสำเร็จ
  Serial.println(WiFi.localIP()); //แสดงเบอร์ไอพีแอดเดรสของไมโครที่เชื่อมต่อกับเราเตอร์
  Serial.println(); //ขึ้นบรรทัดใหม่

  config.api_key = API_KEY; //กำหนดค่า API KEY เพื่อใช้เชื่อมต่อกับไฟล์เบส
  config.database_url = DATABASE_URL; //กำหนดค่า DATABASE URL เพื่อใช้เชื่อมต่อกับไฟล์เบส

  if(Firebase.signUp(&config, &auth, "", "")){ //คำสั่ง sign up บนไฟล์เบส โดยให้เอาค่าที่ได้จาก config ข้างบนและ Authentication มาทำการ sign up ในฐานะ anonymous (บุคคลที่ไร้ตัวตน) ใส่เครื่องหมาย "" ทั้งสองตัว โดยทุกครั้งที่ไมโครคอนโทรเลอร์ทำการเชื่อมต่อไปที่ไฟล์เบส จะทำการสร้างยูสเซอร์ใหม่ที่เป็น anonymous ทุกครั้งไป
    Serial.println("ทำการเชื่อมต่อไฟล์เบสสำเร็จในฐานะ Anonymous"); //แสดงข้อความในกรณีที่ sign up สำเร็จ
    signupOK = true;
  }
  else{
    Serial.printf("%s\n", config.signer.signupError.message.c_str()); //ถ้าการเชื่อมต่อไม่สำเร็จให้แสดงข้อความตามที่ helper ของ firebase ได้ทำการตั้งค่าเอาไว้ (เราไม่ต้องพิมพ์เอง ให้ระบบเจ็นข้อมูลมาแสดง)
  }

  config.token_status_callback = tokenStatusCallback; //ทำการตรวจสอบสอบ Token ระหว่างไมโครคอนโทรเลอร์และตัวไฟล์เบส
  Firebase.begin(&config, &auth); //เริ่มต้นการทำงานไฟล์เบส โดยใช้้ข้อมูล config และ Authentication ที่ได้ทำการสร้างจากข้างบน
  Firebase.reconnectWiFi(true); //ตรวจสอบสถานะการทำงานของไวไฟที่ใช้เชื่อมต่อไฟล์เบส
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Firebase.ready() && signupOK && (millis() - sendDataPreMillis > 5000 || sendDataPreMillis == 0)){ //ตรวจสอบว่าไฟล์เบสพร้อมทำงานหรือยัง และ การ signup เรียบร้อยแล้ว โดยจะทำการทำงานลูปในวงเล็บข้างล่างทุก ๆ 5 วินาทีผ่านฟังก์ชั่น millis()
    sendDataPreMillis = millis();
    
    //analogData = analogRead(ANA_PIN); //การอ่านค่าแอนาล็อกจากขา A0 มาเก็บไว้ที่ตัวแปร analogData
    //voltage = (float)analogReadMilliVolts(ANA_PIN)/1000; //ทำการแปลงค่าจากอินพุตแอนาล็อกที่ขา A0 ให้เป็นค่าแรงดันไฟฟ้าโดยใช้ฟังก์ชั่น analogReadMilliVolts() หน่วยที่ได้เป็นมิลลิโวลต์จึงต้องเอา 1000 ไปหาร แล้วเอามาเก็บไว้ที่ตัวแปร voltage 
    float h = dht.readHumidity(); // เอาค่าความชื้นมาเก็บไว้ที่ตัวแปร h
    float t = dht.readTemperature(); //เอาค่าอุณหภูมิมาเก็บไว้ที่ตัวแปร t

    // การส่งข้อมูลแบบ Float (จุดทศนิยม) ในที่นี้คืออุณหภูมิ (Temperature) ไปเก็บไว้บนไฟล์เบส
    if(Firebase.RTDB.setFloat(&fbdo, "Sensor/temperature", t)){ //ทำการตรวจสอบค่า analogData ที่บนไฟล์เบสในไดเร็คทอรี่ Sensor/ana_data
      Serial.println(); //ขึ้นบรรทัดใหม่
      Serial.print(t); //พิมพ์ค่าตัวแปร อุณหภูมิ
      Serial.print(" - บันทึกข้อมูลบน Firebase สำเร็จ โดยอยู่ในดาต้าพาท: " + fbdo.dataPath()); //แสดงข้อมูลไดเร็คทอรี่บนไฟล์เบส
      Serial.println("(" + fbdo.dataType() + ")"); //แสดงชนิดของข้อมูลที่ถูกนำไปเก็บบนไฟล์เบส
    }
    else{
      Serial.println("การส่งข้อมูลล้มเหลว: " + fbdo.errorReason()); //กรณีที่ไม่สามารถส่งข้อมูลไปเก็บบนไฟล์เบสได้ให้ขึ้นข้อความที่ถูกตั้งไว้บนไฟล์เบส
    }

    // การส่งข้อมูลแบบ Int (ตัวเลขจำนวนเต็ม) ในที่นี้คือค่าความชื้น (Humidity) ไปเก็บไว้บนไฟล์เบส
    if(Firebase.RTDB.setInt(&fbdo, "Sensor/humidity", h)){ //ทำการตรวจสอบค่า voltage ที่บนไฟล์เบสในไดเร็คทอรี่ Sensor/voltage
      Serial.println(); //ขึ้นบรรทัดใหม่
      Serial.print(h); //พิมพ์ค่าตัวแปร ความชื้น
      Serial.print(" - บันทึกข้อมูลบน Firebase สำเร็จ โดยอยู่ในดาต้าพาท: " + fbdo.dataPath()); //แสดงข้อมูลไดเร็คทอรี่บนไฟล์เบส
      Serial.println("(" + fbdo.dataType() + ")"); //แสดงชนิดของข้อมูลที่ถูกนำไปเก็บบนไฟล์เบส
    }
    else{
      Serial.println("การส่งข้อมูลล้มเหลว: " + fbdo.errorReason()); //กรณีที่ไม่สามารถส่งข้อมูลไปเก็บบนไฟล์เบสได้ให้ขึ้นข้อความที่ถูกตั้งไว้บนไฟล์เบส
    }
  }

}
