/* Leetcode - 149. Max Points on a Line (C language) - Hard*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

int maxPoints(int pointVar[ARRAY_SIZE][2], int pointVarSize);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 149. Max Points on a Line (C language) - ");

    red();

    printf("Hard\n");
    
    int points[ARRAY_SIZE][ARRAY_SIZE][2] = {{{1,1},{2,2},{3,3}},{{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}}};
    int pointsSize[ARRAY_SIZE] = {3,6};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", maxPoints(points[test], pointsSize[test]));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

int maxPoints(int pointVar[ARRAY_SIZE][2], int pointVarSize)
{
    bool flag = true;
    int maxVar = 0;
    int counter = 0;

    int acumulation[ARRAY_SIZE] = {0};
    int acumulationSize = 0;

    while (flag)
    {
        flag = false;
        int counter = 0;

        for (int i = 0; i < pointVarSize - 1 - counter; i++)
        {
            if (pointVar[i][0] > pointVar[i + 1][0])
            {
                int temp = pointVar[i][0];
                pointVar[i][0] = pointVar[i + 1][0];
                pointVar[i + 1][0] = temp;

                temp = pointVar[i][1];
                pointVar[i][1] = pointVar[i + 1][1];
                pointVar[i + 1][1] = temp;
                
                flag = true;
            }
        }

        counter++;
    }

    for (int i = 1; i < pointVarSize; i++)
    {
        if (abs(pointVar[i - 1][0] - pointVar[i][0]) == 1 || abs(pointVar[i - 1][1] - pointVar[i][1]) == 1)
        {
            counter++;
        }
        else
        {
            maxVar = ((maxVar < counter) ? counter + 1: maxVar);
        }
    }
    
    maxVar = ((maxVar == 0) ? counter : maxVar);
    
    return maxVar;
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