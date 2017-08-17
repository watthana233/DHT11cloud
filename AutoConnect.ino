#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFiMulti.h>
#include <WiFiManager.h>
#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <PubSubClient.h>

#define FIREBASE_HOST "daydevproject-98be3.firebaseio.com"
#define FIREBASE_AUTH "YfioSzhdDdZockDKpC8v9cNJOHUygCC9F5vg5NJv"
#define SECONDS_DS(seconds) ((seconds)*1000000UL)
#define DHTPIN D4
#define DHTTYPE DHT11

#define mqtt_server "m11.cloudmqtt.com"
#define mqtt_port 18603
#define mqtt_user "sharkpotato"
#define mqtt_password "5221040233"

// NodeMCU Dev Kit => D1 = SCL, D2 = SDA
LiquidCrystal_I2C lcd(0x27, 20, 4);
DHT dht(DHTPIN, DHTTYPE);
ESP8266WiFiMulti WiFiMulti;
String name;
WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);
  Serial.println("LED test!");
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
  dht.begin();
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  client.setServer(mqtt_server, mqtt_port); 
}     
void loop() {
   float h = dht.readHumidity();
   float t = dht.readTemperature();
   float f = dht.readTemperature(true);
   if (isnan(h) || isnan(t) || isnan(f)) {
     Serial.println("Failed to read from DHT sensor!");
     return;
   }
   float hi = dht.computeHeatIndex(f, h);
   Firebase.setInt("DHT/temp", t);
   Firebase.setInt("DHT/humi", h);
   Firebase.setInt("DHT/heat", f);
   if (Firebase.failed()) {
      Serial.print("pushing /DHT failed:");
      Serial.println(Firebase.error());  
      return;
    }
    delay(10000);
    
   Serial.println(t);
   Serial.println(h);
   Serial.println(f);
   lcd.backlight();
   lcd.print("temp :");
   lcd.print(t);
   lcd.setCursor(0, 1);
   lcd.print("humi :");
   lcd.print(h);
   lcd.setCursor(0, 2);
   lcd.print("heat :");
   lcd.print(f);

   if ((WiFiMulti.run() == WL_CONNECTED)) {
      HTTPClient http;
      String url = "https://watthana.us/dht/index.php?temp="+String(t)+"&humi="+String(h)+"&heat="+String(f);
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

    if (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect("ESP8266Client", mqtt_user, mqtt_password)) {
      Serial.println("connected");
      client.subscribe("Temperature");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
      return;
    }
  }
  char buffer[10];
  dtostrf(t,0, 0, buffer);
  client.publish("Temperature",buffer);
  Serial.println("Send !");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");
  delay(5000);
  client.loop();
    
   Serial.println("Sleeping");
   lcd.setCursor(0, 3);
   lcd.print("Sleeping");
   ESP.deepSleep(SECONDS_DS(30));
}
