#include <Servo.h>
#include <Wire.h>			
#include <Adafruit_GFX.h>		
#include <Adafruit_SSD1306.h>		
#define WIDTH 128			
#define HEIGHT 64				
#define OLED_RESET 4

Servo servo1;
Adafruit_SSD1306 oled(WIDTH, HEIGHT, &Wire, OLED_RESET);


int val = 0;
int LED = 3;
int PIN_MOISTURE = A3;
int moisture;
void setup() {
  // put your setup code here, to run once:
  Wire.begin();					
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  servo1.attach(5, 500, 2500);
  
}

void loop() {
  oled.clearDisplay();
  oled.setTextColor(WHITE);	
  moisture = analogRead(PIN_MOISTURE);
  val = moisture; // -> analogRead() [0,1023]/4 -> [0,255]
  val = map(val, 300, 500, 0, 180); //medición -> grados

  if (val >= 0 && val <= 75) {
    int intensity = map(val, 0, 75, 0, 255);
    servo1.write(val);
    Serial.print("VERDE: ");
    Serial.println(intensity);
  } else if (val > 45 && val <= 90) {
    int intensity = map(val, 45, 90, 0, 255);
    servo1.write(val);
    Serial.print("AMARILLO: ");
    Serial.println(intensity);
  } else if (val > 90 && val <= 135) {
    int intensity = map(val, 90, 135, 255, 0);
    servo1.write(val);
    Serial.print("AMARILLO: ");
    Serial.println(intensity);
  } else if (val > 105 && val <= 180) {
    int intensity = map(val, 105, 180, 0, 255);
    servo1.write(val);
    Serial.print("ROJO: ");
    Serial.println(intensity);
  }

  oled.setCursor(20, 0);			
  oled.setTextSize(2);			
  oled.print("Humedad: "); //Humedad: 320
  oled.setCursor(70, 0);			
  oled.setTextSize(2);		
  oled.print(val);
  oled.display();

}
