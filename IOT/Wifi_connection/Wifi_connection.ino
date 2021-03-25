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
  Serial.println(WiFi.status()) ;
  delay(500);
 }
 Serial.println("WiFi Connected") ;
 server.begin();
 Serial.println(WiFi.localIP());
}

void loop() {
  WiFiClient client = server.available() ;
  if(!client){
    return; 
  }
  //Serial.println("New Request Received") ;
  String request = client.readStringUntil('\r') ;
 // Serial.println(request);
 if(request.indexOf("ledon")!=-1){  //if after the ip address, there is /ledon, D2 will be high and led will glow and msg will be shown
  digitalWrite(D2,HIGH);
  Serial.println("LED IS ON") ;
 }
 if(request.indexOf("ledoff")!=-1){
  digitalWrite(D2,LOW);
  Serial.println("LED IS OFF") ;
 }
 client.println("<html><title>LED CONTROL</title><center>");
 client.println("<h1>LED CONTROL</h1>");
 client.println("<a href='/ledon'><button>LED ON</button></a>");
 client.println("<a href='/ledoff'><button>LED OFF</button></a>");
 client.println("</center></html>");

}
