#include "lineDetector.h"

#define line_detector_front1 A9
#define line_detector_front2 A10
#define line_detector_front3 A11

bool checkForLine(){
  
  int front1 = digitalRead(line_detector_front1);
  int front2 = digitalRead(line_detector_front2);
  int front3 = digitalRead(line_detector_front3);

  int ex1 =  analogRead(line_detector_front1);
  int ex2 =  analogRead(line_detector_front2);
  int ex3 =  analogRead(line_detector_front3);
  //int sum = front1+front2+front3;
  //int sum = ex1+ex2+ex3;
  printf("Left analog: %i Middle analog: %i Right analog: %i\n", ex1, ex3, ex2);
  //printf("Left: %i Middle: %i Right: %i\n", front1, front3, front2);
  if (ex1 > 900 || ex2 > 950 || ex3 > 900)  //different tested threshold for all sensors
    return true;
  else
    return false;
}