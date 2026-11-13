#pragma once
#include "vex.h"

using namespace vex;

// Initialize the brain, motors, and sensors necessary for toggling the robot on and off

const double ROBOT_INTERVAL = 0.5; // Time interval for robot operations in seconds

touchled touchSensor(PORT5);
timer robotTimer;

