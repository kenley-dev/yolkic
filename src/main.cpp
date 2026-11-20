#include "vex.h"
#include "config.h"
#include "cracker.h"
#include "feeder.h"
#include "capsule.h"
#include "counter.h"

int main() {
    
    while (!Brain.buttonCheck.pressing()) {} // Waitting for the user to press the button to start the program
    while (Brain.buttonCheck.pressing()) {}

    // Initial calibration
    int eggCount = 0;
    calibrateSensors();
  
    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1, 1);
    Brain.Screen.print("Load all eggs into the capsule and press the button to start cracking!");
    countEggs(eggCount);


    while (!touchSensor.pressing()) {} // Wait for the touch sensor to be released before starting the main loop
    while (touchSensor.pressing()) {}

    touchSensor.on(green);

    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1, 1);
    Brain.Screen.print("Program started. Cracking eggs...");

    while (!allEggsCracked(eggCount)) { // Main loop continues until all eggs are cracked
        
        if (eStopActivated()) {endProgram();}
        
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

    endProgram();

}

