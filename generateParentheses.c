/* Leetcode - 22. Generate Parentheses (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 50
#define NUMBER_OF_TESTS 2

void reset ();
void green ();
void yellow ();
void red ();

int generateBasicPar(int array[ARRAY_SIZE][ARRAY_SIZE], int arrayLen, int numberPar);

int main(void)
{
    yellow();

    printf("Leetcode - 22. Generate Parentheses (C language) - Medium\n");

    int nTest[5] = {3,1};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        int n = nTest[test];
        int output[ARRAY_SIZE][ARRAY_SIZE] = {};
        int sizeOutput = 0;

        sizeOutput = generateBasicPar(output, sizeOutput, n);

        char textPar[ARRAY_SIZE] = "";

        for (int i = 0; i < (n - 1) * 2; i += 2)
        {
            textPar[i] = '(';
            textPar[i+1] = ')';
        }
        
        int gap = 2;
        int indexStart = 0;
        int indexEnd = indexStart + gap - 1;
        int depth = n - 1;

        int indexOutput = 0;

        while (gap < n * 2)
        {
            for (int j = 0; j < depth; j++)
            {
                for (int i = 0; i < (n-1) * 2; i++)
                {
                    if (i == indexStart)
                    {
                        output[sizeOutput][indexOutput] = '(';
                        indexOutput++;
                    }
                    
                    output[sizeOutput][indexOutput] = textPar[i];
                    indexOutput++;

                    if (i == indexEnd)
                    {
                        output[sizeOutput][indexOutput] = ')';
                        indexOutput++;
                    }
                }
                
                indexOutput = 0;
                sizeOutput++;
                indexStart += gap;
                indexEnd += gap;
            }

            gap += 2;
            indexStart = 0;
            indexEnd = gap - 1;

            depth /= 2;
        }

        green();

        printf("Test %i: ", test + 1);

        reset();

        for (int i = 0; i < sizeOutput; i++)
        {
            printf("%s", (i == 0) ? "[" : "");

            for (int j = 0; j < n * 2; j++)
            {
                printf("%c", output[i][j]);
            }

            printf("%s", (i == sizeOutput - 1) ? "] | " : ", ");
        }

        green();

        printf("Passed\n");

        reset();
    }
    
    return 0;
}

int generateBasicPar(int array[ARRAY_SIZE][ARRAY_SIZE], int arrayLen, int numberPar)
{
    for (int i = 0; i < numberPar * 2; i++)
    {
        array[arrayLen][i] = (i < numberPar) ? '(' : ')';
    }

    arrayLen++;

    if (numberPar > 1)
    {
        for (int i = 0; i < numberPar * 2; i += 2)
        {
            array[arrayLen][i] = '(';
            array[arrayLen][i+1] = ')';
        }

        arrayLen++;
    }
    
    return arrayLen;
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