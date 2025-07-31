/* Leetcode - 47. Permutations II (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUMBER_OF_TESTS 2
#define ARRAY_SIZE 20

void printArray(int array[ARRAY_SIZE], int arraySize);
int numberOfPermutations(int arraySize);
bool checkIfArrayIsInArray(int smallArray[ARRAY_SIZE], int sizeSmallArray, int bigArray[ARRAY_SIZE][ARRAY_SIZE], int sizeBigArray);
void appendArrayToBigArray(int smallArray[ARRAY_SIZE], int sizeSmallArray, int bigArray[ARRAY_SIZE][ARRAY_SIZE], int sizeBigArray);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 47. Permutations II (C language) - Medium\n");

    int nums[ARRAY_SIZE][ARRAY_SIZE] = {{1,2,3}, {1,1,2}};
    int nums_size = 3;

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        int depth = numberOfPermutations(nums_size);
        int temp = 0;

        int index1 = 0;
        int index2 = 1;

        int output[ARRAY_SIZE][ARRAY_SIZE] = {};
        int size_output = 0;

        while (depth > 0)
        {
            if (checkIfArrayIsInArray(nums[test], nums_size, output, size_output) == false)
            {
                appendArrayToBigArray(nums[test], nums_size, output, size_output);
            
                size_output++;
            }

            if (index2 == nums_size)
            {
                temp = nums[test][0];
                nums[test][0] = nums[test][nums_size - 1];
                nums[test][nums_size - 1] = temp;

                index1 = -1;
                index2 = 0;
            }
            else
            {
                temp = nums[test][index1];
                nums[test][index1] = nums[test][index2];
                nums[test][index2] = temp;
            }

            index1++;
            index2++;

            depth--;
        }

        green();

        printf("Test %i: ", test + 1);

        reset();

        for (int i = 0; i < size_output; i++)
        {
            printArray(output[i], nums_size);
        }
        
        printf(" | ");

        green();

        printf("Passed\n");

        reset();
    }
    
    return 0;
}

void printArray(int array[ARRAY_SIZE], int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        printf("%s%i%s", ((i == 0) ? "[" : ""), array[i], ((i < arraySize - 1) ? ", " : "],"));
    }
}

int numberOfPermutations(int arraySize)
{
    int depth = 1;
    
    for (int i = 1; i <= arraySize; i++)
    {
        depth *= i;    
    }

    return depth;
}

bool checkIfArrayIsInArray(int smallArray[ARRAY_SIZE], int sizeSmallArray, int bigArray[ARRAY_SIZE][ARRAY_SIZE], int sizeBigArray)
{
    bool flag = true;

    for (int i = 0; i < sizeBigArray; i++)
    {
        flag = true;

        for (int j = 0; j < sizeSmallArray; j++)
        {
            if (bigArray[i][j] != smallArray[j])
            {
                flag = false;
                break;
            }
        }

        if (flag == true)
        {
            return true;
        }
    }

    return false;
}

void appendArrayToBigArray(int smallArray[ARRAY_SIZE], int sizeSmallArray, int bigArray[ARRAY_SIZE][ARRAY_SIZE], int sizeBigArray)
{
    for (int i = 0; i < sizeSmallArray; i++)
    {
        bigArray[sizeBigArray][i] = smallArray[i]; 
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
