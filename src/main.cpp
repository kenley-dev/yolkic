#include "vex.h"
#include "config.h"
#include "conveyor.h"
#include "cracker.h"
#include "feeder.h"

int main() {
    // Initial calibration
    calibrateSensors();
    robotTimer.clear();
    double interval = 0.25; // Interval in seconds for each motor movement

    while (robotTimer.time(seconds) <= interval) {} // waits 1 seconds before starting the cracker motors

    moveTopMotor(90); 
    robotTimer.clear();

    while (robotTimer.time(seconds) <= interval) {}

    moveTopMotor(-90);
    robotTimer.clear();

    while (robotTimer.time(seconds) <= interval) {}

    moveBottomMotor(-90);
    robotTimer.clear();

    while (robotTimer.time(seconds) <= interval) {}

    moveBottomMotor(90);
    robotTimer.clear();
}

