/* 
  Sketch generated by the Arduino IoT Cloud Thing "Untitled"
  https://create.arduino.cc/cloud/things/163d6ca2-e232-4aaa-9611-93efa2a188f2 

  Arduino IoT Cloud Variables description

  The following variables are automatically generated and updated when changes are made to the Thing

  float h_c;
  float t_c;
  int ldr_value;
  bool state_c;

  Variables which are marked as READ/WRITE in the Cloud Thing will also have functions
  which are called when their values are changed from the Dashboard.
  These functions are generated with the Thing and added at the end of this sketch.
*/

#include "thingProperties.h"
#include "DHT.h"
#include "DHT_U.h"

#define DHTPIN 3
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);


void setup() {
  dht.begin();
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  h_c = dht.readHumidity();
  t_c = dht.readTemperature();

  if (isnan(t_c) || isnan(h_c)) {
    Serial.println("Failed to read from DHT");
  }else {
      Serial.print("Humidity: ");
      Serial.print(h_c);
      Serial.print("%\t");
      Serial.print("Temperature: ");
      Serial.print(t_c);
      Serial.println(" *C");
  }
  delay(500);
}





