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
    openFeeder();
    moveTopMotor(90);
    closeFeeder();
    if (checkCapsuleState()) {
        prepareCapsule();
    }
    
    

}

