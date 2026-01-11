#include "utils/array_utils.h"
#include <stdio.h>

int binsearch(int search, const int arr[], int size);

int main() {
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  unsigned long arr_size = sizeof(arr) / sizeof(arr[0]);

  print_int_array(arr, arr_size);
  printf("Result - [%d]\n", binsearch(7, arr, arr_size));
  return 0;
}

int binsearch(int search, const int arr[], int size) {
  int low = 0;
  int high = size - 1;
  int mid = -1;

  while (low < high) {
    mid = (low + high) / 2;

    if (search < arr[mid]) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  if (low == high && search == arr[low]) {
    return low;
  } else {
    return -1;
  }
}
