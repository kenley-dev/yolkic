#include "vex.h"
#include "feeder.h"

bool checkCapsuleState() {

    feederSensor.setLight(ledState::on);
    feederTimer.clear();
    
    while (feederTimer.time(seconds) < FEEDER_INTERVAL) { // checks for 2 seconds if the capsule is empty or not
        Brain.Screen.clearScreen();
        Brain.Screen.setCursor(1, 1);
        
        if (feederSensor.color() == white) {
            Brain.Screen.print("Object detected!");
            return true; // Egg detected, capsule is not empty

        } else {
            Brain.Screen.print("Not white."); // No egg detected
        }

        wait(20, msec);
    }

    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1, 1);
    Brain.Screen.print("Capsule is empty!");
    return false; // No egg detected, capsule is empty
}


void closeFeeder() {
    // Implementation for closing the feeder
    feederMotor.resetPosition();
    feederTimer.clear();

    while (feederTimer.time(seconds) <= FEEDER_INTERVAL){} // waits one seconds before starting the feeder motor

    feederMotor.spin(reverse, 25 percent);

    while (feederMotor.position(degrees) >= -90) {}

    feederMotor.stop(brake);


}

void openFeeder() {
    // Implementation for opening the feeder
    feederMotor.resetPosition();
    feederTimer.clear();

    while (feederTimer.time(seconds) <= FEEDER_INTERVAL) {} // waits one seconds before starting the feeder motor
    
    feederMotor.spin(forward, 25 percent);

    while (feederMotor.position(degrees) <= 90) {}

    feederMotor.stop(brake);

}
