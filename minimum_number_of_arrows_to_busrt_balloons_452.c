/* Leetcode - 452. Minimum Number of Arrows to Burst Balloons (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

void reset ();
void green ();
void yellow ();
void red ();

int findMinArrowShots(int pointsVar[ARRAY_SIZE][2], int pointsSizeVar);

int main()
{
    yellow();

    printf("Leetcode - 452. Minimum Number of Arrows to Burst Balloons (C language) - Medium\n");

    int points[NUMBER_OF_TESTS][ARRAY_SIZE][2] = {{{10,16},{2,8},{1,6},{7,12}},{{1,2},{3,4},{5,6},{7,8}},{{1,2},{2,3},{3,4},{4,5}}};
    int pointsSize[NUMBER_OF_TESTS] = {4,4,4};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", findMinArrowShots(points[test], pointsSize[test]));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

int findMinArrowShots(int pointsVar[ARRAY_SIZE][2], int pointsSizeVar)
{
    int result = 0;

    int max = 0;
    int arrows = 0;

    int acumulation[ARRAY_SIZE][ARRAY_SIZE] = {0};
    int acumulationInSize[ARRAY_SIZE] = {0};
    int acumulationSize = 0;

    int maxArrowNo = 0;

    int cutElements[ARRAY_SIZE] = {0};

    for (int i = 0; i < pointsSizeVar; i++)
    {
        max = ((max < pointsVar[i][0]) ? pointsVar[i][0] : max);
        max = ((max < pointsVar[i][1]) ? pointsVar[i][1] : max);
    }

    for (int i = 0; i < max; i++)
    {
        int temp = 0;

        for (int j = 0; j < pointsSizeVar; j++)
        {
            if (pointsVar[j][0] <= i && i <= pointsVar[j][1])
            {
                temp++;
                acumulation[acumulationSize][acumulationInSize[acumulationSize]++] = j;
            }
        }

        maxArrowNo = ((maxArrowNo < temp) ? temp : maxArrowNo);
        acumulationSize++;
    }

    bool flag = true;

    for (int i = maxArrowNo; i >= 0; i--)
    {
        for (int j = 0; j < acumulationSize; j++)
        {
            flag = true;

            if (acumulationInSize[j] == i)
            {
                bool findInside = false;

                for (int k = 0; k < acumulationInSize[j]; k++)
                {
                    int index = acumulation[j][k];

                    if (cutElements[index] == 0)
                    {
                        cutElements[index] = 1;
                        findInside = true;
                    }
                    else
                    {
                        findInside = false;
                        break;
                    }
                }

                if (!flag)
                {
                    for (int k = 0; k < acumulationInSize[j]; k++)
                    {
                        int index = acumulation[j][k];
                        cutElements[index] = 0;
                    }
                }

                result += ((findInside) ? 1 : 0);
            }

            for (int k = 0; k < pointsSizeVar; k++)
            {
                if (cutElements[k] == 0)
                {
                    flag = false;
                    break;
                }
            }
            
            if (flag)
            {
                break;
            }
        }

        if (flag)
        {
            break;
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