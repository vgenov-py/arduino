#include <Servo.h>

Servo servo1;

int val = 0;
int LED = 3;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  servo1.attach(5);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(A1)/4; // -> analogRead() [0,1023]/4 -> [0,255]
  analogWrite(LED, val); // -> analogWrite() [0,255]
  delay(100);
  servo1.write(0, 0, 1023, 0, 180);
  delay(1000);
  servo1.write(180, 0, 1023, 0, 180);
  delay(1000);
}
