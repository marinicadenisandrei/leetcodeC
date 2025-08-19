/* Leetcode - 417. Pacific Atlantic Water Flow (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void reset ();
void green ();
void yellow ();
void red ();

int** pacificAtlantic(int heighetsVar[ARRAY_SIZE][ARRAY_SIZE], int heightsSizeVar, int heightsInSizeVar, int *resultSizeVar);
void print2DArray(int** arr, int rows, int cols);

int main()
{
    yellow();

    printf("Leetcode - 417. Pacific Atlantic Water Flow (C language) - Medium\n");

    int heights[NUMBER_OF_TESTS][ARRAY_SIZE][ARRAY_SIZE] = {{{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}},{{1}}};
    int heightsSize[NUMBER_OF_TESTS] = {5,1};
    int heightsInSize[NUMBER_OF_TESTS] = {5,1};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        int resultSize = 0;
        int** output = pacificAtlantic(heights[test], heightsSize[test], heightsInSize[test], &resultSize);
        print2DArray(output, resultSize, 2);

        for (int i = 0; i < ARRAY_SIZE; i++)
        {
            free(output[i]);
        }
        free(output);

        green();

        printf("Passed\n");
    }

    reset();
}

void print2DArray(int** arr, int rows, int cols)
{
    printf("[");

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%s%i%s", ((j == 0) ? "[" : ""), arr[i][j], ((j < cols - 1) ? ", " : "]"));   
        }
    }
    
    printf("] | ");
}

int** pacificAtlantic(int heighetsVar[ARRAY_SIZE][ARRAY_SIZE], int heightsSizeVar, int heightsInSizeVar, int *resultSizeVar)
{
    int** result = (int**)malloc(ARRAY_SIZE * sizeof(int*));
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        result[i] = (int*)malloc(2 * sizeof(int));
    }

    for (int i = 0; i < heightsSizeVar; i++)
    {
        int maxElementValue = 0;
        int i_index = 0;
        int j_index = 0;

        for (int j = 0; j < heightsInSizeVar; j++)
        {
            if (maxElementValue <= heighetsVar[i][j])
            {
                maxElementValue = heighetsVar[i][j];
                i_index = i;
                j_index = j;
            }
        }

        result[(*resultSizeVar)][0] = i_index;
        result[(*resultSizeVar)++][1] = j_index;

        if (j_index + 1 < heightsInSizeVar)
        {
            if (heighetsVar[i_index][j_index + 1] == (heighetsVar[i_index][j_index] + 1))
            {
                result[(*resultSizeVar)][0] = i_index;
                result[(*resultSizeVar)++][1] = j_index + 1;
            }
            else if (heighetsVar[i_index][j_index + 1] == (heighetsVar[i_index][j_index] - 1))
            {
                result[(*resultSizeVar)][0] = i_index;
                result[(*resultSizeVar)++][1] = j_index + 1;
            }
            else if (heighetsVar[i_index][j_index + 1] == heighetsVar[i_index][j_index])
            {
                result[(*resultSizeVar)][0] = i_index;
                result[(*resultSizeVar)++][1] = j_index + 1;
            }
        }

        if (j_index - 1 >= 0)
        {
            if (heighetsVar[i_index][j_index - 1] == (heighetsVar[i_index][j_index] + 1))
            {
                result[(*resultSizeVar)][0] = i_index;
                result[(*resultSizeVar)++][1] = j_index - 1;
            }
            else if (heighetsVar[i_index][j_index - 1] == (heighetsVar[i_index][j_index] - 1))
            {
                result[(*resultSizeVar)][0] = i_index;
                result[(*resultSizeVar)++][1] = j_index - 1;
            }
            else if (heighetsVar[i_index][j_index - 1] == heighetsVar[i_index][j_index])
            {
                result[(*resultSizeVar)][0] = i_index;
                result[(*resultSizeVar)++][1] = j_index - 1;
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