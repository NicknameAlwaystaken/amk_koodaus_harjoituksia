
// tehdään pinnien tunnuksista muuttujia jotta voidaan helposti ohjata pinnien tunnuksia
int pin_vihrea = 10;
int pin_keltainen = 11;
int pin_punainen = 12;
int a_read_pin = A0;

void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);

    // Muutetaan lediä ohjaavat pinnit ulostuloksi
    pinMode(pin_vihrea, OUTPUT);
    pinMode(pin_keltainen, OUTPUT);
    pinMode(pin_punainen, OUTPUT);

}

void loop() {
    // put your main code here, to run repeatedly:

    int analog_read_a = analogRead(a_read_pin);

    // Muutetaan analoginen luettu arvo jännitteeksi
    float analog_voltage = analog_read_a * (5.0 / 1023);

    // Sammutetaan kaikki ledit ennenkuin päätetään mikä sytytetään
    digitalWrite(pin_vihrea, LOW);
    digitalWrite(pin_keltainen, LOW);
    digitalWrite(pin_punainen, LOW);

    if (analog_read_a >= 950) { // 1023 A Mittattu laitetaan arvolle hyvän määrä väliä
        digitalWrite(pin_vihrea, HIGH);
    }
    else if (analog_read_a >= 800) { // 850 B Mitattu
        digitalWrite(pin_keltainen, HIGH);

    } else if (analog_read_a <= 10) { // päästä mitattu on 0 kun koskee itse groundiin
        digitalWrite(pin_vihrea, HIGH);
    }
    else { // 681 C Mitattu
        digitalWrite(pin_punainen, HIGH);
    }


    Serial.println();
    Serial.println();
    Serial.print("A0 read voltage: ");Serial.println(analog_voltage);
    Serial.print("A0 read value: ");Serial.println(analog_read_a);

    delay(200);

}
