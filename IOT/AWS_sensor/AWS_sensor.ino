#include<ESP8266WiFi.h>
#include<ESP8266HTTPClient.h>
char* ssid = "VIRUS_ULTRA";
char* pass = "tharoola";
float t,cm,inch;
void setup() {
    pinMode(D2,OUTPUT);  // trigger
    pinMode(D1,INPUT);   // echo
    Serial.begin(9600);
    Serial.println("Connecting to Wifi");
    WiFi.begin(ssid,pass);
    while(WiFi.status()!= WL_CONNECTED){
        Serial.print(".");
        delay(500);
      }
    Serial.println("WiFi connected");
}
 
void loop() {
  digitalWrite(D2,HIGH);
  delayMicroseconds(10);
  digitalWrite(D2,LOW);
  delayMicroseconds(10);
  t = pulseIn(D1,HIGH)/2;  // reads the ultrasound waves and convert to microseconds
  cm = t/29;
  inch = t/74;
  Serial.print("Distance - ");
  Serial.print(cm);
  Serial.print(" Centimetres, ");
  Serial.print(inch);
  Serial.println(" Inches");
  HTTPClient http;
  String url = "http://52.66.71.203/sensor.php?field1="+String(cm)+"&field2="+String(inch);
  http.begin(url);  // open the url
  int code = http.GET();
  String response = http.getString();
  Serial.println(code);
  Serial.println(response);
  delay(5000);
 
}
