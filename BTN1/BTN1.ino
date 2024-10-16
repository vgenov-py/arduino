int btn = 6;
int led3 = 3;
int isOn = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(btn, INPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int isPressed = digitalRead(btn);
  
  if (isPressed) {
    if (isOn) {
      digitalWrite(led3, LOW);
      isOn = 0;
      delay(200);
    } else {
      digitalWrite(led3, HIGH);
      isOn = 1;
      delay(200);
    }
  }
}
