#include "vex.h"
#include "feeder.h"


void closeFeeder() {
    // Implementation for closing the feeder
    feederMotor.resetPosition();
    feederTimer.clear();

    while (feederTimer.time(seconds) <= FEEDER_INTERVAL){} // waits one seconds before starting the feeder motor

    feederMotor.spin(reverse, 25, percent);

    while (feederMotor.position(degrees) >= -90) {}

    feederMotor.stop(brake);


}

void openFeeder() {
    // Implementation for opening the feeder
    feederMotor.resetPosition();
    feederTimer.clear();

    while (feederTimer.time(seconds) <= FEEDER_INTERVAL) {} // waits one seconds before starting the feeder motor
    
    feederMotor.spin(forward, 25, percent);

    while (feederMotor.position(degrees) <= 105) {}

    feederMotor.stop(brake);

}
