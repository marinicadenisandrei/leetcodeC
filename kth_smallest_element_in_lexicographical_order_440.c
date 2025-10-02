/* Leetcode - 440. K-th Smallest in Lexicographical Order (C language) - Hard */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

void reset ();
void green ();
void yellow ();
void red ();

char* findKthNumber(int nVar, int kVar);

int main()
{   
    yellow();

    printf("Leetcode - 440. K-th Smallest in Lexicographical Order (C language) - ");

    red();

    printf("Hard\n");

    int n[NUMBER_OF_TESTS] = {13,1};
    int k[NUMBER_OF_TESTS] = {2,1};
    
    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%s | ", findKthNumber(n[test], k[test]));

        green();

        printf("Passed\n");
    }
    
    reset();

    return 0;
}

char* findKthNumber(int nVar, int kVar)
{
    char* result = malloc(ARRAY_SIZE);

    char candidates[ARRAY_SIZE][ARRAY_SIZE] = {""};
    int candidatesSize = 0;

    for (int i = 1; i <= nVar; i++)
    {
        char str[ARRAY_SIZE];
        sprintf(str, "%d", i);
        strcpy(candidates[candidatesSize++], str);
    }

    bool flag = true;
    int c = 0;

    while (flag)
    {
        flag = false;

        for (int i = 0; i < candidatesSize - 1 - c; i++)
        {
            if (candidates[i][0] > candidates[i + 1][0])
            {
                char temp[20];
                strcpy(temp, candidates[i]);
                strcpy(candidates[i], candidates[i + 1]);
                strcpy(candidates[i + 1], temp);

                flag = true;
            }
        }
        
        c++;
    }

    strcpy(result, candidates[kVar - 1]);
    
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