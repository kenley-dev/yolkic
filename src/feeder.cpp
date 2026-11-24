#include "vex.h"
#include "feeder.h"
#include "config.h"

void openFeeder() {

    feederTimer.clear();
    while (feederTimer.time(seconds) <= FEEDER_INTERVAL) { eStopActivated(); }

    // fast approach
    feederMotor.spin(forward, 15, percent);
    while (feederMotor.position(degrees) <= 15) { eStopActivated(); }

    // slow creep to the target to reduce overshoot
    feederMotor.spin(forward, 8, percent);
    while (feederMotor.position(degrees) <= 30) { eStopActivated(); }

    feederMotor.stop(hold);

}

// A function to close the feeder
void closeFeeder() {

    feederTimer.clear();
    while (feederTimer.time(seconds) <= FEEDER_INTERVAL) { eStopActivated(); }

    // fast approach
    feederMotor.spin(reverse, 15, percent);
    while (feederMotor.position(degrees) >= 15) { eStopActivated(); }

    // slow creep to the target to reduce overshoot
    feederMotor.spin(reverse, 8, percent);
    while (feederMotor.position(degrees) >= 0) { eStopActivated(); }

    feederMotor.stop(hold);

}

// A function to jitter the feeder platform so as to release only one egg
void jitterFeeder() {

    // go up to 55 degrees
    feederMotor.spin(forward, 10, percent);
    while (feederMotor.position(degrees) <= 55) { eStopActivated(); }

    feederMotor.stop(brake);

    wait(0.1, seconds);

    // fast return toward 45
    feederMotor.spin(reverse, 30, percent);
    while (feederMotor.position(degrees) >= 45) { eStopActivated(); }

    // slow creep to the target to reduce overshoot
    feederMotor.spin(reverse, 8, percent);
    while (feederMotor.position(degrees) >= 35) { eStopActivated(); }

    feederMotor.stop(hold);

}

// A function that automates the release of a singular egg
void releaseEgg() {

    openFeeder();

    wait(1.5, seconds);

    jitterFeeder();

    closeFeeder();

}