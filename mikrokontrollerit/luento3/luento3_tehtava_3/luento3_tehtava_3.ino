
const unsigned int game_pin_1 = 2;
const unsigned int game_pin_2 = 3;
const unsigned int game_pin_3 = 4;
const unsigned int game_pin_4 = 5;

volatile uint8_t current_pin = 0;
volatile uint8_t previous_pin = 0;

volatile unsigned long last_time = 0;
volatile unsigned long game_delay = 2000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  PCICR = B00000100; // PCMSK2 maski käytössä 
  PCMSK2 = B00111100; // pinnit 2-5 käytössä PD2-5 PCINT18-21

  pinMode(game_pin_1, INPUT_PULLUP);
  pinMode(game_pin_2, INPUT_PULLUP);
  pinMode(game_pin_3, INPUT_PULLUP);
  pinMode(game_pin_4, INPUT_PULLUP);

  last_time = millis();

  randomSeed(analogRead(A0));

  interrupts();
}

ISR(PCINT2_vect) {
  for(int i = 2; i < 6; i++) {
    byte luettu = digitalRead(i);

    if(previous_pin == 0 && luettu == LOW) {
      if(current_pin == i) {
        Serial.println("oikein!");
        previous_pin = current_pin;
        current_pin = 0;
      } else if (current_pin != 0){
        Serial.println("Vaarin!");
      }
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long current_time = millis();
  if (current_time - last_time >= game_delay) {
    last_time = current_time;
    current_pin = random(2, 6);
    previous_pin = 0;
    Serial.print("\n\nPinni: ");Serial.println(current_pin);
  }
}