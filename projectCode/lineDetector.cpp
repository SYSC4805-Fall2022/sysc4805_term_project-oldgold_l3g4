#include "lineDetector.h"

#define line_detector_front1 A9
#define line_detector_front2 A10
#define line_detector_front3 A11

//method for perimeter detection using line sensor
bool checkForLine(){

  //read from each sensor
  int ex1 =  analogRead(line_detector_front1);
  int ex2 =  analogRead(line_detector_front2);
  int ex3 =  analogRead(line_detector_front3);

  //print readings
  printf("Left analog: %i Middle analog: %i Right analog: %i\n", ex1, ex3, ex2);
  //return true if black detected for any sensor false otherwise
  if (ex1 > 900 || ex2 > 950 || ex3 > 900)  //different tested threshold for all sensors
    return true;
  else
    return false;
}