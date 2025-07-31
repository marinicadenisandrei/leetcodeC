/* Leetcode - 125. Valid Palindrome */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define NUMBER_OF_TESTS 3

int removeSpaces(char string[], int size);

int main(void)
{
    printf("Leetcode - 125. Valid Palindrome\n");
    
    char s[10][100] = {"A man, a plan, a canal: Panama","race a car"," "};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        int s_size = strnlen(s[test], sizeof(s[test]));

        s_size = removeSpaces(s[test], s_size);

        char *pStart = s[test];
        char *pEnd = &s[test][s_size-1];
        bool flagPal = true;

        for (int i = 0; i < s_size; i++)
        {   

            if (tolower(*(pStart+i)) != tolower(*(pEnd-i)))
            {
                flagPal = false;
                break;
            }

        }

        printf("Test %i: %s | Passed\n", test+1, (flagPal) ? "true" : "false");
    }
    
}

int removeSpaces(char string[], int size)
{
    char invalidCharacters[] = " ,:!?.";
    bool flagFinder = false;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < strnlen(invalidCharacters, sizeof(invalidCharacters)); j++)
        {
            if (string[i] == invalidCharacters[j])
            {   
                for (int k = i; k < size; k++)
                {
                    string[k] = string[k+1];
                }

                size--;
                flagFinder = true;
                break;
            }
            else
            {
                flagFinder = false;
            }
        }

        if (flagFinder == true)
        {
            i = 0;
        }
    }
    
    return size;
}

