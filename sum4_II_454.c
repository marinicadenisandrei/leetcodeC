/* Leetcode - 454. 4Sum II (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void reset ();
void green ();
void yellow ();
void red ();

int fourSumCount(int* nums1Var, int nums1SizeVar, int* nums2Var, int nums2SizeVar, int* nums3Var, int nums3SizeVar, int* nums4Var, int nums4SizeVar);

int main()
{
    yellow();

    printf("Leetcode - 454. 4Sum II (C language) - Medium\n");

    int nums1[NUMBER_OF_TESTS][ARRAY_SIZE] = {{1,2},{0}};
    int nums1Size[NUMBER_OF_TESTS] = {2,1};

    int nums2[NUMBER_OF_TESTS][ARRAY_SIZE] = {{-2,-1},{0}};
    int nums2Size[NUMBER_OF_TESTS] = {2,1};

    int nums3[NUMBER_OF_TESTS][ARRAY_SIZE] = {{-1,-2},{0}};
    int nums3Size[NUMBER_OF_TESTS] = {2,1};
    
    int nums4[NUMBER_OF_TESTS][ARRAY_SIZE] = {{0,2},{0}};
    int nums4Size[NUMBER_OF_TESTS] = {2,1};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", fourSumCount(nums1[test], nums1Size[test], nums2[test], nums2Size[test], nums3[test], nums3Size[test], nums4[test], nums4Size[test]));

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

int fourSumCount(int* nums1Var, int nums1SizeVar, int* nums2Var, int nums2SizeVar, int* nums3Var, int nums3SizeVar, int* nums4Var, int nums4SizeVar)
{
    int firstSums[ARRAY_SIZE] = {0};
    int firstSumsSize = 0;

    int secondSums[ARRAY_SIZE] = {0};
    int secondSumsSize = 0;

    int result = 0;

    for (int i = 0; i < nums1SizeVar; i++)
    {
        for (int j = 0; j < nums2SizeVar; j++)
        {
            firstSums[firstSumsSize++] = nums1Var[i] + nums2Var[j];
        }
    }

    for (int i = 0; i < nums3SizeVar; i++)
    {
        for (int j = 0; j < nums4SizeVar; j++)
        {
            secondSums[secondSumsSize++] = nums3Var[i] + nums4Var[j];
        }
    }
    
    for (int i = 0; i < firstSumsSize; i++)
    {
        for (int j = 0; j < secondSumsSize; j++)
        {
            if (firstSums[i] + secondSums[j] == 0)
            {
                result++;
            }
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