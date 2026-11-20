#include "vex.h"
#include "config.h"

// Function to calibrate all sensors and motors
void calibrateSensors() {
    // Implementation for sensor calibration
    touchSensor.on(red);
    BrainInertial.resetRotation();
}

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

bool eStopActivated() {
    if (touchSensor.pressing()) {
        stopAllMotors();
        touchSensor.on(red);
        Brain.Screen.clearScreen();
        Brain.Screen.setCursor(1, 1);
        Brain.Screen.print("Emergency Stop Activated!");
        Brain.programStop();  // ends the program right here, from inside any loop
        return true;
    }
    return false;
}

