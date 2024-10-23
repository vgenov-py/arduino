#include <Wire.h>			
#include <Adafruit_GFX.h>		
#include <Adafruit_SSD1306.h>		
#define WIDTH 128			
#define HEIGHT 64				
#define OLED_RESET 4
Adafruit_SSD1306 oled(WIDTH, HEIGHT, &Wire, OLED_RESET);	

void setup() {
  Wire.begin();					
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);	
}
 
void center(String text) {
  int axis = WIDTH/2; //64
  int textLength = text.length(); //hola -> 4char -> 62:66
  int cursor = axis - textLength/2;
  oled.setCursor(cursor, 0);
  oled.print(text);
}

void loop() {
  oled.clearDisplay();
  oled.setTextColor(WHITE);		
  oled.setCursor(0, 0);			
  oled.setTextSize(1);			
  oled.print("HOLA!"); 	
  oled.display();
}