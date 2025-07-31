#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define INTERVAL_SIZE 2
#define NUMBER_OF_TESTS 2

void printArrayOfIntegers(int array[ARRAY_SIZE], int arraySize);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{   
    yellow();

    printf("Leetcode - 57. Insert Interval (C language) - Medium\n");

    int intervals[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE] = {{{1,3}, {6,9}}, {{1,2}, {3,5}, {6,7}, {8, 10}, {12,16}}};
    int size_intervals[ARRAY_SIZE] = {2, 5};

    int newInterval[ARRAY_SIZE][ARRAY_SIZE] = {{2,5}, {4,8}};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        int output[ARRAY_SIZE][ARRAY_SIZE] = {};
        int size_output = 0;

        int flag = false;

        for (int i = 0; i < size_intervals[test]; i++)
        {
            if ((intervals[test][i][0] <= newInterval[test][0] && newInterval[test][0] <= intervals[test][i][1] && intervals[test][i][1] <= newInterval[test][1]) || (newInterval[test][0] <= intervals[test][i][0] && intervals[test][i][1] <= newInterval[test][1]) || (intervals[test][i][0] == newInterval[test][1]))
            {
                if (flag == false)
                {
                    output[size_output][0] = intervals[test][i][0];
                    size_output++;
                }
                else
                {
                    output[size_output - 1][1] = intervals[test][i][1];
                }

                flag = true;
            }
            else
            {
                if (newInterval[test][1] > output[size_output - 1][1])
                {
                    output[size_output - 1][1] = newInterval[test][1];
                }
                
                flag = false;

                output[size_output][0] = intervals[test][i][0];
                output[size_output][1] = intervals[test][i][1];

                size_output++;
            }
        }

        green();

        printf("Test %i: ", test + 1);

        reset();

        for (int i = 0; i < size_output; i++)
        {
            printArrayOfIntegers(output[i], 2);
        }

        printf(" | ");

        green();

        printf("Passed\n");

        reset();
    }

    return 0;
}

void printArrayOfIntegers(int array[ARRAY_SIZE], int arraySize)
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


