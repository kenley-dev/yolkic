#include "vex.h"
#include "counter.h"
#include "feeder.h"
#include "config.h"

// Versitle function that takes a variable as a reference and tracks the number of eggs placed into the feeder
void countEggs(int& eggCount) {

    while (!touchSensor.pressing()) {
        
        feederMotor.stop(hold); // Hold the feeder motor in place before eggs are being loaded

        if (counterBumper.pressing()) {
            eggCount++;

            while (counterBumper.pressing()) { wait(10, msec); }

            Brain.Screen.clearScreen();
            Brain.Screen.setCursor(1, 1);
            Brain.Screen.print("Eggs counted: %d", eggCount);
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