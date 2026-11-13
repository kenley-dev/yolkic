#include "vex.h"
#include "capsule.h"

bool checkCapsuleState() {

    feederSensor.setLight(ledState::on);
    feederTimer.clear();
    
    while (feederTimer.time(seconds) < FEEDER_INTERVAL*5) { // checks for 10 seconds if the capsule is empty or not
        Brain.Screen.clearScreen();
        Brain.Screen.setCursor(1, 1);
        
        if (feederSensor.hue() <= 20 && feederSensor.hue() >= 5) { // checks if the color detected is white (hue value between 5 and 20)
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

// Reset capsule motors (reset to base position)
void resetCapsuleMotors() {
}