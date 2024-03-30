#include <stdio.h>

void sortThreeIntegers(int arr[3]) {
  int temp;

  if(arr[0] > arr[1]) {
    temp = arr[0];
    arr[0] = arr[1];
    arr[1] = temp;
  }
  if(arr[1] > arr[2]) {
    temp = arr[1];
    arr[1] = arr[2];
    arr[2] = temp;
  }
  if(arr[0] > arr[1]) {
    temp = arr[0];
    arr[0] = arr[1];
    arr[1] = temp;
  }
}

int main(int argv, char** argc) {
  int values[3], sortedValues[3];

  (void)scanf("%d %d %d", &values[0], &values[1], &values[2]);
  sortedValues[0] = values[0];
  sortedValues[1] = values[1];
  sortedValues[2] = values[2];
  sortThreeIntegers(sortedValues);
  (void)printf("%d\n%d\n%d\n\n", sortedValues[0], sortedValues[1], sortedValues[2]);
  (void)printf("%d\n%d\n%d\n", values[0], values[1], values[2]);
  return 0;
}