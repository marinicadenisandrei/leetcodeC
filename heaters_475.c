/* Leetcode - 475. Heaters (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

void reset ();
void green ();
void yellow ();
void red ();

int findRadius(int *housesVar, int housesSizeVar, int *heatersVar, int heatersSizeVar);

int main()
{
    yellow();

    printf("Leetcode - 475. Heaters (C language) - Medium\n");

    int houses[NUMBER_OF_TESTS][ARRAY_SIZE] = {{1,2,3},{1,2,3,4},{1,5}};
    int housesSize[NUMBER_OF_TESTS] = {3,4,2};

    int heaters[NUMBER_OF_TESTS][ARRAY_SIZE] = {{2},{1,4},{2}};
    int heatersSize[NUMBER_OF_TESTS] = {1,2,1};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", (test + 1));

        reset();

        printf("%i | ", findRadius(houses[test], housesSize[test], heaters[test], heatersSize[test]));

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

int findRadius(int *housesVar, int housesSizeVar, int *heatersVar, int heatersSizeVar)
{
    int allHouses[ARRAY_SIZE] = {0};
    int allHousesSize = 0;

    int heatersFlags[ARRAY_SIZE] = {0};
    int heatersFlagsSize = 0;

    for (int i = 1; i <= housesVar[housesSizeVar - 1]; i++)
    {
        allHouses[allHousesSize++] = i;
    }

    for (int i = 0; i < allHousesSize; i++)
    {
        bool found = false;

        for (int j = 0; j < allHousesSize; j++)
        {
            if (allHouses[i] == heatersVar[j])
            {
                found = true;
                break;
            }
        }
        
        heatersFlags[heatersFlagsSize++] = ((found) ? 1 : 0);
    }    
    
    int radius = 1;
    bool flag = true;
    
    while (flag)
    {
        flag = false;
        
        int copyFlags[ARRAY_SIZE] = {0};
        
        for (int i = 0; i < heatersFlagsSize; i++)
        {
            copyFlags[i] = heatersFlags[i];
        }

        for (int i = 0; i < heatersSizeVar; i++)
        {
            int start = heatersVar[i] - 1 - radius;
            int end =  heatersVar[i] - 1 + radius;

            start = (start < 0) ? 0 : start;
            end = (end > heatersFlagsSize) ? heatersFlagsSize : end;

            for (int j = start; j < end; j++)
            {
                copyFlags[j] = 1;   
            }
        }

        for (int i = 0; i < heatersFlagsSize; i++)
        {
            if (copyFlags[i] == 0)
            {
                flag = true;
            }
        }
        
        radius++;
    }

    return radius - 2;
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