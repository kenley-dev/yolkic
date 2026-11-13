#include "vex.h"
#include "cracker.h"

void crackEggKen() {
    // Implementation for cracking the egg
    crackerMotor.resetPosition();

    crackerMotor.spin(forward, 100, percent);

    while (crackerMotor.position(degrees) <= 180) {}

    crackerMotor.stop();
    crackerMotor.spin(reverse, 100, percent);

    while (crackerMotor.position(degrees) >= 0) {}

    crackerMotor.stop();

}

void crackEggSeb(){

crackerMotor.resetPosition();
crackerMotor.spin(forward, 100, degrees);

while (crackerMotor.position(degrees) < 200){}

crackerMotor.stop(brake);

float movedDistance = crackerMotor.position(degrees);
float distanceNeeded = 360 - movedDistance;

crackerMotor.spin(forward, 25, percent);

while (crackerMotor.position(degrees) < distanceNeeded){}

crackerMotor.stop(brake);
}
