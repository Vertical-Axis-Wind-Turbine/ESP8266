unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 1000;    // the debounce time; increase if the output flickers
int pinInterrupt = 5;
volatile int Count = 0;
 
ICACHE_RAM_ATTR void onChange()
{
  if ( digitalRead(pinInterrupt) == LOW )
  {
    Count++;
  }
}
 
void setup()
{
  Serial.begin(9600); //Initialize serial port
  Serial.println("hi");
  pinMode(pinInterrupt, INPUT_PULLUP);// set the interrupt pin
  attachInterrupt( digitalPinToInterrupt(pinInterrupt), onChange, FALLING);
}
 
void loop()
{
  if ((millis() - lastDebounceTime) > debounceDelay)
  {
    lastDebounceTime = millis();
    
    Serial.println("hello");
    Serial.print(Count * 0.83);
    
    Count = 0;
    
    Serial.println("m/s");
    
  }
  delay(1);
}
