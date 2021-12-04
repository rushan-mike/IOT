
int brightness = 0;
int time = 5;
int fade = 5;

void setup() {

  int pin = 1;

  while (true){

    pin = pin + 1;
    pinMode(pin, OUTPUT);
    if (pin == 12 ) break;

  }

  pinMode(13, INPUT_PULLUP);
}

void loop() {

  if (digitalRead(13) == HIGH){
    lightUP(2, 12, true);
    lightUP(2, 12, false);
    delay(time*10 - time);

    lightUP(12, 2, true);
    lightUP(12, 2, false);
    delay(time*100 - time);
  }
}

void lightUP(int start, int end, bool state){

  while (true){
    
    delay(time);
    if (state == true) brightness = 0;
    if (state == false) brightness = 255;

    while (true){

      delay(time/5);
      analogWrite(start, brightness);

      if (state == true && brightness == 255) break;
      if (state == false && brightness == 0) break;
      if (state == true) brightness = brightness + fade;
      if (state == false) brightness = brightness - fade;
    }

    if (start == end) break;
    if (start < end) start = start + 1; 
    if (start > end) start = start - 1; 
  }

}