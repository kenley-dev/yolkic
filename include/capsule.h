#pragma once
#include "vex.h"

using namespace vex;

// Initialize all sensors and motors pertaining to the capsule system
const double CAPSULE_INTERVAL = 0.25;

timer capsuleTimer;
motor capsuleTopMotor(PORT1, false);
motor capsuleBottomMotor(PORT2, true);