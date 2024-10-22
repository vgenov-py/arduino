#include <Servo.h>

Servo servo1;

int val = 0;
int LED_G = 3;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  servo1.attach(5, 500, 2500);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = 300; // -> analogRead() [0,1023]/4 -> [0,255]
  //analogWrite(LED, val); // -> analogWrite() [0,255]

  val = map(val, 300, 500, 0, 180); // 300 -> 0

  int val = 500; //Medición higrómetro
  val = map(val, 300, 500, 0, 180); //medición -> grados
  if (val >= 0 && val <= 75) {
    int intensity = map(val, 0, 75, 0, 255);
    Serial.print("VERDE: ");
    Serial.println(intensity);
  } else if (val > 45 && val <= 90) {
    int intensity = map(val, 45, 90, 0, 255);
    Serial.print("AMARILLO: ");
    Serial.println(intensity);
  } else if (val > 90 && val <= 135) {
    int intensity = map(val, 90, 135, 255, 0);
    Serial.print("AMARILLO: ");
    Serial.println(intensity);
  } else if (val > 105 && val <= 180) {
    int intensity = map(val, 105, 180, 0, 255);
    Serial.print("ROJO: ");
    Serial.println(intensity);
  }

  servo1.write(val);
}
