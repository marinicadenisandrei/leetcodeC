/* Leetcode - 407. Trapping Rain Water II (C language) - Hard */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void reset ();
void green ();
void yellow ();
void red ();

int trapRainWater(int heightMapVar[ARRAY_SIZE][ARRAY_SIZE], int heightSizeVar, int heightInSizeVar);

int main()
{
    yellow();

    printf("Leetcode - 407. Trapping Rain Water II (C language) - ");

    red();

    printf("Hard\n");

    int heightMap[NUMBER_OF_TESTS][ARRAY_SIZE][ARRAY_SIZE] = {{{1,4,3,1,3,2},{3,2,1,3,2,4},{2,3,3,2,3,1}},{{3,3,3,3,3},{3,2,2,2,3},{3,2,1,2,3},{3,2,2,2,3},{3,3,3,3,3}}};
    int heightSize[NUMBER_OF_TESTS] = {3,5};
    int heightInSize[NUMBER_OF_TESTS] = {6,5};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {   
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", trapRainWater(heightMap[test], heightSize[test], heightInSize[test]));

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

int trapRainWater(int heightMapVar[ARRAY_SIZE][ARRAY_SIZE], int heightSizeVar, int heightInSizeVar)
{

    int water = 0;

    for (int i = 1; i < heightSizeVar - 1; i++)
    {
        for (int j = 1; j < heightInSizeVar - 1; j++)
        {
            int add = 0;

            int arr[4] = {};
            arr[0] = heightMapVar[i - 1][j];
            arr[1] = heightMapVar[i][j + 1];
            arr[2] = heightMapVar[i + 1][j];
            arr[3] = heightMapVar[i][j - 1];

            int occ[4] = {};

            for (int k = 0; k < 4; k++)
            {
                int counter = 0;
                
                for (int l = 0; l < 4; l++)
                {
                    counter += (l != k && arr[k] == arr[l]) ? 1 : 0;
                }
                
                occ[k] = counter;
            }

            int min = arr[0];
            int occ_max = occ[0];
            
            for (int k = 0; k < 4; k++)
            {
                if (occ_max < occ[k])
                {
                    occ_max = occ[k];
                    min = arr[k];
                }
            }

            bool flag = false;

            for (int k = 0; k < 4; k++)
            {
                if (arr[k] >= heightMapVar[i][j])
                {
                    flag = true;
                    break;
                }
            }

            if (flag)
            {
                if (heightMapVar[i][j] == min)
                {
                    water++;
                    add = 1;
                }
                else if (heightMapVar[i][j] <= min)
                {
                    water += (min - heightMapVar[i][j]);
                    add = (min - heightMapVar[i][j]);
                    heightMapVar[i][j]++;
                }
                else
                {
                    water += (heightMapVar[i][j] - min);
                    add = (heightMapVar[i][j] - min);
                }
            }
        }        
    }

    return water;
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