#include "vex.h"
#include "cracker.h"

void moveTopMotor(float degrees){
  crackerTopMotor.resetPosition();
  if (degrees < 0){
    crackerTopMotor.spin(reverse, 10, percent);
    while (crackerTopMotor.position(degrees) > degrees){}
    crackerTopMotor.stop(brake);
  }else{
    crackerTopMotor.spin(forward, 10, percent);
    while(crackerTopMotor.position(degrees) < degrees){}
    crackerTopMotor.stop(brake);
  }
}

void moveBottomMotor(float degrees){
  crackerBottomMotor.resetPosition();
  if (degrees  < 0){
    crackerBottomMotor.spin(reverse, 10, percent);
    while (bottomMotor.position(degrees) > degrees){}
    crackerBottomMotor.stop(brake);
  }else{
    crackerBottomMotor.spin(forward, 10, percent);
    while(topMotor.position(degrees) < degrees){}
    crackerBottomMotor.stop(brake);

  }
}