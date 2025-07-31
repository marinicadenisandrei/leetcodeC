/* Leetcode - 273. Integer to English Words (C language) - Hard */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

char numbers[ARRAY_SIZE][ARRAY_SIZE] = {"One","Two","Three","Four","Five","Six","Seven","Nine"};
char zecimals[ARRAY_SIZE][ARRAY_SIZE] = {"Ten","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};

char* numberToWords(int numVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 273. Integer to English Words (C language) - ");

    red();

    printf("Hard\n");

    int num[NUMBER_OF_TESTS] = {123,12345,1234567};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        char *result = numberToWords(num[test]);

        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%s | ", result);

        green();

        printf("Passed\n");

        free(result);
    }

    reset();
    
    return 0;
}

char* numberToWords(int numVar)
{
    char str[10];
    sprintf(str, "%d", numVar);
    int counter = 0;
    int strSize = 0;
    int numVar_copy = numVar;
    bool flag = false;

    char *result = (char *)malloc(70 * sizeof(char));
    char temp[100] = "";

    while (numVar > 0)
    {
        strSize++;
        numVar /= 10;
    }

    for (int i = strSize - 1; i >= 0; i--)
    {
        switch (counter)
        {
        case 0:
        {
            strcpy(temp, numbers[(str[i] - '0') - 1]);
            strcat(temp, " ");
            break;   
        }
        case 1:
        {
            strcpy(temp, zecimals[(str[i] - '0') - 1]);
            strcat(temp, " ");
            break;
        }
        case 2:
        {
            strcpy(temp, numbers[(str[i] - '0') - 1]);
            strcat(temp, " Hundred ");
            break;
        }
        case 3:
        {
            if (str[i] == '2' && str[i - 1] == '1')
            {
                strcpy(temp, "Twelve ");
                flag = true;
            }
            else
            {
                strcpy(temp, numbers[(str[i] - '0') - 1]);
            }

            strcat(temp, " Thousand ");
            break;
        }
        case 4:
        {
            strcpy(temp, zecimals[(str[i] - '0') - 1]);
            strcat(temp, " ");
            break;
        }
        case 5:
        {
            strcpy(temp, numbers[(str[i] - '0') - 1]);
            strcat(temp, " Hundred ");
            break;
        }
        case 6:
        {
            strcpy(temp, numbers[(str[i] - '0') - 1]);
            strcat(temp, " Million ");
            break;
        }
        default:
            break;
        }

        strcat(temp, result);
        strcpy(result, "");
        strcpy(result, temp);
        strcpy(temp, "");

        if (flag)
        {
            break;
        }
        
        counter++;
    }

    return result;
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