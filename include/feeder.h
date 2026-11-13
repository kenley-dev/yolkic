#pragma once
#include "vex.h"

using namespace vex;

// Initialize all sensors, timer, and motors pertaining to the feeder system
const double FEEDER_INTERVAL = 0.25;
timer feederTimer;
motor feederMotor(PORT3, true);
optical feederSensor(PORT4);
