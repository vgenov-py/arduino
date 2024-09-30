
float temperatures[4] = {1,2,3,4}; // avg -> 2.5 -> int -> 2
float pressures[4] = {3,6,9,11}; // avg -> 2.5 -> int -> 2



float avg(float nums[], int numsLength) {
  float result = 0;
  for (int i = 0; i < numsLength; i ++) {
    result += nums[i]/numsLength; // -> 10;
  }
  return result;
}

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  float meanTemperatures = avg(
    temperatures, sizeof(temperatures)/sizeof(temperatures[0])
  );
  float meanPressures = avg(
    pressures, sizeof(pressures)/sizeof(pressures[0])
  );
  Serial.println(meanTemperatures);
  Serial.println(meanPressures);

}

void loop() {
  // put your main code here, to run repeatedly:

}
