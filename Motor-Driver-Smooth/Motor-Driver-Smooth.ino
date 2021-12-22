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

  stepUpFor(120, 200, 100);
  stepDownFor(200, 120, 100);
  delay(1000);
  
  stepUpBack(120, 200, 100);
  stepDownBack(200, 120, 100);
  delay(1000);

}

void stepUpFor(int stepMin, int stepMax, int duration){
  for(int i = stepMin; i <= stepMax; i=i+10)
    {
      speedCon(i);
      forwardCon(duration);
    }
}

void stepDownFor(int stepMax, int stepMin, int duration){
  for(int i = stepMax; i >= stepMin; i=i-10)
    {
      speedCon(i);
      forwardCon(duration);
    }
  stopCon();
}

void stepUpBack(int stepMin, int stepMax, int duration){
  for(int i = stepMin; i <= stepMax; i=i+10)
    {
      speedCon(i);
      backwardCon(duration);
    }
}

void stepDownBack(int stepMax, int stepMin, int duration){
  for(int i = stepMax; i >= stepMin; i=i-10)
    {
      speedCon(i);
      backwardCon(duration);
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

void stopCon(){
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, LOW);

  speedCon(0);
}