
int count = 0;

void setup() {

  int pin = 1;

  while (true){

    pin = pin + 1;
    pinMode(pin, OUTPUT);
    if (pin == 12 ) break;
    
  }

  Serial.begin(9600);
}

void loop() {

  int pin = 1;
  int time = 100;
  count = count + 1;

  Serial.print(count);
  Serial.println();

  while (true){
    
    delay(time);
    pin = pin + 1;

    digitalWrite(pin, HIGH);
    if (pin == 12 ) break;
    
  }

  pin = 1;

  while (true){
    
    delay(time);
    pin = pin + 1;

    digitalWrite(pin, LOW);
    if (pin == 12 ) break;
    
  }

  pin = 13;
  delay(time*10 - time);
  
  while (true){
    
    delay(time);
    pin = pin - 1;

    digitalWrite(pin, HIGH);
    if (pin == 2 ) break;
    
  }
  
  pin = 13;

  while (true){
    
    delay(time);
    pin = pin - 1;

    digitalWrite(pin, LOW);
    if (pin == 2 ) break;
    
  }
  
  delay(time*10 - time);

}
