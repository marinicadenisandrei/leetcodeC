/* Leetcode - 80. Remove Duplicates from Sorted Array II (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

int *removeDuplicates(int nums[ARRAY_SIZE], int *numsSize);
void printArray(const int nums[ARRAY_SIZE], int numsSize);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 80. Remove Duplicates from Sorted Array II (C language) - Medium\n");

    int nums[ARRAY_SIZE][ARRAY_SIZE] = {{1,1,1,2,2,3},{0,0,1,1,1,1,2,3,3}};
    int numsSize[ARRAY_SIZE] = {6,9};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        int *output = {NULL};

        output = removeDuplicates(nums[test], &numsSize[test]);

        green();

        printf("Test %i: ", test + 1);

        reset();

        printArray(output, numsSize[test]);

        green();

        printf("Passed\n");

        free(output);
    }

    reset();
    
    return 0;
}

int *removeDuplicates(int nums[ARRAY_SIZE], int *numsSize)
{
    int *ptr = {NULL};
    ptr = (int*)malloc(ARRAY_SIZE * sizeof(int));
    int ptrSize = 0;
    int occurence = 0;

    for (int i = 1; i <= *numsSize; i++)
    {
        if (nums[i-1] == nums[i])
        {
            occurence++;
        }
        else
        {
            if (occurence == 0)
            {
                *(ptr + ptrSize) = nums[i - 1];
                ptrSize++;
                
            }
            else if (occurence > 0)
            {
                *(ptr + ptrSize) = nums[i - 1];
                *(ptr + ptrSize + 1) = nums[i - 1];

                ptrSize += 2;
            }
            
            occurence = 0;
        }
    }

    *numsSize = ptrSize;

    return ptr;
}

void printArray(const int nums[ARRAY_SIZE], int numsSize)
{
    for (int i = 0; i < numsSize; i++)
    {
        printf("%s%i%s", ((i == 0) ? "[" : ""), nums[i], ((i < numsSize - 1) ? ", " : "] | "));
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