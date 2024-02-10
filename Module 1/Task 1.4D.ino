// C++ code
//

volatile bool state=false;
volatile bool PIRstate=false;

int timer1_compare_match;
const uint16_t t1_load=0;
const uint16_t t1_comp=31250;

ISR(TIMER1_COMPA_vect){
  
  digitalWrite(13,digitalRead(13) ^ 1);
   int value= analogRead(A2);
  float miliVoltage= value*(5000/1024);
  float temperature=(miliVoltage-500)/10;
  Serial.print("Temperature: ");
  Serial.println(temperature);
 
}
void setup()
{
  Serial.begin(9600);
  noInterrupts();
  TCCR1A=0;

  TCCR1B &=~(1<<WGM13);
  TCCR1B |=(1<<WGM12);

  TCCR1B |= (1<<CS12);
  TCCR1B &= ~(1<<CS11);
  TCCR1B |= (1<<CS10);
  TCNT1=t1_load;
  OCR1A=t1_comp;

  TIMSK1 = (1 << OCIE1A);

  interrupts();
  Serial.println("Hello");
  pinMode(7,INPUT_PULLUP);
  pinMode(11,OUTPUT);
  pinMode(13,OUTPUT);
  PCICR |= B00000100;
  PCMSK2 |=B10000100;

}

void loop()
{
  
 
 // delay(1000);
 // digitalWrite(13,LOW);
 // digitalWrite(7,LOW);
 
  
}
ISR(PCINT2_vect){
  if(digitalRead(2)==HIGH )
  {
    Serial.println("Interrupted By PIR Sensor");
   
  
  }
 
 
  else{
  // If the button is pressed and was released previously
  if (digitalRead(7) == LOW ) {
    // Toggle the state of the LED
    state = !state;
    digitalWrite(11, state);
   Serial.println("Interrupted By Push Button");
  }
    
  }
 
 
}
