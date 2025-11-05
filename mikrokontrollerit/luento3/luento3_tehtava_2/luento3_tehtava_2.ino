volatile int pcint0PinLow = 0;




void setup() {

  for(int i = 8;i<14;i++)
  {
    pinMode(i,INPUT_PULLUP);  // Arduino pinnit 8-14 INPUT_PULLUP tilaan
  }

  PCICR = 0x01;               // aktivoidaan PCINT0 Portti B antaa vain keskeytyksiä portit C ja D disabloituina 
  //PCICR = B00000001;
  PCMSK0 = B00011111;         // 0x15; pinnit 8-12


  Serial.begin(9600);
  interrupts();               // Keskeytykset enabloituna CPU:sta.
}

void loop() {

  if(pcint0PinLow !=0)
  {
    Serial.print("PCINT0 vaylasta keskeytys pinnista HIGH to LOW = ");
    Serial.println(pcint0PinLow);
    pcint0PinLow = 0;
  }



}

ISR(PCINT0_vect) {
  // Joku pinneista D8 - D13 on muuttanut tilaansa 1:sta 0 tai 0 ykkoseen selvitetaan mika pinni
  for(int i = 8;i<=12;i++)
  {
    byte luettu = digitalRead(i);
    
    /*while(digitalRead(i)==LOW)
    {
      //odotellaan, etta kayttaja nostaa napin
    }*/

    if(luettu==LOW)
    {
      pcint0PinLow = i;
    }

  }  
}

ISR(PCINT1_vect) {
  // This function will be called when a pin change interrupt occurs on pin 2
  Serial.println("interrupt 1");
}

ISR(PCINT2_vect) {
  // This function will be called when a pin change interrupt occurs on pin 2
  Serial.println("interrupt 2");
}