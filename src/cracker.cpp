#include "vex.h"
#include "cracker.h"
#include "config.h"

// A function that automates teh egg-cracking process
void crackEgg() {

    crackerMotor.resetPosition();

    crackerMotor.spin(forward, 100, percent);

    while (crackerMotor.position(degrees) <= 180) {eStopActivated();}

    crackerMotor.stop();
    crackerMotor.spin(reverse, 15, percent);

    while (crackerMotor.position(degrees) >= 0) {eStopActivated();}

    crackerMotor.stop();

}