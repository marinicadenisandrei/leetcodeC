#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE 50
void transposeFile(char *fileVar);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 194. Transpose File (C language) - Medium\n");

    reset();
    
    char file[50] = "name age\nalice 21\nryan 30\n";
    green();
    printf("Test 1: \n");
    reset();
    transposeFile(file);
    green();
    printf("Passed");
    reset();

    return 0;
}

void transposeFile(char *fileVar)
{
    char columns[20][20] = {""};
    int columnsSize = 0;
    int realSize = 0;
    
    char temp[10];
    int tempSize = 0;
    
    for (int i = 0; i < strlen(fileVar); i++)
    {
        if (fileVar[i] != '\n' && fileVar[i] != ' ')
        {
            temp[tempSize++] = fileVar[i];   
        }
        else if (fileVar[i] == ' ')
        {
            temp[tempSize++] = ' ';
            temp[tempSize] = '\0';
            strcat(columns[columnsSize++],temp);
            temp[0] = '\0';
            tempSize = 0;
        }
        else if (fileVar[i] == '\n')
        {
            realSize = tempSize;
            temp[tempSize++] = ' ';
            temp[tempSize] = '\0';
            strcat(columns[columnsSize++],temp);
            temp[0] = '\0';
            tempSize = 0;
            columnsSize = 0;
        }
    }

    for (int j = 0; j < realSize; j++)
    {
        printf("%s%s", columns[j], ((j < realSize - 1) ? "\n" : "| "));
    }
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