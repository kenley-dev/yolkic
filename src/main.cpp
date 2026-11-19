#include "vex.h"
#include "config.h"
#include "cracker.h"
#include "feeder.h"
#include "capsule.h"
#include "counter.h"

int main() {
    
    while (!Brain.buttonCheck.pressing()) { wait(5, msec); } // Waitting for the user to press the button to start the program
    while (Brain.buttonCheck.pressing()) { wait(5, msec); }

    // Initial calibration
    int eggCount = 0;
    calibrateSensors();
   
    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1, 1);
    Brain.Screen.print("Load all eggs into the capsule and press the button to start cracking!");
    
    countEggs(eggCount);

    while (!touchSensor.pressing()) { wait(5, msec);} // Wait for the touch sensor to be released before starting the main loop
    while (touchSensor.pressing()) { wait(5, msec);}

    touchSensor.on(green);

    while (!eStopActivated() && !allEggsCracked(eggCount)) { // Main loop continues until emergency stop is activated or all eggs are cracked

        // open feeder and move capsule at the same time
        moveTopMotor(90);
        openFeeder();
        closeFeeder();

        if (checkCapsuleState()) {
            moveTopMotor(-90);
            crackEgg();
            eggCount -= 1;
            dropEgg();
        }

    }

    touchSensor.off();
    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1, 1);
    Brain.Screen.print("Program stopped.");
    Brain.programStop();

}

