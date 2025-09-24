/* Leetcode - 437. Path Sum III (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void reset ();
void green ();
void yellow ();
void red ();

int pathSum(int*rootVar, int rootSizeVar, int targetSumVar);

int main()
{
    yellow();

    printf("Leetcode - 437. Path Sum III (C language) - Medium\n");

    int root[NUMBER_OF_TESTS][ARRAY_SIZE] = {{10,5,-3,3,2,0,11,3,-2,0,1},{5,4,8,11,0,13,4,7,2,0,0,5,1}};
    int rootSize[NUMBER_OF_TESTS] = {15,13};
    int targetSum[NUMBER_OF_TESTS] = {8,22};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", pathSum(root[test], rootSize[test], targetSum[test]));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

int pathSum(int*rootVar, int rootSizeVar, int targetSumVar)
{
    int power = 1;

    while (power <= rootSizeVar)
    {
        power *= 2;
    }
    
    int arrIndex[ARRAY_SIZE][ARRAY_SIZE] = {};
    int arrIndexSize = 0;
    int arrIndexInSize = 0;

    int level = power / 4;
    int counter = 0;
    int index = 0;
    int trigger = level * 2;

    for (int i = 0; i < level; i++)
    {
        for (int j = 0; j < level * 2; j++)
        {
            if (trigger == counter)
            {
                index++;
                counter = 0;
            }
            
            counter++;
            
            arrIndex[arrIndexSize][arrIndexInSize++] = index;
        }    

        index++;

        arrIndexSize++;
        arrIndexInSize = ((i < level - 1) ? 0 : arrIndexInSize);

        counter = 0;
        trigger /= 2;
    }
    
    int result = 0;

    for (int k = 0; k < arrIndexInSize; k++)
    {
        for (int i = 0; i < arrIndexInSize; i++)
        {
            int tempSum = 0;
            int zeroFound = 0;

            for (int j = k; j < arrIndexSize; j++)
            {

                tempSum += rootVar[arrIndex[j][i]];

                if (rootVar[arrIndex[j][i]] == 0)
                {
                    zeroFound = 1;
                    break;
                }

                if (tempSum == targetSumVar && zeroFound == 0)
                {
                    result++;
                }
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