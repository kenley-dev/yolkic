#include "vex.h"
#include "capsule.h"
#include "config.h"

bool checkCapsuleState() {

    capsuleOptical.setLight(ledState::on); // ensures we can detect white
    capsuleTimer.clear();
    
    while (capsuleTimer.time(seconds) < CAPSULE_INTERVAL*8) { // checks for 2 seconds if the capsule is empty or not
        Brain.Screen.clearScreen();
        Brain.Screen.setCursor(1, 1);
        
        wait(1, seconds);

        // Checks for a white egg with a hue range of 10 to 25
        if (capsuleOptical.hue() >= 10 && capsuleOptical.hue() <= 25) { 
            Brain.Screen.print("Object detected!");
            return true;

        } else {
            Brain.Screen.print("Not a white egg");
        }

        wait(20, msec);
    }

    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1, 1);
    Brain.Screen.print("Capsule is empty!");
    return false;
}

// Versitile function that takes an angle as a parameter and moves the top capsule motor accordingly
void moveTopCapsuleMotor(float angle) {
  capsuleTopMotor.resetPosition();

  if (angle < 0) {

    capsuleTopMotor.spin(reverse, 5, percent);

    while (capsuleTopMotor.position(degrees) > angle){eStopActivated();}

    capsuleTopMotor.stop(hold);
    capsuleBottomMotor.stop(hold); // holds the position of the bottom capsule motor so that heavy eggs don't spin it

  } else {

    capsuleTopMotor.spin(forward, 5, percent);

    while(capsuleTopMotor.position(degrees) < angle){eStopActivated();}

    capsuleTopMotor.stop(hold);
    capsuleBottomMotor.stop(hold); // holds the position of the bottom capsule motor so that heavy eggs don't spin it

  }
}

// Versitile function that takes an angle as a parameter and moves the top capsule motor accordingly
void moveBottomCapsuleMotor(float angle) {
  capsuleBottomMotor.resetPosition();

  if (angle  < 0) {

    capsuleBottomMotor.spin(reverse, 5, percent);

    while (capsuleBottomMotor.position(degrees) > angle){eStopActivated();}

    capsuleBottomMotor.stop(hold);

  } else {

    capsuleBottomMotor.spin(forward, 5, percent);

    while(capsuleBottomMotor.position(degrees) < angle){eStopActivated();}

    capsuleBottomMotor.stop(hold);

  }
}

// Function that uses the previous helper functions to automate the egg-empting process
void emptyContents() {

    moveBottomCapsuleMotor(-90);
    capsuleTimer.clear();

    while (capsuleTimer.time(seconds) <= CAPSULE_INTERVAL) {eStopActivated();}

    moveBottomCapsuleMotor(90);
    capsuleTimer.clear();

}
