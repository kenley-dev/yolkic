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
    Brain.Screen.print("Load all eggs into the capsule and press");
    Brain.Screen.setCursor(2,1);
    Brain.Screen.print("the Touch LED to start cracking!");
    
    countEggs(eggCount); // Returns the number of eggs after the touch sensor is clicked

    touchSensor.on(green);

    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1, 1);
    Brain.Screen.print("Program started. Cracking eggs...");
    Brain.Screen.setCursor(2, 1);
    Brain.Screen.print("Tap the touch LED for an e-stop.");

    while (!allEggsCracked(eggCount)) { // Main loop continues until all eggs are cracked

        moveTopMotor(90);
        openFeeder();
        closeFeeder();

        if (checkCapsuleState()) {
            moveTopMotor(-90);
            crackEgg();
            eggCount -= 1;
            dropEgg();
        } else {
            moveTopMotor(-90);
        }

    }

    stopAllMotors();
    Brain.programStop();

}

