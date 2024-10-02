
const int size = 5;
int nums[size] = {5, 6, 7, 8, 1};

int getIndex(int numToLookFor, int elements[], int length) {
  int numToLookForIndex = -1;
  for (int i = 0; i < length; i ++) {
    if (elements[i] == numToLookFor) {
      return i;
    }
  }
}

int getMax(int elements[], int length) {
  int bigger = elements[0];
  for (int i = 0; i < length; i ++) {
    if (elements[i] > bigger) {
      bigger = elements[i];
    }
  }
  return bigger;
}

int getMin(int elements[], int length) {
  int smaller = elements[0];
  for (int i = 0; i < length; i ++) {
    if (elements[i] < smaller) {
      smaller = elements[i];
    }
  }
  return smaller;
}


void setup() {
  Serial.begin(9600);

  // Código para encontrar índice:

  Serial.println(getIndex(7, nums, size));
  Serial.println(getMin(nums, size));

}

void loop() {
  // put your main code here, to run repeatedly:
}