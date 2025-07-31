/* Leetcode - 324. Wiggle Sort II (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void wiggleSort(int *numsVar, int numsVarSize);
void printArray(int *array, int arraySize);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 324. Wiggle Sort II (C language) - Medium\n");

    int nums[NUMBER_OF_TESTS][ARRAY_SIZE] = {{1,5,1,1,6,4},{1,3,2,2,3,1}};
    int numsSize[NUMBER_OF_TESTS] = {6,6};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        wiggleSort(nums[test], numsSize[test]);
        printArray(nums[test], numsSize[test]);

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

void printArray(int *array, int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        printf("%s%i%s", ((i == 0) ? "[" : ""), array[i], ((i < arraySize - 1) ? ", " : "] | "));
    }
}

void wiggleSort(int *numsVar, int numsVarSize)
{
    bool flag = true;
    int c = 0;

    int *p = (int*)malloc(numsVarSize * sizeof(int));
    int p_size = 0;

    while (flag)
    {
        flag = false;

        for (int i = 0; i < numsVarSize - 1 - c; i++)
        {
            if (numsVar[i] > numsVar[i + 1])
            {
                int temp = numsVar[i];
                numsVar[i] = numsVar[i + 1];
                numsVar[i + 1] = temp;

                flag = true;
            }
            
        }
        
        c++;
    }
    
    for (int i = 0; i < numsVarSize / 2; i++)
    {
        p[p_size++] = numsVar[i];
        p[p_size++] = numsVar[(numsVarSize / 2) + i];
    }

    for (int i = 0; i < numsVarSize; i++)
    {
        numsVar[i] = p[i];
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
