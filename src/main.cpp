#include "vex.h"
#include "config.h"
#include "cracker.h"
#include "feeder.h"
#include "capsule.h"

int main() {
    // Initial calibration
    calibrateSensors();
    robotTimer.clear();
    
    while (!touchSensor.pressing()) {}
    while (touchSensor.pressing()) {}

    // open feeder and move capsule at the same time
    moveTopMotor(90);
    openFeeder();
    closeFeeder();
    if (checkCapsuleState()) {
        prepareCapsule();
    }

    while (robotTimer.time(seconds) < ROBOT_INTERVAL*30) {}

    Brain.programStop();

}

