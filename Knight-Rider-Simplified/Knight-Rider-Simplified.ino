
void setup() {

  int pin = 1;

  while (true){

    pin = pin + 1;
    pinMode(pin, OUTPUT);
    if (pin == 12 ) break;
    
  }
  // pinMode(2, OUTPUT);
  // pinMode(3, OUTPUT);
  // pinMode(4, OUTPUT);
  // pinMode(5, OUTPUT);
  // pinMode(6, OUTPUT);
  // pinMode(7, OUTPUT);
  // pinMode(8, OUTPUT);
  // pinMode(9, OUTPUT);
  // pinMode(10, OUTPUT);
  // pinMode(11, OUTPUT);
  // pinMode(12, OUTPUT);
}

void loop() {

  int pin = 1;
  int time = 100;

  while (true){
    
    delay(time);
    pin = pin + 1;

    digitalWrite(pin, HIGH);
    if (pin == 12 ) break;
    
  }
  // digitalWrite(2, HIGH);
  // delay(10);
  // digitalWrite(3, HIGH);
  // delay(10);
  // digitalWrite(4, HIGH);
  // delay(10);
  // digitalWrite(5, HIGH);
  // delay(10);
  // digitalWrite(6, HIGH);
  // delay(10);
  // digitalWrite(7, HIGH);
  // delay(10);
  // digitalWrite(8, HIGH);
  // delay(10);
  // digitalWrite(9, HIGH);
  // delay(10);
  // digitalWrite(10, HIGH);
  // delay(10);
  // digitalWrite(11, HIGH);
  // delay(10);
  // digitalWrite(12, HIGH);
  
  pin = 1;

  while (true){
    
    delay(time);
    pin = pin + 1;

    digitalWrite(pin, LOW);
    if (pin == 12 ) break;
    
  }
  // delay(10);
  // digitalWrite(2, LOW);
  // delay(10);
  // digitalWrite(3, LOW);
  // delay(10);
  // digitalWrite(4, LOW);
  // delay(10);
  // digitalWrite(5, LOW);
  // delay(10);
  // digitalWrite(6, LOW);
  // delay(10);
  // digitalWrite(7, LOW);
  // delay(10);
  // digitalWrite(8, LOW);
  // delay(10);
  // digitalWrite(9, LOW);
  // delay(10);
  // digitalWrite(10, LOW);
  // delay(10);
  // digitalWrite(11, LOW);
  // delay(10);
  // digitalWrite(12, LOW);

  pin = 13;
  delay(time*10 - time);
  // delay(100);
  
  while (true){
    
    delay(time);
    pin = pin - 1;

    digitalWrite(pin, HIGH);
    if (pin == 2 ) break;
    
  }
  // digitalWrite(12, HIGH);
  // delay(10);
  // digitalWrite(11, HIGH);
  // delay(10);
  // digitalWrite(10, HIGH);
  // delay(10);
  // digitalWrite(9, HIGH);
  // delay(10);
  // digitalWrite(8, HIGH);
  // delay(10);
  // digitalWrite(7, HIGH);
  // delay(10);
  // digitalWrite(6, HIGH);
  // delay(10);
  // digitalWrite(5, HIGH);
  // delay(10);
  // digitalWrite(4, HIGH);
  // delay(10);
  // digitalWrite(3, HIGH);
  // delay(10);
  // digitalWrite(2, HIGH);
  
  pin = 13;

  while (true){
    
    delay(time);
    pin = pin - 1;

    digitalWrite(pin, LOW);
    if (pin == 2 ) break;
    
  }
  // delay(10);
  // digitalWrite(12, LOW);
  // delay(10);
  // digitalWrite(11, LOW);
  // delay(10);
  // digitalWrite(10, LOW);
  // delay(10);
  // digitalWrite(9, LOW);
  // delay(10);
  // digitalWrite(8, LOW);
  // delay(10);
  // digitalWrite(7, LOW);
  // delay(10);
  // digitalWrite(6, LOW);
  // delay(10);
  // digitalWrite(5, LOW);
  // delay(10);
  // digitalWrite(4, LOW);
  // delay(10);
  // digitalWrite(3, LOW);
  // delay(10);
  // digitalWrite(2, LOW);
  
  delay(time*10 - time);
  // delay(1000);
}
