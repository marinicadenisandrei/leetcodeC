/* Leetcode - 383. Ransom Note (C language) - Easy */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

void reset ();
void green ();
void yellow ();
void red ();

bool canConstruct(char *ransomNoteVar, char *magazineVar);

int main()
{
    yellow();

    printf("Leetcode - 383. Ransom Note (C language) - ");

    green();

    printf("Easy\n");
    
    char ransomNote[NUMBER_OF_TESTS][ARRAY_SIZE] = {"a","aa","aa"};
    char magazine[NUMBER_OF_TESTS][ARRAY_SIZE] = {"b","ab","aab"};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%s | ", ((canConstruct(ransomNote[test], magazine[test])) ? "true" : "false"));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

bool canConstruct(char *ransomNoteVar, char *magazineVar)
{
    for (int i = 0; i < strlen(ransomNoteVar); i++)
    {
        bool flag = false;
        
        for (int j = 0; j < strlen(magazineVar); j++)
        {
            if (ransomNoteVar[i] == magazineVar[j])
            {
                for (int k = j; k < strlen(magazineVar); k++)
                {
                    magazineVar[j] = magazineVar[j + 1];
                }

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