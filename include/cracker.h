#pragma once
#include "vex.h"

using namespace vex;

// Initialize all sensors and motors pertaining to the cracker system
motor crackerTopMotor(PORT1, false);
motor crackerBottomMotor(PORT2, true);