#include "vex.h"
#include "counter.h"

// Function to count the number of eggs (FAULTY, PLEASE REWRITE)
void countEggs(int& eggCount) {

    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1, 1);
    Brain.Screen.print("Eggs counted: %d", eggCount);

    // Keep counting until the touch LED is pressed
    while (!touchSensor.pressing()) {

        if (counterBumper.pressing()) {
            eggCount++;

            while (counterBumper.pressing()) { wait(5, msec); } // wait for release
            wait(20, msec); // debounce

            Brain.Screen.clearScreen();
            Brain.Screen.setCursor(1, 1);
            Brain.Screen.print("Eggs counted: %d", eggCount);
        }

        wait(5, msec);
    }

    while (touchSensor.pressing()) { wait(5, msec); } // wait for release
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