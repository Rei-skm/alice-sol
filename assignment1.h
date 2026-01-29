#ifndef ASSIGNMENT1_H
#define ASSIGNMENT1_H

#include <stdio.h>

// gets two numbers a, b
// if a>b, returns a^3 + b^2
// otherwise, returns a^2 + b^3
int square_cube(int a, int b);


// get pointers to three ints
// and rotates their values to the left
void rotate3(int* a,int* b,int* c);


// gets a string str
// changes all its digits to 0 (zero)
// returns the number of digits in the string.
int digits_to_zero(char* str);


// that gets an array of ints
// returns the maximum of the absolute values in the array
int max_abs(const int* arr, int len);



// gets a string representing a positive integer and an int between 0 and 9
// the function multiplies that two numbers and returns the result in a string
char* mult_number_by_digit(const char* num, int digit);



#endif