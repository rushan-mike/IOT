
void setup() {

  int pin = 1;

  while (true){

    pin = pin + 1;
    pinMode(pin, OUTPUT);
    if (pin == 12 ) break;
    
  }
}

void loop() {

  int pin = 1;
  int time = 10;

  int brightness = 0;
  int fade = 5;

  while (true){
    
    delay(time);
    brightness = 0;
    pin = pin + 1;

    while (true){

      delay(time/5);
      brightness = brightness + fade;
      analogWrite(pin, brightness);

      if (brightness == 255 ) break;
    }

    if (pin == 12 ) break;  
  }
  
  pin = 1;

  while (true){
    
    delay(time);
    brightness = 255;
    pin = pin + 1;

     while (true){

      delay(time/5);
      brightness = brightness - fade;
      analogWrite(pin, brightness);

      if (brightness == 0 ) break;
    }
    
    if (pin == 12 ) break;
  }

  pin = 13;
  delay(time*10 - time);
  
  while (true){
    
    delay(time);
    brightness = 0;
    pin = pin - 1;

    while (true){

      delay(time/5);
      brightness = brightness + fade;
      analogWrite(pin, brightness);

      if (brightness == 255 ) break;
    }

    if (pin == 2 ) break;   
  }
  
  pin = 13;

  while (true){
    
    delay(time);
    brightness = 255;
    pin = pin - 1;

    while (true){

      delay(time/5);
      brightness = brightness - fade;
      analogWrite(pin, brightness);

      if (brightness == 0 ) break;
    }

    if (pin == 2 ) break;
  }
  
  delay(time*10 - time);
}
