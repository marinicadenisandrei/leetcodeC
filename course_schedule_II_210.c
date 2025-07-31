/* Leetcode - 210. Course Schedule II (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define SUBARRAY_SIZE 2
#define NUMBER_OF_TESTS 3

int outputSize = 2;

int* findOrder(int numCoursesVar, int prerequisitesVar[ARRAY_SIZE][SUBARRAY_SIZE]);
void printArray(int *array, int arraySize);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 210. Course Schedule II (C language) - Medium\n");

    int numCourses[ARRAY_SIZE] = {2,4,1};
    int prerequisites[NUMBER_OF_TESTS][ARRAY_SIZE][SUBARRAY_SIZE] = {{{1,0}},{{1,0},{2,0},{3,1},{3,2}},{}};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        int *result;
        result = (int*)malloc(ARRAY_SIZE * sizeof(int));
        result = findOrder(numCourses[test], prerequisites[test]);
        printArray(result, outputSize);

        free(result);
        outputSize = 2;

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

void printArray(int *array, int arraySize)
{
    if (outputSize == 0)
    {
        printf("[] | ");
        return;
    }
    
    for (int i = 0; i < arraySize; i++)
    {
        printf("%s%i%s", ((i == 0) ? "[" : ""), array[i], ((i < arraySize - 1) ? ", " : "] | "));
    }
}

int* findOrder(int numCoursesVar, int prerequisitesVar[ARRAY_SIZE][SUBARRAY_SIZE])
{
    int *output;
    output = (int*)malloc(ARRAY_SIZE * sizeof(int));

    if (numCoursesVar == 1)
    {
        outputSize = 0;
        return output;
    }

    output[0] = prerequisitesVar[0][1];
    output[1] = prerequisitesVar[0][0];

    for (int i = 1; i < numCoursesVar; i++)
    {
        bool flag = false;

        for (int j = 0; j < outputSize; j++)
        {
            if (output[j] == prerequisitesVar[i][1])
            {
                flag = true;
                break;
            }
        }

        if (!flag)
        {
            output[outputSize++] = prerequisitesVar[i][1];
        }
            
        flag = false;

        for (int j = 0; j < outputSize; j++)
        {
            if (output[j] == prerequisitesVar[i][0])
            {
                flag = true;
                break;
            }
        }
        
        if (!flag)
        {
            output[outputSize++] = prerequisitesVar[i][0];
        }
    }
    
    return output;
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