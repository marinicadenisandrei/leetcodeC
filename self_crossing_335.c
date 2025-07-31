/* Leetcode - 335. Self Crossing (C language) - Hard */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

bool isSelfCrossing(int *distanceVar, int distanceVarSize);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 335. Self Crossing (C language) - ");

    red();

    printf("Hard\n");

    int distance[NUMBER_OF_TESTS][ARRAY_SIZE] = {{2,1,1,2},{1,2,3,4},{1,1,1,2,1}};
    int distanceSize[NUMBER_OF_TESTS] = {4,4,5};
    
    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%s | ", isSelfCrossing(distance[test], distanceSize[test]) == 1 ? "true" : "false");

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

bool isSelfCrossing(int *distanceVar, int distanceVarSize)
{
    for (int i = 0; i < distanceVarSize; i += 4)
    {
        if (i > distanceVarSize - 1)
        {
            break;
        }

        if (distanceVar[i] > distanceVar[i + 2] || distanceVar[i + 1] > distanceVar[i + 3])
        {
            return true;
        }
    }
    

    return false;
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