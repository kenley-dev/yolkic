#include "vex.h"
#include "config.h"
#include "cracker.h"
#include "feeder.h"
#include "capsule.h"
#include "counter.h"

int main() {
    
    // Waitting for the user to click the brain check button before starting the program
    while (!Brain.buttonCheck.pressing()) {}
    while (Brain.buttonCheck.pressing()) {}

    // Initial calibration of sensors and an egg coutning variable
    int eggCount = 0;
    calibrateSensors();
    
    // Prompts the user to start loading eggs and to tap the touch led to start the cracking process
    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1, 1);
    Brain.Screen.print("Load all eggs into the capsule and press");
    Brain.Screen.setCursor(2,1);
    Brain.Screen.print("the Touch LED to start cracking!");
    
    // Tracks the number of eggs placed into the feeder, the program will not proceed
    // further until the user has finsihed loading eggs and tapped the touch led
    countEggs(eggCount);

    // Informs the user that they have finished loading their eggs and that the cracking will begin
    touchSensor.on(green);
    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1, 1);
    Brain.Screen.print("Program started. Cracking eggs...");

    // Informs user that the touch led can be tapped to stop teh prgram at any time
    Brain.Screen.setCursor(2, 1);
    Brain.Screen.print("Tap the touch LED for an e-stop.");

    // Main loop continues until all eggs are cracked
    while (!allEggsCracked(eggCount)) {
        
        // opens the egg capsule
        moveTopCapsuleMotor(75);

        // releases one egg from the feeder
        releaseEgg();

        // checks if an egg has been properly placed in the capsule
        if (checkCapsuleState()) {
            // if it has, the capsule closes to securly hold the egg in place
            moveTopCapsuleMotor(-75);

            // the egg is cracked
            crackEgg();

            // the egg count decreases by one, and the status of eggs left is printed for the user convience
            eggCount -= 1;
            Brain.Screen.clearScreen();
            Brain.Screen.setCursor(1, 1);
            Brain.Screen.print("Eggs left: %d", eggCount);

            // lastly, the contents of the egg are emptied through a filter and into a bowl
            emptyContents();

        } else {
            // otherwise, reset the position of the capsule to prepare for the next egg
            moveTopCapsuleMotor(-75);

            // even in failure, the egg count decreases by one, and the status of eggs left is printed
            eggCount -= 1;
            Brain.Screen.clearScreen();
            Brain.Screen.setCursor(1, 1);
            Brain.Screen.print("Eggs left: %d", eggCount);
        }

    }

    // once all eggs have been cracked, all motors will stop and the program will be terminated
    stopAllMotors();
    Brain.programStop();

}

