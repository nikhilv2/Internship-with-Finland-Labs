#include<DHT.h>
DHT dht(D2,DHT11) ;
float h,t ;
void setup() {
  Serial.begin(9600);
  dht.begin() ; //enable the sensor
  

}

void loop() {
  h = dht.readHumidity() ;
  t = dht.readTemperature() ; // in degree celcius
  //t = dht.readTemperature(true) ; //in farenheit
  Serial.print("Humidity- ");
  Serial.print(h);
  Serial.print(",");
  Serial.print("Temperature- ") ;
  Serial.println(t) ;  //println to print the output on next line
  delay(5000); 

}
