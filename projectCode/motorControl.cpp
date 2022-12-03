#include "motorControl.h"
//left_motor controls 2 wheels on left side of robot
//right_motor controls 2 wheels on right side of robot
#define left_motor_en 2
#define right_motor_en 3
#define left_motor_dir 4
#define right_motor_dir 5

//move robot forward using driver board 
void forward(){
  printf("FORWARD\n");
  analogWrite(left_motor_en, 200);
  analogWrite(right_motor_en, 200);
  digitalWrite(left_motor_dir, LOW);
  digitalWrite(right_motor_dir, HIGH);
}

//move robot forward at slower speed 
void slowForward(){
  printf("FORWARD SLOWER\n");
  analogWrite(left_motor_en, 150);
  analogWrite(right_motor_en, 150);
  digitalWrite(left_motor_dir, LOW);
  digitalWrite(right_motor_dir, HIGH);
}

//move robot backward
void backward(){
  printf("BACKWARD\n");
  analogWrite(left_motor_en, 255);
  analogWrite(right_motor_en, 255);
  digitalWrite(left_motor_dir, HIGH);
  digitalWrite(right_motor_dir, LOW);
}

//turn robot left
void left(){
  printf("LEFT\n");
  analogWrite(left_motor_en, 255);
  analogWrite(right_motor_en, 255);
  digitalWrite(left_motor_dir, HIGH);
  digitalWrite(right_motor_dir, HIGH);
  delay(1000); //turn left for 1s
}

//turn robot right
void right(){ 
  printf("RIGHT\n");
  analogWrite(left_motor_en, 255);
  analogWrite(right_motor_en, 255);
  digitalWrite(left_motor_dir, LOW);
  digitalWrite(left_motor_dir, LOW);
  delay(1000); //turn right for 1s 
}

//stop robot movement
void stop(){
  printf("STOP\n");
  analogWrite(left_motor_en, 0);
  analogWrite(right_motor_en, 0);
  digitalWrite(left_motor_dir, LOW);
  digitalWrite(right_motor_dir, LOW);
}