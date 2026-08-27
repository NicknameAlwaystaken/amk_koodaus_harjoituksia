int pin_a = 8;
int pin_b = 9;

int output_s = 2;
int output_c = 3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(output_s, OUTPUT);
  pinMode(output_c, OUTPUT);
}

void loop() {
  // put your main code here, to run  repeatedly:

  int a_bit = digitalRead(pin_a);
  int b_bit = digitalRead(pin_b);

  Serial.print("a_bit: ");Serial.println(a_bit);
  Serial.print("b_bit: ");Serial.println(b_bit);

  int a_not_and_b = !a_bit * b_bit;
  Serial.print("a_not_and_b: ");Serial.println(a_not_and_b);

  int a_and_b_not = a_bit * !b_bit;
  Serial.print("a_and_b_not: ");Serial.println(a_and_b_not);

  int xor_ab = a_not_and_b || a_and_b_not;
  Serial.print("xor_ab: ");Serial.println(xor_ab);

  int a_and_b = a_bit && b_bit;
  Serial.print("a_and_b: ");Serial.println(a_and_b);

  digitalWrite(output_s, xor_ab);
  digitalWrite(output_c, a_and_b);

  delay(10);
}
