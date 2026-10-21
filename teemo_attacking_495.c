/* Leetcode - 495. Teemo Attacking (C language) - Easy */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

int findPoisonedDuration(int* timeSeriesVar, int timeSeriesSizeVar, int durationVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 495. Teemo Attacking (C language) - ");

    green();

    printf("Easy\n");

    int timeSeries[NUMBER_OF_TESTS][ARRAY_SIZE] = {{1,4},{1,2}};
    int timeSeriesSize[NUMBER_OF_TESTS] = {2,2};
    int duration[NUMBER_OF_TESTS] = {2,2};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", (test + 1));

        reset();

        printf("%i | ", findPoisonedDuration(timeSeries[test], timeSeriesSize[test], duration[test]));

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

int findPoisonedDuration(int* timeSeriesVar, int timeSeriesSizeVar, int durationVar)
{
    int result = durationVar;

    for (int i = 0; i < timeSeriesSizeVar - 1; i++)
    {
        if (timeSeriesVar[i] + durationVar <= timeSeriesVar[i + 1])
        {
            result += durationVar;        
        }
        else if (timeSeriesVar[i] + durationVar > timeSeriesVar[i + 1])
        {
            result += (timeSeriesVar[i] + durationVar) - timeSeriesVar[i + 1];
        }
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