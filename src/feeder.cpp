#include "vex.h"
#include "feeder.h"
#include "config.h"

void closeFeeder() {

    feederTimer.clear();

    // quarter of a second time interval for estop to be registered
    while (feederTimer.time(seconds) <= FEEDER_INTERVAL){eStopActivated();} 

    feederMotor.spin(reverse, 15, percent);

    while (feederMotor.position(degrees) >= 0) {eStopActivated();}

    feederMotor.stop(hold);


}

void lowerFeeder(){
    feederMotor.resetPosition();
    feederTimer.clear();

    while (feederTimer.time(seconds) <= FEEDER_INTERVAL) {eStopActivated();}

    feederMotor.spin(forward, 30, percent);

    while(feederMotor.position(degrees) <= 40) {eStopActivated();}

    feederMotor.stop(hold);

}

void jitterFeeder()
{

  feederMotor.spin(forward, 10, percent);

  while(feederMotor.position(degrees) <= 90) {eStopActivated();};

  feederMotor.stop(hold);

  wait(0.1, seconds);

  feederMotor.spin(reverse, 30, percent);

  while(feederMotor.position(degrees) >= 70) {eStopActivated();}

  feederMotor.stop(hold);

}

void releaseEgg() {

  lowerFeeder();

  wait(1, seconds);

  jitterFeeder();

  wait(2, seconds);

  jitterFeeder();

  closeFeeder();

}
