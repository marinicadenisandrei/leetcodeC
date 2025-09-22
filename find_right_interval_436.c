/* Leetcode - 436. Find Right Interval (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

void reset ();
void green ();
void yellow ();
void red ();

int* findRightInterval(int intervalsVar[ARRAY_SIZE][2], int intervalsSizeVar);
void printArray(int* arr, int arrSize);

int main()
{
    yellow();

    printf("Leetcode - 436. Find Right Interval (C language) - Medium\n");

    int intervals[NUMBER_OF_TESTS][ARRAY_SIZE][2] = {{{1,2}},{{3,4},{2,3},{1,2}},{{1,4},{2,3},{3,4}}};
    int intervalsSize[NUMBER_OF_TESTS] = {1,3,3};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();
        
        printf("Test %i: ", test + 1);

        reset();

        int* output = findRightInterval(intervals[test], intervalsSize[test]);
        printArray(output, intervalsSize[test]);        
        free(output);

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

void printArray(int* arr, int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        printf("%s%i%s", ((i == 0) ? "[" : ""), arr[i], ((i < arrSize - 1) ? ", " : "] | "));   
    }
}

int* findRightInterval(int intervalsVar[ARRAY_SIZE][2], int intervalsSizeVar)
{
    int* result = (int*)malloc(intervalsSizeVar * sizeof(int));
    int resultSize = 0;

    for (int i = 0; i < intervalsSizeVar; i++)
    {
        bool flag = false;

        for (int j = 0; j < intervalsSizeVar; j++)
        {
            if (i != j && intervalsVar[i][1] == intervalsVar[j][0])
            {
                result[resultSize++] = j;
                flag = true;
                break;
            }
        }

        if (!flag)
        {
            result[resultSize++] = -1;
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

