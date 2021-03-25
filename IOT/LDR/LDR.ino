void setup() {
  // put your setup code here, to run once:
 pinMode(A0,INPUT);
 pinMode(D2,OUTPUT);
 Serial.begin(9600);  // baudrate (9600 std in india)  - data transmission speed
 
}

void loop() {
  // put your main code here, to run repeatedly:
  int s = analogRead(A0);  //digitalread converts input to binary
  if(s>80){
    digitalWrite(D2,LOW);
  }
  else{
    digitalWrite(D2,HIGH);
  }
  Serial.println(s);
  //delay(1000);
  
}
