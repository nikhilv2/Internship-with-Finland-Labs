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
Adafruit_MQTT_Publish sensor = Adafruit_MQTT_Publish(&mqtt,user"/feeds/gauge");
Adafruit_MQTT_Publish chart = Adafruit_MQTT_Publish(&mqtt,user"/feeds/chart");
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
  pinMode(D2,OUTPUT); //trigger
  pinMode(D1,INPUT); //echo
  Serial.println("Connecting to WiFi") ;
  WiFi.begin(ssid,pass);
  while(WiFi.status()!=WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }
  Serial.println("Wifi connected");
 
 
}

void loop() {
  MQTT_Connect();
  digitalWrite(D2,HIGH);
  delayMicroseconds(10);
  digitalWrite(D2,LOW);
  delayMicroseconds(10);
  float t = pulseIn(D1,HIGH)/2;  // reads the ultrasound waves and convert to microseconds
  float d_cm = t/29;
  float d_inch = t/74;
  Serial.print("Distance - ");
  Serial.print(d_cm);
  Serial.print(" Centimetres, ");
  Serial.print(d_inch);
  Serial.println(" Inches");
  sensor.publish(d_cm);
  chart.publish(d_cm);
  delay(10000);
  

}
