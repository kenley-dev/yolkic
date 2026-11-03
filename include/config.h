#pragma once
#include "vex.h"

using namespace vex;

// Initialize the brain, motors, and sensors

brain Brain;
motor leftMotor = motor(PORT1, false);
motor rightMotor = motor(PORT6, true);
