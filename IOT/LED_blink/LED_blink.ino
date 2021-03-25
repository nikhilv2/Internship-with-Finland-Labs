
void setup()
{
  pinMode(D2, OUTPUT);
  
}

void loop()
{
 for(int i=0; i<1024;i++){
  analogWrite(D2, i);
  delay(10);
  }

}
