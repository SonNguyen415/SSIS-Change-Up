/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       imperium                                                  */
/*    Created:      Sun Jun 14 2020                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Motor1               motor         1               
// Motor2               motor         2               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

//Forming motor groups
motor_group Motor = motor_group(Motor1, Motor2);

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  //Spin motor infinitely at 50 percent
  Motor.spin(forward, 50, percent);

  //Stop motor: brake, hold (active stopping), or coast (allow wheels to move)
  Motor.stop(hold);

  //Motor rotate []
  
}
