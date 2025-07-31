/* Leetcode - 169. Majority Element (C language) */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define NUMBER_OF_TESTS 2

bool checkElementExistInArray(int *array, int sizeArray, int checkElement);
int removeDuplicates(int array[], int sizeArray, int NoDuplicatesArray[], int sizeNoDuplicatesArray);

void reset ();
void green ();
void yellow ();

int main(void)
{
    yellow();

    printf("Leetcode - 169. Majority Element (C language)\n");

    int nums[50][50] = {{3,2,3},{2,2,1,1,1,2,2}};

    int sizeNumsTest[10] = {3,7};

    struct majorityElement
    {
        int number;
        int numberCounter;
    };

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        int sizeNums = sizeNumsTest[test];
        
        int noDuplicates[50] = {};
        int sizeNoDuplicates = 0;

        sizeNoDuplicates = removeDuplicates(nums[test], sizeNums, noDuplicates, sizeNoDuplicates);

        struct majorityElement arrayStructure[sizeNoDuplicates];

        for (int i = 0; i < sizeNoDuplicates; i++)
        {
            arrayStructure[i].number = noDuplicates[i];
            int counter = 0;

            for (int j = 0; j < sizeNums; j++)
            {
                counter += (nums[test][j] == arrayStructure[i].number) ? 1 : 0;
            }

            arrayStructure[i].numberCounter = counter;
        }

        int maximum = 0;
        int indexMax = 0;

        for (int i = 0; i < sizeNoDuplicates; i++)
        {
            if (maximum < arrayStructure[i].numberCounter)
            {
                maximum = arrayStructure[i].numberCounter;
                indexMax = i;
            }
        }

        green();

        printf("Test %i: ", test+1);

        reset();

        printf("%i", arrayStructure[indexMax].number);

        green();

        printf(" | Passed\n");

        reset();

    }
        
    return 0;
}

bool checkElementExistInArray(int *array, int sizeArray, int checkElement)
{
    bool flagFinder = false;
    const int *parray = array; 

    for (int i = 0; i < sizeArray; i++, array++)
    {
        if (*array == checkElement)
        {
            flagFinder = true;
            break;
        }
    }
    
    return flagFinder;
}

int removeDuplicates(int array[], int sizeArray, int NoDuplicatesArray[], int sizeNoDuplicatesArray)
{   
    for (int i = 0; i < sizeArray; i++)
    {
        if (checkElementExistInArray(NoDuplicatesArray, sizeNoDuplicatesArray, array[i]) == 0)
        {
            NoDuplicatesArray[sizeNoDuplicatesArray] = array[i];
            sizeNoDuplicatesArray++;
        }
    }

    return sizeNoDuplicatesArray;
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

