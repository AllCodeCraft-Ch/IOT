#include <WiFi.h> //เรียกใช้งานไลบารี่ไวไฟ
#include <HTTPClient.h> //เรียกใช้งานไลบารี่ที่ใช้ส่งข้อมูลที่ใช้โปรโตคอล http ในฝั่งไคลเอ็นต์

//---------------------------------------------------------------------
const char * ssid = "Thira"; //ชื่อเราเตอร์ที่ใช้
const char * password = "bas1234567"; //พาสเวิร์ดของเราเตอร์
String GOOGLE_SCRIPT_ID = "AKfycbxQjk81xWF5-2WzxsnbP5w20Ex0h0MGPSc7UsEWkj7yB_ByxxWGrw_Er0FYltkKpkBxZw"; //สคริปไอดีที่ได้จาก Google Sheet
//---------------------------------------------------------------------

//-----------------------------
#define relay1_pin 2 //กำหนดขาอุปกรณ์ที่จะใช้ควบคุมเป็นขาที่ 2 ให้ชื่อว่า relay1_pin
#define relay2_pin 3 //กำหนดขาอุปกรณ์ที่จะใช้ควบคุมเป็นขาที่ 3 ให้ชื่อว่า relay2_pin
#define relay3_pin 4 //กำหนดขาอุปกรณ์ที่จะใช้ควบคุมเป็นขาที่ 4 ให้ชื่อว่า relay3_pin
#define relay4_pin 5 //กำหนดขาอุปกรณ์ที่จะใช้ควบคุมเป็นขาที่ 5 ให้ชื่อว่า relay4_pin
//-----------------------------

const int sendInterval = 2000; //ระยะเวลาในการส่งในแต่ละรอบ โดยกำหนดให้ค่าเริ่มต้นเป็น 2 วินาที

WiFiClientSecure client; //กำหนดให้ไมโครคอนโทรเลอร์เป็นไคลเอ็นต์

// ส่วนของฟังก์ชั่น setup
void setup() {
  //--------------------------------------------
  pinMode(relay1_pin, OUTPUT); //กำหนดให้ขาที่ 2 เป็นเอาต์พุต
  pinMode(relay2_pin, OUTPUT); //กำหนดให้ขาที่ 3 เป็นเอาต์พุต
  pinMode(relay3_pin, OUTPUT); //กำหนดให้ขาที่ 4 เป็นเอาต์พุต
  pinMode(relay4_pin, OUTPUT); //กำหนดให้ขาที่ 5 เป็นเอาต์พุต
  //--------------------------------------------
  Serial.begin(115200); //กำหนดให้อัตราบอร์ดเรตในการสื่อสารข้อมูลใน Serial Monitor มีค่าเท่ากับ 115000 บิตต่อวินาที
  delay(10); //ดีเลย์ 10 มิลลิวินาที
  //--------------------------------------------
  WiFi.mode(WIFI_STA); //กำหนดโหมดของไวไฟที่ใช้ให้เป็นแบบ STA (Station mode หรือ Wi-Fi client mode)
  WiFi.begin(ssid, password); //สั่งให้ไวไฟทำงานโดยอ้างอิงชื่อและพาสเวิร์ดตามที่ได้กำหนดไว้ตามโค้ดข้างบน

  Serial.print("กำลังเชื่อมต่อไวไฟ..."); //สั่งพิมพ์ข้อความออก Serial Monitor ในขณะที่กำลังเชื่อมต่อไวไฟ
  while (WiFi.status() != WL_CONNECTED) { //ขณะที่กำลังเชื่อมต่อไวไฟกับเราต์เตอร์ ให้ทำการพิมพ์ . ในทุก ๆ 300 มิลลิวินาที
    Serial.print(".");
    delay(300);
  }
  Serial.println("เชื่อมต่อไวไฟสำเร็จ"); //เมื่อเชื่อมต่อไวไฟสำเร็จก็ให้ขึ้นข้อความ
  Serial.println("IP address: "); //พิมพ์ข้อความ IP address:
  Serial.println(WiFi.localIP()); //แสดงเบอร์ไอพีแอดเดรสที่ได้รับจากเราต์เตอร์
  //--------------------------------------------
}

//ส่วนของเนื้อโปรแกรมจะเรียกผ่านฟังก์ชั่น read_google_sheet();
void loop() {
  read_google_sheet(); // เรียกใช้งานฟังก์ชั่น read_google_sheet();
  delay(sendInterval); //กำหนดให้รอบในการส่งแต่ละรอบอยู่ที่ 2 วินาที ตามค่าที่ได้ประกาศเอาไว้ข้างบน
}

//ฟังก์ชั่นการทำงานหลัก read_google_sheet();
void read_google_sheet(void) {
   //-----------------------------------------------------------------------------------
   HTTPClient http; //ประกาศออปเจ็ค http เพื่อใช้งานคำสั่งที่อยู่ในไลบารี่ HTTPClient.h
   String url="https://script.google.com/macros/s/"+GOOGLE_SCRIPT_ID+"/exec?read"; //คำสั่งที่ใช้เรียกค่าจาก Google Sheet ในรูปแบบโปรโตคอล http
  //Serial.print(url);
  Serial.println("กำลังอ่านค่าจาก Google Sheet....."); //ขณะที่กำลังอ่านค่าจาก Google Sheet ให้แสดงข้อความ กำลังอ่านค่าจาก Google Sheet.....
  http.begin(url.c_str()); //สั่งให้โปรโตคอล http ทำงาน
  //-----------------------------------------------------------------------------------
  //สั่งไม่ให้คำสั่ง Eror ทำงาน ---> "302 Moved Temporarily Error"
  http.setFollowRedirects(HTTPC_STRICT_FOLLOW_REDIRECTS);
  //-----------------------------------------------------------------------------------
  //ทำการรับค่ารหัสสถานะของโปรโตคอล http (Get the returning HTTP status code)
  int httpCode = http.GET(); //รับค่ารหัสสถานะของโปรโตคอล http ในสภาวะปกติ รหัสตรงนี้จะมีค่าเป็น 200
  Serial.print("รหัสสถานะของโปรโตคอล http: "); //แสดงข้อความที่ Serial Monitor
  Serial.println(httpCode); //แสดงรหัสสถานะของ http
  //-----------------------------------------------------------------------------------
  if(httpCode <= 0){Serial.println("มีความผิดพลาดเกิดขึ้นในการเชื่อมต่อโปรโตคอล http"); http.end(); return;} //ในกรณีมีความผิดพลาดเกิดขึ้นในการร้องขอสถานะ http ให้ขึ้นข้อความดังกล่าว
  //-----------------------------------------------------------------------------------
  //ทำการอ่านข้อมูลจาก Google sheet
  String payload = http.getString(); //อ่านค่าจากเพย์โหลดที่ได้จาก Google Sheet
  Serial.println("Payload: "+payload); //แสดงผลค่าเพย์โหลดที่ได้จาก Google Sheet ใน Serial Monitor
  //-----------------------------------------------------------------------------------
  if(httpCode == 200){ //ในกรณีที่เชื่อมต่อกับ Google Sheet ได้ปกติ (รหัสเป็น 200)
    //=====================================================================
    //get relay number from payload variable
    String temp = payload.substring(0, 1);
    int relay_number = temp.toInt();
    //=====================================================================
    //get the command comming from Google Sheet
    //i.e ON or OFF
    payload.remove(0, 1);
    payload.toLowerCase();
    payload.trim();
    Serial.println("Payload - Command: "+payload);
    //=====================================================================
    if(payload != "on" && payload != "off")
      {Serial.println("คำสั่งการติด/ดับของอุปกรณ์ผิดพลาด"); http.end(); return;}
    //=====================================================================
    if(relay_number < 1 || relay_number > 4) // ในกรณีที่จำนวนอุปกรณ์เชื่อมต่อมากกว่า 4 ตัว ให้มาแก้ค่าตรงนี้
      {Serial.println("จำนวนอุปกรณ์ไม่อยู่ในค่าที่กำหนด"); http.end(); return;}
    //=====================================================================
    int relay_state = control_relay(relay_number, payload);
    write_google_sheet( "relay_number="+String(relay_number)+"&relay_state="+String(relay_state) );
    //=====================================================================
  }
  //-------------------------------------------------------------------------------------
  http.end();
}

//ฟังก์ชั่นในการเขียนค่าลงใน Google Sheet ในกรณีที่จะส่งสถานะการติดดับให้กับ Google Sheet
void write_google_sheet(String params) {
   HTTPClient http;
   String url="https://script.google.com/macros/s/"+GOOGLE_SCRIPT_ID+"/exec?"+params;
   //Serial.print(url);
    Serial.println("กำลังอัพเดตสถานะของตัวอุปกรณ์ที่ทำการเชื่อมต่อที่ไมโครคอนโทรเลอร์");
    http.begin(url.c_str());
    http.setFollowRedirects(HTTPC_STRICT_FOLLOW_REDIRECTS);
    int httpCode = http.GET();  
    Serial.print("รหัสสถานะของโปรโตคอล http: ");
    Serial.println(httpCode);
    
    String payload;
    if (httpCode > 0) {
        payload = http.getString(); //อ่านค่าจากเพย์โหลดที่ได้จาก Google Sheet
        Serial.println("Payload: "+payload);  //แสดงผลค่าเพย์โหลดที่ได้จาก Google Sheet ใน Serial Monitor   
    }
    http.end();
}

//ส่วนของการควบคุมอุปกรณ์อิเล็กทรอนิกส์ที่ไมโครคอนโทรเลอร์ หากทำการเพิ่มหรือลดตัวอุปกรณ์ที่ต่อกับตัวไมโครคอนโทรเลอร์ ต้องมาแก้ไขในส่วนนี้
int control_relay(int relay, String command){
  switch (relay) {
    //------------------------------------------------
    case 1:
      if(command == "on"){
        digitalWrite(relay1_pin, HIGH);
        Serial.println("อุปกรณ์ตัวที่ 1 ติด");
        return 1;
      } else {
        digitalWrite(relay1_pin, LOW);
        Serial.println("อุปกรณ์ตัวที่ 1 ดับ");
        return 0;
      }
      break;
    //------------------------------------------------
    case 2:
      if(command == "on"){
        digitalWrite(relay2_pin, HIGH);
        Serial.println("อุปกรณ์ตัวที่ 2 ติด");
        return 1;
      } else {
        digitalWrite(relay2_pin, LOW);
        Serial.println("อุปกรณ์ตัวที่ 2 ดับ");
        return 0;
      }
      break;
    //------------------------------------------------
    case 3:
      if(command == "on"){
        digitalWrite(relay3_pin, HIGH);
        Serial.println("อุปกรณ์ตัวที่ 3 ติด");
        return 1;
      } else {
        digitalWrite(relay3_pin, LOW);
        Serial.println("อุปกรณ์ตัวที่ 3 ดับ");
        return 0;
      }
      break;
    //------------------------------------------------
    case 4:
      if(command == "on"){
        digitalWrite(relay4_pin, HIGH);
        Serial.println("อุปกรณ์ตัวที่ 4 ติด");
        return 1;
      } else {
        digitalWrite(relay4_pin, LOW);
        Serial.println("อุปกรณ์ตัวที่ 4 ดับ");
        return 0;
      }
      break;
    //------------------------------------------------    
    default:
      return -1;
      break;
  }
}
