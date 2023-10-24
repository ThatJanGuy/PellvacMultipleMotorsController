#include "Arduino.h"
#include "PellvacControllerMotor.h"

PellvacControllerMotor::PellvacControllerMotor(){
  //Empty constructor for better instantiation control.
  Serial.println("PellvacControllerMotor object instantiated.");
}

bool PellvacControllerMotor::setup(int MotorPin){
  //Setting the private variables and setting up the sensorPin
  _pin = MotorPin;
  Serial.print("Motor pin is set to ");
  Serial.print(_pin, DEC);
  Serial.println(".");

  pinMode(_pin, OUTPUT);
  Serial.println("Motor pin set to OUTPUT mode.");
  
  stop();
  return true;
}

bool PellvacControllerMotor::start(){
  digitalWrite(_pin, HIGH);
  Serial.println("Motor start signal sent.");

  return true;
}

bool PellvacControllerMotor::stop(){
  digitalWrite(_pin, LOW);
  Serial.println("Motor stop signal sent.");
  
  return true;
}