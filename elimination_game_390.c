/* Leetcode - 390. Elimination Game (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void reset ();
void green ();
void yellow ();
void red ();

int lastRemaining(int nVar);

int main()
{
    yellow();

    printf("Leetcode - 390. Elimination Game (C language) - Medium\n");

    int n[NUMBER_OF_TESTS] = {9,1};
    
    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", lastRemaining(n[test]));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

int lastRemaining(int nVar)
{
    int startArr[ARRAY_SIZE] = {};
    int startArrSize = 0;

    int newArr[ARRAY_SIZE] = {};
    int newArrSize = 0;
    
    bool left = true;

    for (int i = 1; i <= nVar; i++)
    {
        startArr[startArrSize++] = i;
    }
    
    while (startArrSize > 1)
    {
        for (int i = ((left) ? 1 : 0); i < startArrSize - 1; i += 2)
        {
            newArr[newArrSize++] = startArr[i];
        }

        for (int i = 0; i < newArrSize; i++)
        {
            startArr[i] = newArr[i];
        }
        
        startArrSize = newArrSize;
        newArrSize = 0;

        if (left)
        {
            left = false;
        }
        else
        {
            left = true;
        }
    }

    if (left)
    {
        return startArr[0];   
    }

    return startArr[1];
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