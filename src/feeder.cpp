#include "vex.h"
#include "feeder.h"
#include "config.h"

// A function to close the feeder
void closeFeeder() {

    feederMotor.resetPosition();
    feederTimer.clear();

    // quarter of a second time interval for estop to be registered
    while (feederTimer.time(seconds) <= FEEDER_INTERVAL){eStopActivated();} 

    feederMotor.spin(reverse, 15, percent);

    while (feederMotor.position(degrees) >= -70) {eStopActivated();}

    feederMotor.stop(hold);

}

// A function to open the feeder 80 degrees
void openFeeder() {

    feederMotor.resetPosition();
    feederTimer.clear();

    while (feederTimer.time(seconds) <= FEEDER_INTERVAL) {eStopActivated();}

    feederMotor.spin(forward, 50, percent);

    while(feederMotor.position(degrees) <= 80) {eStopActivated();}

    feederMotor.stop(hold);

}

// A function to jitter the feeder platform so as to release only one egg
void jitterFeeder() {

    feederMotor.spin(forward, 10, percent);

    while(feederMotor.position(degrees) <= 90) {eStopActivated();};

    feederMotor.stop(hold);

    wait(0.1, seconds);

    feederMotor.spin(reverse, 30, percent);

    while(feederMotor.position(degrees) >= 70) {eStopActivated();}

    feederMotor.stop(hold);

}

// A function that automates the release of a singular egg
void releaseEgg() {

  openFeeder();

  wait(1, seconds);

  jitterFeeder();

  closeFeeder();

}
