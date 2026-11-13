#include "vex.h"
#include "config.h"
#include "cracker.h"
#include "feeder.h"
#include "capsule.h"

int main() {
    // Initial calibration
    calibrateSensors();
    
    while (!touchSensor.pressing()) {}
    while (touchSensor.pressing()) {}

    robotTimer.clear();

    // open feeder and move capsule at the same time
    moveTopMotor(90);
    openFeeder();
    closeFeeder();
    if (checkCapsuleState()) {

        robotTimer.clear();
        moveTopMotor(-90);

        while (robotTimer.time(seconds) <= ROBOT_INTERVAL*2) {} // waits a full second before starting the cracker motors

        robotTimer.clear();
        crackEgg();

        while (robotTimer.time(seconds) <= ROBOT_INTERVAL*4) {}

        moveBottomMotor(90);
        robotTimer.clear();
    }
    
    Brain.program.stop();

}

