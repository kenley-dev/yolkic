#include "vex.h"
#include "counter.h"
#include "feeder.h"
#include "config.h"

// Tracks the number of eggs placed into the feeder, passed in by reference
void countEggs(int& eggCount) {

    feederMotor.stop(hold); // Hold the feeder motor in place before eggs are being loaded

    while (!touchSensor.pressing()) {

        if (counterBumper.pressing()) {
            wait(20, msec);               // debounce the press: let the contact settle

            if (counterBumper.pressing()) { // still pressed, so it was a real click
                eggCount++;

                // Wait for a clean release: bumper must stay released for 30 ms
                int releasedTime = 0;
                while (releasedTime < 30) {
                    if (counterBumper.pressing()) {
                        releasedTime = 0;
                    } else {
                        releasedTime += 10;
                    }
                    wait(10, msec);
                }

                Brain.Screen.clearScreen();
                Brain.Screen.setCursor(1, 1);
                Brain.Screen.print("Eggs counted: %d", eggCount);
            }
        }

        wait(10, msec);
    }

    while (touchSensor.pressing()) { wait(10, msec); }   // wait for release
}

// Boolean function that checks if all the eggs have been cracked, used as a terminating condition
bool allEggsCracked(int eggCount) {

    if (eggCount == 0) {
        return true;
    } else {
        return false;
    }

}