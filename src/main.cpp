#include "vex.h"
#include "config.h"
#include "conveyor.h"
#include "cracker.h"
#include "feeder.h"

int main() {
    // Initial calibration
    calibrateSensors();

    // Turn robot on from a touch sensor click
    while (!TouchSensor.pressing()) {}
    while (TouchSensor.pressing()) {}

    turnRobotOn();

    while (turnRobotOn()) {
        // Check if cache is empty before starting a new cycle
        if (checkCacheEmpty()) {
            return 0;
        }

        // Step 1: Release Egg
        releaseEgg();

        // Step 2: Conveyor moves forward to the appropriate distance
        advanceEgg();

        //Step 3: Cracking function (feeds, clamps, cracks, and empties)
        feedEgg();
        clampEgg();
        crackEgg();
        emptyEgg();
    }
}

