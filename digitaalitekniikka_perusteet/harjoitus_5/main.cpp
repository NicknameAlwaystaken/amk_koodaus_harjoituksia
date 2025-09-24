
int pin_segment_e = 6;
int pin_segment_d = 7;
int pin_segment_c = 8;
int pin_segment_rdp = 9;
int pin_segment_b = 10;
int pin_segment_a = 11;
int pin_segment_f = 12;
int pin_segment_g = 13;

// laitetaan pinnit mitä käytetään jokaiseen kirjaimeen taulukkoon
// joka viedään sitten segment_show() funktioon taulukon pituuden kanssa
int letter_L[] = {
  pin_segment_e,
  pin_segment_d,
  pin_segment_f
};

int letter_o[] = {
  pin_segment_e,
  pin_segment_d,
  pin_segment_g,
  pin_segment_c
};

int letter_p[] = {
  pin_segment_e,
  pin_segment_f,
  pin_segment_a,
  pin_segment_b,
  pin_segment_g,
};

int letter_r[] = {
  pin_segment_e,
  pin_segment_g,
};

int letter_i[] = {
  pin_segment_b,
  pin_segment_c
};


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pin_segment_a, OUTPUT);
  pinMode(pin_segment_b, OUTPUT);
  pinMode(pin_segment_c, OUTPUT);
  pinMode(pin_segment_d, OUTPUT);
  pinMode(pin_segment_e, OUTPUT);
  pinMode(pin_segment_f, OUTPUT);
  pinMode(pin_segment_g, OUTPUT);
  pinMode(pin_segment_rdp, OUTPUT);
}

void set_pins_low() {
  digitalWrite(pin_segment_a, LOW);
  digitalWrite(pin_segment_b, LOW);
  digitalWrite(pin_segment_c, LOW);
  digitalWrite(pin_segment_d, LOW);
  digitalWrite(pin_segment_e, LOW);
  digitalWrite(pin_segment_f, LOW);
  digitalWrite(pin_segment_g, LOW);
  digitalWrite(pin_segment_rdp, LOW);
}

void segment_show(const int *pins, int length) {
  Serial.print("sizeof(pins)"); Serial.println(sizeof(pins));
  Serial.print("sizeof(pins[0])"); Serial.println(sizeof(pins[0]));
  Serial.print("Length: "); Serial.println(length);
  for (int i = 0; i < length; i++) {
    digitalWrite(pins[i], HIGH);
    Serial.print("pins[i]: "); Serial.println(pins[i]);
  }
  Serial.println("\n\n");
}

void loop() {
  // put your main code here, to run repeatedly:

  int loop_amount = 10;
  int start_delay = 1000;
  int current_delay = start_delay;
  for (int i = 0; i < loop_amount; i++) {
    delay(current_delay); // viive joka muuttuu loopin lopussa.

    set_pins_low(); // Pinnit muutetaan LOW asentoon
    Serial.println("letter_L");
    segment_show(letter_L, sizeof(letter_L) / sizeof(letter_L[0]));
    delay(current_delay);

    set_pins_low();
    Serial.println("letter_o");
    segment_show(letter_o, sizeof(letter_o) / sizeof(letter_o[0]));
    delay(current_delay);
    set_pins_low();

    Serial.println("letter_p");
    segment_show(letter_p, sizeof(letter_p) / sizeof(letter_p[0])); // annetaan taulukko ja sen pituus
    delay(current_delay);
    set_pins_low();

    Serial.println("letter_r");
    segment_show(letter_r, sizeof(letter_r) / sizeof(letter_r[0]));
    delay(current_delay);
    set_pins_low();

    Serial.println("letter_i");
    segment_show(letter_i, sizeof(letter_i) / sizeof(letter_i[0]));
    delay(current_delay);

    current_delay *= 0.9; // pienenetään viivettä joka pysyy kunnes for loop on käyty loppuun
  }

  delay(2000);
}
