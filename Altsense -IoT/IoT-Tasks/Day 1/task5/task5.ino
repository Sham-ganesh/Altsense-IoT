void setup() {
  // put your setup code here, to run once:
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int i,j,k;
for(i=0;i<2;i++)
{
  for(j=0;j<2;j++)
  {
    for(k=0;k<2;k++)
    {
       digitalWrite(9,i);
       digitalWrite(10,j);
       digitalWrite(11,k);
       delay(2000);
    }
  }
 }
}
