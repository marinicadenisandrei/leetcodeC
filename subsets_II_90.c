/* Leetcode - 90. Subsets II (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

struct outputVar
{
    int outputElement[ARRAY_SIZE];
    int outptutSizeElement;
};

void subsetsWithDup(int *numsVar, int numsVarSize, struct outputVar *outputVar, int *outputVarSize);
void printStructSubsets(struct outputVar * structureVar, int structureVarSize);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 90. Subsets II (C language) - Medium\n");

    int nums[ARRAY_SIZE][ARRAY_SIZE] = {{1, 2, 2}, {0}};
    int numsSize[ARRAY_SIZE] = {3,1};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        struct outputVar output[ARRAY_SIZE];
        int outputSize = 1;

        output[0].outptutSizeElement = 0;

        subsetsWithDup(nums[test], numsSize[test], output, &outputSize);

        green();

        printf("Test %i: ", test + 1);

        reset();

        printStructSubsets(output, outputSize);

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

void subsetsWithDup(int *numsVar, int numsVarSize, struct outputVar *outputVar, int *outputVarSize)
{
    int tempArray[ARRAY_SIZE] = {};
    int tempArraySize = 0;

    for (int i = 0; i < numsVarSize; i++)
    {
        for (int j = i; j < numsVarSize; j++)
        {
            tempArray[tempArraySize] = *(numsVar + j);
            tempArraySize++;

            for (int k = 0; k < tempArraySize; k++)
            {
                outputVar[*outputVarSize].outputElement[k] = tempArray[k];
            }

            outputVar[*outputVarSize].outptutSizeElement = tempArraySize;
            (*outputVarSize)++;
        }

        tempArraySize = 0;
    }
}

void printStructSubsets(struct outputVar * structureVar, int structureVarSize)
{
    for (int i = 0; i < structureVarSize; i++)
    {
        if (structureVar[i].outptutSizeElement == 0)
        {
            printf("[]");
        }
        
        for (int j = 0; j < structureVar[i].outptutSizeElement; j++)
        {
            printf("%s%i%s", ((j == 0) ? "[" : ""), structureVar[i].outputElement[j], ((j < structureVar[i].outptutSizeElement - 1) ? ", " : "]"));
        }
    }

    printf(" | ");
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