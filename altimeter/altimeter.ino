
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>
#define buzzer 13

Adafruit_BMP280 bmp;

float base_altitude, prev_altitude;
float max_altitude = 0;
int base_tone = 500;
int altitudes_length = 10;
float altitudes[10];

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  if ( !bmp.begin() ) {				// si falla la comunicacion con el sensor mostrar
    Serial.println("BMP280 no encontrado !");	// texto y detener flujo del programa
    while (1);					// mediante bucle infinito
  }
  base_altitude = bmp.readPressure()/100+5;
  prev_altitude = base_altitude;
  for (int i = 100; i < 1000; i ++) {
    // tone(buzzer, i, 100);
    delay(100);
    i = i + 100;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  float altitude = log(bmp.readAltitude(base_altitude));
  // Serial.print("pre: ");
  // Serial.println(prev_altitude);
  // Serial.print("Altitude: ");
  // Serial.println(altitude);
  //noTone(buzzer);
  // delay(1000);
  float diff = altitude - prev_altitude;
  // Serial.println(diff);

  // Serial.println(max_altitude);
  Serial.println(altitude);
  // if (diff > 0.01) {
  //   int new_tone = base_tone  + diff * 100;
  //   tone(buzzer, new_tone, 100);
  //   delay(200);
  //   while (bmp.readAltitude(base_altitude) > prev_altitude) {
  //     new_tone += 50;
  //     // tone(buzzer, new_tone, 100);
  //     prev_altitude = bmp.readAltitude(base_altitude);
  //   }

  if (max_altitude + 0.01 < altitude) {
    tone(buzzer, 800, 200);
    max_altitude = altitude;
  } else {
    if (altitude <= max_altitude - 0.02) {
      max_altitude = altitude;
    }
  }

  delay(300);
  prev_altitude = altitude;
}
