/* Leetcode - 307. Range Sum Query - Mutable (C language) - Medium */

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

void update(NumArray *obj, int index, int x)
{
    obj->array[index] = x;
}

int main()
{
    yellow();

    printf("Leetcode - 307. Range Sum Query - Mutable (C language) - Medium\n");

    int nums[] = {1, 3, 5};
    int size = sizeof(nums) / sizeof(nums[0]);

    green();

    printf("Test 1: ");

    reset();

    NumArray* numArray = createNumArray(nums, size);
    printf("%i ", numArraySumRange(numArray, 0, 2));
    update(numArray, 1, 2);
    printf("%i | ", numArraySumRange(numArray, 0, 2));

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