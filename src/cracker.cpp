#include "vex.h"
#include "cracker.h"

void moveTopMotor(float angle){
  crackerTopMotor.resetPosition();
  if (angle < 0){
    crackerTopMotor.spin(reverse, 10, percent);
    while (crackerTopMotor.position(degrees) > angle){}
    crackerTopMotor.stop(brake);
  } else{
    crackerTopMotor.spin(forward, 10, percent);
    while(crackerTopMotor.position(degrees) < angle){}
    crackerTopMotor.stop(brake);
  }
}

void moveBottomMotor(float angle){
  crackerBottomMotor.resetPosition();
  if (angle  < 0){
    crackerBottomMotor.spin(reverse, 10, percent);
    while (bottomMotor.position(degrees) > angle){}
    crackerBottomMotor.stop(brake);
  } else{
    crackerBottomMotor.spin(forward, 10, percent);
    while(topMotor.position(degrees) < angle){}
    crackerBottomMotor.stop(brake);
  }
}