/* Leetcode - 95. Unique Binary Search Trees II (C language) - Medium */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

int output[ARRAY_SIZE][ARRAY_SIZE] = {};
int outputInSize[ARRAY_SIZE] = {};
int outputSize = 0;

int generateTrees(int nVar);
void printArray(int *arrayVar, int arraySize);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 95. Unique Binary Search Trees II (C language) - Medium\n");

    int n[ARRAY_SIZE] = {3,1};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        generateTrees(n[test]);

        green();

        printf("Test %i: ", test + 1);

        reset();

        for (int i = 0; i < outputSize; i++)
        {
            printArray(output[i], outputInSize[i]);
        }

        printf(" | ");

        green();

        printf("Passed\n");

        outputSize = 0;
    }

    reset();

    return 0;
}

void printArray(int *arrayVar, int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        printf("%s%i%s", ((i == 0) ? "[" : ""), *(arrayVar + i), ((i < arraySize - 1) ? ", " : "]"));
    }
}

int generateTrees(int nVar)
{
    if (nVar == 1)
    {
        output[outputSize][0] = 1;
        outputInSize[outputSize] = 1;
        outputSize++;

        return 0;
    }
    
    int arrayStart[ARRAY_SIZE] = {};

    for (int i = 1; i <= nVar; i++)
    {
        arrayStart[i - 1] = i;
    }

    for (int i = 0; i < nVar; i++)
    {

        int origin = 0;

        int left[ARRAY_SIZE][ARRAY_SIZE] = {};
        int leftInSize[ARRAY_SIZE] = {};
        int leftGlobalSize = 0;

        int right[ARRAY_SIZE][ARRAY_SIZE] = {};
        int rightInSize[ARRAY_SIZE] = {};
        int rightGlobalSize = 0;

        int offsetLeft = 0;
        int offsetRight = 0;
    
        origin = arrayStart[i];

        if (i == 0)
        {
            left[leftGlobalSize][0] = 0;
            leftInSize[leftGlobalSize] = 1;
            leftGlobalSize++;
        }
        else
        {
            int counterLeft = 0;

            for (int j = 0; j < i; j++)
            {
                left[leftGlobalSize][counterLeft] = arrayStart[j];
                counterLeft++;
            }

            leftInSize[leftGlobalSize] = counterLeft;
            leftGlobalSize++;
        }

        if (i == nVar - 1)
        {
            right[rightGlobalSize][0] = 0;
            rightInSize[rightGlobalSize] = 1;
            rightGlobalSize++;
        }
        else
        {
            int counterRight = 0;

            for (int j = i + 1; j < nVar; j++)
            {
                right[rightGlobalSize][counterRight] = arrayStart[j];
                counterRight++;
            }

            rightInSize[rightGlobalSize] = counterRight;
            rightGlobalSize++;
        }

        // Left

        for (int j = 0; j < leftGlobalSize; j++)
        {
            if (leftInSize[j] > 1)
            {
                for (int k = 0; k < leftInSize[j]; k++)
                {
                    left[leftGlobalSize][0] = left[j][k];
                    leftInSize[leftGlobalSize] = 1;
                    leftGlobalSize++;

                    if (k == 0)
                    {
                        left[leftGlobalSize][0] = 0;
                        leftInSize[leftGlobalSize] = 1;
                        leftGlobalSize++;
                    }
                    else
                    {
                        int counterLeft = 0;

                        for (int l = 0; l < leftInSize[j] - 1; l++)
                        {
                            left[leftGlobalSize][counterLeft] = left[j][l];
                            counterLeft++;
                        }

                        leftInSize[leftGlobalSize] = counterLeft;
                        leftGlobalSize++;
                    }

                    if (k == leftInSize[j] - 1)
                    {
                        left[leftGlobalSize][0] = 0;
                        leftInSize[leftGlobalSize] = 1;
                        leftGlobalSize++;
                    }
                    else
                    {
                        int counterLeft = 0;

                        for (int l = k + 1; l < leftInSize[j]; l++)
                        {
                            left[leftGlobalSize][counterLeft] = left[j][l];
                            counterLeft++;
                        }

                        leftInSize[leftGlobalSize] = counterLeft;
                        leftGlobalSize++;
                    }
                }

                offsetLeft++;
            }
        }

        // Right

        for (int j = 0; j < rightGlobalSize; j++)
        {
            if (rightInSize[j] > 1)
            {
                for (int k = 0; k < rightInSize[j]; k++)
                {
                    right[rightGlobalSize][0] = right[j][k];
                    rightInSize[rightGlobalSize] = 1;
                    rightGlobalSize++;

                    if (k == 0)
                    {
                        right[rightGlobalSize][0] = 0;
                        rightInSize[rightGlobalSize] = 1;
                        rightGlobalSize++;
                    }
                    else
                    {
                        int counterRight = 0;

                        for (int l = 0; l < rightInSize[j] - 1; l++)
                        {
                            right[rightGlobalSize][counterRight] = right[j][l];
                            counterRight++;
                        }

                        rightInSize[rightGlobalSize] = counterRight;
                        rightGlobalSize++;
                    }

                    if (k == rightInSize[j] - 1)
                    {
                        right[rightGlobalSize][0] = 0;
                        rightInSize[rightGlobalSize] = 1;
                        rightGlobalSize++;
                    }
                    else
                    {
                        int counterRight = 0;

                        for (int l = k + 1; l < rightInSize[j]; l++)
                        {
                            right[rightGlobalSize][counterRight] = right[j][l];
                            counterRight++;
                        }

                        rightInSize[rightGlobalSize] = counterRight;
                        rightGlobalSize++;
                    }
                }

                offsetRight++;
            }
        }

        int starterCombination = 3;

        if (rightGlobalSize > leftGlobalSize)
        {
            while (starterCombination < rightGlobalSize)
            {
                int outSize = 0;
                output[outputSize][outSize] = origin;

                outSize++; 

                for (int m = offsetLeft; m < leftGlobalSize; m++)
                {
                    output[outputSize][outSize] = left[m][0];
                    outSize++; 

                    for (int n = offsetRight + starterCombination - 3; n <= starterCombination; n++)
                    {
                        output[outputSize][outSize] = right[n][0];
                        outSize++;
                    }
                }
                
                outputInSize[outputSize] = outSize;
                outputSize++;

                starterCombination += 3;
            }
        }
        else if (leftGlobalSize > rightGlobalSize)
        {
            while (starterCombination < leftGlobalSize)
            {
                int outSize = 0;

                output[outputSize][outSize] = origin;
                outSize++; 

                for (int m = offsetRight; m < rightGlobalSize; m++)
                {
                    for (int n = offsetLeft + starterCombination - 3; n <= starterCombination; n++)
                    {
                        output[outputSize][outSize] = left[n][0];
                        outSize++;
                    }

                    output[outputSize][outSize] = right[m][0];
                    outSize++;
                }
                
                outputInSize[outputSize] = outSize;
                outputSize++;

                starterCombination += 3;
            }
        }
        else
        {
            output[outputSize][0] = origin;
            output[outputSize][1] = left[0][0];
            output[outputSize][2] = right[0][0];  

            outputInSize[outputSize] = 3;
            outputSize++;         
        }
    }

    return 0;
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