#include "vex.h"
#include "counter.h"
#include "config.h"

// Function to count the number of eggs
void countEggs(int& eggCount) {
    while (!touchSensor.pressing()) {          // touch LED = "done loading"
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

// Function to check if all eggs have been cracked
bool allEggsCracked(int eggCount) {

    // Logic to determine if all eggs have been cracked
    if (eggCount == 0) {
        return true;
    } else {
        return false;
    }
}