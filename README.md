# Autonomous Snowplow

This repository was created for the SYSC4805 term project by team OldGold.
The goal of the project is to materialize a robot whose task will be to clear 
off snow in an enclosed area without hitting any fixed or moving obstacles.

## Technical information ```UML Diagram```

### Architecture Diagram
<p align="center" width="100%">
   <img src="https://github.com/SYSC4805-Fall2022/sysc4805_term_project-oldgold_l3g4/blob/ca081ecd65f376da9b269ba511171101433c0726/UML_Diagram/Architecture%20Diagram_SYSC4805.png" width="80%" margin-left="auto" margin-right="auto">
</p>

### StateChart Diagram
<p align="center" width="100%">
   <img src="https://github.com/SYSC4805-Fall2022/sysc4805_term_project-oldgold_l3g4/blob/ca081ecd65f376da9b269ba511171101433c0726/UML_Diagram/StateChart%20Diagram_SYSC4805.png" width="80%" margin-left="auto" margin-right="auto">
</p>

### Sequence Diagram
<p align="center" width="100%">
   <img src="https://github.com/SYSC4805-Fall2022/sysc4805_term_project-oldgold_l3g4/blob/ca081ecd65f376da9b269ba511171101433c0726/UML_Diagram/Sequence%20Diagram_SYSC4805.png" width="80%" margin-left="auto" margin-right="auto">
</p>

## The Scripts ```Project Code``` 

### The [lineDetector.cpp](https://github.com/SYSC4805-Fall2022/sysc4805_term_project-oldgold_l3g4/blob/f5fa6cdf03f40748cd4755e9c3312ee090cc197e/projectCode/lineDetector.cpp)

This C++ file is used to detect the black path line or perimeter and makes use of the Line follower
sensor.  

### The [motorControl.cpp](https://github.com/SYSC4805-Fall2022/sysc4805_term_project-oldgold_l3g4/blob/f3e2f253620e33eb8b9833ad3b2a7756e02619ba/projectCode/motorControl.cpp)

This C++ file is used to control the motor and allow the assembly to move in any direction or stop
```Forward```,  ```Backward```,  ```Left```, ```Right``` and ```Stop```. 

### The [projectCode.ino](https://github.com/SYSC4805-Fall2022/sysc4805_term_project-oldgold_l3g4/blob/f3e2f253620e33eb8b9833ad3b2a7756e02619ba/projectCode/projectCode.ino)

This Arduino file is used to control the whole system and also has a funtion called
```checkForObstacle()``` which makes use of the Time of Flight sensor to detect any 
obstacles. This file uses the previous files through the ```#include``` statemets.
