#include <ArduinoJson.h>
#include <ESP8266HTTPClient.h>

#include <ESP8266WiFi.h>
void setup() {
  pinMode(2,INPUT);
  Serial.begin(115200);                  //Serial connection
  WiFi.begin("dreamers", "dreamers13");   //WiFi connection
  while (WiFi.status() != WL_CONNECTED) {  //Wait for the WiFI connection completion
    delay(500);
    Serial.println("Waiting for connection");
  }
}

void loop() {
  int value = digitalRead(2);
  int wattage=0;
  if(value>0)  //OFF
    wattage=0;
  else        //ON
    wattage=10;
  String thisString = String(value);
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  root["zone_name"] = "Zone 1";
  root["floor_id"] = 6;
  root["wattage"] = wattage;
  String json;
  root.printTo(json);
  if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status
    HTTPClient http;    //Declare object of class HTTPClient
    http.begin("http://192.168.0.4:9191/saveTImeSeriesDataWifi");      //Specify request destination
    http.addHeader("Content-Type", "application/json");  //Specify content-type header
    int httpCode = http.POST(json);   //Send the request
    String payload = http.getString();                                        //Get the response payload
    value++;
    Serial.println("httpCode" +httpCode);   //Print HTTP return code
    Serial.println(payload);    //Print request response payload
    http.end();  //Close connection
  } else {
    Serial.println("Error in WiFi connection");
  }
  delay(10000);  //Send a request every 10 seconds
}
