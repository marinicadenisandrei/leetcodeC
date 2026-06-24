/* Leetcode - 476. Number Complement (C language) - Easy */

#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_TESTS 2

void reset ();
void green ();
void yellow ();
void red ();

int findComplement(int numVar);

int main()
{
    yellow();

    printf("Leetcode - 476. Number Complement (C language) - ");

    green();

    printf("Easy\n");

    int num[NUMBER_OF_TESTS] = {5,1};
    
    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();
        
        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", findComplement(num[test]));

        green();

        printf("Passed\n");
    }
    
    reset();
}

int findComplement(int numVar)
{
    int temp = numVar;
    int mask = 0;

    while (temp > 0)
    {
        mask = (mask << 1) | 1;
        temp >>= 1;
    }
    
    return (~numVar) & mask;
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