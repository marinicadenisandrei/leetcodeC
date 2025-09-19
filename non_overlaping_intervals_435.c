/* Leetcode - 435. Non-overlapping Intervals (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

void reset ();
void green ();
void yellow ();
void red ();

int eraseOverlapIntervals(int intervalsVar[ARRAY_SIZE][2], int intervalsSizeVar);

int main()
{
    yellow();

    printf("Leetcode - 435. Non-overlapping Intervals (C language) - Medium\n");

    int intervals[NUMBER_OF_TESTS][ARRAY_SIZE][2] = {{{1,2},{2,3},{3,4},{1,3}},{{1,2},{1,2},{1,2}},{{1,2},{2,3}}};
    int intervalsSize[NUMBER_OF_TESTS] = {4,3,2};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", eraseOverlapIntervals(intervals[test], intervalsSize[test]));
        
        green();

        printf("Passed\n");
    }
    
    reset();

    return 0;
}

int eraseOverlapIntervals(int intervalsVar[ARRAY_SIZE][2], int intervalsSizeVar)
{
    int result = 0;
    int same = 0;

    for (int i = 0; i < intervalsSizeVar; i++)
    {
        bool flag = true;

        for (int j = 0; j < intervalsSizeVar; j++)
        {
            if (i != j && intervalsVar[i][0] > intervalsVar[j][1])
            {
                flag = false;
                break;
            }

            if (i != j && intervalsVar[i][0] == intervalsVar[j][0] && intervalsVar[i][1] == intervalsVar[j][1])
            {
                same++;
            }
        }

        if (flag)
        {
            result++;
        }
    }

    return intervalsSizeVar - result + (same / intervalsSizeVar);
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