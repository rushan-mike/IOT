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

  int stepSize = 5;
  int duration = 20;
  int stepMax = 255;
  int stepMin = 0;
  // step : 0 - 255 
  // direction : true --> forward
  // heading : true --> turn
  // yaw: true --> right
  
  stepUp(100, stepMax, stepSize, duration, true, false, true);
  delay(1000);
  stepDown(stepMax, 50, stepSize, duration, true, false, true);
  delay(1000);
  
  stepUp(100, stepMax, stepSize, duration, false, false, true);
  delay(1000);
  stepDown(stepMax, 50, stepSize, duration, false, false, true);
  delay(1000);

}

void stepUp(int stepMin, int stepMax, int stepSize, int duration, bool direction, bool heading, bool yaw){
  for(int i = stepMin; i <= stepMax; i=i+stepSize){
    speedCon(i);
    if (direction == true && heading == false) forwardCon(duration);
    if (direction == false && heading == false) backwardCon(duration);
    if (direction == true && heading == true && yaw == true) forwardRightCon(duration);
    if (direction == true && heading == true && yaw == false) forwardLeftCon(duration);
    if (direction == false && heading == true && yaw == true) backwardRightCon(duration);
    if (direction == false && heading == true && yaw == false) backwardLeftCon(duration);
  }
}

void stepDown(int stepMax, int stepMin, int stepSize, int duration, bool direction, bool heading, bool yaw){
  for(int i = stepMax; i >= stepMin; i=i-stepSize){
    speedCon(i);
    if (direction == true && heading == false) forwardCon(duration);
    if (direction == false && heading == false) backwardCon(duration);
    if (direction == true && heading == true && yaw == true) forwardRightCon(duration);
    if (direction == true && heading == true && yaw == false) forwardLeftCon(duration);
    if (direction == false && heading == true && yaw == true) backwardRightCon(duration);
    if (direction == false && heading == true && yaw == false) backwardLeftCon(duration);
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