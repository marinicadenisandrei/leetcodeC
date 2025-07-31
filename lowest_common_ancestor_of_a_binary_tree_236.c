/* Leetcode - 236. Lowest Common Ancestor of a Binary Tree (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

int lowestCommonAncestor(int *rootVar, int rootVarSize, int pVar, int qVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 236. Lowest Common Ancestor of a Binary Tree (C language) - Medium\n");

    int root[NUMBER_OF_TESTS][ARRAY_SIZE] = {{3,5,1,6,2,0,8,0,0,7,4},{3,5,1,6,2,0,8,0,0,7,4},{1,2}};
    int rootSize[NUMBER_OF_TESTS] = {11,11,2};

    int p[NUMBER_OF_TESTS] = {5,5,1};
    int q[NUMBER_OF_TESTS] = {1,4,2};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", lowestCommonAncestor(root[test], rootSize[test], p[test], q[test]));

        green();

        printf("Passed\n");

        // break;
    }

    reset();

    return 0;
}

int lowestCommonAncestor(int *rootVar, int rootVarSize, int pVar, int qVar)
{
    int start = 1;
    int end = 2;
    int pLevel = 0;
    int qLevel = 0;

    int globalLevel = 0;

    int acumulation[ARRAY_SIZE][ARRAY_SIZE];
    int acumulationInSize[ARRAY_SIZE] = {0};
    int acumulationSize = 0;

    while (end < rootVarSize)
    {   
        for (int i = start; i <= end; i++)
        {
            acumulation[acumulationSize][acumulationInSize[acumulationSize]] = rootVar[i];
            acumulationInSize[acumulationSize]++;

            if (rootVar[i] == pVar)
            {
                pLevel = globalLevel;
            }
            
            if (rootVar[i] == qVar)
            {
                qLevel = globalLevel;
            }
        }

        acumulationSize++;

        start = end + 1;
        end = start * 2;

        globalLevel++;
    }

    for (int i = start; i < rootVarSize; i++)
    {
        acumulation[acumulationSize][acumulationInSize[acumulationSize]] = rootVar[i];
        acumulationInSize[acumulationSize]++;

        if (rootVar[i] == pVar)
        {
            pLevel = globalLevel;
        }
        
        if (rootVar[i] == qVar)
        {
            qLevel = globalLevel;
        }
    }

    acumulationSize++;

    if (pLevel == 0 && pLevel == qLevel)
    {
        return rootVar[0];
    }
    else if (pLevel < qLevel)
    {
        return pVar;
    }
    else if (pLevel != qLevel)
    {
        int min = acumulation[pLevel][0];

        for (int i = 1; i < acumulationInSize[pLevel]; i++)
        {
            if (min > acumulation[pLevel][i])
            {
                min = acumulation[pLevel][i];
            }

            return min;
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