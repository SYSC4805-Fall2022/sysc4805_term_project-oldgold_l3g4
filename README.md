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

### The [lineDetector.cpp] (lineDetector.cpp)

This script is used to detect the black path line and makes use of the Line follower
sensor.  

### The [motorControl.cpp] (motorControl.cpp)

This script is used to control the motor and allow the assembly to move in any direction
```Forward```,  ```Backward```,  ```Left``` and ```Right```. 

### The [projectCode.ino] (projectCode.ino)

This script is used to control the whole system and is composed of a funtion called
```checkForObstacle()``` which makes use of the Time of Flight sensor to detect any 
close obstacle.
