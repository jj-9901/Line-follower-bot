//SENSORS
#define Sensor_centre A2  //Output pin for center IR sensor
#define Sensor_left_in A1 //Output pin for left in IR sensor
#define Sensor_right_in A3 //Output pin for right in IR sensor
#define Sensor_left A0 //Output pin for left out sensor
#define Sensor_right A4 //Output pin for right out IR sensor

//Left Motor Pins
#define Motor_left_forward 9 //IN1 for left motor
#define Motor_left_backward 8 //IN2 fr left motor
#define Enable_left 10 //Enable pin for left motor

//Right Motor Pins
#define Motor_right_forward 7 //IN3 for right motor
#define Motor_right_backward 6 //IN4 fr right motor
#define Enable_right 5 //Enable pin for right motor

int on = HIGH;
int off = LOW;
void setup() {
  
  pinMode(Sensor_centre,INPUT);
  pinMode(Sensor_left,INPUT);
  pinMode(Sensor_right,INPUT);
  pinMode(Sensor_left_in,INPUT);
  pinMode(Sensor_right_in,INPUT);

  //Set motor control pins and enable pins for output
  pinMode(Motor_left_forward,OUTPUT);
  pinMode(Motor_left_backward,OUTPUT);
  pinMode(Enable_left,OUTPUT);

  pinMode(Motor_right_forward,OUTPUT);
  pinMode(Motor_right_backward,OUTPUT);
  pinMode(Enable_right,OUTPUT);

  //Enable both motors
  digitalWrite(Enable_left,HIGH);
  digitalWrite(Enable_right,HIGH);

  Serial.begin(9600);

}

void forward(int delayd) {
  digitalWrite(Motor_right_forward,HIGH);   // Right motor forward
  digitalWrite(Motor_right_backward,LOW);   
  digitalWrite(Motor_left_forward,HIGH);    // Left motor forward
  digitalWrite(Motor_left_backward,LOW);
  analogWrite(Enable_left,235);
  analogWrite(Enable_right,100);
  //Enable pins
  delay(delayd);
}

void slight_left(int delayd) {
  digitalWrite(Motor_right_forward,HIGH);   // Right motor forward
  digitalWrite(Motor_right_backward,LOW);   
  digitalWrite(Motor_left_forward,LOW);    // Left motor stop
  digitalWrite(Motor_left_backward,LOW);
  analogWrite(Enable_left,100);
  analogWrite(Enable_right,20);
  //Enable pins
  delay(delayd);
}

void slight_right(int delayd) {
  digitalWrite(Motor_right_forward,LOW);   // Right motor stop
  digitalWrite(Motor_right_backward,LOW);   
  digitalWrite(Motor_left_forward,HIGH);    // Left motor forward
  digitalWrite(Motor_left_backward,LOW);
  analogWrite(Enable_left,50);
  analogWrite(Enable_right,225);
  //Enable pins
  delay(delayd);
}

void left90(int delayd) {
   // Move slightly left by slowing down the left motor
  digitalWrite(Motor_right_forward,HIGH);   // Right motor forward
  digitalWrite(Motor_right_backward,LOW);   
  digitalWrite(Motor_left_forward,LOW);    // Left motor stop
  digitalWrite(Motor_left_backward,LOW);
  analogWrite(Enable_left,235);
  analogWrite(Enable_right,100);
  //Enable pins
  delay(delayd);
}

void right90(int delayd) {
  // Move slightly right by slowing down the right motor
  digitalWrite(Motor_right_forward,LOW);   // Right motor stop
  digitalWrite(Motor_right_backward,LOW);   
  digitalWrite(Motor_left_forward,HIGH);    // Left motor forward
  digitalWrite(Motor_left_backward,LOW);
  analogWrite(Enable_left,235);
  analogWrite(Enable_right,100);
  //Enable pins
  delay(delayd);
}

void reverse(int delayd) {
  // Move both motors backward
  digitalWrite(Motor_right_forward,LOW);   
  digitalWrite(Motor_right_backward,HIGH);   
  digitalWrite(Motor_left_forward,LOW);    
  digitalWrite(Motor_left_backward,HIGH);
  analogWrite(Enable_left,235);
  analogWrite(Enable_right,100);
  //Enable pins
  delay(delayd);
}

void turn_around(int delayd) {
  // Perform a 180-degree turn (rotate in place)
  digitalWrite(Motor_right_forward,LOW);   // Right motor forward
  digitalWrite(Motor_right_backward,HIGH);   
  digitalWrite(Motor_left_forward,HIGH);    // Left motor forward
  digitalWrite(Motor_left_backward,LOW);
  analogWrite(Enable_left,235);
  analogWrite(Enable_right,100);
  //Enable pins
  delay(delayd);
}


void loop() {
  
  int left=digitalRead(Sensor_left);
  int right=digitalRead(Sensor_right);
  int centre=digitalRead(Sensor_centre);
  int left_in=digitalRead(Sensor_left_in);
  int right_in=digitalRead(Sensor_right_in);

   //if(right_in==on){
  //   slight_right();
  //   delay(200);
  // }

  // else if(left_in==on){
  //   slight_left();
  //   delay(200);
  // }

  if(left==on){
    left90(1450);
  }

  else if(centre==on){
    forward(2000);
  }

  else if(right==on){
    right90(1600);
  }

  // else if(centre==off && left==off && right==off && right_in==off && left_in==off){
  //   turn_around();
  // }

  // else{
  //   move_reverse();
  // }
}
