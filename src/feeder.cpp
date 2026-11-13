#include "vex.h"
#include "feeder.h"


void closeFeeder() {
    // Implementation for closing the feeder
    feederMotor.resetPosition();
    feederTimer.clear();

    while (feederTimer.time(seconds) <= FEEDER_INTERVAL){} // waits one seconds before starting the feeder motor

    feederMotor.spin(reverse, 25, percent);

    while (feederMotor.position(degrees) >= -100) {}

    feederMotor.stop(brake);


}

void openFeeder() {
    // Implementation for opening the feeder
    feederMotor.resetPosition();
    feederTimer.clear();

    while (feederTimer.time(seconds) <= FEEDER_INTERVAL) {} // waits one seconds before starting the feeder motor
    
    feederMotor.spin(forward, 25, percent);

    while (feederMotor.position(degrees) <= 100) {}

    feederMotor.stop(brake);

}

void prepareCapsule() {

    moveTopMotor(-90);

    while (capsuleTimer.time(seconds) <= CAPSULE_INTERVAL*20) {} // waits a quarter of a seconds before starting the cracker motors

    moveBottomMotor(-90);
    capsuleTimer.clear();

    while (capsuleTimer.time(seconds) <= CAPSULE_INTERVAL) {}

    moveBottomMotor(90);
    capsuleTimer.clear();

}
