#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "assignment1.h"

bool test_q1_1() {
  if (square_cube(-1, 2) == 9) {
    printf("Q1-1 ok\n");
    return true;
  }
  else  {
    printf("Q1-1 ERROR\n");
    return false;
  }
}


bool test_q1_2() {
  if (square_cube(3, 1) == 28) {
    printf("Q1-2 ok\n");
    return true;
  }
  else  {
    printf("Q1-2 ERROR\n");
    return false;
  }
}


bool test_q2_1() {
  int x=1, y=2, z=3;
  rotate3(&x, &y, &z);

  if ((x==2) && (y==3) && (z==1)) {
    printf("Q2-1 ok\n");
    return true;
  }
  else  {
    printf("Q2-1 ERROR\n");
    return false;
  }
}


bool test_q2_2() {
  int x=7, y=2, z=2;
  rotate3(&x, &y, &z);

  if ((x==2) && (y==2) && (z==7)) {
    printf("Q2-2 ok\n");
    return true;
  }
  else  {
    printf("Q2-2 ERROR\n");
    return false;
  }
}


bool test_q3_1() {
  char str[] = "abcd123X";
  int ret = digits_to_zero(str);

  // check that ret is 3 and str was changed correctly
  if ((ret==3) && (strcmp(str,"abcd000X") == 0)) {
    printf("Q3-1 ok\n");
    return true;
  }
  else  {
    printf("Q3-1 ERROR\n");
    return false;
  }
}


bool test_q3_2() {
  char str[] = "00";
  int ret = digits_to_zero(str);

  // check that ret is 2 and str was changed correctly
  if ((ret==2) && (strcmp(str,"00") == 0)) {
    printf("Q3-2 ok\n");
    return true;
  }
  else  {
    printf("Q3-2 ERROR\n");
    return false;
  }
}


bool test_q4_1() {
  const int ar[5] = {1,-2,3,-8,3};

  if (max_abs(ar, 5) == 8) {
    printf("Q4-1 ok\n");
    return true;
  }
  else  {
    printf("Q4-1 ERROR\n");
    return false;
  }
}


bool test_q4_2() {
  const int ar[6] = {3,-2,0,-4,6,1};

  if (max_abs(ar, 6) == 6) {
    printf("Q4-2 ok\n");
    return true;
  }
  else  {
    printf("Q4-2 ERROR\n");
    return false;
  }
}



bool test_q5_1() {
  char* res = mult_number_by_digit("12340", 6);

  if (res!=NULL && strcmp(res, "74040") == 0) {
    free(res);
    printf("Q5-1 ok\n");
    return true;
  }
  else  {
    printf("Q5-1 ERROR\n");
    if (res)
      free(res);
    return false;
  }
}

bool test_q5_2() {
  // testing a really large number, it does not fit into int or long
  char* res = mult_number_by_digit("99999999999999999999999999999999999", 4);

  if (res!=NULL && strcmp(res, "399999999999999999999999999999999996") == 0) {
    free(res);
    printf("Q5-2 ok\n");
    return true;
  }
  else  {
    printf("Q5-2 ERROR\n");
    if (res)
      free(res);
    return false;
  }
}

// when testing your code, it may be convenient 
// to comment out some of the test cases
// and focus only on the one you are working on right now
int main() {
  test_q1_1();
  test_q1_2();
  
  test_q2_1();
  test_q2_2();
  
  test_q3_1();
  test_q3_2();

  test_q4_1();
  test_q4_2();
  
  test_q5_1();
  test_q5_2();
  
  return 0;
}
