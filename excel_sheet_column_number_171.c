#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ARRAY_SIZE 30
#define NUMBER_OF_TESTS 3

struct database
{
    char alphabet[ARRAY_SIZE];
    int alphabetSize;
};

const struct database AZ = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ", 25}; 

int titleToNumber(char *charcolumnTitleVar, struct database DB);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 171. Excel Sheet Column Number (C language) - ");

    green();

    printf("Easy\n");
    
    char charcolumnTitle[ARRAY_SIZE][NUMBER_OF_TESTS] = {"A","AB","ZY"};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ",titleToNumber(charcolumnTitle[test], AZ));   

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

int titleToNumber(char *charcolumnTitleVar, struct database DB)
{
    int number = 0;

    for (int i = strlen(charcolumnTitleVar) - 1, counter = 0; i >= 0; i--, counter++)
    {
        for (int j = 0; j <= DB.alphabetSize; j++)
        {
            if (DB.alphabet[j] == charcolumnTitleVar[i])
            {
                if (counter == 0)
                {
                    number += (j + 1);
                    break;
                }
                else
                {
                    number += 26 * (j + 1);
                    break;
                }
            }
        }
    }

    return number;
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