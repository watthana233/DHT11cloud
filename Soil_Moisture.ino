#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFiMulti.h>
#include <WiFiManager.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define FIREBASE_HOST "soil-5abff.firebaseio.com"
#define FIREBASE_AUTH "8ZZGo1DD9OE8mAzvifAkzJkfOKHfVMoE7r8g0lEK"
#define SECONDS_DS(seconds) ((seconds)*1000000UL)

int sensorPin = A0; 
int soil=0,soi,so,s; 
ESP8266WiFiMulti WiFiMulti;
// NodeMCU Dev Kit => D1 = SCL, D2 = SDA
LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup() {
  Serial.begin(115200);
  //Serial.println("LED test!");
  lcd.begin();
    WiFiManager wifiManager;
    wifiManager.setTimeout(180);    
    if(!wifiManager.autoConnect("AutoConnectAP")) 
    {
      Serial.println("Failed to connect and hit timeout");
      delay(3000);
      ESP.reset();
      delay(5000);
    }
    WiFi.printDiag(Serial);
    Serial.println();
    Serial.println("connected...OK");  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH); 

}

void loop() {
  soil = analogRead(sensorPin);
  soi = 1024-soil;
  s = (soi*100)/1024;
  delay(1000);
  Serial.print("Soil Moisture% = " );
  Serial.println(s);
  Serial.print("Soil Moisture  = " );
  Serial.println(soi);
  Firebase.setInt("Soil/percent", s);
  Firebase.setInt("Soil/data", soi);
  if (Firebase.failed()) {
      Serial.print("pushing /Soil failed:");
      Serial.println(Firebase.error());  
      return;
    }
    delay(10000);
   lcd.backlight();
   lcd.print("Hello SOIL");
   lcd.setCursor(0, 1);
   lcd.print("Soil Moisture% = ");
   lcd.print(s);
   lcd.setCursor(0, 2);
   lcd.print("Soil Moisture  = ");
   lcd.print(soi);
   
   if ((WiFiMulti.run() == WL_CONNECTED)) {
      HTTPClient http;
      String url = "https://watthana.us/soil/index.php?percent="+String(s)+"&data="+String(soi);
      Serial.println(url);
      http.begin(url,"3A 36 07 3E 51 10 C6 46 62 C6 C4 35 63 B0 40 9D 26 E5 35 B6"); 
  
      int httpCode = http.GET();
      if (httpCode > 0) {
      Serial.printf("[HTTP] GET... code: %d\n", httpCode);
      Serial.println("Successful Ok");
      if (httpCode == HTTP_CODE_OK) {
      String payload = http.getString();
      Serial.println(payload);
      }
      } else {
      Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }
      http.end();
    }
    
   Serial.println("Sleeping");
   lcd.setCursor(0, 3);
   lcd.print("Sleeping");
   //ESP.deepSleep(SECONDS_DS(30));
}
