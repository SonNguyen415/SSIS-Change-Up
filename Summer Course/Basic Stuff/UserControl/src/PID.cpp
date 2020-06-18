#include "vex.h"

motor_group Left = motor_group(L1, L2);
motor_group Right = motor_group(R1, R2);

using namespace vex;


double constrain(double inputValue, double max, double min) {
  if(inputValue >= max) {
    return max;
  }
  if(inputValue <= min) {
    return min;
  }
  return inputValue;
}

void move(double lSetPoint, double rSetPoint, double maxVelocity) {
  double kP = 2.5;
  double TOLERANCE = 10;
  
  while(1) {
    double lRotation = Left.rotation(deg);
    double rRotation = Right.rotation(deg);

    double lError = lSetPoint - lRotation;
    double rError = rSetPoint - rRotation;

    double lVelocity = lError / kP;
    double rVelocity = rError / kP;

    lVelocity = constrain(lVelocity, maxVelocity, -maxVelocity);
    rVelocity = constrain(rVelocity, maxVelocity, -maxVelocity);

    Left.spin(forward, lVelocity, pct);
    Right.spin(forward, rVelocity, pct);

    if (lError > -TOLERANCE && lError < TOLERANCE && rError > -TOLERANCE && rError < TOLERANCE) {
      Left.stop(coast);
      Right.stop(coast);
      return;
    }
  }
}


