#include <Arduino.h>
#include "aliohjelma.h"

digitaaliPinnit selvitaPinnienTilat1() {
  return digitaaliPinnit {
    digitalRead(2),
    digitalRead(3),
    digitalRead(4),
    digitalRead(5),
  };
};

void selvitaPinnienTilat2(int *digitaaliPinnit) {
  digitaaliPinnit[0] = digitalRead(2);
  digitaaliPinnit[1] = digitalRead(3);
  digitaaliPinnit[2] = digitalRead(4);
  digitaaliPinnit[3] = digitalRead(5);
}