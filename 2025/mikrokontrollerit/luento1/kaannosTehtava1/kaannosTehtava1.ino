int printsubroutine(String s);

void setup() {
  Serial.begin(9600); // korjattiin 9600
}

void loop() {
  if(Serial.available()>0)  // odotellaan, että vähintään yksi 8-bitin merkki on sarjamonitorilta tullut
  {
    int luettu = Serial.read();
    if(luettu == 49) // merkki 1 on int 49
    {
      while(Serial.available()>0)
      {
        Serial.read();     // luetaan ylimääräiset merkit pois // puuttu ;
      }
      printSubroutine("Sinun pitaa saada tama teksti tulostumaan sarjamonitorille!");  
    }
  } // täältä pois ;
} // täältä pois ;

void printSubroutine(String s)
{
  Serial.println(s);
}
