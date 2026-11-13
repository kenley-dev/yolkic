#pragma once
#include "vex.h"

using namespace vex;

// Initialize the brain, motors, and sensors necessary for toggling the robot on and off

touchled touchSensor(PORT5);
timer robotTimer;
