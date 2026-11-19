#include "vex.h"
#include "config.h"

// Function to calibrate all sensors and motors
void calibrateSensors() {
    // Implementation for sensor calibration
    touchSensor.on(blue);
    BrainInertial.resetRotation();
}

bool eStopActivated() {
    // Implementation for checking if the emergency stop is activated

    robotTimer.clear();

    while (robotTimer.time(seconds) < ROBOT_INTERVAL/5) { // checks for 0.1 second if the emergency stop is activated

        while (!touchSensor.pressing()) {}
        while (touchSensor.pressing()) {}
            
        Brain.Screen.clearScreen();
        Brain.Screen.setCursor(1, 1);
        Brain.Screen.print("Emergency Stop Activated!");
        return true;
        
    }

    return false;
}

