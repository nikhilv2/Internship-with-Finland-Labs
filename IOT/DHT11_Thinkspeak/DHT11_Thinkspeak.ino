#include<DHT.h>
#include<ThingSpeak.h>
#include<ESP8266WiFi.h>
DHT dht(D2,DHT11) ;
float h,t ;
char* api = "7TTUWLD9MPU5AZD5" ;
char* ssid = "VIRUS_ULTRA" ;
char* pass = "tharoola" ;
WiFiClient client ;
long id = 1236742 ; 
char ip[] = "184.106.153.149" ; //ip of thingspeak.com
void setup() {
  Serial.begin(9600);
  dht.begin() ; //enable the sensor
  Serial.println("Connecting to WiFi") ;
  WiFi.begin(ssid,pass) ;
  while(WiFi.status()!=WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }
  Serial.println("WiFi Connected") ;
  ThingSpeak.begin(client) ;

}

void loop() {
  if(client.connect(ip,80)){
    h = dht.readHumidity() ;
    t = dht.readTemperature() ; // in degree celcius
    Serial.print("Humidity- ");
    Serial.print(h);
    Serial.print(",");
    Serial.print("Temperature- ") ;
    Serial.println(t) ;  //println to print the output on next line
    ThingSpeak.setField(1,h) ;
    ThingSpeak.setField(2,t);
    ThingSpeak.writeFields(id,api);
    client.stop();
  }
  else{
    Serial.print("Unable to connect") ;
  }
  delay(15000); 

}
