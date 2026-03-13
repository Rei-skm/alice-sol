#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "labexam.h"

void test_q1() {
  char* str1 = "1234";    // 1+2+3+4=10
  char* str2 = "h1e2l34lo78";  // 1+2+3+4+7+8=25

  if (sum_of_digits(str1) == 10 && sum_of_digits(str2) == 25) 
    printf("Q1 ok\n");
  else
    printf("Q1 ERROR\n");
}


int square(int x) { return x*x;}
 
void test_q2() { 
  int ar[] = {2,6,2,3,1,-10,0};
  int* ans = map_to_new_array(ar, 7, square);

  /**********test answer**********/ 
  if (ans==NULL) {
    printf("Q2 ERROR : ans==NULL\n");
    return;
  }

  int correct[] = {4,36,4,9,1,100,0};
  bool okFlag = true;
  for(int i=0;i<7;i++) {
    if (ans[i]!=correct[i])
      okFlag = false;
  }
  free(ans);

  if (okFlag)
    printf("Q2 ok\n");
  else
    printf("Q2 ERROR\n");
}


void test_q3() { 
  int a1[] = {1,1,3,3,3,1,5,1};
  int a2[] = {1,3,3,2,3,3,3,3};

  if (longest_seq(a1, 8, 1)==2 && longest_seq(a2, 8, 3)==4) 
    printf("Q3 ok\n");
  else
    printf("Q3 ERROR\n");
}


int main(void) {
  test_q1();
  test_q2();
  test_q3();
  return 0;
}
