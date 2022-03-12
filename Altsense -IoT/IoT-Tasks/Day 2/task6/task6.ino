void setup() {
  // put your setup code here, to run once:
  pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int a[3]={9,10,11};
  for(int i=0;i<2;i++)
  {
    for(int j=0;j<3;j++)
   {
    digitalWrite(a[j],i);
    delay(2000);
  }
  }
}
