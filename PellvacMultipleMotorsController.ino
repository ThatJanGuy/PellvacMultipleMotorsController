// Include libraries
#include "PellvacControllerMotor.h"

// CONFIG! Change these values
// List the motor pins in the order you want them to start.
int motorPins[] = {11, 6}; 
// Change the value to the time im ms you want to wait between motor starts.
#define motorDelay 1500
#define SerialSpeed 31250

// Hands OFF!
const int numberOfMotors = sizeof(motorPins) / sizeof(motorPins[0]);
PellvacControllerMotor motors[numberOfMotors];


void setup() {
  Serial.begin(SerialSpeed);
  while (!Serial) {};
  Serial.print("Serial communication started with a baud rate of ");
  Serial.print(SerialSpeed, DEC);
  Serial.println(".");

  Serial.println("####################################");
  Serial.println("Starting setup.");
  Serial.println();

  for (int pin : motorPins){
    static int position = 0;
    motors[position] = PellvacControllerMotor();
    motors[position].setup(pin);
    position++;
  }

}

void loop() {
  

  for (PellvacControllerMotor motor : motors){
    static int motorNumber = 1;
    Serial.print("Motor ");
    Serial.print(motorNumber, DEC);
    Serial.println(":");
    motor.start();
    delay(motorDelay);
    motorNumber++;
  }

  Serial.println("All start signals sent. Please check the motors.");

  while(true) {};

}
