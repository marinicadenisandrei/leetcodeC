/* Leetcode - 23. Merge k Sorted Lists (C language) - Hard */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define NUMBER_OF_TESTS 3
#define ARRAY_SIZE 50

int arrayOfArraysInSingleArray(int bigArray[ARRAY_SIZE][ARRAY_SIZE], int sizeBigArray, int singleArray[ARRAY_SIZE], int sizeSingleArray);
void sortArray(int *array, int sizeArray);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 23. Merge k Sorted Lists (C language) - ");

    red();

    printf("Hard\n");

    int lists[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE] = {{{1,4,5}, {1,3,4}, {2,6}}, {}, {{}}};
    int sizeLists[NUMBER_OF_TESTS] = {3, 0, 0};

    for (int test = 0; test < 3; test++)
    {
        int oneArrayValues[ARRAY_SIZE] = {};
        int sizeOneArrayValues = 0;

        sizeOneArrayValues = arrayOfArraysInSingleArray(lists[test], sizeLists[test], oneArrayValues, sizeOneArrayValues);
        sortArray(oneArrayValues, sizeOneArrayValues);

        green();

        printf("Test %i: ", test + 1);

        reset();

        for (int i = 0; i < sizeOneArrayValues; i++)
        {
            printf("%s%i%s", ((i == 0) ? "[" : ","), oneArrayValues[i], ((i == sizeOneArrayValues - 1) ? "] | " : ""));
        }

        printf("%s", (sizeLists[test] == 0) ? "[] | " : "");

        green();
        
        printf("Passed\n");

        reset();
    }
    
    return 0;
}

int arrayOfArraysInSingleArray(int bigArray[ARRAY_SIZE][ARRAY_SIZE], int sizeBigArray, int singleArray[ARRAY_SIZE], int sizeSingleArray)
{
    for (int i = 0; i < sizeBigArray; i++)
    {
        for (int j = 0; j < sizeof(bigArray[i])/sizeof(bigArray[i][0]); j++)
        {
            if (bigArray[i][j] != 0)
            {
                singleArray[sizeSingleArray] = bigArray[i][j];
                sizeSingleArray++;
            }
        }   
    }

    return sizeSingleArray;
}

void sortArray(int* array, int sizeArray)
{
    int temp = 0;
    bool flag = true;
    int *ptr;

    while (flag)
    {
        flag = false;
        for (ptr = array + 1; ptr < array + sizeArray; ptr++)
        {
            if (*(ptr - 1) > *ptr)
            {
                temp = *(ptr - 1);
                *(ptr - 1) = *ptr;
                *ptr = temp;
                flag = true;
            }
        }
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


