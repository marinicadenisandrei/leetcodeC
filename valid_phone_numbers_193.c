/* Leetcode - 193. Valid Phone Numbers (C language) - Easy */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ARRAY_SIZE 45

void validPhoneNumbers(char *file);
bool validSyntax(char *phone);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 193. Valid Phone Numbers (C language) - ");

    green();

    printf("Easy\n");

    char file[ARRAY_SIZE] = "987-123-4567\n123 456 7890\n(123) 456-7890\n";
    
    printf("Test 1: \n");

    reset();

    validPhoneNumbers(file);

    green();

    printf("Passed\n");

    reset();

    return 0;
}

bool validSyntax(char *phone)
{
    char database1[20] = "xxx-xxx-xxxx";
    char database2[20] = "(xxx) xxx-xxxx";
    bool flag1 = true;
    bool flag2 = true;

    for (int i = 0; i < strlen(phone); i++)
    {
        if (database1[i] == 'x' && phone[i] != '-')
        {
            continue;
        }
        else if (database1[i] == phone[i])
        {
            continue;
        }
        else
        {
            flag1 = false;
        }
    }

    for (int i = 0; i < strlen(phone); i++)
    {
        if (database2[i] == 'x' && phone[i] != '-')
        {
            continue;
        }
        else if (database2[i] == phone[i])
        {
            continue;
        }
        else
        {
            flag2 = false;
        }
    }
     
    if (flag1 == true || flag2 == true)
    {
        return true;
    }
    
    return false;
}

void validPhoneNumbers(char *file)
{
    char temp[20];
    int tempSize = 0;

    for (int i = 0; i < strlen(file); i++)
    {
        if (file[i] != '\n')
        {
            temp[tempSize++] = file[i];
        }
        else
        {
            temp[tempSize] = '\0';

            if (validSyntax(temp))
            {
                printf("%s\n", temp);
            }
            
            temp[0] = '\0';
            tempSize = 0;
        }
    }

    printf("| ");
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