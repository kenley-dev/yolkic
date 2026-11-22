#include "vex.h"
#include "config.h"

// Function to calibrate all sensors needed for start-up or shut-down
void calibrateSensors() {
    touchSensor.on(red);
    BrainInertial.resetRotation();
}

// Function to shut-dwon all motors and sensors
void stopAllMotors() {
    touchSensor.off();
    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1, 1);
    Brain.Screen.print("Motors stopped.");
    capsuleTopMotor.stop(brake);
    capsuleBottomMotor.stop(brake);
    feederMotor.stop(brake);
    crackerMotor.stop(brake);
}

// Boolean function used to check if the e-stop button has been pressed to initate a shut-down procedure
bool eStopActivated() {

    if (touchSensor.pressing()) {
        stopAllMotors();
        touchSensor.on(red);
        Brain.Screen.clearScreen();
        Brain.Screen.setCursor(1, 1);
        Brain.Screen.print("Emergency Stop Activated!");
        Brain.programStop();
        return true;
    }

    return false;
}

