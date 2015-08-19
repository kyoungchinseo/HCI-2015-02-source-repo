const int SER = 8;
const int LATCH = 9;
const int CLK = 10;

void setup()
{
  pinMode(SER,OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLK, OUTPUT);
  digitalWrite(LATCH,LOW);
  shiftOut(SER,CLK, MSBFIRST, B10101010);
  digitalWrite(LATCH,HIGH);  
}

void loop() 
{
  
}
