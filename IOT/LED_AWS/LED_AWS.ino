#include<ESP8266WiFi.h>
#include<ESP8266HTTPClient.h>
char* ssid = "VIRUS_ULTRA";
char* pass = "tharoola";
int code ;
void setup() {
  pinMode(D2,OUTPUT);
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
  HTTPClient http;
  String url = "http://52.66.71.203/get.php";
  http.begin(url);
  code = http.GET();
  String response = http.getString();
  Serial.println(code);
  Serial.println(response);
  if(response=="1"){
     digitalWrite(D2,HIGH);
  }
  else{
     digitalWrite(D2,LOW);
  }
  delay(50);

  

}
