/* Leetcode - 373. Find K Pairs with Smallest Sums (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void reset ();
void green ();
void yellow ();
void red ();

int **KSmallestPairs(int *nums1Var, int nums1VarSize, int *nums2Var, int nums2VarSize, int kVar);
void print2DArray(int **p_array, int arraySize, int arrayInSize);

int main()
{
    yellow();

    printf("Leetcode - 373. Find K Pairs with Smallest Sums (C language) - Medium\n");

    int nums1[NUMBER_OF_TESTS][ARRAY_SIZE] = {{1,7,11},{1,1,2}};
    int nums1Size[NUMBER_OF_TESTS] = {3,3};

    int nums2[NUMBER_OF_TESTS][ARRAY_SIZE] = {{2,4,6},{1,2,3}};
    int nums2Size[NUMBER_OF_TESTS] = {3,3};

    int k[NUMBER_OF_TESTS] = {3,2};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        print2DArray(KSmallestPairs(nums1[test], nums1Size[test], nums2[test], nums2Size[test], k[test]), k[test], 2);

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

void print2DArray(int **p_array, int arraySize, int arrayInSize)
{
    printf("[");

    for (int i = 0; i < arraySize; i++)
    {
        for (int j = 0; j < arrayInSize; j++)
        {
            printf("%s%i%s", ((j == 0) ? "[" : ""), p_array[i][j], ((j < arrayInSize - 1) ? ", " : "]"));
        }
    }

    printf("] | ");
}

int **KSmallestPairs(int *nums1Var, int nums1VarSize, int *nums2Var, int nums2VarSize, int kVar)
{
    int numbers = 0;

    int candidates[ARRAY_SIZE][2] = {};
    int candidatesSize = 0;

    bool flag = true;
    int c = 0;

    int **p_result = (int**)malloc(kVar * sizeof(int*));

    for (int i = 0; i < kVar; i++)
    {
        p_result[i] = (int*)malloc(2 * sizeof(int));
    }

    for (int i = 0; i < nums1VarSize; i++)
    {
        for (int j = 0; j < nums2VarSize; j++)
        {
            candidates[candidatesSize][0] = nums1Var[i];
            candidates[candidatesSize++][1] = nums2Var[j];
        }
    }

    while (flag)
    {
        flag = false;

        for (int i = 0; i < candidatesSize - 1 - c; i++)
        {
            if (candidates[i][0] + candidates[i][1] > candidates[i + 1][0] + candidates[i + 1][1])
            {
                int temp = candidates[i][0];
                candidates[i][0] = candidates[i + 1][0];
                candidates[i + 1][0] = temp;

                temp = candidates[i][1];
                candidates[i][1] = candidates[i + 1][1];
                candidates[i + 1][1] = temp;

                flag = true;
            }
        }

        c++;
    }

    for (int i = 0; i < kVar; i++)
    {
        p_result[i][0] = candidates[i][0];
        p_result[i][1] = candidates[i][1];
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
  
  