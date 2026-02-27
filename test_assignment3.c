#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "assignment3.h"


bool test_q1_1()  {
  char* str1 = "abc EFaG hi ";
  char* str2 = "ab12ef+";
  if (count_tokens(str1, ' ')==3 && count_tokens(str2,'+')==1) {
    printf("Q1-1 ok\n");
    return true;
  }
  else  {
    printf("Q1-1 ERROR\n");
    return false;
  }
}

bool test_q1_2()  {
  char** tokens = get_tokens("++All+Along+the+Watchtower++", '+');

  if (tokens==NULL) {
    printf("Q1-2 ERROR: tokens==NULL\n");
    return false;
  }

  bool check_tokens = true;

  char* sol[5] = {"All", "Along", "the", "Watchtower", NULL};

  for (int i=0; i<4; i++)
    if (tokens[i]==NULL || strcmp(tokens[i], sol[i]) != 0) {
      printf("Q1-2 ERROR: tokens[%d] error\n" ,i);
      check_tokens = false;
    }

  if (tokens[4] != NULL){
      printf("Q1-2 ERROR: tokens[4] is expected to be NULL\n");
      check_tokens = false;
  }

  // free tokens
  for (int i=0;i<4;i++)
    free(tokens[i]);
  free(tokens);
  

  if (check_tokens) {
    printf("Q1-2 ok\n");
    return true;
  }
  else  {
    printf("Q1-2 ERROR\n");
    return false;
  }
}


// used for test_q2_find and test_q2_count
bool is_even(int x) { return x%2 == 0; }
bool is_positive(int x) { return x>0; }

void test_q2_find()  {
  int A[6] = {-1,3,-6,5,2,7};

  if (find(A, 6, is_even)==2 && find(A, 6, is_positive)==1) 
    printf("Q2_find ok\n");
  else
    printf("Q2_find ERROR\n");
}

void test_q2_count()  {
  int A[6] = {-1,3,-6,5,2,8};

  if (count(A, 6, is_even)==3 && count(A, 6, is_positive)==4) 
    printf("Q2_count ok\n");
  else
    printf("Q2_count ERROR\n");
}

// used for test Q2_map
int mult4(int x) { return x*4;}

void test_q2_map()  {
  int A[6] = {-1,3,-6,5,2,7};
  map(A, 6, mult4);

  if (A[0]==-4 && A[3]==20) 
    printf("Q2_map ok\n");
  else
    printf("Q2_map ERROR\n");
}

// used for test Q2_reduce
int sum(int x, int y) {return x+y;}
int last(int x, int y) {return y;}

void test_q2_reduce()  {
  int A[6] = {-1,3,-6,5,2,7};

  if (reduce(A, 6, sum)==10 && reduce(A, 6, last)==7) 
    printf("Q2_reduce ok\n");
  else
    printf("Q2_reduce ERROR\n");
}


// used for test test_q3 for sorting in reverse order
int cmpr_ints_rev(const void* a, const void* b) {
  return *(const int*)b - *(const int*)a;
}

bool test_q3()  {
  int len = 6;
  int ar[6] = {7,3,5,1,11,9};
  
  // cmpr_ints_rev sorts the array in reverse order
  int swaps = gen_insertion_sort(ar, len, sizeof(int), cmpr_ints_rev);
  // 7 : [7,3,5,1,11,9]  0
  // 3 : [7,3,5,1,11,9]  0
  // 5 : [7,5,3,1,11,9] +1
  // 1 : [7,5,3,1,11,9]  0
  //11 : [11,7,5,3,1,9] +4
  //11 : [11,9,7,5,3,1] +4
  

  bool okFlag = true;
  for (int i=0;i<len;i++)
    if (ar[i] != 11-2*i)
      okFlag = false;


  if (okFlag && swaps==9) {
    printf("Q3 ok\n");
    return true;
  }
  else  {
    printf("Q3 ERROR\n");
    return false;
  }
}

bool test_q4_1() {
  const char* A[] = {"hello", "World", "1", "2", "12345678"};
  sort_strings(A, 5);
  const char* correct_ans[] = { "1", "2", "World", "hello", "12345678"};
  bool flag_ok = true;
  for (int i = 0; i < 5; i++) {
    if (strcmp(A[i], correct_ans[i]) != 0) {
      flag_ok = false;
      break;
    }
  }
  if (flag_ok) {
    printf("Q4-1 ok\n");
    return true;
  }
  else  {
    printf("Q4-1 ERROR\n");
    return false;
  }
}


bool test_q4_2() {
  const char* A[] = {"Wx", "ab", "Zde", "6_@7h", "7", "hij",  "_hh", "b"};
  sort_strings(A, 8);
  const char* correct_ans[] = {"7", "b", "Wx", "ab", "Zde", "_hh", "hij", "6_@7h"};
  bool flag_ok = true;
  for (size_t i = 0; i < 8; i++) {
    if (strcmp(A[i], correct_ans[i]) != 0) {
      flag_ok = false;
      break;
    }
  }
  if (flag_ok) {
    printf("Q4-2 ok\n");
    return true;
  }
  else  {
    printf("Q4-2 ERROR\n");
    return false;
  }
}



// when testing your code, it may be convenient 
// to comment out some of the test cases
// and focus only on the one you are working on right now
int main() {

  test_q1_1();
  test_q1_2();

  test_q2_find();
  test_q2_count();
  test_q2_map();
  test_q2_reduce(); 

  test_q3();

  test_q4_1();
  test_q4_2();

  return 0;
}