#include <Wire.h>
#include <VL53L1X.h>
#include "motorControl.h"
#include "lineDetector.h"

//motor connections
#define left_motor_en 2
#define right_motor_en 3
#define left_motor_dir 4
#define right_motor_dir 5
//line detector connections
#define line_detector_front1 A9
#define line_detector_front2 A10
#define line_detector_front3 A11
VL53L1X sensorToF; //time of flight sensor
int state = 0; //state of robot: 0 = move forward, 1 = turn right, 2 = turn left
//wheel encoder initializations
volatile uint32_t CaptureCountA; //time measurement
volatile boolean CaptureFlag; //interrupt flag
float speed; //calculated speed
boolean speedFlag; //true = too fast, false = good speed

//Override default watchdog method
void watchdogSetup(void){

}

//setup code
void setup() {
  watchdogEnable(20000); //enable watchdog timer with timeout of 20s
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
  sensorToF.setTimeout(500); //0.5s timeout
  if (!sensorToF.init()){ 
    Serial.println("Failed to detect and initialize ToF sensor.");
    while(1);
  }
  sensorToF.setDistanceMode(VL53L1X::Short); //ToF in short mode
  sensorToF.setMeasurementTimingBudget(20000);
  sensorToF.startContinuous(50);
  //Wheel encoder
  PMC->PMC_PCER0 |= PMC_PCER0_PID28; // Timer Counter 0 channel 1 IS TC1, TC1 power ON
  TC0->TC_CHANNEL[1].TC_CMR = TC_CMR_TCCLKS_TIMER_CLOCK1 // capture mode, MCK/2 = 42 MHz
    | TC_CMR_ABETRG // TIOA is used as the external trigger
    | TC_CMR_LDRA_RISING// load RA on rising edge of TIOA
    | TC_CMR_ETRGEDG_RISING; // Trigger on rising edge
  TC0->TC_CHANNEL[1].TC_CCR = TC_CCR_SWTRG | TC_CCR_CLKEN; // Reset TC counter and enable
  TC0->TC_CHANNEL[1].TC_IER |= TC_IER_LDRAS; // Trigger interrupt on Load RA
  NVIC_EnableIRQ(TC1_IRQn); // Enable TC1 interrupts
}

//main code to continually loop 
void loop() {
  watchdogReset(); //reset watchdog timer
  if (CaptureFlag) { //wheel encoder interrupt
    CaptureFlag = 0; //Reset the flag,
    speed = (19.648/(CaptureCountA/42000.0/1000.0)/10.0); //calculate speed
    printf("Speed: %f cm/s\n", speed); 
    if (speed > 30){ 
      speedFlag = true; //robot going too fast
    } else {
      speedFlag = false; //robot moving below max allowed speed
    }
  }
  bool line = checkForLine(); //check robot within perimeter
  bool obstacle = checkForObstacle(); //check for any obstacles in front of robot
  printf("Current state is: %i\n", state);
  switch(state){ //state machine 
    case 0: //move forward state
      if (speedFlag){ //check if robot moving too fast
        slowForward();
      } else {
        forward();
      }
      if (line || obstacle){ //check for perimeter or obstacle
        stop();
        state = 1; //turn right 
      } else {
        state = 0; //continue forward
      }
      break;
    case 1: //turn right state
      right();
      if (line || obstacle){
        stop();
        state = 2; //turn left
      } else {
        state = 0; //continue forward
      }
      break;
    case 2: //turn left state
      left();
      if (line || obstacle){ 
        stop();
        state = 2; //turn left again 
      } else {
        state = 0; //continue forward
      }
      break;
  }
  delay(500); //poll every 0.5s
}

void TC1_Handler() { //interrupt handler
  uint32_t status = TC0->TC_CHANNEL[1].TC_SR; //Read status register, Clear status
  if (status & TC_SR_LDRAS) { // If ISR is fired by LDRAS then ....
    CaptureCountA = TC0->TC_CHANNEL[1].TC_RA; //read TC_RA
    speed = (19.648/(CaptureCountA/42000.0/1000.0)/10.0);
    if (speed < 40) { //debouncing any extremely high speed reports
      CaptureFlag = 1; //Inform the main loop of an update
    }
  }
}

//method for obstacle detection using ToF sensor
bool checkForObstacle(){
  sensorToF.read();
  Serial.println(sensorToF.ranging_data.range_mm);
  if (sensorToF.ranging_data.range_mm <= 200) //if obstacle detected within 200mm of robot
    return true;
  else
    return false;
}
