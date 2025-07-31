/* Leetcode - 93. Restore IP Addresses (C++ language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

int restoreIpAddresses(char *sVar, int s_SizeVar);
bool stringExistsInBigArray(char *string, char **stringArray, int stringArraySize);
bool checkValidity(char *charVar);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 93. Restore IP Addresses (C++ language) - Medium\n");

    char s[ARRAY_SIZE][ARRAY_SIZE] = {"25525511135", "0000", "101023"};
    int s_size[ARRAY_SIZE] = {11,4,6};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        restoreIpAddresses(s[test], s_size[test]);

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

bool stringExistsInBigArray(char *string, char **stringArray, int stringArraySize)
{
    for (int i = 0; i < stringArraySize; i++)
    {
        if (strcmp(string, stringArray[i]) == 0)
        {
            return true;
        }
    }

    return false;
}

bool checkValidity(char *charVar)
{   
    char string[ARRAY_SIZE];
    int stringSize = 0;

    int integerArray[4] = {};
    int sizeIntegerArray = 0;

    for (int i = 0; i < strlen(charVar); i++)
    {
        if (charVar[i] != '.')
        {
            string[stringSize] = charVar[i];
            stringSize++;
        }
        else
        {
            string[stringSize] = '\0';
            int integer = atoi(string);
            
            if (integer > 255)
            {
                return false;
            }

            if (string[0] == '0' && strlen(string) > 1)
            {
                return false;
            }
            
            string[0] = '\0';
            stringSize = 0;
        }
    }

    string[stringSize] = '\0';
    int integer = atoi(string);
    
    if (integer > 255)
    {
        return false;
    }

    if (string[0] == '0' && strlen(string) > 1)
    {
        return false;
    }

    return true;
}

int restoreIpAddresses(char *sVar, int s_SizeVar)
{   
    char **result = (char**)malloc(ARRAY_SIZE * sizeof(char*));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        result[i] = (char *)malloc(ARRAY_SIZE * sizeof(char));
        if (result[i] == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            return 1;
        }
    }
    
    int resultSize = 0;

    if (strlen(sVar) == 4)
    {
        char stringShort[ARRAY_SIZE];
        int stringShortSize = 0;

        for (int i = 0; i < 4; i++)
        {
            stringShort[stringShortSize] = sVar[i];
            stringShort[stringShortSize + 1] = '.';

            stringShortSize += 2;
        }

        stringShort[stringShortSize - 1] = '\0';

        printf("[%s] | ", stringShort);

        return 0;
    }
    
    int length = s_SizeVar;
    int divVar = 4;

    char order[ARRAY_SIZE] = "";
    int orderSize = 0;

    while (divVar > 0)
    {
        int r = length / divVar;
        length -= length / divVar;
        divVar--;

        char str[2];
        sprintf(str, "%d", r);

        order[orderSize] = str[0];
        orderSize++;
    }

    order[orderSize] = '\0';

    for (int i = orderSize - 1; i > 0; i--)
    {
        if ((order[i] - '0') < 3 && ((order[i - 1] - '0') - 1) > 0)
        {
            int first = order[i] - '0';
            first++;

            int second = order[i - 1] - '0';
            second--;

            order[i] = first + '0';
            order[i - 1] = second + '0';
        }
    }

    int offset = 0;

    for (int i = orderSize - 1; i >= 0; i--)
    {
        if (order[i] == '3')
        {
            offset++;
        }
        else
        {
            break;
        }
    }
    
    offset -= 1;

    char blocker[ARRAY_SIZE];
    int blockerSize = 0;

    blocker[0] = '\0';

    if (offset != 0)
    {
        int counter = 0;
        for (int i = 0; i < offset * 3; i++)
        {
            if (counter == 3)
            {
                blocker[blockerSize] = '.';
                blockerSize++;

                counter = 0;
            }

            counter++;

            blocker[blockerSize] = sVar[i];
            blockerSize++;
        }


        blocker[blockerSize] = '.';
        blocker[blockerSize + 1] = '\0';
    }
    
    char ipVar[ARRAY_SIZE] = "";
    int sizeIpVar = 0;

    int orderIndex = 0;

    for (int i = 0; i < 4 - offset; i++)
    {
        for (int j = 0; j < order[i] - '0'; j++)
        {
            ipVar[sizeIpVar] = sVar[orderIndex + (offset * 3)];
            sizeIpVar++;
            orderIndex++;
            
        }

        if (i < 3 - offset)
        {
            ipVar[sizeIpVar] = '.';
            sizeIpVar++;
        }
    }

    ipVar[sizeIpVar + 1] = '\0';
    
    if (checkValidity(ipVar))
    {
        if (!stringExistsInBigArray(ipVar, result, resultSize))
        {
            strcpy(result[resultSize], ipVar);
            resultSize++;
        }
    }

    int stoper = sizeIpVar - 2;

    for (int i = 0; i < 3 - offset; i++)
    {
        while (ipVar[stoper] != '.')
        {
            for (int j = stoper; j > 0; j--)
            {
                if (ipVar[j] == '.')
                {
                    char temp = ipVar[j];
                    ipVar[j] = ipVar[j + 1];
                    ipVar[j + 1] = temp;

                    if (checkValidity(ipVar))
                    {
                        if (!stringExistsInBigArray(ipVar, result, resultSize))
                        {
                            strcpy(result[resultSize], ipVar);
                            resultSize++;                            
                        }
                    }

                    break;
                }
            }
        }

        stoper -= 2;
    }

    for (int i = 0; i < strlen(ipVar); i++)
    {
        if (ipVar[i] == '.')
        {
            char temp = ipVar[i];
            ipVar[i] = ipVar[i - 1];
            ipVar[i - 1] = temp;

            if (checkValidity(ipVar))
            {
                if (!stringExistsInBigArray(ipVar, result, resultSize))
                {
                    strcpy(result[resultSize], ipVar);
                    resultSize++;
                }
            }
        }
    }

    for (int i = 0; i < resultSize; i++)
    {
        char temp[ARRAY_SIZE];
        temp[0] = '\0';

        strcat(temp, blocker);
        strcat(temp, result[i]);
        strcpy(result[i], temp);

        printf("%s%s%s", ((i == 0) ? "[" : ""), result[i], ((i < resultSize - 1) ? ", " : "] | "));
    }

    for (int i = 0; i < ARRAY_SIZE; i++) {
        free(result[i]);
    }

    free(result);

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