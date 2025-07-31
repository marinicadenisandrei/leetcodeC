/* Leetcode - 129. Sum Root to Leaf Numbers (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 2

int sumNumbers(int *rootVar, int rootVarSize);
int increaseAndReturnSize(int *rootVar, int rootVarSize);
int returnDepth(int *rootVar, int rootVarSize);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();
    
    printf("Leetcode - 129. Sum Root to Leaf Numbers (C language) - Medium\n");
    
    int root[ARRAY_SIZE][ARRAY_SIZE] = {{1,2,3}, {4,9,0,5,1}};
    int rootSize[ARRAY_SIZE] = {3, 5};
    
    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();
        
        printf("Test %i: ", test + 1);
        
        reset();
        
        printf("%i | ", sumNumbers(root[test], rootSize[test]));
        
        green();
        
        printf("Passed\n");
    }
    
    reset();

    return 0;
}

int increaseAndReturnSize(int *rootVar, int rootVarSize)
{
    int power = 1;
    int copySize = rootVarSize;
    
    while(rootVarSize > 0)
    {
        rootVarSize -= power;
        power *= 2;
    }
    
    rootVarSize *= ((rootVarSize < 0) ? -1 : 1);
    
    for (int i = 0; i < rootVarSize; i++, copySize++)
    {
        rootVar[copySize] = 0;
    }
    
    return copySize;
}

int returnDepth(int *rootVar, int rootVarSize)
{
    int power = 1;
    
    while(rootVarSize > 0)
    {
        rootVarSize -= power;
        power *= 2;
    }

    return power / 2;
}

int sumNumbers(int *rootVar, int rootVarSize)
{
    
    rootVarSize = increaseAndReturnSize(rootVar, rootVarSize);
    int increment = returnDepth(rootVar, rootVarSize);
    int copy_increment = increment;
    int lines = (increment / 2) + 1;
    int number = 0;
    int counter = 0;
    
    int formationArray[ARRAY_SIZE][ARRAY_SIZE] = {0};
    
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < copy_increment; j++)
        {
            formationArray[i][j] = number;
            
            if (counter == increment - 1)
            {
                number++;
                counter = 0;
            }
            else
            {
                counter++;
            }
        }
        
        counter = 0;
        increment /= 2;
    }
    
    int mulNumber = 1;
    
    for (int i = 0; i < lines - 1; i++)
    {
        mulNumber *= 10;
    }
    
    int sum = 0;
    int numberFormation = 0;
    int forMulNumber = mulNumber;
    
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < copy_increment; j++)
        {
            numberFormation += forMulNumber * rootVar[formationArray[j][i]];
            forMulNumber /= 10;
            
            if (rootVar[formationArray[j][i]] == 0)
            {
                numberFormation /= 10;
                break;
            }
        }
        
        sum += numberFormation;
        numberFormation = 0;
        forMulNumber = mulNumber;
    }
    
    return sum;
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