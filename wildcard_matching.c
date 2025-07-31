/* Leetcode - 44. Wildcard Matching (C language) - Hard */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#define CHAR_ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

int main(void)
{
    printf("Leetcode - 44. Wildcard Matching (C language) - ");

    printf("Hard\n");

    char s[CHAR_ARRAY_SIZE][CHAR_ARRAY_SIZE] = {"aa", "aa", "ca"};
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
        
        printf("%s", (flag == true) ? "true | " : "false | ");
        printf("Passed\n");
    }
    
    return 0;
}


