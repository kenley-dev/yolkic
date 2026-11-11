#pragma once
#include "vex.h"

using namespace vex;

// Initialize the brain, motors, and sensors necessary for toggling the robot on and off

brain Brain;
inertial BrainInertial();
touch touchSensor(PORT4);
timer robotTimer;
