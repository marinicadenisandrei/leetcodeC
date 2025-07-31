/* Leetcode - 368. Largest Divisible Subset (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

int p_outputSize = 0;

void reset ();
void green ();
void yellow ();
void red ();

int *LargestDivisibleSubset(int *p_numsVar, int p_numsVarSize);
void printArray(int *p_array, int p_arraySize);

int main()
{
    yellow();

    printf("Leetcode - 368. Largest Divisible Subset (C language) - Medium\n");

    int nums[NUMBER_OF_TESTS][ARRAY_SIZE] = {{1,2,3},{1,2,4,8}};
    int numsSize[NUMBER_OF_TESTS] = {3,4};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        int *p_output = LargestDivisibleSubset(nums[test], numsSize[test]);
        printArray(p_output, p_outputSize);

        free(p_output);
        p_outputSize = 0;

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

void printArray(int *p_array, int p_arraySize)
{
    for (int i = 0; i < p_arraySize; i++)
    {
        printf("%s%i%s", ((i == 0) ? "[" : ""), p_array[i], ((i < p_arraySize - 1) ? ", " : "] | "));   
    }
}

int *LargestDivisibleSubset(int *p_numsVar, int p_numsVarSize)
{
    int *p_result = (int*)malloc(ARRAY_SIZE * sizeof(int));

    for (int i = 0; i < p_numsVarSize; i++)
    {
        int temp[ARRAY_SIZE] = {};
        int tempSize = 0;

        temp[tempSize++] = p_numsVar[i];

        for (int j = i + 1; j < p_numsVarSize; j++)
        {
            if (p_numsVar[j] % temp[tempSize - 1] == 0)
            {
                temp[tempSize++] = p_numsVar[j];
            }
        }
        
        if (p_outputSize < tempSize)
        {
            for (int j = 0; j < tempSize; j++)
            {
                p_result[j] = temp[j];
            }
            
            p_outputSize = tempSize;
        }
    }


    return p_result;
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