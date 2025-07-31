/* Leetcode - 350. Intersection of Two Arrays II (C language) - Easy */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

int resultSize = 0;

void reset ();
void green ();
void yellow ();
void red ();

void printArray(int *array, int arraySize);
int* intersect(int *nums1Var, int *nums2Var, int nums1VarSize, int nums2VarSize);
int occInArray(int *array, int arraySize, int ele);

int main()
{
    yellow();

    printf("Leetcode - 350. Intersection of Two Arrays II (C language) - ");

    green();

    printf("Easy\n");

    int nums1[NUMBER_OF_TESTS][ARRAY_SIZE] = {{1,2,2,1},{4,9,5}};
    int nums2[NUMBER_OF_TESTS][ARRAY_SIZE] = {{2,2},{9,4,9,8,4}};

    int nums1Size[NUMBER_OF_TESTS] = {4,3};
    int nums2Size[NUMBER_OF_TESTS] = {2,5};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        int *output = intersect(nums1[test], nums2[test], nums1Size[test], nums2Size[test]);

        reset();

        printArray(output, resultSize);

        resultSize = 0;
        free(output);

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

int occInArray(int *array, int arraySize, int ele)
{
    int counter = 0;

    for (int i = 0; i < arraySize; i++)
    {
        if (array[i] == ele)
        {
            counter++;
        }
    }
    
    return counter;
}

int* intersect(int *nums1Var, int *nums2Var, int nums1VarSize, int nums2VarSize)
{   
    int noDuplArr[ARRAY_SIZE] = {};
    int noDuplArrSize = 0;

    int *result = (int *)malloc(ARRAY_SIZE * sizeof(int));

    for (int i = 0; i < nums1VarSize; i++)
    {
        if (occInArray(noDuplArr, noDuplArrSize, nums1Var[i]) == 0)
        {
            noDuplArr[noDuplArrSize++] = nums1Var[i];
        }
    }
    
    for (int i = 0; i < nums2VarSize; i++)
    {
        if (occInArray(noDuplArr, noDuplArrSize, nums2Var[i]) == 0)
        {
            noDuplArr[noDuplArrSize++] = nums2Var[i];
        }
    }

    for (int i = 0; i < noDuplArrSize; i++)
    {
        int occ1 = occInArray(nums1Var, nums1VarSize, noDuplArr[i]);
        int occ2 = occInArray(nums2Var, nums2VarSize, noDuplArr[i]);

        if (occ1 > 0 && occ2 > 0)
        {
            for (int j = 0; j < ((occ1 > occ2) ? occ2 : occ1); j++)
            {
                result[resultSize++] = noDuplArr[i]; 
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