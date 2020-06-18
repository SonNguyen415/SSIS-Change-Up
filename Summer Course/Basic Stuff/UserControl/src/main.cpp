/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       imperium                                                  */
/*    Created:      Thu Jun 18 2020                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// L1                   motor         1               
// L2                   motor         2               
// R1                   motor         3               
// R2                   motor         4               
// Lift                 motor         5               
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

motor_group Left = motor_group(L1, L2);
motor_group Right = motor_group(R1, R2);

using namespace vex;

const double LIFT_VELOCITY = 50;

void raiseLift() {
  Lift.spin(forward, LIFT_VELOCITY, pct);
}
  
void lowerLift() {
  Lift.spin(reverse, LIFT_VELOCITY, pct);
}


int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  Controller1.ButtonR1.pressed(raiseLift);
  Controller1.ButtonR2.pressed(lowerLift);

  while(1) {
    double leftAxis = Controller1.Axis3.value();
    double rightAxis = Controller1.Axis2.value();

    Left.spin(forward, leftAxis, pct);
    Right.spin(forward, rightAxis, pct);
  } 

}
