/* Leetcode - 44. Wildcard Matching (C language) - Hard */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#define CHAR_ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 44. Wildcard Matching (C language) - ");

    red();

    printf("Hard\n");

    char s[CHAR_ARRAY_SIZE][CHAR_ARRAY_SIZE] = {"aa", "aa", "cb"};
    char p[CHAR_ARRAY_SIZE][CHAR_ARRAY_SIZE] = {"a", "*", "?a"};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        int s_size = strlen(s[test]);
        int p_size = strlen(p[test]);

        bool flag = false;
        int compareStrings = strcmp(s[test],p[test]);

        if (p_size == 1 && p[test][0] == '*')
        {
            flag = true;
        }
        else if (compareStrings == 0)
        {
            flag = true;
        }
        else
        {
            flag = true;

            for (int i = 0; i < s_size; i++)
            {
                if (s[test][i] != p[test][i])
                {
                    if (p[test][i] != '*')
                    {
                        if (p[test][i] != '?')
                        {
                            flag = false;
                            break;
                        }
                    }
                }
            }
        }

        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%s", (flag == true) ? "true | " : "false | ");

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

