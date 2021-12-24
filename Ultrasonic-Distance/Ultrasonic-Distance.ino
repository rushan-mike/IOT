#define trigPin 3
#define echoPin 2

long duration;
int distance;

void setup(){
  // Serial.begin(9600);
  // Serial.begin(38400);
  Serial.begin(57600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
 }

void loop(){
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  
  duration=pulseIn(echoPin,HIGH);
  distance=(duration*0.034/2);
  Serial.print("Distance : ");
  Serial.print(distance);
  Serial.println(" cm ");
  delay(1000);              
}
