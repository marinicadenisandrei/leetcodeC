/* Leetcode - 388. Longest Absolute File Path (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ARRAY_SIZE 100
#define NUMBER_OF_TESTS 3

void reset ();
void green ();
void yellow ();
void red ();

int lengthLongestPath(char *input);

int main()
{
    yellow();

    printf("Leetcode - 388. Longest Absolute File Path (C language) - Medium\n");

    char input[NUMBER_OF_TESTS][100] = {"dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext","dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext","a"};
    
    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", lengthLongestPath(input[test]));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

int lengthLongestPath(char *input)
{   
    int result = 0;

    int nestedLen[10] = {0};
    int nestedLenSize = 0;

    int tempSize = 0;
    int historyLoc = 0;

    bool isGlobalFile = false;

    int i = 0;
    while (input[i] != '\n' && input[i] != '\0')
    {
        nestedLen[0]++;
        i++;
    }

    nestedLen[0]++;

    for (int i = 0; i < strlen(input) - 1; i++)
    {
        if (input[i] == '\n')
        {
            int location = 0;
            int inSize = 0;
            int j = i + 1;
            bool isFile = false;

            while (input[j] == '\t')
            {
                location++;
                j++;
            }

            while (input[j] != '\n' && input[j] != '\0')
            {
                if (!isFile && input[j] == '.')
                {
                    isFile = true;
                }
                
                inSize++;
                j++;
            }

            if (location > historyLoc)
            {
                nestedLen[location] = inSize;
                historyLoc = location;
                nestedLenSize = location;
            }
            else if (location == historyLoc)
            {
                int sumVar = 0;

                for (int j = 0; j <= nestedLenSize; j++)
                {
                    sumVar += nestedLen[j];
                }
                
                if (isFile)
                {
                    result = (result < sumVar) ? sumVar : result;
                }
            }
            
            else
            {
                int sumVar = 0;
                bool isFile = false;

                for (int j = 0; j <= nestedLenSize; j++)
                {
                    sumVar += nestedLen[j];
                }

                if (isFile)
                {
                    result = (result < sumVar) ? sumVar : result;
                }

                location--;
                historyLoc = location;
            }

            if (!isGlobalFile && isFile == true)
            {
                isGlobalFile = true;
            }
        }
    }

    int sumVar = 0;

    for (int j = 0; j <= nestedLenSize; j++)
    {
        sumVar += nestedLen[j];
    }

    result = (result < sumVar) ? sumVar : result;
    
    if (!isGlobalFile)
    {
        return 0;
    }

    return result + nestedLenSize - 1;
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