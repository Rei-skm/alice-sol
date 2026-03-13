#ifndef LAB_EXAM_201_202_H
#define LAB_EXAM_201_202_H

// the function gets a string
// and returns the sum of all digits (0...9) in the strings
int sum_of_digits(const char* str);


// the function gets an array of ints of length n, and a function foo
// and returns a new array (on the heap) of the same length
// where ret[i] = foo(ar[i]) for all i
int* map_to_new_array(const int* ar, int n, int(*foo)(int));


// returns the length of the longest subsequence
// of consecutive k’s in the array
int longest_seq(const int* ar, int n, int k);

#endif
