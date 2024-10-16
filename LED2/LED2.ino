#define ledsLength 3
#define interval 500
int leds[3] = {3,4,5}; //[]

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  //pinMode(3, OUTPUT);
  for (int i = 0; i < ledsLength; i++) {
    pinMode(leds[i], OUTPUT); //pinMode(leds[0], OUTPUT) -> leds[0] = 2; 2º pinMode(leds[1], OUTPUT) -> leds[1] = 3;
  }

}

void ledOnOff(int led, int intv) {
  digitalWrite(led, HIGH);
  delay(intv);
  digitalWrite(led, LOW);
  delay(intv);
}

void loop() {
  int rnum = random(3,6);
  Serial.println(rnum);
  delay(2000);
  digitalWrite(rnum, HIGH);
  delay(200);
  digitalWrite(rnum, LOW);
  // put your main code here, to run repeatedly:
  // for (int i = ledsLength - ledsLength; i < ledsLength; i++) {
  //   ledOnOff(leds[i], interval);
  // }

  // for (int i = ledsLength - 1; i >= 0; i--) {
  //   ledOnOff(leds[i], interval);
  // }

}
