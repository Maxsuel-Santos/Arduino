int sw1 = A5;

void setup() 
{
  for (int j=2; j<10; j++)
   {
    pinMode(j,OUTPUT);
   }
  for(int i=10; i<18;i++)
   {
    pinMode(i,OUTPUT);
   }
   pinMode(sw1,INPUT);
   randomSeed(analogRead(0));
}
void effect1(int repeat)
{
for(int ile=0;ile<repeat;ile++) 
{
  for (int j=2; j<10; j++)
    {
      digitalWrite(j, HIGH); 
      for (int k= 10 ; k<18 ; k++)
          {
            digitalWrite(k, LOW);
            delay(10);
            digitalWrite(k, HIGH);
          }      
      digitalWrite(j, LOW); 
    }
}
}
void effect2(int repeat)
{
  for(int ile=0;ile<repeat;ile++)
  {
  for (int i=10; i<18; i++)
    {
    digitalWrite(i, LOW);
    for (int x=2; x<10; x++)
      {
      digitalWrite(x, HIGH);
      delay(10);
      digitalWrite(x, LOW);
      }
    digitalWrite(i, HIGH);
  }
}
}
void los1()
{
  for (int j=2; j<4; j++){
    int liczba_losowa = random()%8+2;
    digitalWrite(liczba_losowa,HIGH);}
}
  void los2()
    {
    for (int i=10; i<13; i++){
    int liczba_losowa = random()%8+10;
    digitalWrite(liczba_losowa,LOW); }
  } 
void loop()
{
if(digitalRead(sw1)==HIGH)
 {
  effect1(4);
  
  effect2(4);
  
  los1();
  
  los2();
 }
}
