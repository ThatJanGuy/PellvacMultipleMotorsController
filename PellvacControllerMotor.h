#ifndef PellvacControllerMotor_h
#define PellvacControllerMotor_h
#include "Arduino.h"

class PellvacControllerMotor {
  public:
    PellvacControllerMotor();
    bool setup(int MotorPin);
    bool start();
    bool stop();
  private:
    int _pin;

};

#endif