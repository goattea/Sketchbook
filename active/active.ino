int buzzer = 12;
int buzzToneDelay = 10;
int tonePauseDelay = 5000;

void setup()
{
 pinMode(buzzer,OUTPUT);//initialize the buzzer pin as an output
}

void loop()
{
  for(unsigned int i = 0; i < 100; i++)
  {
    digitalWrite(buzzer,HIGH);
    delayMicroseconds(buzzToneDelay * i);
    digitalWrite(buzzer,LOW);
    delayMicroseconds(buzzToneDelay * i);
  }

  digitalWrite(buzzer,LOW);
  delay(tonePauseDelay);
  buzzToneDelay += buzzToneDelay;
/*
 unsigned char i;
 while(1)
 {
   //output an frequency
   for(i=0;i<80;i++)
   {
  
    }
    //output another frequency
     for(i=0;i<100;i++)
      {
        digitalWrite(buzzer,HIGH);
        delay(2);//wait for 2ms
        digitalWrite(buzzer,LOW);
        delay(2);//wait for 2ms
      }
  }
  */
} 
