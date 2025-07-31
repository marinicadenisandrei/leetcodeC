/* Leetcode - 42. Trapping Rain Water (C language) - Hard */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void printArray(int array[ARRAY_SIZE], int sizeArray);
int maxElementFromArray(int array[ARRAY_SIZE], int sizeArray);
int boundaryLeft(int array[ARRAY_SIZE], int sizeArray);
int boundaryRight(int array[ARRAY_SIZE], int sizeArray);
int findZerosInInterval(int array[ARRAY_SIZE], int sizeArray, int bLeft, int bRight);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 42. Trapping Rain Water (C language) - ");
    
    red();

    printf("Hard\n");

    int height[ARRAY_SIZE][ARRAY_SIZE] = {{0,1,0,2,1,0,1,3,2,1,2,1}, {4,2,0,3,2,5}};
    int sizeHeitght[ARRAY_SIZE] = {12, 6};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        int maxElement = maxElementFromArray(height[test], sizeHeitght[test]);
        int matrix[ARRAY_SIZE][ARRAY_SIZE] = {};

        int counter = 0;

        for (int i = 0; i < maxElement; i++)
        {
            for (int j = 0; j < sizeHeitght[test]; j++)
            {
                matrix[i][j] = (height[test][j] - i > 0) ? 1 : 0;
            }
        }

        for (int i = maxElement - 1; i >= 0; i--)
        {
            int bLeft = boundaryLeft(matrix[i], sizeHeitght[test]);
            int bRight = boundaryRight(matrix[i], sizeHeitght[test]);

            if (bLeft != bRight)
            {
                counter += findZerosInInterval(matrix[i], sizeHeitght[test], bLeft, bRight);
            }
        }

        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", counter);

        green();

        printf("Passed\n");

        reset();
    }
    
    return 0;
}

int maxElementFromArray(int array[ARRAY_SIZE], int sizeArray)
{
    int *parray = array;
    int max = 0;

    for (int i = 0; i < sizeArray; i++)
    {
        max = (max < *(array + i)) ? *(array + i) : max;
    }

    return max;
}

void printArray(int array[ARRAY_SIZE], int sizeArray)
{
    for (int i = 0; i < sizeArray; i++)
    {
        printf("%s%i%s", (i == 0) ? "[" : "", array[i], (i < sizeArray - 1) ? ", " : "]");
    }
}

int boundaryLeft(int array[ARRAY_SIZE], int sizeArray)
{
    for (int i = 0; i < sizeArray; i++)
    {
        if (array[i] != 0)
        {
            return i;
        }
    }
}

int boundaryRight(int array[ARRAY_SIZE], int sizeArray)
{
    for (int i = sizeArray - 1; i >= 0; i--)
    {
        if (array[i] != 0)
        {
            return i;
        }
    }
}

int findZerosInInterval(int array[ARRAY_SIZE], int sizeArray, int bLeft, int bRight)
{
    int counter = 0;

    for (int i = bLeft; i <= bRight; i++)
    {
        if (array[i] == 0)
        {
            counter++;
        }
    }

    return counter;
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