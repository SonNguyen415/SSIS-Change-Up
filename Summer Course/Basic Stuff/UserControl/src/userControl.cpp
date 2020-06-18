#include "vex.h"

using namespace vex;

motor_group Left = motor_group(L1, L2);
motor_group Right = motor_group(R1, R2);


double LIFT_VELOCITY = 50;

void raiseLift() {
  Lift.spin(forward, LIFT_VELOCITY, pct);
}

void lowerLift() {
  Lift.spin(reverse, LIFT_VELOCITY, pct);
}

void stopLift() {
  Lift.stop(hold);
}

void goToTower() {
  Lift.spinToPosition(500, rotationUnits::deg, 50, velocityUnits::pct);
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  Controller1.ButtonR1.pressed(raiseLift);
  Controller1.ButtonR2.pressed(lowerLift);
  Controller1.ButtonR1.released(stopLift);
  Controller1.ButtonR2.released(stopLift);

  Controller1.ButtonA.pressed(goToTower);
 
  while(1) {

    double LeftAxis = Controller1.Axis3.value();
    double RightAxis = Controller1.Axis2.value();
    
    Left.spin(forward, LeftAxis, pct);
    Right.spin(forward, RightAxis, pct);
  }
  
}
