/* Leetcode - 83. Move Zeroes (C language) - Easy */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void moveZeroes(int *numsVar, int numsVarSize);
void printArray(int *array, int arraySize);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 83. Move Zeroes (C language) - ");

    green();

    printf("Easy\n");

    int nums[NUMBER_OF_TESTS][ARRAY_SIZE] = {{0,1,0,3,12},{0}};
    int numsSize[NUMBER_OF_TESTS] = {5,1};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        moveZeroes(nums[test], numsSize[test]);
        printArray(nums[test], numsSize[test]);

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

void moveZeroes(int *numsVar, int numsVarSize)
{
    bool flag = true;
    int c = 0;

    while (flag)
    {
        flag = false;

        for (int i = 0; i < numsVarSize - c; i++)
        {
            if (numsVar[i] == 0)
            {
                for (int j = i; j < numsVarSize - 1 - c; j++)
                {
                    int temp = numsVar[j];
                    numsVar[j] = numsVar[j + 1];
                    numsVar[j + 1] = temp;
                }
                
                flag = true;
                c++;
                break; 
            }
        }
    }
}

void printArray(int *array, int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        printf("%s%i%s", ((i == 0) ? "[" : ""), array[i], ((i < arraySize - 1) ? ", " : "] | "));
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