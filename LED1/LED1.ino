// LED 3.3V
// Resistencia 330

void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(3, HIGH);
  delay(15);
  digitalWrite(3, LOW);
  delay(15);
}
