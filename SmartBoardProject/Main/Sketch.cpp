#include <Arduino.h>
#include <Servo.h>
#include <Stepper.h>
#include "include/PenHandler.hpp"

void setup() {
  drawing::PenHandler penHandler;
  penHandler.penDown();
  delay(2000);
  penHandler.up();
}

void loop() {
  
}
