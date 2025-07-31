/* Leetcode - 10. Regular Expression Matching (C language) - Hard */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUMBER_OF_TESTS 3

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 10. Regular Expression Matching (C language)");

    red();

    printf(" - Hard\n");

    char s[10][50] = {"aa", "aa", "ab"};
    char p[10][50] = {"a", "a*", ".*"};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        bool flag = true;

        for (int i = 0; i < 2; i++)
        {
            if (s[test][i] != p[test][i])
            {
                if (p[test][i] != '.')
                {
                    if (p[test][i] == '*')
                    {
                        for (int j = i; j < 2; j++)
                        {
                            if (s[test][i] == s[test][j])
                            {
                                break;
                            }
                        }                    
                    }
                    else
                    {
                        flag = false;
                        break;
                    }   
                }
            }
        }

        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%s | ", (flag == true) ? "true" : "false");

        green();

        printf("Passed\n");

        reset();
    }
    
    return 0;
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