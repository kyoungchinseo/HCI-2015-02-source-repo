const int SER = 8;
const int LATCH = 9;
const int CLK = 10;

int seqFirst[14] = {1,2,4,8,16,32,64,128,64,32,16,8,4,2};
int seqSecond[14]= {128,64,32,16,8,4,2,1,2,4,8,16,32,64};

void setup()
{
  pinMode(SER,OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLK, OUTPUT);
}

void loop() 
{
  for(int i =0;i<14;i++) {
    digitalWrite(LATCH,LOW);
    shiftOut(SER,CLK, MSBFIRST, seqFirst[i]);
    shiftOut(SER,CLK, MSBFIRST, seqSecond[i]);
    digitalWrite(LATCH,HIGH);  
    delay(100);
  }
}
