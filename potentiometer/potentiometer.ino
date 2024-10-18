#include <Servo.h>

Servo servo1;

int val = 0;
int LED = 3;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  servo1.attach(5, 500, 2500);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(A1); // -> analogRead() [0,1023]/4 -> [0,255]
  //analogWrite(LED, val); // -> analogWrite() [0,255]
  val = map(val, 0, 1023, 0, 180);
  servo1.write(val);
}
