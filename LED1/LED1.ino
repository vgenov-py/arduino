// LED 3.3V
// Resistencia 330
#define LED1 3
#define LED2 4
//const int LED1 = 3;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly: //DRY - WET: DONT REPEAT YOURSELF - WRITE EVERYTHING TWICE
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, LOW);
  delay(500);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, HIGH);
  delay(500);
}
