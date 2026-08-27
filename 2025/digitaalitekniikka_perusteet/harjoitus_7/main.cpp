int output_pin = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(output_pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(output_pin, HIGH);
  delay(500);
  digitalWrite(output_pin, LOW);
  delay(500);
}
