#include "vex.h"
#include "config.h"
#include "conveyor.h"
#include "cracker.h"
#include "feeder.h"

int main() {
    // Initial calibration
    calibrateSensors();
    robotTimer.clear();

    while (robotTimer.time(seconds) <= 1) {} // waits 1 seconds before starting the cracker motors

    moveTopMotor(90); 
    robotTimer.clear();

    while (robotTimer.time(seconds) <= 1) {}

    moveTopMotor(-90);
    robotTimer.clear();

    while (robotTimer.time(seconds) <= 1) {}

    moveBottomMotor(-90);
    robotTimer.clear();

    while (robotTimer.time(seconds) <= 1) {}

    moveBottomMotor(90);
    robotTimer.clear();
}

