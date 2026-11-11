#include "vex.h"
#include "feeder.h"

bool checkCacheEmpty() {
    // Implementation for checking if the cache is empty
    return false;
}


void closeFeeder() {
    // Implementation for closing the feeder
    feederMotor.resetRotation();
    feederTimer.clear();

    while (feederTimer.time(seconds) <= 1){} // waits one seconds before starting the feeder motor

    feederMotor.spin(reverse, 25 percent);

    while (feederMotor.rotation(degrees) >= -90) {}

    feederMotor.stop(brake);


}

void openFeeder() {
    // Implementation for opening the feeder
    feederMotor.resetRotation();
    feederTimer.clear();

    while (feederTimer.time(seconds) <= 1){} // waits one seconds before starting the feeder motor
    
    feederMotor.spin(forward, 25 percent);

    while (feederMotor.rotation(degrees) <= 90) {}

    feederMotor.stop(brake);

}

