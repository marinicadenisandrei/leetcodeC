/* Leetcode - 433. Minimum Genetic Mutation (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void reset ();
void green ();
void yellow ();
void red ();

int minMutation(char* startGeneVar, char* endGeneVar, char bankVar[ARRAY_SIZE][ARRAY_SIZE], int bankSizeVar);
int compareTwoStrings(char* str1, char* str2);

int main()
{
    yellow();

    printf("Leetcode - 433. Minimum Genetic Mutation (C language) - Medium\n");

    char startGene[NUMBER_OF_TESTS][ARRAY_SIZE] = {"AACCGGTT","AACCGGTT"};
    char endGene[NUMBER_OF_TESTS][ARRAY_SIZE] = {"AACCGGTA","AAACGGTA"};
    char bank[NUMBER_OF_TESTS][ARRAY_SIZE][ARRAY_SIZE] = {{"AACCGGTA"},{"AACCGGTA","AACCGCTA","AAACGGTA"}};
    int bankSize[NUMBER_OF_TESTS] = {1,3};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);
        
        reset();

        printf("%i | ", minMutation(startGene[test], endGene[test], bank[test], bankSize[test]));
        
        green();

        printf("Passed\n");
    }

    reset();
}

int compareTwoStrings(char* str1, char* str2)
{
    int counter = 0;

    for (int i = 0; i < strlen(str1); i++)
    {
        if (str1[i] != str2[i])
        {
            counter++;
        }
    }
    
    return counter;
}

int minMutation(char* startGeneVar, char* endGeneVar, char bankVar[ARRAY_SIZE][ARRAY_SIZE], int bankSizeVar)
{
    int counter = 0;

    for (int i = 0; i < bankSizeVar; i++)
    {
        int counter1 = compareTwoStrings(bankVar[i], startGeneVar);
        int counter2 = compareTwoStrings(bankVar[i], endGeneVar);

        if (abs(counter1 - counter2) <= 1)
        {
            counter++;
        }
    }

    return counter;
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