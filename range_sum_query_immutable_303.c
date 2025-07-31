/* Leetcode - 303. Range Sum Query - Immutable (C language) - Easy */

#include <stdio.h>
#include <stdlib.h>

void reset ();
void green ();
void yellow ();
void red ();

typedef struct {
    int* array;  
    int size;    
} NumArray;

NumArray* createNumArray(int* nums, int size) {
    NumArray* numArray = (NumArray*)malloc(sizeof(NumArray));
    numArray->size = size;
    numArray->array = (int*)malloc(sizeof(int) * size);

    for (int i = 0; i < numArray->size; i++)
    {
        numArray->array[i] = nums[i];
    }

    return numArray;
}

int numArraySumRange(NumArray* obj, int left, int right) {
    int sumVar = 0;

    for (int i = left; i <= right; i++)
    {
        sumVar += obj->array[i];
    }

    return sumVar;
}

int main()
{
    yellow();

    printf("Leetcode - 303. Range Sum Query - Immutable (C language) - ");

    green();

    printf("Easy\n");

    int nums[] = {-2, 0, 3, -5, 2, -1};
    int size = sizeof(nums) / sizeof(nums[0]);

    printf("Test 1: ");

    reset();

    NumArray* numArray = createNumArray(nums, size);
    printf("%i ", numArraySumRange(numArray, 0, 2));
    printf("%i ", numArraySumRange(numArray, 2, 5));
    printf("%i | ", numArraySumRange(numArray, 0, 5));

    green();

    printf("Passed\n");

    reset();

    return 0;
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