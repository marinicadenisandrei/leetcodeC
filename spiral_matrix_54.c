/* Leetcode - 54. Spiral Matrix (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

bool checkIfElementIsInArray(int element, int array[ARRAY_SIZE], int array_size);
void printArrayOfIntegers(int array[ARRAY_SIZE], int arraySize);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 54. Spiral Matrix (C language) - Medium\n");

    int matrix[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE] = {{{1,2,3},{4,5,6},{7,8,9}}, {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}}};

    int array_in_test[ARRAY_SIZE] = {3, 4};
    int size_matrix_test[ARRAY_SIZE] = {3, 3};
    
    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {   

        int array_in = array_in_test[test];
        int size_matrix = size_matrix_test[test]; 
        int starter = 0;
        int flag = true;

        int output[ARRAY_SIZE] = {};
        int size_output = 0;

        while (flag)
        {
            flag = false;

            for (int i = starter; i < array_in; i++)
            {
                flag = (i == 0) ? true : flag;
                if (!checkIfElementIsInArray(matrix[test][starter][i], output, size_output))
                {
                    output[size_output] = matrix[test][starter][i];
                    size_output++;
                }
            }

            for (int i = starter + 1; i < size_matrix; i++)
            {
                flag = (i == 0) ? true : flag;

                if (!checkIfElementIsInArray(matrix[test][i][array_in - 1], output, size_output))
                {
                    output[size_output] = matrix[test][i][array_in - 1];
                    size_output++;
                }
            }

            for (int i = array_in - 2; i >= starter; i--)
            {
                flag = (i == 0) ? true : flag;

                if (!checkIfElementIsInArray(matrix[test][size_matrix - 1][i], output, size_output))
                {
                    output[size_output] = matrix[test][size_matrix - 1][i];
                    size_output++;
                }
            }

            for (int i = size_matrix - 2; i > starter; i--)
            {
                flag = (i == 0) ? true : flag;

                if (!checkIfElementIsInArray(matrix[test][i][starter], output, size_output));
                {
                    output[size_output] = matrix[test][i][starter];
                    size_output++;
                }
            }

            array_in--;
            size_matrix--;

            starter++;
        }

        green();

        printf("Test %i: ", test + 1);

        reset();

        printArrayOfIntegers(output, size_output);

        green();

        printf("Passed\n");

        reset();
    }

    return 0;
}

bool checkIfElementIsInArray(int element, int array[ARRAY_SIZE], int array_size)
{
    for (int i = 0; i < array_size; i++)
    {
        if (array[i] == element)
        {
            return true;
        }
    }

    return false;
}

void printArrayOfIntegers(int array[ARRAY_SIZE], int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        printf("%s%i%s", ((i == 0) ? "[" : ""), array[i], ((i < arraySize - 1) ? ", " : "] | "));
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