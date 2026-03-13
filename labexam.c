#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "labexam.h"


int sum_of_digits(const char* str) {
  int sum = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] >= '0' && str[i] <= '9') {
      sum += str[i] - '0';
    }
    i++;
  }
  return sum;
}



int* map_to_new_array(const int* ar, int n, int(*foo)(int)) {
  int* new_array = (int*)malloc(n * sizeof(int));
  if (new_array == NULL) {
    return NULL;
  }
  for (int i = 0; i < n; i++) {
    new_array[i] = foo(ar[i]);
  }
  return new_array;
}



int longest_seq(const int* ar, int n, int k) {
  int max_length = 0;
  int current_length = 0;
  for (int i = 0; i < n; i++){
    if (ar[i] == k) {
      current_length++;
      if (current_length > max_length) {
        max_length = current_length;
      }
    } else {
      current_length = 0;
    }
  }
  return max_length;
}

