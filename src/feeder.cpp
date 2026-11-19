#include "vex.h"
#include "feeder.h"

// try differnet brake styles for the feeder motor to see if it helps with the feeder motor not stopping at the right position
void closeFeeder() {
    // Implementation for closing the feeder
    feederMotor.resetPosition();
    feederTimer.clear();

    while (feederTimer.time(seconds) <= FEEDER_INTERVAL){} // waits one seconds before starting the feeder motor

    feederMotor.spin(reverse, 15, percent);

    while (feederMotor.position(degrees) >= -95) {}

    feederMotor.stop(brake);


}

void openFeeder() {
    // Implementation for opening the feeder
    feederMotor.resetPosition();
    feederTimer.clear();

    while (feederTimer.time(seconds) <= FEEDER_INTERVAL) {} // waits one seconds before starting the feeder motor
    
    feederMotor.spin(forward, 15, percent);

    while (feederMotor.position(degrees) <= 95) {}

    feederMotor.stop(brake);

}
