#pragma once
#include "vex.h"

using namespace vex;

// Initialize the brain, motors, and sensors necessary for toggling the robot on and off

brain Brain;
motor leftMotor = motor(PORT1, false);
motor rightMotor = motor(PORT6, true);
touch TouchSensor = touch(PORT3);
