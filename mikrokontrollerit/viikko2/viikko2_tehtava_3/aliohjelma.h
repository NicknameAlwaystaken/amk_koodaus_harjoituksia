#ifndef ALIOHJELMA_H
#define ALIOHJELMA_H

struct digitaaliPinnit
{
  byte pin2;
  byte pin3;
  byte pin4;
  byte pin5;
};

digitaaliPinnit selvitaPinnienTilat1(); 
void selvitaPinnienTilat2(int *);

#endif