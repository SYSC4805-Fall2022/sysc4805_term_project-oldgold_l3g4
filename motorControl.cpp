#include "motorControl.h"
#define left_motor_en 2
#define right_motor_en 3
#define left_motor_dir 4
#define right_motor_dir 5

void forward(){
  printf("FORWARD\n");
  analogWrite(left_motor_en, 255);
  analogWrite(right_motor_en, 255);
  digitalWrite(left_motor_dir, LOW);
  digitalWrite(right_motor_dir, HIGH);
}

void slowForward(){
  printf("FORWARD SLOWER\n");
  analogWrite(left_motor_en, 200);
  analogWrite(right_motor_en, 200);
  digitalWrite(left_motor_dir, LOW);
  digitalWrite(right_motor_dir, HIGH);
}

void backward(){
  printf("BACKWARD\n");
  analogWrite(left_motor_en, 255);
  analogWrite(right_motor_en, 255);
  digitalWrite(left_motor_dir, HIGH);
  digitalWrite(right_motor_dir, LOW);
}

void left(){
  printf("LEFT\n");
  analogWrite(left_motor_en, 255);
  analogWrite(right_motor_en, 255);
  digitalWrite(left_motor_dir, HIGH);
  digitalWrite(right_motor_dir, HIGH);
  delay(850);
}

void right(){ 
  printf("RIGHT\n");
  analogWrite(left_motor_en, 255);
  analogWrite(right_motor_en, 255);
  digitalWrite(left_motor_dir, LOW);
  digitalWrite(left_motor_dir, LOW);
  delay(850);
}

void stop(){
  printf("STOP\n");
  analogWrite(left_motor_en, 0);
  analogWrite(right_motor_en, 0);
  digitalWrite(left_motor_dir, LOW);
  digitalWrite(right_motor_dir, LOW);
}