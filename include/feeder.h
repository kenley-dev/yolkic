#pragma once
#include "vex.h"

using namespace vex;

// Initialize all sensors, timer, and motors pertaining to the feeder system
timer feederTimer;
motor feederMotor(PORT3, false);
