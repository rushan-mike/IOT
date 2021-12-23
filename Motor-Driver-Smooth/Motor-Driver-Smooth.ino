int motor1pin1 = 4;
int motor1pin2 = 14;
int motor1pin3 = 6;

int motor2pin1 = 8;
int motor2pin2 = 7;
int motor2pin3 = 9;

void setup() {
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor1pin3, OUTPUT); 

  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  pinMode(motor2pin3, OUTPUT);
}

void loop() {  

  int stepLength = 5;
  int duration = 50;
  int stepMax = 200;
  
  stepUp(100, stepMax, stepLength, duration, true);
  stepDown(stepMax, 50, stepLength, duration, true);
  delay(1000);
  
  stepUp(100, stepMax, stepLength, duration, false);
  stepDown(stepMax, 50, stepLength, duration, false);
  delay(1000);

}

void stepUp(int stepMin, int stepMax, int stepLength, int duration, bool direction){
  for(int i = stepMin; i <= stepMax; i=i+stepLength)
    {
      speedCon(i);
      if (direction == true) forwardCon(duration);
      if (direction == false) backwardCon(duration);
    }
}

void stepDown(int stepMax, int stepMin, int stepLength, int duration, bool direction){
  for(int i = stepMax; i >= stepMin; i=i-stepLength)
    {
      speedCon(i);
      if (direction == true) forwardCon(duration);
      if (direction == false) backwardCon(duration);
    }
  stopCon();
}

void speedCon(int speed){
  analogWrite(motor1pin3, speed);
  analogWrite(motor2pin3, speed);
}

void forwardCon(int duration){
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);

  delay(duration);
}

void backwardCon(int duration){
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);

  delay(duration);  
}

void forwardLeftCon(int duration){
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);

  delay(duration);
}

void forwardRightCon(int duration){
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);

  delay(duration);
}

void backwardLeftCon(int duration){
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);

  delay(duration);  
}

void backwardRightCon(int duration){
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);

  delay(duration);  
}

void stopCon(){
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, LOW);

  speedCon(0);
}