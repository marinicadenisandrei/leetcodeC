/* Leetcode | 28. Find the Index of the First Occurrence in a String */

#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>

int main(void)
{
    printf("Leetcode | 28. Find the Index of the First Occurrence in a String\n");

    char haystack[10][50] = {"sadbutsad", "leetcode"};
    char needle[10][50] = {"sad", "leeto"};

    for (int test = 0; test < 2; test++)
    {
        int sizeHaystack = strlen(haystack[test]);
        int sizeNeedle = strlen(needle[test]);

        bool flag = true;
        
        int reminder = 0;

        for (int i = 0; i < sizeHaystack; i++)
        {
            if (haystack[test][i] == needle[test][0])
            {
                reminder = i;

                for (int j = 0; j < sizeNeedle; j++)
                {
                    if (needle[test][j] == haystack[test][i])
                    {
                        flag = true;
                    }
                    else
                    {
                        flag = false;
                        i = reminder;
                        break;
                    }
                    i++;
                }
            }
            if (flag == true)
            {
                break;
            }
        }
        
        printf("Test %i: %i | Passed\n", test+1, (flag == true) ? reminder : -1);
    }
}

