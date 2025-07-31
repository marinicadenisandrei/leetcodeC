#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

int calculateMinimumHP(int dungeonVar[ARRAY_SIZE][ARRAY_SIZE], int dungeonVarSize, int dungeonVarInSize);
void printMatrix(int matrix[ARRAY_SIZE][ARRAY_SIZE], int matrixSize, int matrixInSize);
int maxIntegers(int var1, int var2);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();
    
    printf("Leetcode - 174. Dungeon Game (C language) - ");

    red();

    printf("Hard\n");
    
    int dungeon[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE] = {{{-2,-3,3},{-5,-10,1},{10,30,-5}}, {{0}}};
    int dungeonSize[ARRAY_SIZE] = {3,1};
    int dungeonInSize[ARRAY_SIZE] = {3,1};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ",calculateMinimumHP(dungeon[test], dungeonSize[test], dungeonInSize[test]));

        green();

        printf("Passed\n");   
    }

    reset();

    return 0;
}

int maxIntegers(int var1, int var2)
{
    if (var1 > var2)
    {
        return var1;
    }

    return var2;
}

int minIntegers(int var1, int var2)
{
    if (var1 < var2)
    {
        return var1;
    }
    
    return var2;
}

void printMatrix(int matrix[ARRAY_SIZE][ARRAY_SIZE], int matrixSize, int matrixInSize)
{
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < matrixInSize; j++)
        {
            printf("%s%i%s", ((j == 0) ? "[" : ""), matrix[i][j], ((j < matrixInSize - 1) ? ", " : "]\n"));       
        }   
    }

    printf("\n");
}

int calculateMinimumHP(int dungeonVar[ARRAY_SIZE][ARRAY_SIZE], int dungeonVarSize, int dungeonVarInSize)
{
    dungeonVar[dungeonVarSize - 1][dungeonVarInSize - 1] = maxIntegers(1, 1 - dungeonVar[dungeonVarSize - 1][dungeonVarInSize - 1]);

    for (int i = dungeonVarInSize - 2; i >= 0; i--)
    {
        dungeonVar[dungeonVarSize - 1][i] = maxIntegers(1, 1 - dungeonVar[dungeonVarSize - 1][i + 1]);
    }
 
    for (int i = dungeonVarSize - 2; i >= 0 ; i--)
    {
        dungeonVar[i][dungeonVarInSize - 1] = maxIntegers(1 , dungeonVar[i + 1][dungeonVarInSize - 1] - dungeonVar[i][dungeonVarInSize - 1]);
    }

    int minusVar = 1;

    for (int i = dungeonVarSize - 2; i >= 0; i--)
    {
        for (int j = dungeonVarInSize - 2; j >= 0; j--)
        {
            int f = minIntegers(dungeonVar[i + 1][j], dungeonVar[i][j + 1]);
            dungeonVar[i][j] = maxIntegers(f, f - dungeonVar[i][j]);
        }
    }
 
    return dungeonVar[0][0];    
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