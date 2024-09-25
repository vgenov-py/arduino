
int b = 3;
char x = "d";
int basic1() {
  return 1;    
}

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  int x = basic1() + 3;
  Serial.println(x);

}

void loop() {
  // put your main code here, to run repeatedly:

}
