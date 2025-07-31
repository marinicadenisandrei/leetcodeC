/* Leetcode - 196. Delete Duplicate Emails (C language) - Easy */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ARRAY_SIZE 20

void deleteDuplicateEmails(char (*emailVar)[ARRAY_SIZE], int *emailVarSize);
void printArray(char (*arrayVar)[ARRAY_SIZE], int arrayVarSize);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 196. Delete Duplicate Emails (C language) - ");

    green();

    printf("Easy\n");

    char email[][ARRAY_SIZE] = {"john@example.com", "bob@example.com", "john@example.com"};
    int emailSize = 3;
    
    deleteDuplicateEmails(email, &emailSize);

    green();

    printf("Test 1: \n");

    reset();

    printArray(email, emailSize);

    green();

    printf("Passed\n");

    reset();

    return 0;
}

void printArray(char (*arrayVar)[ARRAY_SIZE], int arrayVarSize)
{
    for (int i = 0; i < arrayVarSize; i++) {
        printf("%s\n", arrayVar[i]);
    }

    printf(" | ");
}

void deleteDuplicateEmails(char (*emailVar)[ARRAY_SIZE], int *emailVarSize)
{
    for (int i = 0; i < *emailVarSize; i++)
    {
        for (int j = i + 1; j < *emailVarSize; j++)
        {
            if (strcmp(emailVar[i], emailVar[j]) == 0)
            {
                for (int k = j; k < *emailVarSize - 1; k++)
                {
                    strcpy(emailVar[k], emailVar[k + 1]);
                }

                (*emailVarSize)--;
                j--;
            }
        }
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

