// C++ code
//
int state=0;
void setup()
{
  Serial.begin(9600);
    Serial.print("Hello");
pinMode(2,INPUT_PULLUP);
  pinMode(7, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(2),isr,FALLING);
  attachInterrupt(digitalPinToInterrupt(3),pir,RISING);
}

void loop()
{
  int value= analogRead(A2);
  float miliVoltage= value*(5000/1024);
  float temperature=(miliVoltage-500)/10;
  Serial.print("Temperature: ");
  Serial.println(temperature);
  state= digitalRead(3);
  
 
  delay(1000);
  digitalWrite(13,LOW);
}
void isr(){
  digitalWrite(13,HIGH);
  Serial.println(" Interrupted by Push Button");
}
void pir(){
  digitalWrite(7,HIGH);
  Serial.println("Interrupted By PIR Sensor");
}
