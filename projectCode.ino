#include <Wire.h>
#include <VL53L1X.h>

#define left_motor_en 2
#define right_motor_en 3
#define left_motor_dir 4
#define right_motor_dir 5
#define line_detector_front1 A9
#define line_detector_front2 A10
#define line_detector_front3 A11
#define VL53L1X sensorToF;

void watchdogSetup(void){

}

void setup() {
  // put your setup code here, to run once:
  watchdogEnable(1000); //enable watchdog timer with timeout of 1s
  Serial.begin(115200);
  Wire.begin();
  Wire.setClock(400000); //400kHz I2C
  //motor pins
  pinMode(left_motor_en, OUTPUT);
  pinMode(right_motor_en, OUTPUT);
  pinMode(left_motor_dir, OUTPUT);
  pinMode(right_motor_dir, OUTPUT);
  //line detector pins
  pinMode(line_detector_front1, INPUT);
  pinMode(line_detector_front2, INPUT);
  pinMode(line_detector_front3, INPUT);
  //ToF sensor 
  sensorToF.setTimeout(500);
  if (!sensorToF.init()){
    Serial.println("Failed to detect and initialize ToF sensor.");
    while(1);
  }
  sensorToF.setDistanceMode(VL53L1X::Short);
  sensorToF.setMeasurementTimingBudget(20000);
  sensorToF.startContinuous(50);
}

void loop() {
  // put your main code here, to run repeatedly:
  watchdogReset();
  forward();
  bool line = checkForLine();
  bool obstacle = checkForObstacle();
  if (line){
    backward();
  } 
  /*if (obstacle){
    stop();
  }*/
  delay(1000);
}

bool checkForLine(){
  int front1 = digitalRead(line_detector_front1);
  int front2 = digitalRead(line_detector_front2);
  int front3 = digitalRead(line_detector_front3);
  int sum = front1+front2+front3;
  if (sum == 3)
    return true;
  else
    return false;
}

bool checkForObstacle(){
  sensorToF.read();
  Serial.println(sensorToF.ranging_data.range_mm);
  if (sensorToF.ranging_data.range_mm <= 200)
    return true;
  else
    return false;
}

void forward(){
  analogWrite(left_motor_en, 255);
  analogWrite(right_motor_en, 255);
  digitalWrite(left_motor_dir, LOW);
  digitalWrite(right_motor_dir, HIGH);
}

void backward(){
  analogWrite(left_motor_en, 255);
  analogWrite(right_motor_en, 255);
  digitalWrite(left_motor_dir, HIGH);
  digitalWrite(right_motor_dir, LOW);
}

void left(){
  analogWrite(left_motor_en, 255);
  analogWrite(right_motor_en, 255);
  digitalWrite(left_motor_dir, HIGH);
  digitalWrite(right_motor_dir, HIGH);
}

void right(){ 
  analogWrite(left_motor_en, 255);
  analogWrite(right_motor_en, 255);
  digitalWrite(left_motor_dir, LOW);
  digitalWrite(left_motor_dir, LOW);
}

void stop(){
  analogWrite(left_motor_en, 0);
  analogWrite(right_motor_en, 0);
  digitalWrite(left_motor_dir, LOW);
  digitalWrite(right_motor_dir, LOW);
}
