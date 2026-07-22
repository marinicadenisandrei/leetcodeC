/* Leetcode - 480. Sliding Window Median (C language) - Hard */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void reset ();
void green ();
void yellow ();
void red ();

int* medianSlidingWindow(int *numsVar, int numsSizeVar, int kVar, int *outputSizeVar);

int compare_ints(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x > y) - (x < y);
}

void sort_array(int *arr, size_t n) {
    qsort(arr, n, sizeof(int), compare_ints);
}

void printArray(int *arr, int arrSize);

int main(void)
{
    yellow();

    printf("Leetcode - 480. Sliding Window Median (C language) - ");

    red();

    printf("Hard\n");

    int nums[NUMBER_OF_TESTS][ARRAY_SIZE] = {{1,3,-1,-3,5,3,6,7},{1,2,3,4,2,3,1,4,2}};
    int numsSize[NUMBER_OF_TESTS] = {8,9};
    int k[NUMBER_OF_TESTS] = {3,3};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        int outputSize = 0;
        int *output = medianSlidingWindow(nums[test], numsSize[test], k[test], &outputSize);

        printArray(output, outputSize);

        free(output);

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

int* medianSlidingWindow(int *numsVar, int numsSizeVar, int kVar, int *outputSizeVar)
{
    int *result = malloc((numsSizeVar - kVar + 1) * sizeof(int));
    *outputSizeVar = 0;

    for (int i = 0; i < numsSizeVar - kVar + 1; i++)
    {
        int slideArray[ARRAY_SIZE] = {0};
        int slideArraySize = 0;

        for (int j = i; j < i + kVar; j++)
        {
            slideArray[slideArraySize++] = numsVar[j];
        }

        sort_array(slideArray, slideArraySize);

        int medianTemp = 0;
        int middle = slideArraySize / 2;

        if (slideArraySize % 2 == 0)
        {
            medianTemp = (slideArray[middle - 1] + slideArray[middle]) / 2;
        }
        else
        {
            medianTemp = slideArray[middle];
        }

        result[(*outputSizeVar)++] = medianTemp;
    }

    return result;
}

void printArray(int *arr, int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        printf("%s%d%s", ((i == 0) ? "[" : ""), arr[i], ((i < arrSize - 1) ? ", " : "] | "));
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