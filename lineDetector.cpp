#include "lineDetector.h"

#define line_detector_front1 A9
#define line_detector_front2 A10
#define line_detector_front3 A11

bool checkForLine(){
  int front1 = digitalRead(line_detector_front1);
  int front2 = digitalRead(line_detector_front2);
  int front3 = digitalRead(line_detector_front3);
  int sum = front1+front2+front3;
  printf("Left: %i Middle: %i Right: %i\n", front1, front3, front2);
  if (sum >= 2)
    return true;
  else
    return false;
}