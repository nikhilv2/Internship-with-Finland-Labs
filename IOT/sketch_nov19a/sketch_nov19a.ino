#include<ESP8266WiFi.h>
char* ssid = "VIRUS_ULTRA";
char* pass = "tharoola";
WiFiServer server(80); 


void setup() {
 Serial.begin(9600) ;
 pinMode(D2,OUTPUT);
 Serial.println("Connecting to WiFi...");
 WiFi.begin(ssid,pass) ; //connect nodemcu to the wifi
 while(WiFi.status()!= WL_CONNECTED){
  Serial.println(".") ;
  delay(500);
 }
 Serial.println("WiFi Connected") ;
 server.begin();
 Serial.println(WiFi.localIP());
}


void loop() {
  // put your main code here, to run repeatedly:

}
