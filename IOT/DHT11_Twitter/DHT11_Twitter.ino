#include<DHT.h>
#include<ESP8266WiFi.h>
DHT dht(D2,DHT11) ;
float h,t ;

char* ssid = "VIRUS_ULTRA" ;
char* pass = "tharoola" ;
WiFiClient client ;

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
    String api = "YZLKB20PLHDEUYBD";
    String data = "api_key="+api+"&status=The temperature of my room is "+String(t);
    client.print("POST /apps/thingtweet/1/statuses/update HTTP/1.1\n");
    client.print("Host: api.thingspeak.com\n");
    client.print("Connection :close\n");
    client.print("Content-Type: application/x-www-form-urlencoded\n");
    client.print("Content-Length: ");
    client.print(data.length());
    client.print("\n\n");
    client.print(data);
    Serial.println("Success");
  }
  else{
    Serial.print("Unable to connect") ;
  }
  delay(15000); 

}
