/* Leetcode - 187. Repeated DNA Sequences (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ARRAY_SIZE 50
#define NUMBER_OF_TESTS 2

int resultsSize = 0;

char **findRepeatedDnaSequences(char *sVar);
void reverseString(char *string);
void printVectorString(char **vector, int size);

void reset();
void green();
void yellow();
void red();

int main(void)
{
    yellow();

    printf("Leetcode - 187. Repeated DNA Sequences (C language) - Medium\n");

    char s[ARRAY_SIZE][ARRAY_SIZE] = {"AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT","AAAAAAAAAAAAA"}; 
    
    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        char **output = (char **)malloc(20 * sizeof(char *));
        for (int i = 0; i < 20; i++) {
            output[i] = (char *)malloc(20 * sizeof(char));
        }

        green();
        
        printf("Test %i: ", test + 1);

        reset();

        output = findRepeatedDnaSequences(s[test]);
        printVectorString(output, resultsSize);

        green();

        printf("Passed\n");

        for (int i = 0; i < 20; i++) {
            free(output[i]);
        }
        free(output);

        resultsSize = 0;
    }

    reset();

    return 0;
}

void printVectorString(char **vector, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%s%s%s", ((i == 0) ? "[" : ""),vector[i], ((i < size - 1) ? ", " : "]"));
    }

    printf(" | ");
}

void reverseString(char *string)
{
    char temp[2];

    for (int i = 0, j = strlen(string) - 1; i < j; i++, j--)
    {
        temp[0] = string[i];
        string[i] = string[j];
        string[j] = temp[0];       
    }
}

char **findRepeatedDnaSequences(char *sVar)
{
    char acumulation[ARRAY_SIZE][ARRAY_SIZE] = {};
    int acumulationSize = 0;

    char **results = (char **)malloc(20 * sizeof(char *));
    for (int i = 0; i < 20; i++) {
        results[i] = (char *)malloc(20 * sizeof(char));
    }

    int counter = 0;

    for (int i = 0; i < strlen(sVar); i++)
    {   
        char temp[ARRAY_SIZE];
        int tempSize = 0;

        if ((i + 10) > strlen(sVar) )
        {
            break;
        }

        for (int j = i; j < i + 10; j++)
        {
            temp[tempSize++] = sVar[j]; 
        }

        temp[tempSize] = '\0';
        strcpy(acumulation[acumulationSize++], temp);
        reverseString(temp);
        strcpy(acumulation[acumulationSize++], temp);
        strcpy(temp,"");
    }

    for (int i = 0; i < acumulationSize; i++)
    {
        for (int j = 0; j < acumulationSize; j++)
        {
            if (strcmp(acumulation[i], acumulation[j]) == 0 && i != j)
            {
                counter++;
            }

            if (counter > 1)
            {
                bool flag = true;

                for (int k = 0; k < resultsSize; k++)
                {
                    if (strcmp(results[k], acumulation[j]) == 0)
                    {
                        flag = false;
                        break;
                    }
                }

                if (flag)
                {
                    strcpy(results[resultsSize++], acumulation[i]);
                    break;
                }

                break;
            }
        }

        counter = 0;
    }    

    return results;
}

void reset() {
  printf("\033[1;0m");
}

void green() {
  printf("\033[1;32m");
}

void yellow() {
  printf("\033[1;33m");
}

void red() {
  printf("\033[1;31m");
}