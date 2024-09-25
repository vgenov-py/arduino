
int nums[] = {5,6,6,7};
int size = sizeof(nums)/sizeof(nums[0]);

void setup() {
  Serial.begin(9600);
  int count = 0;
  int uniqueNums[size]; 

  for (int i = 0; i < size; i ++) {
    // bucle externo
    int numToLookFor = nums[i]; 
    for (int j = 0; j < size; j ++) { 
      // bucle interno
      if (numToLookFor != uniqueNums[j] && uniqueNums[j] == 0) { 
        count ++;
        uniqueNums[i] = numToLookFor; 
        break;
      } else if (numToLookFor == uniqueNums[j]) {
        break;
        }
      }
    }
    for (int i = 0; i < size; i ++) {
      Serial.println(uniqueNums[i]);
    }
    Serial.println(count);
    delay(0);
  }


void loop() {
  // put your main code here, to run repeatedly:
}