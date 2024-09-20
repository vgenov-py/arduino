int nums[4] = {1,2,3,4}; // -> []
int result = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (int i = 0; i < 4; i ++) {
    result = result + nums[i];
  }
  Serial.println(result);
}

void loop() {
  // put your main code here, to run repeatedly:

}
