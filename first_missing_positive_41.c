/* Leetcode - 41. First Missing Positive (C language) - Hard */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUMBER_OF_TESTS 3
#define ARRAY_SIZE 20

void printArray(int array[ARRAY_SIZE], int sizeArray);
void sortArray(int array[ARRAY_SIZE], int sizeArray);
int returnMissingPositiveFromArray(int array[ARRAY_SIZE], int sizeArray);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 41. First Missing Positive (C language) - ");

    red();

    printf("Hard\n");

    int nums[ARRAY_SIZE][ARRAY_SIZE] = {{1,2,0}, {3,4,-1,1}, {7,8,9,11,12}};
    int sizeNums[ARRAY_SIZE] = {3,4,5};
    
    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        sortArray(nums[test], sizeNums[test]);
        printf("%i | ", returnMissingPositiveFromArray(nums[test], sizeNums[test]));

        green();

        printf("Passed\n");

        reset();
    }
    
    return 0;
}

void printArray(int array[ARRAY_SIZE], int sizeArray)
{
    for (int i = 0; i < sizeArray; i++)
    {
        printf("%s%i%s", (i == 0) ? "[" : "", array[i], (i < sizeArray - 1) ? ", " : "]");
    }
}

void sortArray(int array[ARRAY_SIZE], int sizeArray)
{
    int temp = 0;
    int flag = true;

    while (flag)
    {
        flag = false;

        for (int i = 1; i < sizeArray; i++)
        {
            if (array[i-1] > array[i])
            {
                temp = array[i-1]; 
                array[i-1] = array[i];
                array[i] = temp;

                flag = true;
                break;
            }
        }
    }
}

int returnMissingPositiveFromArray(int array[ARRAY_SIZE], int sizeArray)
{   
    int result = 0;

    for (int i = 0; i < sizeArray; i++)
    {
        if (i > 0)
        {
            if (array[i] - 1 > 1)
            {
                return 1;
            }
            
            for (int j = i + 1; j < sizeArray; j++)
            {
                if (array[j] - array[j-1] > 1)
                {
                    return j;
                }
            }
        }
    }
    
    return array[sizeArray-1] + 1;
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