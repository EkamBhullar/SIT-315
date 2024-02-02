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
}

void loop()
{
  int value= analogRead(A2);
  float miliVoltage= value*(5000/1024);
  float temperature=(miliVoltage-500)/10;
  Serial.print("Temperature: ");
  Serial.println(temperature);
  state= digitalRead(4);
  
  if(temperature>25 and state==HIGH){
  digitalWrite(7, HIGH);
  }
  else{
    digitalWrite(7,LOW);
  }
  delay(1000);
  digitalWrite(13,LOW);
}
void isr(){
  digitalWrite(13,HIGH);
  Serial.println("Task Interrupted");
}
