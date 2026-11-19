#include "vex.h"
#include "config.h"

// Function to calibrate all sensors and motors
void calibrateSensors() {
    // Implementation for sensor calibration
    touchSensor.on(red);
    BrainInertial.resetRotation();
}

bool eStopActivated() {
    if (!touchSensor.pressing()) {
        while (touchSensor.pressing()) { wait(5, msec); } // wait for release

        Brain.Screen.clearScreen();
        Brain.Screen.setCursor(1, 1);
        Brain.Screen.print("Emergency Stop Activated!");
        return true;
    }

    return false;
}

