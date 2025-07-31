#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TEST 2

int minimumTotal(int triangle[ARRAY_SIZE][ARRAY_SIZE], int triangleSize);
int minElementFromArray(int* array, int arraySize);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 120. Triangle (C language) - Medium\n");

    int triangle[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE] = {{{2}, {3,4}, {6,5,7}, {4,1,8,3}}, {{-10}}};
    int triangleSize[ARRAY_SIZE] = {4,1};
    
    for (int test = 0; test < NUMBER_OF_TEST; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", minimumTotal(triangle[test], triangleSize[test]));

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

int minElementFromArray(int* array, int arraySize)
{
    int min = array[0];

    for (int i = 1; i < arraySize; i++)
    {
        if (min > array[i])
        {
            min = array[i];
        }
    }

    return min;
}

int minimumTotal(int triangle[ARRAY_SIZE][ARRAY_SIZE], int triangleSize)
{
    int sum = 0;

    for (int i = 0; i < triangleSize; i++)
    {
        sum += minElementFromArray(triangle[i], i + 1);
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