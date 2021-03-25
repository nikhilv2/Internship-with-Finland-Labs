void setup() {
  pinMode(A0,INPUT);
  pinMode(D2,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int s = analogRead(A0);
  if(s>80){
    digitalWrite(D2,LOW);
  }
  else{
    digitalWrite(D2,HIGH); 
  }
  Serial.println(s);
 // delay(1000);
}
