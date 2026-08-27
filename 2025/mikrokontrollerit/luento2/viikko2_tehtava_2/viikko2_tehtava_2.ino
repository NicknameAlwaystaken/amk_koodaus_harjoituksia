#include "aliohjelma.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Pin 1: ");Serial.println(analogCompare(1));
  //Serial.print("Pin 2: ");Serial.println(analogCompare(2));
  //Serial.print("Pin 3: ");Serial.println(analogCompare(3));
  //Serial.print("Pin 4: ");Serial.println(analogCompare(4));
  //Serial.print("Pin 5: ");Serial.println(analogCompare(5));
  
  delay(1000);
}
