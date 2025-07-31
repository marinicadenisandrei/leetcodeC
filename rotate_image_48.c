/* Leetcode - 48. Rotate Image (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void printArray(int array[ARRAY_SIZE], int sizeArray);
void reverseImage(int array1[ARRAY_SIZE][ARRAY_SIZE], int sizeArray1 , int array2[ARRAY_SIZE][ARRAY_SIZE]);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 48. Rotate Image (C language) - Medium\n");

    int matrix[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE] = {{{1,2,3}, {4,5,6}, {7,8,9}}, {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}}};
    unsigned matrixSize[ARRAY_SIZE] = {3, 4};

    for (unsigned test = 0; test < NUMBER_OF_TESTS; test++)
    {
        int output[ARRAY_SIZE][ARRAY_SIZE] = {};

        reverseImage(matrix[test], matrixSize[test], output);

        green();

        printf("Test %i: ", test + 1);

        reset();

        for (unsigned i = 0; i < matrixSize[test]; i++)
        {
            printArray(output[i], matrixSize[test]);
            printf("%s", ((i <= matrixSize[test] - 2) ? ", " : " | "));
        }

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
        printf("%s%i%s", ((i == 0) ? "[" : ""), array[i], ((i < sizeArray - 1) ? ", " : "]"));
    }
}

void reverseImage(int array1[ARRAY_SIZE][ARRAY_SIZE], int sizeArray1 , int array2[ARRAY_SIZE][ARRAY_SIZE])
{
    unsigned indexTemp = 0;

    for (unsigned i = 0; i < sizeArray1; i++)
    {
        indexTemp = 0;
        
        for (int j = sizeArray1 - 1; j >= 0; j--)
        {
            array2[i][indexTemp] = array1[j][i];
            indexTemp++;
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