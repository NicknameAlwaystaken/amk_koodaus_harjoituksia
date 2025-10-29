int random_a_pin = 5;

void tyhjenna_bufferi() {
  while(Serial.available() != 0) { // tyhjennetään
    char t = Serial.read();
  }
}

int get_random(int lowest, int highest) {
  int random_seed = analogRead(random_a_pin); // otetaan "leijuvasta" pinnistä randomi numero

  int modulo = random_seed % (highest - lowest); // katsotaan pienimmän ja isomman etäisyys ja otetaan siitä väliltä joku numero

  int result = lowest + modulo; // lisätään pienin numero jotta päässään lowest ja highest numeroiden väliin

  return result;
}

void set_ranges(uint16_t *lowest_range, uint16_t *highest_range) {
  Serial.println("Anna alaraja: ");
  int low = 0;
  int high = 0;
  while(Serial.available() == 0);

  low = Serial.parseInt();

  *lowest_range = low;

  tyhjenna_bufferi();

  Serial.println("Anna ylaraja: ");
  while(Serial.available() == 0);

  high = Serial.parseInt();

  *highest_range = high;

  tyhjenna_bufferi();

  Serial.print("Alaraja: ");Serial.println(low);
  Serial.print("Ylaraja: ");Serial.println(high);

}

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  Serial.setTimeout(100000);

  pinMode(random_a_pin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  uint16_t lowest_range, highest_range;

  set_ranges(&lowest_range, &highest_range); // haetaan syötä käyttäjältä

  Serial.print("Alaraja: ");Serial.println((int)lowest_range); // tulostetaan saadut rajat
  Serial.print("Ylaraja: ");Serial.println((int)highest_range);

  Serial.print("Random number: ");Serial.println(get_random(lowest_range, highest_range)); // tulostetaan sattumanvarainen numero numeroiden välistä
}
