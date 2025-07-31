/* Leetcode - 349. Intersection of Two Arrays (C language) - Easy */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

int resultSize = 0;

int* intersection(int *arr1, int arr1Size, int *arr2, int arr2Size);
bool elementInArray(int *arr, int arrSize, int ele);
void printArray(int *arr, int arrSize);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 349. Intersection of Two Arrays (C language) - ");

    green();

    printf("Easy\n");

    int nums1[NUMBER_OF_TESTS][ARRAY_SIZE] = {{1,2,2,1},{4,9,5}};
    int nums1Size[NUMBER_OF_TESTS] = {4,3};

    int nums2[NUMBER_OF_TESTS][ARRAY_SIZE] = {{2,2},{9,4,9,8,4}};
    int nums2Size[NUMBER_OF_TESTS] = {2,5};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        int *result = intersection(nums1[test], nums1Size[test], nums2[test], nums2Size[test]); 
        printArray(result, resultSize);
        free(result);
        resultSize = 0;

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

void printArray(int *arr, int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        printf("%s%i%s", ((i == 0) ? "[" : ""), arr[i], ((i < arrSize - 1) ? ", " : "] | "));
    }
}

bool elementInArray(int *arr, int arrSize, int ele)
{
    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i] == ele)
        {
            return true;
        }
    }

    return false;
}

int* intersection(int *arr1, int arr1Size, int *arr2, int arr2Size)
{
    int *result = (int*)malloc((arr1Size + arr2Size) * sizeof(int));
    
    for (int i = 0; i < arr1Size; i++)
    {
        if (elementInArray(arr2, arr2Size, arr1[i]) && !elementInArray(result, resultSize, arr1[i]))
        {
            result[resultSize++] = arr1[i];
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