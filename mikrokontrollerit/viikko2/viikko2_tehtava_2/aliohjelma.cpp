#include <Arduino.h>
#include "aliohjelma.h"

float analogCompare(int analog_pin) {
  int reference_pin = A0;
  
  float reference_voltage = analogRead(reference_pin) / 1023.0 * 5.0;

  float compare_voltage;

  switch(analog_pin) {
    case 1: {
      compare_voltage = analogRead(A1) / 1023.0 * 5.0;
      break;
    }
    case 2: {
      compare_voltage = analogRead(A2) / 1023.0 * 5.0;
      break;
    }
    case 3: {
      compare_voltage = analogRead(A3) / 1023.0 * 5.0;
      break;
    }
    case 4: {
      compare_voltage = analogRead(A4) / 1023.0 * 5.0;
      break;
    }
    case 5: {
      compare_voltage = analogRead(A5) / 1023.0 * 5.0;
      break;
    }
    default: {
      compare_voltage = 0.0;
      break;
    }
  }

  return reference_voltage - compare_voltage;
}