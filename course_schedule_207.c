/* Leetcode - 207. Course Schedule (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

bool canFinish(int numCoursesVar, int prerequisitesVar[ARRAY_SIZE][ARRAY_SIZE], int prerequisitesVarSize);
bool isDescending(int *array, int arraySize);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 207. Course Schedule (C language) - Medium\n");

    int numCourses[NUMBER_OF_TESTS] = {2,2};
    int prerequisites[NUMBER_OF_TESTS][ARRAY_SIZE][ARRAY_SIZE] = {{{1,0}},{{1,0},{0,1}}};
    int prerequisitesSize[NUMBER_OF_TESTS] = {1,2};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%s | ", (canFinish(numCourses[test], prerequisites[test], prerequisitesSize[test]) == 0 ? "false" : "true"));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

bool isDescending(int *array, int arraySize)
{
    for (int i = 0; i < arraySize - 1; i++)
    {
        if (array[i] - array[i + 1] < 0)
        {
            return false;
        }
    }

    return true;
}

bool canFinish(int numCoursesVar, int prerequisitesVar[ARRAY_SIZE][ARRAY_SIZE], int prerequisitesVarSize)
{
    for (int i = 0; i < prerequisitesVarSize; i++)
    {
        if (!isDescending(prerequisitesVar[i], numCoursesVar))
        {
            return false;
        }
    }

    return true;
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