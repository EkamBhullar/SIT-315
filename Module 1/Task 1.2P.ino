const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  6;      // the number of the LED pin

// variables will change:
volatile int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
Serial.begin(9600);
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  // Attach an interrupt to the ISR vector
  attachInterrupt(digitalPinToInterrupt(buttonPin), pin_ISR, FALLING);
}

void loop() {
  int value= analogRead(A2);
  float miliVoltage= value*(5000/1024);
  float temperature=(miliVoltage-500)/10;
  Serial.print("Temperature: ");
  Serial.println(temperature);
  if(temperature>25){
  digitalWrite(ledPin, HIGH);
  }
  else{
    digitalWrite(ledPin,LOW);
  }
  delay(1000);
}

void pin_ISR() {
  
  Serial.println("Task interrupted");
  delayMicroseconds(5000000);
}
