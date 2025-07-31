#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void printArray(int *array, int arraySize);
void sortColors(int *array, int arraySize);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 75. Sort Colors (C language) - Medium\n");

    int numsTest[ARRAY_SIZE][ARRAY_SIZE] = {{2,0,2,1,1,0}, {2,0,1}}; 
    int sizeNumsTest[ARRAY_SIZE] = {6,3} ;

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        sortColors(numsTest[test], sizeNumsTest[test]);

        green();

        printf("Passed\n");
    }
    
    reset();

    return 0;
}

void sortColors(int *array, int arraySize)
{   
    bool flag = true;
    int counter = 0;

    while (flag)
    {
        flag = false;

        for (int i = 0; i < arraySize - 1 - counter; i++)
        {
            if (array[i] > array[i + 1])
            {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;

                flag = true;
            }
        }

        counter++;
    }

    printArray(array, arraySize);
}

void printArray(int *array, int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        printf("%s%i%s", ((i == 0) ? "[" : ""), *(array + i), ((i < arraySize - 1) ? ", " : "] | "));
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