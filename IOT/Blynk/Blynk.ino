#define BLYNK_PRINT Serial
#include<BlynkSimpleEsp8266.h>
char auth[] = "vXY29DW4l7YNQQMy2zXQxBCpYb43owmX";
char ssid[] = "VIRUS_ULTRA" ;
char pass[] = "tharoola" ;
void setup() {
  Serial.begin(9600) ;
  Blynk.begin(auth,ssid,pass);

}

void loop() {
  Blynk.run() ;
}
