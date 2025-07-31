/* Leetcode - 134. Gas Station (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

int canCompleteCircuit(int *gasVar, int *costSize, int actualSize);
void printArray(int *array, int arraySize);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 134. Gas Station (C language) - Medium");

    int gas[ARRAY_SIZE][ARRAY_SIZE] = {{1,2,3,4,5}, {2,3,4}};
    int cost[ARRAY_SIZE][ARRAY_SIZE] = {{3,4,5,1,2}, {3,4,3}};
    int gasSize[ARRAY_SIZE] = {5,3};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", canCompleteCircuit(gas[test], cost[test], gasSize[test]));

        green();

        printf("Passed\n");
    }
}

void printArray(int *array, int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        printf("%s%i%s", ((i == 0) ? "[" : ""), array[i], ((i < arraySize - 1) ? ", " : "]"));
    }
    
}

int canCompleteCircuit(int *gasVar, int *costSize, int actualSize)
{
    int calculateGas[ARRAY_SIZE] = {0};

    for (int i = 0; i < actualSize; i++)
    {   
        calculateGas[i] = gasVar[i] - costSize[i];
    }    
    
    int fuelTank = 0;

    for (int i = 0; i < actualSize; i++)
    {
        if (calculateGas[i] > 0)
        {   
            for (int j = i; j < actualSize; j++)
            {
                fuelTank += calculateGas[j];
            }

            for (int j = 0; j < i; j++)
            {
                fuelTank += calculateGas[j];
            }
            
            if (fuelTank >= 0)
            {
                return i;
            }
        }
    }

    return -1;
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