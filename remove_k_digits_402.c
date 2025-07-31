/* Leetcode - 402. Remove K Digits (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

void reset ();
void green ();
void yellow ();
void red ();

int removeKdigits(char* numVar, int kVar);

int main()
{
    yellow();

    printf("Leetcode - 402. Remove K Digits (C language) - Medium\n");

    char num[NUMBER_OF_TESTS][ARRAY_SIZE] = {"1432219","10200","10"};
    int k[NUMBER_OF_TESTS] = {3,1,2};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", removeKdigits(num[test], k[test]));

        green();

        printf("Passed\n");
    }
    
    reset();
}

int removeKdigits(char* numVar, int kVar)
{
    int result = atoi(numVar);
    int acumulation[ARRAY_SIZE] = {};
    int acumulationSize = 0;

    for (int i = 0; i < strlen(numVar) - kVar + 1; i++)
    {
        char buff[20];
        int buffSize = 0;

        for (int j = 0; j < strlen(numVar); j++)
        {
            if (j < i || j > i + kVar - 1)
            {
                buff[buffSize++] = numVar[j];
            }
        }

        buff[buffSize] = '\0';
        int temp = atoi(buff);
        result = ((temp < result) ? temp : result);
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