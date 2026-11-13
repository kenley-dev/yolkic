#include "vex.h"
#include "capsule.h"

void moveTopMotor(float angle){
  capsuleTopMotor.resetPosition();
  if (angle < 0){
    capsuleTopMotor.spin(reverse, 10, percent);
    while (capsuleTopMotor.position(degrees) > angle){}
    capsuleTopMotor.stop(brake);
  } else{
    capsuleTopMotor.spin(forward, 10, percent);
    while(capsuleTopMotor.position(degrees) < angle){}
    capsuleTopMotor.stop(brake);
  }
}

void moveBottomMotor(float angle){
  capsuleBottomMotor.resetPosition();
  if (angle  < 0){
    capsuleBottomMotor.spin(reverse, 10, percent);
    while (capsuleBottomMotor.position(degrees) > angle){}
    capsuleBottomMotor.stop(brake);
  } else{
    capsuleBottomMotor.spin(forward, 10, percent);
    while(capsuleBottomMotor.position(degrees) < angle){}
    capsuleBottomMotor.stop(brake);
  }
}

void moveCapsule() {

    while (capsuleTimer.time(seconds) <= CAPSULE_INTERVAL*4) {} // waits a quarter of a seconds before starting the cracker motors

    moveTopMotor(90); 
    capsuleTimer.clear();

    while (capsuleTimer.time(seconds) <= CAPSULE_INTERVAL) {}

    moveTopMotor(-90);
    capsuleTimer.clear();

    while (capsuleTimer.time(seconds) <= CAPSULE_INTERVAL) {}

    moveBottomMotor(-90);
    capsuleTimer.clear();

    while (capsuleTimer.time(seconds) <= CAPSULE_INTERVAL) {}

    moveBottomMotor(90);
    capsuleTimer.clear();

}