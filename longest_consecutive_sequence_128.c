/* Leetcode - 128. Longest Consecutive Sequence (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

int longestConsecutive(int *numsVar, int numsVarSize);
void bubbleSort(int *numsVar, int numsVarSize);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 128. Longest Consecutive Sequence (C language) - Medium\n");
    
    int nums[ARRAY_SIZE][ARRAY_SIZE] = {{100,4,200,1,3,2}, {0,3,7,2,5,8,4,6,0,1}};
    int numsSize[ARRAY_SIZE] = {6,10};
    
    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();
        
        printf("%d | ", longestConsecutive(nums[test], numsSize[test]));

        green();
        
        printf("Passed\n");
    }

    reset();

    return 0;
}

void bubbleSort(int *numsVar, int numsVarSize)
{
    bool flag = true;
    
    while (flag)
    {
        flag = false;
        int counter = 0;
        
        for(int i = 0; i < numsVarSize - 1 - counter; i++)
        {
            if (numsVar[i] > numsVar[i + 1])
            {
                int temp = numsVar[i];
                numsVar[i] = numsVar[i + 1];
                numsVar[i + 1] = temp;
                
                flag = true;
            }
        }
        
        counter++;
    }
}

int longestConsecutive(int *numsVar, int numsVarSize)
{
    int consecutiveNumber = 1;
    bubbleSort(numsVar, numsVarSize);
    
    for (int i = 0; i < numsVarSize - 1; i++)
    {
        if (numsVar[i + 1] - numsVar[i] == 1)
        {
            consecutiveNumber++;
        }
        else if (numsVar[i + 1] - numsVar[i] == 0)
        {
            continue;
        }
        else
        {
            break;
        }
    }
    
    return consecutiveNumber;
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