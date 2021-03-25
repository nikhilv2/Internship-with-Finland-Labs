#include<ESP8266WiFi.h>
#include<Adafruit_MQTT.h>
#include<Adafruit_MQTT_Client.h>
#define ssid "VIRUS_ULTRA" 
#define pass "tharoola" 
#define server "io.adafruit.com"
#define port 1883
#define user "nikhilv2"
#define key "aio_LNaj33wd73msmSiRVtYHWszi2TkV"
WiFiClient client ;
Adafruit_MQTT_Client mqtt(&client,server,port,user,key);
Adafruit_MQTT_Subscribe button = Adafruit_MQTT_Subscribe(&mqtt,user"/feeds/switch");
Adafruit_MQTT_Subscribe slider = Adafruit_MQTT_Subscribe(&mqtt,user"/feeds/slider");
void MQTT_Connect(){
  if(mqtt.connected()){
    return;
  }
  Serial.println("Connecting to MQTT Adafruit server") ;
  int ret,retries=3;
  while(ret=mqtt.connect()!=0){
    Serial.println(mqtt.connectErrorString(ret));
    Serial.println("Retrying to connect after 5 seconds");
    mqtt.disconnect();
    delay(5000) ;
    retries-- ;
    if(retries==0){
      while(1);
    }
  }
  Serial.println("MQTT Connected");
}
void setup() {
  Serial.begin(9600);
  pinMode(D2,OUTPUT);
  Serial.println("Connecting to WiFi") ;
  WiFi.begin(ssid,pass);
  while(WiFi.status()!=WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }
  Serial.println("Wifi connected");
  mqtt.subscribe(&button);
  mqtt.subscribe(&slider);

}

void loop() {
  MQTT_Connect();
  Adafruit_MQTT_Subscribe *sub;
  while((sub = mqtt.readSubscription(500))){
    if(sub==&button){
      char* data = (char*)button.lastread;
      Serial.println(data);
      if(strcmp(data,"ON")==0){
        digitalWrite(D2,HIGH);
        Serial.println("LED ON");
      }
      if(strcmp(data,"OFF")==0){
        digitalWrite(D2,LOW);
        Serial.println("LED OFF");
      }
    }
    if(sub==&slider){
      int brightness = atoi((char*)slider.lastread);
      Serial.println(brightness);
      analogWrite(D2,brightness);
    }
  }

}
