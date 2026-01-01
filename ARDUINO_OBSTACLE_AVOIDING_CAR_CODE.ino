#include <Servo.h>

// Ultrasonic sensor pins
#define Trig 11
#define Echo 12
#define MOTOR_SPEED 180  
#define DIST_LIMIT 20    

Servo s;

// Right motor pins 
int enableRightMotor = 6;
int rightMotorPin1 = 7;
int rightMotorPin2 = 8;

// Left motor pins 
int enableLeftMotor = 5;
int leftMotorPin1 = 9;
int leftMotorPin2 = 10;

void setup() {

  pinMode(enableRightMotor, OUTPUT);
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);

  pinMode(enableLeftMotor, OUTPUT);
  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);

  s.attach(2);
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);

  s.write(90); 
  
  delay(1000); 
}

void loop() {
  int distanceForward = get_dist();

  if (distanceForward > DIST_LIMIT) {
    rotatemotor(MOTOR_SPEED, MOTOR_SPEED); 
  } 
  else {
    rotatemotor(0, 0); 
    delay(500);
    
    // Look Right
    s.write(10);
    delay(600);
    int distRight = get_dist();

    // Look Left
    s.write(170);
    delay(800);
    int distLeft = get_dist();

    
    s.write(90);
    delay(400);

    
    if (distRight > distLeft && distRight > DIST_LIMIT) {
      // Turn Right
      rotatemotor(-MOTOR_SPEED, MOTOR_SPEED); 
      delay(500); 
    } 
    else if (distLeft > distRight && distLeft > DIST_LIMIT) {
      // Turn Left
      rotatemotor(MOTOR_SPEED, -MOTOR_SPEED);
      delay(500); 
    else {
      
      rotatemotor(-MOTOR_SPEED, -MOTOR_SPEED);
      delay(800);
      rotatemotor(MOTOR_SPEED, -MOTOR_SPEED); 
      delay(600);
    }
    
    rotatemotor(0, 0);
    delay(300);
  }
}


int get_dist() {
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);

  long duration = pulseIn(Echo, HIGH, 30000); 
  int d = duration * 0.034 / 2;

  if (d == 0) return 400;  
  return d;
}


void rotatemotor(int rightmotor, int leftmotor) {
  // Right Motor
  if (rightmotor > 0) {
    digitalWrite(rightMotorPin1, HIGH);
    digitalWrite(rightMotorPin2, LOW);
  } else if (rightmotor < 0) {
    digitalWrite(rightMotorPin1, LOW);
    digitalWrite(rightMotorPin2, HIGH);
  } else {
    digitalWrite(rightMotorPin1, LOW);
    digitalWrite(rightMotorPin2, LOW);
  }

  // Left Motor
  if (leftmotor > 0) {
    digitalWrite(leftMotorPin1, HIGH);
    digitalWrite(leftMotorPin2, LOW);
  } else if (leftmotor < 0) {
    digitalWrite(leftMotorPin1, LOW);
    digitalWrite(leftMotorPin2, HIGH);
  } else {
    digitalWrite(leftMotorPin1, LOW);
    digitalWrite(leftMotorPin2, LOW);
  }

  analogWrite(enableRightMotor, abs(rightmotor));
  analogWrite(enableLeftMotor, abs(leftmotor));
}