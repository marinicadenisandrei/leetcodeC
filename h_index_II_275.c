/* Leetcode - 275. H-Index II (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

int hIndex(int *citationsVar, int citationsVarSize);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 275. H-Index II (C language) - Medium\n");

    int citations[NUMBER_OF_TESTS][ARRAY_SIZE] = {{0,1,3,5,6},{1,2,100}};
    int citationsSize[NUMBER_OF_TESTS] = {5,3};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ",hIndex(citations[test], citationsSize[test]));

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

int hIndex(int *citationsVar, int citationsVarSize)
{
    for (int i = citationsVarSize - 1; i >= 0 ; i--)
    {
        if ((citationsVar[i] - 1) == i)
        {
            return citationsVar[i];
        }
    }
    
    return -1;
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