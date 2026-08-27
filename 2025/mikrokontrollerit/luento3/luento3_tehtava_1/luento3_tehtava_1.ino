uint8_t pin_grow_by_one = 2;
uint8_t pin_grow_by_ten = 3;

uint8_t button_grow_by_one = 0;
uint8_t button_grow_by_ten = 0;

volatile long int counter = 0;

unsigned long last_time = 0;
const unsigned long counter_reset_delay = 5000;

volatile unsigned long last_interrupt_time_one = 0;
volatile unsigned long last_interrupt_time_ten = 0;
const unsigned long debounce_delay = 100; // viive uuden painalluksen ottamiselle

/*
1. Tee Arduino ohjelma, joka kasvattaa muuttujan arvoa yhdellä,
kun arduinon pinniin 2 kytkettyä nappia painetaan ja
kasvattaa muuttujan arvoa kymmenellä, kun arduinon pinniin 3
kytkettyä nappia painetaan. Pääohjelma (loop) tulostaa viiden sekunnin
välein  muuttujan arvon sarjamonitorille, ja nollaa muuttujan.
(muista volatile!)
*/

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(pin_grow_by_one, INPUT_PULLUP);
  pinMode(pin_grow_by_ten, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(pin_grow_by_one), grow_by_one_isr, FALLING);
  attachInterrupt(digitalPinToInterrupt(pin_grow_by_ten), grow_by_ten_isr, FALLING);
}

void grow_by_one_isr() {
  unsigned long current_time = millis();
  if(current_time - last_interrupt_time_one > debounce_delay) {
    counter += 1;
    last_interrupt_time_one = current_time;
  }
}

void grow_by_ten_isr() {
  unsigned long current_time = millis();
  if(current_time - last_interrupt_time_ten > debounce_delay) {
    counter += 10;
    last_interrupt_time_ten = current_time;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long current_time = millis();

  if (current_time - last_time >= counter_reset_delay) {
    last_time = current_time;
    Serial.print("Counter: ");Serial.println(counter);

    counter = 0;
  }

}
