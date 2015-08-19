
int LED = 9;
int BUTTON = 2;

void setup()
{
  pinMode(BUTTON, INPUT);
  pinMode(LED, OUTPUT);
}

void loop()
{
  if (digitalRead(BUTTON) == HIGH) 
  {
    digitalWrite(LED,HIGH);
  } else {
    digitalWrite(LED,LOW);
  }
}
