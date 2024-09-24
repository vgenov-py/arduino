
int nums[] = {1,2,2,10,11,13,2,8,9,16,26,50,50,50,89,150,2,3,6,7,67,98};
int size = sizeof(nums)/sizeof(nums[0]);

void setup() {
  Serial.begin(9600);
  int count = 0;
  for (int i = 0; i < size; i ++) {
    // bucle externo
    int numToLookFor = nums[i]; // -> 1
    for (int j = 0; j < size; j ++) { // Cuántas veces aparace cada número en la lista.
      // bucle interno
      if (numToLookFor == nums[j]) {
        count ++;
      }
    } // fin bucle interno
    if (count > 1) {
      Serial.print(numToLookFor);
      Serial.println(" es un número repetido.");
    }
    count = 0;
    delay(1500);
  } // fin bucle externo

}

void loop() {
  // put your main code here, to run repeatedly:
}