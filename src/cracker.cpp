#include "vex.h"
#include "cracker.h"

void crackEgg() {
    // Implementation for cracking the egg
    crackerMotor.resetPosition();

    crackerMotor.spin(forward, 100, percent);

    while (crackerMotor.position(degrees) <= 180) {}

    crackerMotor.stop();
    crackerMotor.spin(reverse, 100, percent);

    while (crackerMotor.position(degrees) >= 0) {}

    crackerMotor.stop();

}