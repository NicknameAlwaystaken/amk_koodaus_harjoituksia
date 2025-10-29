#include "aliohjelmat.h" // vaihdettiin tänne uusi nimi

int aliohjelma(int eka, int toka, char kolmas)
{
  // This subroutine should be able to do +, -, * and / operations
  int tulos = 0;
  if (kolmas == '+') {
    tulos = eka + toka;
  }
  else if (kolmas == '-') {
    tulos = eka - toka;
  }
  else if (kolmas == '*') {
    tulos = eka * toka;
  }
  else if (kolmas == '/') {
    tulos = eka / toka;
  }
  return tulos;
}
