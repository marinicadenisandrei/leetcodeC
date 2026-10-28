/* Leetcode - 496. Next Greater Element I (c language) - Easy */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize);
void printArray(int* arr, int arrSize);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 496. Next Greater Element I (c language) - ");

    green();

    printf("Easy\n");

    int nums1[NUMBER_OF_TESTS][ARRAY_SIZE] = {{4,1,2},{2,4}};
    int nums2[NUMBER_OF_TESTS][ARRAY_SIZE] = {{1,3,4,2},{1,2,3,4}};

    int nums1Size[NUMBER_OF_TESTS] = {3,2};
    int nums2Size[NUMBER_OF_TESTS] = {4,4};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        printf("Test %i: ", test + 1);

        reset();

        int resultSize = 0;
        int* result = nextGreaterElement(nums1[test], nums1Size[test], nums2[test], nums2Size[test], &resultSize);

        printArray(result, resultSize);
        free(result);

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
    int* result = malloc(nums1Size * sizeof(int));
    *returnSize = nums1Size;

    for (int i = 0; i < nums1Size; i++)
    {
        int next = -1;
        int found = 0;

        for (int j = 0; j < nums2Size; j++)
        {
            if (nums2[j] == nums1[i])
                found = 1;
            else if (found && nums2[j] > nums1[i])
            {
                next = nums2[j];
                break;
            }
        }
        result[i] = next;
    }
    return result;
}

void printArray(int* arr, int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        printf("%s%i%s", ((i == 0) ? "[" : ", "), arr[i], ((i == arrSize - 1) ? "] | " : ""));   
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