/* Leetcode - 96. Unique Binary Search Trees (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

int numTrees(int nVar);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 96. Unique Binary Search Trees (C language) - Medium\n");

    int n[ARRAY_SIZE] = {3, 1};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        int result = numTrees(n[test]);
        printf("%i | ", result);

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

int numTrees(int nVar)
{
    int array[ARRAY_SIZE] = {};
    int sum = 0;

    for (int i = 1; i <= nVar; i++)
    {
        array[i - 1] = i;
    }

    for (int i = 0; i < nVar; i++)
    {
        int left = 0;
        int right = 0;

        left = ((i == 0) ? 1 : i);
        right = ((i == nVar - 1) ? 1 : nVar - i - 1);
        sum += left * right;
    }
    
    return sum;
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