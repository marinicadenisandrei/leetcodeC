/* Leetcode - 179. Largest Number (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

int largestNumber(int *numsVar, int numsVarSize);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 179. Largest Number (C language) - Medium\n");

    int nums[NUMBER_OF_TESTS][ARRAY_SIZE] = {{10,2},{3,30,34,5,9}};
    int numsSize[NUMBER_OF_TESTS] = {2,5};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ",largestNumber(nums[test], numsSize[test]));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

int largestNumber(int *numsVar, int numsVarSize)
{
    int number = 0;

    for (int i = 1; i < numsVarSize; i++)
    {
        char integer1[ARRAY_SIZE];
        char integer2[ARRAY_SIZE];

        char str1[ARRAY_SIZE];
        char str2[ARRAY_SIZE];

        sprintf(str1, "%d", numsVar[i - 1]);
        sprintf(str2, "%d", numsVar[i]);
        
        strcpy(integer1, str1);
        strcat(integer1, str2);

        strcpy(integer2, str2);
        strcat(integer2, str1);

        int number1 = atoi(integer1);
        int number2 = atoi(integer2);
        
        numsVar[i] = ((number1 > number2) ? number1 : number2);
    }

    return numsVar[numsVarSize - 1];
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