void setup() {
  pinMode(D2,INPUT);    // echo
  pinMode(D1,OUTPUT);// trigger
  pinMode(D3,OUTPUT);
  pinMode(D4,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(D1,HIGH);
  delayMicroseconds(10);
  digitalWrite(D1,LOW);
  delayMicroseconds(10);
  long t = pulseIn(D2,HIGH)/2;  // reads the ultrasound waves and convert to microseconds
  long d_cm = t/29;
  long d_inch = t/74;
  Serial.print("Distance - ");
  Serial.print(d_cm);
  Serial.print(" Centimetres, ");
  Serial.print(d_inch);
  Serial.println(" Inches");
  delay(1000);
  if(d_cm<=20)
  {
    digitalWrite(D3,HIGH);
     digitalWrite(D4,LOW);
  }
  else
  {
    digitalWrite(D4,HIGH);
    digitalWrite(D3,LOW); 
  }
}
