// C++ code
//
void setup()
{
  Serial.begin(9600);
    Serial.print("Hello");

  pinMode(5, OUTPUT);
}

void loop()
{
  int value= analogRead(A2);
  float miliVoltage= value*(5000/1024);
  float temperature=(miliVoltage-500)/10;
  Serial.print("Temperature: ");
  Serial.println(temperature);
  if(temperature>25){
  digitalWrite(5, HIGH);
  }
  else{
    digitalWrite(5,LOW);
  }
  delay(1000);
}
