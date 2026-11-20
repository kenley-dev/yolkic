#include "vex.h"
#include "cracker.h"
#include "config.h"

void crackEgg() {
    // Implementation for cracking the egg
    crackerMotor.resetPosition();

    crackerMotor.spin(forward, 100, percent);

    while (crackerMotor.position(degrees) <= 190) {eStopActivated();}

    crackerMotor.stop();
    crackerMotor.spin(reverse, 15, percent);

    while (crackerMotor.position(degrees) >= 0) {eStopActivated();}

    crackerMotor.stop();

}