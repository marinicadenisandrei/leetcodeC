/* Leetcode - 399. Evaluate Division (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

int resultSize = 0;

void reset ();
void green ();
void yellow ();
void red ();

float* calcEquation(char equationsVar[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE], int equationsSizeVar, float valuesVar[ARRAY_SIZE], int valuesSizeVar, char queriesVar[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE], int queriesVarSize);
bool checkStrings(char s1[ARRAY_SIZE], char s2[ARRAY_SIZE]);
void printArray(float *array, int arraySize);

int main()
{
    yellow();

    printf("Leetcode - 399. Evaluate Division (C language) - Medium\n");

    char equations[NUMBER_OF_TESTS][ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE] = {{{"a","b"},{"b","c"}}, {{"a","b"},{"b","c"}}, {{"a","b"}}};
    int equationsSize[NUMBER_OF_TESTS] = {2,2,1};

    float values[NUMBER_OF_TESTS][ARRAY_SIZE] = {{2.0,3.0},{1.5,2.5,5.0},{0.5}};
    int valuesSize[NUMBER_OF_TESTS] = {2,2};

    char queries[NUMBER_OF_TESTS][ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE] = {
        {{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}},
        {{"a","c"},{"c","b"},{"bc","cd"},{"cd","bc"}},
        {{"a","b"}, {"b","a"},{"a","c"},{"x","y"}}
    };
    int queriesSize[NUMBER_OF_TESTS] = {5,4,4};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        float* output = calcEquation(equations[test], equationsSize[test], values[test], valuesSize[test], queries[test], queriesSize[test]);
        printArray(output, resultSize);

        free(output);
        resultSize = 0;

        green();

        printf("Passed\n");
    }
    
    reset();

    return 0;
}

void printArray(float *array, int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        printf("%s%f%s", ((i == 0) ? "[" : ""), array[i], ((i < arraySize - 1) ? ", " : "] | "));
    }   
}

bool checkStrings(char s1[ARRAY_SIZE], char s2[ARRAY_SIZE])
{
    for (int i = 0; i < strlen(s1); i++)
    {
        if (s1[i] != s2[i])
        {
            return false;
        }
    }
    
    return true;
}

float* calcEquation(char equationsVar[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE], int equationsSizeVar, float valuesVar[ARRAY_SIZE], int valuesSizeVar, char queriesVar[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE], int queriesVarSize)
{
    float* result = (float*)malloc(ARRAY_SIZE * sizeof(float));

    for (int i = 0; i < queriesVarSize; i++)
    {
        int indexFirst = -1;
        int indexLast = -1;
        
        int checkedIndex = 0;

        for (int j = 0; j < equationsSizeVar; j++)
        {
            if ((checkStrings(queriesVar[i][0], equationsVar[j][0]) || 
                checkStrings(queriesVar[i][0], equationsVar[j][1])) && indexFirst == -1)
            {
                indexFirst = j;
            }


            if ((checkStrings(queriesVar[i][1], equationsVar[j][0]) || 
                checkStrings(queriesVar[i][1], equationsVar[j][1])) && indexLast == -1)
            {
                indexLast = j;
            }
        }

        
        if (indexFirst != -1 && indexLast != -1)
        {
            if (checkStrings(queriesVar[i][0], queriesVar[i][1]))
            {
                result[resultSize++] = 1.0;
                continue;
            }

            if (indexFirst < indexLast)
            {
                result[resultSize++] = valuesVar[indexFirst] / valuesVar[indexLast];
            }
            else if (indexFirst == indexLast)
            {
                if (checkStrings(queriesVar[i][0], equationsVar[indexFirst][0]))
                {
                    result[resultSize++] = valuesVar[indexFirst];
                }
                else
                {
                    result[resultSize++] = 1 / valuesVar[indexFirst];
                }
            }
        }
        else
        {
            result[resultSize++] = -1.0;
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