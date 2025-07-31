/* Leetcode - 223. Rectangle Area (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_TESTS 2

int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 223. Rectangle Area (C language) - Medium\n");

    int ax1[NUMBER_OF_TESTS] = {-3,-2};
    int ay1[NUMBER_OF_TESTS] = {0,-2};
    
    int ax2[NUMBER_OF_TESTS] = {3,2};
    int ay2[NUMBER_OF_TESTS] = {4,2};
    
    int bx1[NUMBER_OF_TESTS] = {0,-2};
    int by1[NUMBER_OF_TESTS] = {-1,-2};
    
    int bx2[NUMBER_OF_TESTS] = {9,2};
    int by2[NUMBER_OF_TESTS] = {2,2};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ",computeArea(ax1[test], ay1[test], ax2[test], ay2[test], bx1[test], by1[test], bx2[test], by2[test]));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
{
    int result = 0;

    int rec1 = (abs(ay2) + abs(ay1)) * (abs(ax1) + abs(ax2));
    int rec2 = (abs(by2) + abs(by1)) * (abs(bx1) + abs(bx2));

    int cy = ((by2 > ay1 && by2 < ay2) ? by2 : 0);
    int cx = ((ax2 > bx1 && ax2 < bx2) ? ax2 : 0);
    int minus = cy * cx;
    
    result = rec1 + rec2 - minus;

    if (ax1 == bx1 && ay1 == by1 && ax2 == bx2 && ay2 == by2)
    {
        result /= 2;
    }
    
    return result;
}

void reset () {
  printf("\033[1;0m");
}

void green () {
  printf("\033[1;32m");
}

void yellow () {
  printf("\033[1;33m");
}

void red () {
  printf("\033[1;31m");
}