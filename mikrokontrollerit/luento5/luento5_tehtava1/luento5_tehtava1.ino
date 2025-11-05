volatile uint16_t milliseconds = 0;
volatile uint16_t seconds = 0;
volatile uint16_t minutes = 0;

volatile unsigned long last_time = 0;

volatile uint8_t timer_enabled = 0;

const unsigned int start_pin = 2;
const unsigned int restart_pin = 3;

volatile unsigned long last_restart_interrupt = 0;
const unsigned long restart_delay = 500;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(start_pin, INPUT_PULLUP);
  pinMode(restart_pin, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(start_pin), start_timer, FALLING);
  attachInterrupt(digitalPinToInterrupt(restart_pin), restart_timer, FALLING);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (timer_enabled) {
    update_timer();
    print_timer();
    delay(1000);
  }
}

void update_timer() {
  unsigned long current_time = millis();

  milliseconds += current_time - last_time;

  last_time = current_time;

  while (milliseconds >= 1000) {
    milliseconds -= 1000;
    seconds += 1;
    while(seconds >= 60) {
      seconds -= 60;
      minutes += 1;
    }
  }
}

void start_timer() {
  if (!timer_enabled) { // varotaan uusia startteja
    reset_timer();
    timer_enabled = 1;
  }
}

void restart_timer() {
  unsigned long current_time = millis();
  if (current_time - last_restart_interrupt > restart_delay) {
    Serial.println("TIMER RESET!!!");
    update_timer();
    print_timer();
    reset_timer();
    last_restart_interrupt = current_time;
  }
}

void print_timer() {
  Serial.print("Aika: ");
  Serial.print(minutes);
  Serial.print("m ");
  Serial.print(seconds);
  Serial.print("s ");
  Serial.print(milliseconds);
  Serial.println("ms");
}

void reset_timer() {
  milliseconds = 0;
  seconds = 0;
  minutes = 0;

  last_time = millis();
}