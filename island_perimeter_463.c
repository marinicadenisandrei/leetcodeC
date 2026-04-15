/* Leetcode - 463. Island Perimeter (C language) - Easy */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

void reset ();
void green ();
void yellow ();
void red ();

int islandPerimeter(int gridVar[ARRAY_SIZE][ARRAY_SIZE], int gridSizeVar, int gridInSizeVar);

int main()
{
    yellow();

    printf("Leetcode - 463. Island Perimeter (C language) - ");

    green();

    printf("Easy\n");

    int grid[NUMBER_OF_TESTS][ARRAY_SIZE][ARRAY_SIZE] = {{{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}},
                                                        {{1}},
                                                        {{1,0}}};
    int gridSize[NUMBER_OF_TESTS] = {4,1,1};
    int gridInSize[NUMBER_OF_TESTS] = {4,1,2};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", islandPerimeter(grid[test], gridSize[test], gridInSize[test]));

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

int islandPerimeter(int gridVar[ARRAY_SIZE][ARRAY_SIZE], int gridSizeVar, int gridInSizeVar)
{
    int result = 0;

    for (int i = 0; i < gridSizeVar; i++)
    {
        for (int j = 0; j < gridInSizeVar; j++)
        {
            if (gridVar[i][j] == 1)
            {
                int top_n = 0;
                int bot_n = 0;
                int left_n = 0;
                int right_n = 0;

                if (i > 0)
                    top_n = gridVar[i - 1][j];

                if (i < gridSizeVar - 1)
                    bot_n = gridVar[i + 1][j];

                if (j > 0)
                    left_n = gridVar[i][j - 1];

                if (j < gridInSizeVar - 1)
                    right_n = gridVar[i][j + 1];

                int sum_n = top_n + bot_n + left_n + right_n;
                result += 4 - sum_n;
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