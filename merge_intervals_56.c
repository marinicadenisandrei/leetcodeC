/* Leetcode - 56. Merge Intervals (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define INTERVAL_SIZE 2
#define NUMBER_OF_TESTS 2

void printArrayOfInt(int *array, int arraySize);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 56. Merge Intervals (C language) - Medium\n");

    int intervals[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE] = {{{1,3}, {2,6}, {8,10}, {15,18}}, {{1,4}, {4,5}}};
    int intervals_size[ARRAY_SIZE] = {4, 2};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        int int_size = intervals_size[test] + 1;

        int output[ARRAY_SIZE][ARRAY_SIZE] = {};
        int output_size = 0;

        int interval_start = 0;

        for (int i = 1; i < int_size; i++)
        {
            if (!(intervals[test][interval_start][0] <= intervals[test][i][0] && intervals[test][i][0] <= intervals[test][interval_start][1] && intervals[test][interval_start][1] <= intervals[test][i][1]))
            {
                output[output_size][0] = intervals[test][interval_start][0];
                output[output_size][1] = intervals[test][i-1][1];
                output_size++;
                interval_start = i;
            }
        }

        green();

        printf("Test %i: ", test + 1);
        
        reset();

        printf("[");

        for (int i = 0; i < output_size; i++)
        {
            printArrayOfInt(output[i], INTERVAL_SIZE);
        }

        printf("] | ");

        green();

        printf("Passed\n");

        reset();
    }
    
    return 0;
}

void printArrayOfInt(int *array, int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        printf("%s%i%s", ((i == 0) ? "[" : ""), array[i], ((i < arraySize - 1) ? ", " : "]"));
    }
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

