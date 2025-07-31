/* Leetcode - 321. Create Maximum Number (C language) - Hard */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

int resultSize = 0;

int* maxNumber(int *nums1Var, int nums1VarSize, int *nums2Var, int nums2VarSize, int kVar);
void sortArray(int *array, int arraySize);
void printArray(int *array, int arraySize);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 321. Create Maximum Number (C language) - ");

    red();

    printf("Hard\n");

    int nums1[NUMBER_OF_TESTS][ARRAY_SIZE] = {{3,4,6,5},{6,7},{3,9}};
    int nums1Size[NUMBER_OF_TESTS] = {4,2,2};

    int nums2[NUMBER_OF_TESTS][ARRAY_SIZE] = {{9,1,2,5,8,3},{6,0,4},{8,9}};
    int nums2Size[NUMBER_OF_TESTS] = {6,3,2};

    int k[NUMBER_OF_TESTS] = {5,5,3};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        int *output = maxNumber(nums1[test], nums1Size[test], nums2[test], nums2Size[test], k[test]);
        printArray(output, resultSize);

        free(output);
        resultSize = 0;

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

void printArray(int *array, int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        printf("%s%i%s", ((i == 0) ? "[" : ""), array[i], ((i < arraySize - 1) ? ", " : "] | "));
    }
}

int* maxNumber(int *nums1Var, int nums1VarSize, int *nums2Var, int nums2VarSize, int kVar)
{
    int sortedNum1[ARRAY_SIZE] = {};
    int sortedNum2[ARRAY_SIZE] = {};

    int indexesNum1[ARRAY_SIZE] = {};
    int indexesNum2[ARRAY_SIZE] = {};

    int candidates1[ARRAY_SIZE] = {};
    int cand1Size = 0;

    int candidates2[ARRAY_SIZE] = {};
    int cand2Size = 0;

    int *result = (int*)malloc(ARRAY_SIZE * sizeof(int));

    for (int i = 0; i < nums1VarSize; i++)
    {
        sortedNum1[i] = nums1Var[i];
    }
    
    for (int i = 0; i < nums2VarSize; i++)
    {
        sortedNum2[i] = nums2Var[i];
    }

    sortArray(sortedNum1, nums1VarSize);
    sortArray(sortedNum2, nums2VarSize);

    for (int i = 0; i < nums1VarSize; i++)
    {
        for (int j = 0; j < nums1VarSize; j++)
        {
            if (sortedNum1[i] == nums1Var[j])
            {
                indexesNum1[i] = j;   
            }   
        }
    }

    for (int i = 0; i < nums2VarSize; i++)
    {
        for (int j = 0; j < nums2VarSize; j++)
        {
            if (sortedNum2[i] == nums2Var[j])
            {
                indexesNum2[i] = j;   
            }   
        }
    }

    bool flag1Desc = true;
    bool flag2Desc = true;

    for (int i = 0; i < nums1VarSize; i++)
    {
        if (indexesNum1[i] < indexesNum1[i + 1])
        {
            flag1Desc = false;
        }
    }

    for (int i = 0; i < nums2VarSize; i++)
    {
        if (indexesNum2[i] < indexesNum2[i + 1])
        {
            flag2Desc = false;
        }
    }

    if (flag1Desc)
    {
        int index1 = 0;
        int index2 = 0;
        int c = 0;

        int maxVar = 0;
        int *output = (int*)malloc(ARRAY_SIZE * sizeof(int));
        int outputSize = 0;

        while (c < nums1VarSize)
        {
            resultSize = 0;
            index1 = c;
            index2 = 0;

            while (index1 < nums1VarSize || index2 < nums2VarSize)
            {   
                if (nums1Var[index1] > nums2Var[index2])
                {
                    result[resultSize++] = nums1Var[index1];
                    index1++;
                }
                else if (nums1Var[index1] < nums2Var[index2])
                {
                    result[resultSize++] = nums2Var[index2];
                    index2++;
                }
                else
                {
                    if (nums1Var[index1 + 1] > nums2Var[index2 + 1])
                    {
                        result[resultSize++] = nums1Var[index1];
                        index1++;
                    }
                    else if (nums1Var[index1 + 1] < nums2Var[index2 + 1])
                    {
                        result[resultSize++] = nums2Var[index2];
                        index2++;
                    }
                }

                if (index1 + index2 == kVar)
                {
                    break;
                }
            }

            if (index1 + index2 - c < kVar)
            {
                if (index1 < nums1VarSize)
                {
                    for (int i = index1; i + index2 < kVar + c; i++)
                    {
                        result[resultSize++] = nums1Var[i];
                    }
                }
                else
                {
                    for (int i = index2; index1 + i < kVar + c; i++)
                    {
                        result[resultSize++] = nums2Var[i];
                    }
                }   
            }
            
            int sumVar = 0;

            for (int i = 0; i < resultSize; i++)
            {
                sumVar += result[i];
            }

            if (sumVar > maxVar)
            {
                outputSize = 0;

                for (int i = 0; i < resultSize; i++)
                {
                    output[outputSize++] = result[i];
                }

                outputSize = resultSize;
                maxVar = sumVar;
            }
            
            c++;
        }
        
        return output;
    }

    int start = indexesNum1[0];
    candidates1[0] = start;
    cand1Size++;

    for (int i = 1; i < nums1VarSize; i++)
    {
        if (start < indexesNum1[i])
        {
            start = indexesNum1[i];
            candidates1[cand1Size++] = start;
        }
    }
    
    start = indexesNum2[0];
    candidates2[0] = start;
    cand2Size++;

    for (int i = 1; i < nums2VarSize; i++)
    {
        if (start < indexesNum2[i])
        {
            start = indexesNum2[i];
            candidates2[cand2Size++] = start;
        }
    }

    for (int i = 0; i < cand1Size; i++)
    {
        result[resultSize++] = nums1Var[candidates1[i]];
    }

    for (int i = 0; i < cand2Size; i++)
    {
        result[resultSize++] = nums2Var[candidates2[i]];
    }

    sortArray(result, resultSize);
    
    return result;
}

void sortArray(int *array, int arraySize)
{
    bool flag = true;
    int c = 0;

    while (flag)
    {
        flag = false;

        for (int i = 0; i < arraySize - 1 - c; i++)
        {
            if (array[i] < array[i + 1])
            {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                flag = true;
            }
        }

        c++;
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