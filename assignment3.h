 #ifndef ASSIGNMENT3_H
#define ASSIGNMENT3_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


/* Question 1 */


// gets a string str, and a char delim
// returns the number of tokens in str separated by delim.
int count_tokens(const char* str, char delim);


// gets a string str, and a char delim
// returns an array of tokens in str, ending with the NULL pointer
char** get_tokens(const char* str, char delim);


/* Question 2 */

// The function gets an array A of length n of ints, and a boolean predicate p.
// It returns the smallest index i such that p(A[i])==true.
// If no such element is not found, the function returns -1.
int find(int* A, int n, bool (*pred)(int));


// The function gets an array A of length n of ints, and a boolean predicate p.
// It returns the number of indices i such that p(A[i])==true.
int count(int* A, int n, bool (*pred)(int));


// The function gets an array A of length n of ints, and a function f
// It applies f to each element of A
void map(int* A, int n, int (*f)(int));


// The function gets an array A of length n of ints, and a function f.
// The function f gets 2 ints and works as follows:
// * Start with accumulator = A[0]
// * For i=1...length-1 compute accumulator=f(accumulator, A[i])
// *Return accumulator
// For example, if f computes the sum of the two inputs
// then reduce() will compute the sum of the entire array
int reduce(int* A, int n, int (*f)(int,int));


/* Question 3 */

// InsertionSort algorithm for arrays of a generic type
// the function gets an array of length n of objects of given size
// it also get a compare function
// and sorts the array using the compare function
// the function returns the number of swaps made by the algorithm
// About compare()
// if compare (a,b)<0, then a must come before b in the sorted array
// if compare (a,b)>0, then a must come after b in the sorted array
int gen_insertion_sort(void* ar, int n, size_t size, int (*compare)(const void*, const void*));


/* Question 4 */

// the function gets an array of strings of length n
// and sorts the strings in the array.
// In the sorted array the strings are arranged so that
// shorter strings come before the longer strings
// and among strings of equal length we compare them using strcmp()
void sort_strings(const char* A[], int n);


#endif
