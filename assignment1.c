#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "assignment1.h"

// Q1
int square_cube(int a, int b) { 
    if (a > b){
      // If a > b, return a^3 + b^2  
      return (a * a * a + b * b); 
    } else {
      // otherwise return a^2 + b^3
          return (a * a + b * b * b);
    }
}



// Q2
void rotate3(int* a, int* b, int* c) {
    int temp = *a; 
    *a = *b;
    *b = *c; 
    *c = temp;    
}


// Q3
int digits_to_zero(char* str) {
    int count = 0;
    if (str == NULL) return 0; 

    while (*str) {
        if (*str >= '0' && *str <= '9') { 
            *str = '0'; 
            count++;   
        }
        str++; 
    }
    
    return count; 
}
  

// Q4
int max_abs(const int* arr, int len) {
    if (len == 0) return 0; 

    int max_value = abs(arr[0]); 
    for (int i = 0; i < len; i++) {
        int current_abs = abs(arr[i]); 
        
        if (current_abs > max_value) {
            max_value = current_abs;
        }    
    }
    
    return max_value; 
}

// Q5
char* mult_number_by_digit(const char* num, int digit) {
    int len = strlen(num);
    char* result = malloc((len + 2) * sizeof(char));
    if (result == NULL) return NULL;

    int carry = 0;
    int k = 0; 
    for (int i = len - 1; i >= 0; i--) {
        int n = num[i] - '0'; 
        int prod = n * digit + carry;
        result[k++] = (prod % 10) + '0'; 
        carry = prod / 10;               
    }
    if (carry > 0) {
        result[k++] = carry + '0';
    }
    result[k] = '\0'; 
    for (int i = 0; i < k / 2; i++) {
        char temp = result[i];
        result[i] = result[k - 1 - i];
        result[k - 1 - i] = temp;
    }

    return result;
}