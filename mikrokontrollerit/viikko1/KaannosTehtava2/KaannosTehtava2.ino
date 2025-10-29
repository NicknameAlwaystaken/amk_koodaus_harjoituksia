#include "aliohjelmat.h" // vaihdoin uuteen nimeen

void setup() {
  Serial.begin(BAUDINOPEUS);
  Serial.setTimeout(100000); // Annetaan käyttäjälle aikaa syöttää, parseInt käyttää tätä timeouttia.
}

void tyhjenna_bufferi() {
  while(Serial.available() != 0) { // tyhjennetään
    char t = Serial.read();
  }
}

void loop() {
  // poistin ylimääräisen while loopin
  tyhjenna_bufferi();
  Serial.println("Give first number");
  int foo = 0; // siirrettiin ulkopuolelle while loopista
  while(Serial.available() == 0)
  {
    // let's just wait until user gives a number
  }
  foo = Serial.parseInt();

  tyhjenna_bufferi();

  Serial.println("And give now second number");
  int bar = 0; // siirrettiin ulkopuolelle while loopista
  while(Serial.available() == 0)
  {
    // let's just wait until user gives a number
  }
  bar = Serial.parseInt();

  tyhjenna_bufferi();

  Serial.println("And give operation +,-,* or / you want to make");
  while(Serial.available() == 0)
  {
    // let's just wait until user gives a number
  }

  char operation = Serial.read();

  Serial.print(foo);
  Serial.print(" ");
  Serial.print(operation); // vaihdettiin tänne operation teksti
  Serial.print(" ");
  Serial.print(bar);
  Serial.print(" = ");
  Serial.println(aliohjelma(foo,bar,operation));   

  tyhjenna_bufferi();

}   // end of loop()
  
