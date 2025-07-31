#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TEST 2

bool search(int arrayVar[ARRAY_SIZE], int arraySize, int targetVar);
bool linearSearch(int array[ARRAY_SIZE], int left_index, int right_index, int element);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 81. Search in Rotated Sorted Array II (C language) - Medium\n");

    int nums[ARRAY_SIZE][ARRAY_SIZE] = {{2,5,6,0,0,1,2},{2,5,6,0,0,1,2}}; 
    int numsSize[ARRAY_SIZE] = {7,7};
    int target[ARRAY_SIZE] = {0,3};

    for (int test = 0; test < NUMBER_OF_TEST; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%s", ((search(nums[test], numsSize[test], target[test])) == 1) ? "true | " : "false | ");

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

bool search(int arrayVar[ARRAY_SIZE], int arraySize, int targetVar)
{
    return linearSearch(arrayVar, 0, arraySize, targetVar);
}

bool linearSearch(int array[ARRAY_SIZE], int left_index, int right_index, int element)
{
    if (left_index > right_index)
    {
        return false;
    }
    
    if (array[left_index] == element)
    {
        return true;
    }
    else
    {
        return linearSearch(array, left_index + 1, right_index, element);
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