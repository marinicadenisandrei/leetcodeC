/* Leetcode - 200. Number of Islands (C language) - Medium */ 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

int numIslands(char gridVar[][ARRAY_SIZE], int gridVarSize, int gridVarInSize);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 200. Number of Islands (C language) - Medium\n");

    char grid[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE] = {{
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    },
    {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    }};

    int gridSize[ARRAY_SIZE] = {4,4};
    int gridInSize[ARRAY_SIZE] = {5,5};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", numIslands(grid[test], gridSize[test], gridInSize[test]));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

int numIslands(char gridVar[][ARRAY_SIZE], int gridVarSize, int gridVarInSize)
{
    int counter = 0;

    int startRow = 0;
    int endRow = 0;
    int endCol = 0; 

    bool flag = true;

    while (flag)
    {
        flag = false;

        for (int i = 0; i < gridVarSize; i++)
        {
            for (int j = 0; j < gridVarInSize; j++)
            {
                if (gridVar[i][j] == '1')
                {
                    startRow = i;

                    for (int k = j; k < gridVarInSize; k++)
                    {
                        if (gridVar[i][k] == '0')
                        {
                            endRow = k;
                            break;
                        }
                    }

                    if (endRow == 0)
                    {
                        endRow = gridVarInSize;
                    }
                    

                    for (int k = i; k < gridVarSize; k++)
                    {
                        if (gridVar[k][j] == '0')
                        {
                            endCol = k;
                        }
                    }

                    if (endCol == 0)
                    {
                        endCol = gridVarSize;
                    }

                    flag = true;
                    counter++;
                    
                    break;
                }
            }

            if (flag)
            {
                break;
            }
        }

        for (int i = startRow; i < endCol; i++)
        {
            for (int j = startRow; j < endRow; j++)
            {
                gridVar[i][j] = '0';
            }
        }

        startRow = 0;
        endRow = 0;
        endCol = 0; 
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

