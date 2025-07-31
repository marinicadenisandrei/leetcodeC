#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_TESTS 2
#define ARRAY_SIZE 26
#define IN_SIZE 3

int resultSize = 0;

int** getSkyline(int buildingsVar[ARRAY_SIZE][ARRAY_SIZE], int buildingsVarSize);
void print2DArray(int **array, int arraySize, int arrayInSize);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 218. The Skyline Problem (C language) - ");

    red();

    printf("Hard\n");

    int buildings[NUMBER_OF_TESTS][ARRAY_SIZE][ARRAY_SIZE] = {{{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}},{{0,2,3},{2,5,3}}};
    int buildingsSize[NUMBER_OF_TESTS] = {5,2};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    { 
        int **output = (int **)malloc(ARRAY_SIZE * sizeof(int *)); 

        for (int i = 0; i < ARRAY_SIZE; i++) {
            output[i] = (int *)malloc(ARRAY_SIZE * sizeof(int));
        }

        output = getSkyline(buildings[test], buildingsSize[test]);
        
        green();

        printf("Test %i: ", test + 1);

        reset();

        print2DArray(output, resultSize, IN_SIZE - 1);

        green();

        printf("Passed\n");

        for (int i = 0; i < ARRAY_SIZE; i++) {
            free(output[i]);
        }
        free(output);

        resultSize = 0;
    }

    reset();

    return 0;
}

void print2DArray(int **array, int arraySize, int arrayInSize)
{
    printf("[");

    for (int i = 0; i < arraySize; i++)
    {
        for (int j = 0; j < arrayInSize; j++)
        {
            printf("%s%i%s", ((j == 0) ? "[" : ""), array[i][j], ((j < arrayInSize - 1) ? ", " : "]"));
        }
    }

    printf("] | ");
}

int** getSkyline(int buildingsVar[ARRAY_SIZE][ARRAY_SIZE], int buildingsVarSize)
{
    int **result = (int **)malloc(ARRAY_SIZE * sizeof(int *)); 

    for (int i = 0; i < ARRAY_SIZE; i++) {
        result[i] = (int *)malloc(ARRAY_SIZE * sizeof(int));
    }

    int bluePrint[ARRAY_SIZE][ARRAY_SIZE] = {0};
    int maxHeight = 0;
    int maxWidth = 0;

    for (int i = 0; i < buildingsVarSize; i++)
    {
        for (int j = 0; j < IN_SIZE; j++)
        {
            maxHeight = ((buildingsVar[i][2] > maxHeight) ? buildingsVar[i][2] : maxHeight);
            maxWidth = ((buildingsVar[i][1] > maxWidth) ? buildingsVar[i][1] : maxWidth);
        }
    }

    maxHeight += 2;
    maxWidth += 2;

    for (int i = 0; i < buildingsVarSize; i++)
    {

        for (int j = buildingsVar[i][0]; j < buildingsVar[i][1] + 1; j++)
        {
            for (int k = 0; k < buildingsVar[i][2] + 1; k++)
            {
                bluePrint[j][k] = 1;
            }
        }
    }

    for (int i = 0; i < maxWidth; i++)
    {
        for (int j = 0; j < maxHeight; j++)
        {
            if (bluePrint[i][j] == 1 && (bluePrint[i - 1][j] == 0 || i == 0) && bluePrint[i][j + 1] == 0)
            {
                result[resultSize][0] = i;
                result[resultSize][1] = j;
                resultSize++; 
            }
            else if (bluePrint[i][j] == 1 && bluePrint[i - 1][j] == 0 && (j + 1) == maxHeight)
            {
                result[resultSize][0] = i;
                result[resultSize][1] = j;
                resultSize++;
            }
            else if (bluePrint[i][j] == 1 && bluePrint[i + 1][j] == 1 && bluePrint[i][j + 1] == 1 && bluePrint[i][j] == 1 && bluePrint[i + 1][j + 1] == 0)
            {
                result[resultSize][0] = i;
                result[resultSize][1] = j;
                resultSize++;
            }
            else if (bluePrint[i][j] == 1 && j == 0 && bluePrint[i + 1][j] == 0)
            {
                result[resultSize][0] = i;
                result[resultSize][1] = j;
                resultSize++;
            }
        }
    }

    return result;
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