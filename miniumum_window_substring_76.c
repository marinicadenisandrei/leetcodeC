/* Leetcode - 76. Minimum Window Substring - Hard */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

void minWindow(char s[ARRAY_SIZE], char t[ARRAY_SIZE]);
bool checkIfElementsAreThere(char tempChar[ARRAY_SIZE], char searchingElements[ARRAY_SIZE]);
void printStringBetweenIndexes(char s[ARRAY_SIZE], int start_index, int end_index);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 76. Minimum Window Substring - ");

    red();

    printf("Hard\n");

    char s[ARRAY_SIZE][ARRAY_SIZE] = {"ADOBECODEBANC", "a", "a"};
    char t[ARRAY_SIZE][ARRAY_SIZE] = {"ABC", "a", "aa"};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        minWindow(s[test], t[test]);  

        green(); 

        printf("Passed\n");
    }
    
    reset();

    return 0;
}

void minWindow(char s[ARRAY_SIZE], char t[ARRAY_SIZE])
{
    if (strlen(s) > strlen(t))
    {
        char tempString[ARRAY_SIZE] = "";
        int min = strlen(s);
        int index1 = 0;
        int index2 = 0;


        for (int i = 0; i < strlen(s); i++)
        {
            for (int j = i; j < strlen(s); j++)
            {
                strncat(tempString, &s[j], 1);

                if (checkIfElementsAreThere(tempString, t) && strlen(tempString) < min)
                {
                    min = strlen(tempString);
                    index1 = i;
                    index2 = j + 1; 
                    tempString[0] = '\0';
                }
            }

            tempString[0] = '\0';
        }

        printStringBetweenIndexes(s, index1, index2);
    }
    else if (strlen(s) == 1 && strlen(t) == 1 && s[0] == t[0])
    {
        printf("%c | ", s[0]);
    }
    
    else
    {
        printf("\"\" | ");
    }
}

bool checkIfElementsAreThere(char tempChar[ARRAY_SIZE], char searchingElements[ARRAY_SIZE])
{
    bool flag = false;

    for (int j = 0; j < strlen(searchingElements); j++)
    {
        flag = false;

        for (int i = 0; i < strlen(tempChar); i++)
        {
            if (searchingElements[j] == tempChar[i])
            {
                flag = true;
                break;
            }
        }

        if (!flag)
        {
            return false;
        }
    }

    return true;
}

void printStringBetweenIndexes(char s[ARRAY_SIZE], int start_index, int end_index)
{
    for (int i = start_index; i < end_index; i++)
    {
        printf("%c", s[i]);
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

