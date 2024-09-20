
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>
#define buzzer 13
#define size 10
#define interval 20

Adafruit_BMP280 bmp;

float base_altitude, prev_altitude, altitude;
int base_tone = 500;
float oscilation = 0.5;
float altitudes[10];

void setup() {
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  if ( !bmp.begin() ) {
    Serial.println("BMP280 not found!");
    while (1);
  }
  base_altitude = bmp.readPressure()/100 + 5;
  prev_altitude = base_altitude;
  for (int i = 100; i < 1000; i ++) {
    tone(buzzer, i, 100);
    delay(100);
    i = i + 100;
  }
}

float get_measurement() {
  return bmp.readAltitude(base_altitude);
}

float get_altitude() {
  float result = 0;
  for (int i = 0; i < size; i++) {
    result += get_measurement()/size;
    delay(interval);
  }
  return result;
}

void loop() {
  altitude = get_altitude();
  float diff = altitude - prev_altitude;
  if (diff >= oscilation || diff <= oscilation) {
    int new_tone = base_tone + diff * 100;
    tone(buzzer, new_tone, 200);
  }
  prev_altitude = altitude;
}
