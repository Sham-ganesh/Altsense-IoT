void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
pinMode(A1,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.print("Temperature of surrounding");
Serial.println(analogRead(A1)*0.48);
delay(2000);
}
