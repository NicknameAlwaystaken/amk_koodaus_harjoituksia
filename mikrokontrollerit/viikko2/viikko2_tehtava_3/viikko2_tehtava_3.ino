#include "aliohjelma.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  struct digitaaliPinnit pinnit;
  int pinnit_ptr[4];

  pinnit = selvitaPinnienTilat1(); 
  selvitaPinnienTilat2(pinnit_ptr);

  for(int i = 0; i < 4; i++) {
    Serial.print("Pinni ptr ");Serial.print(i);Serial.print(": ");Serial.println(pinnit_ptr[i]);
  }

  Serial.println("\n");
  Serial.print("Pinni struct 2: ");Serial.println(pinnit.pin2);
  Serial.print("Pinni struct 3: ");Serial.println(pinnit.pin3);
  Serial.print("Pinni struct 4: ");Serial.println(pinnit.pin4);
  Serial.print("Pinni struct 5: ");Serial.println(pinnit.pin5);

  delay(500);
}
