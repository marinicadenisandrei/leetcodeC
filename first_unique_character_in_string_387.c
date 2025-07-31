/* Leetcode - 387. First Unique Character in a String - Easy */

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

int firstUniqChar(char *s);

int main()
{
    yellow();

    printf("Leetcode - 387. First Unique Character in a String - ");

    green();

    printf("Easy\n");

    char s[NUMBER_OF_TESTS][ARRAY_SIZE] = {"leetcode","loveleetcode","aabb"};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", firstUniqChar(s[test]));

        green();

        printf("Passed\n");
    }
    
    reset();

    return 0;
}

int firstUniqChar(char *s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        bool flag = true;

        for (int j = 0; j < strlen(s); j++)
        {
            if (i != j && s[i] == s[j])
            {
                flag = false;
            }
        }

        if (flag)
        {
            return i;
        }
    }

    return -1;
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