#include "vex.h"
#include "capsule.h"
#include "config.h"

bool checkCapsuleState() {

    capsuleOptical.setLight(ledState::on);
    capsuleTimer.clear();
    
    while (capsuleTimer.time(seconds) < CAPSULE_INTERVAL*5) { // checks for 10 seconds if the capsule is empty or not
        Brain.Screen.clearScreen();
        Brain.Screen.setCursor(1, 1);
        
        if (capsuleOptical.hue() <= 20 || capsuleOptical.hue() >= 5) { // checks if the color detected is white (hue value between 20 and 340)
            Brain.Screen.print("Object detected!");
            return true; // Egg detected, capsule is not empty

        } else {
            Brain.Screen.print("Not white."); // No egg detected
        }

        wait(20, msec);
    }

    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1, 1);
    Brain.Screen.print("Capsule is empty!");
    return false; // No egg detected, capsule is empty
}

void moveTopMotor(float angle){
  capsuleTopMotor.resetPosition();
  if (angle < 0){
    capsuleTopMotor.spin(reverse, 5, percent);
    while (capsuleTopMotor.position(degrees) > angle){eStopActivated();}
    capsuleTopMotor.stop(brake);
  } else{
    capsuleTopMotor.spin(forward, 5, percent);
    while(capsuleTopMotor.position(degrees) < angle){eStopActivated();}
    capsuleTopMotor.stop(brake);
  }
}

void moveBottomMotor(float angle){
  capsuleBottomMotor.resetPosition();
  if (angle  < 0){
    capsuleBottomMotor.spin(reverse, 5, percent);
    while (capsuleBottomMotor.position(degrees) > angle){eStopActivated();}
    capsuleBottomMotor.stop(brake);
  } else{
    capsuleBottomMotor.spin(forward, 5, percent);
    while(capsuleBottomMotor.position(degrees) < angle){eStopActivated();}
    capsuleBottomMotor.stop(brake);
  }
}

void dropEgg() {

    moveBottomMotor(-90);
    capsuleTimer.clear();

    while (capsuleTimer.time(seconds) <= CAPSULE_INTERVAL) {eStopActivated();}

    moveBottomMotor(90);
    capsuleTimer.clear();

}
