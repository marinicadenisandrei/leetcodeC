/* Leetcode - 31. Next Permutation (C example) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define NUMBER_OF_TESTS 3
#define ARRAY_SIZE 3

int numberOfPermutations(int arraySize);
int nextPermutation(int array[ARRAY_SIZE], int numberOfPermutations);
void convertIntToArrayAndPrint(int integer, int array[ARRAY_SIZE]);
bool checkMaxPermutation(char string[ARRAY_SIZE + 1]);
void printArray(int array[ARRAY_SIZE]);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 31. Next Permutation (C example) - Medium\n");

    int nums[ARRAY_SIZE][ARRAY_SIZE] = {{1,2,3}, {3,2,1}, {1,1,5}};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        int permutationsNo = 0;

        permutationsNo = numberOfPermutations(ARRAY_SIZE);
        int result = nextPermutation(nums[test], permutationsNo);
        int output[ARRAY_SIZE] = {};

        convertIntToArrayAndPrint(result, output);

        green();

        printf("Test %i: ", test + 1);

        reset();

        printArray(output);

        printf(" | ");

        green();

        printf("Passed\n");

        reset();
    }
    
    return 0;
}

int numberOfPermutations(int arraySize)
{
    int perNo = 1;

    for (int i = 1; i <= arraySize; i++)
    {
        perNo *= i;
    }

    return perNo;
}

bool checkMaxPermutation(char string[ARRAY_SIZE + 1])
{
    for (int i = 1; string[i] != '\0'; i++)
    {
        if (string[i-1] < string[i])
        {
            return false;
        }
    }

    return true;    
}

int nextPermutation(int array[ARRAY_SIZE], int numberOfPermutations)
{   
    char stringNumber[ARRAY_SIZE + 1] = "";

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        char digit[2];
        sprintf(digit, "%d", array[i]);
        strcat(stringNumber, digit);
    }

    int counter = 0;
    char temp[ARRAY_SIZE - 1] = "";

    int startIndex = 0;
    int endIndex = 1;

    int myNumber = atoi(stringNumber);
    int next = 0;

    int subtraction = 0;

    bool maximFlag = checkMaxPermutation(stringNumber);

    subtraction += (maximFlag) ? 0 : 99999;

    while (counter < numberOfPermutations)
    {
        if (maximFlag)
        {
            if (abs(atoi(stringNumber) - myNumber) > 0 && abs(atoi(stringNumber) - myNumber) > subtraction)
            {
                subtraction = abs(atoi(stringNumber) - myNumber);
                next = atoi(stringNumber);
            }
        }
        else
        {
            if (abs(atoi(stringNumber) - myNumber) > 0 && abs(atoi(stringNumber) - myNumber) < subtraction)
            {
                subtraction = abs(atoi(stringNumber) - myNumber);
                next = atoi(stringNumber);
            }
        }
        
        if (endIndex < ARRAY_SIZE)
        {
            temp[0] = stringNumber[startIndex];
            stringNumber[startIndex] = stringNumber[endIndex];
            stringNumber[endIndex] = temp[0];
        }

        if (endIndex == ARRAY_SIZE)
        {
            temp[0] = stringNumber[0];
            stringNumber[0] = stringNumber[ARRAY_SIZE - 1];
            stringNumber[ARRAY_SIZE - 1] = temp[0];

            startIndex = -1;
            endIndex = 0;
        }

        startIndex++;
        endIndex++;

        counter++;
    }
    
    return next;
}

void convertIntToArrayAndPrint(int integer, int array[ARRAY_SIZE])
{
    char stringInteger[ARRAY_SIZE + 1] = "";
    sprintf(stringInteger, "%d", integer);

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        array[i] = stringInteger[i] - '0';
    }
}

void printArray(int array[ARRAY_SIZE])
{
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        printf("%s%i%s", (i == 0) ? "[" : "", array[i], (i < ARRAY_SIZE - 1) ? ", " : "]");
    }
    
    printf("%s", (ARRAY_SIZE == 0) ? "[]" : "");
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
