#include <ArduinoJson.h>
#include <aJSON.h>
#include <ESP8266HTTPClient.h>

#include <ESP8266WiFi.h>
void setup() {
  pinMode(2,INPUT);
  Serial.begin(115200);                  //Serial connection
}

void loop() {
 digitalWrite(2,HIGH);
 
 delay(10000);  //Send a request every 10 seconds
 digitalWrite(2,LOW);
}
