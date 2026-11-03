#include "vex.h"
#include "config.h"

int main() {
    Brain.Screen.print("Testing Modular Workflow");
    
    timer timer1;
    timer1.clear();

    // Spin both motors forward at 25% velocity for 5 seconds
    leftMotor.spin(forward, 25, percent);
    rightMotor.spin(forward, 25, percent);

    while (timer1.time(seconds) < 5) {}
    
    // Stop motors
    leftMotor.stop();
    rightMotor.stop();
    
    Brain.Screen.newLine();
    Brain.Screen.print("Test Complete!");
}