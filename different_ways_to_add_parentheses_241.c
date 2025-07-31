/* Leetcode - 241. Different Ways to Add Parentheses (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ARRAY_SIZE 20 
#define NUMBER_OF_TESTS 2

int resultFinalSize = 0;

int* diffWaysToCompute(char *expressionVar);
int returnResultExpression(char *expression);
int returnResultExpressionReverse(char *expression);
void printArray(int *array, int arraySize);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 241. Different Ways to Add Parentheses (C language) - Medium\n");

    char expression[NUMBER_OF_TESTS][ARRAY_SIZE] = {"2-1-1","2*3-4*5"}; 

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        int *output = diffWaysToCompute(expression[test]);
        printArray(output, resultFinalSize);
        free(output);
        resultFinalSize = 0;

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

void printArray(int *array, int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        printf("%s%i%s", ((i == 0) ? "[" : ""), array[i], ((i < arraySize - 1) ? ", " : "] | "));
    }
}

int* diffWaysToCompute(char *expressionVar)
{
    int start = 0;
    int end = 2;  
    
    int *resultFinal = (int*)malloc(ARRAY_SIZE * sizeof(int));


    while (end < strlen(expressionVar))
    {
        char startExpression[ARRAY_SIZE] = "";
        int startExpressionSize = 0;

        for (int i = 0; i < start; i++)
        {
            startExpression[startExpressionSize++] = expressionVar[i];
        }

        char numberChar[10] = "";
        int numberCharSize = 0;
        
        int number1 = expressionVar[start] - '0'; 
        int number2 = expressionVar[end] - '0'; 
        int result = 0;

        if (expressionVar[start + 1] == '-') 
        {
            result = number1 - number2;
        }
        else if (expressionVar[start + 1] == '*')
        {
            result = number1 * number2;
        }
        else if (expressionVar[start + 1] == '/')
        {
            result = number1 / number2;
        }
        else if (expressionVar[start + 1] == '+')
        {
            result = number1 + number2;
        }

        if (result < 0)
        {
            startExpression[startExpressionSize++] = '-';
            result = -result; 
        }

        while (result > 0)
        {
            numberChar[numberCharSize++] = (result % 10) + '0';
            result /= 10;
        }

        if (numberCharSize == 0)
        {
            startExpression[startExpressionSize++] = '0';
        }
        
        for (int i = numberCharSize - 1; i >= 0; i--)
        {
            startExpression[startExpressionSize++] = numberChar[i];
        }

        for (int i = end + 1; i < strlen(expressionVar); i++)
        {
            startExpression[startExpressionSize++] = expressionVar[i];
        }

        startExpression[startExpressionSize++] = '\0';

        char tempExpr[10] = "";
        strcpy(tempExpr, startExpression);
        
        resultFinal[resultFinalSize++] = returnResultExpression(startExpression);

        strcpy(startExpression, tempExpr);
        resultFinal[resultFinalSize++] = returnResultExpressionReverse(startExpression);

        start += 2;
        end += 2;
    }

    return resultFinal;
}

int returnResultExpression(char *expression)
{
    int counter = 0;
    int breakValue = 3;
    
    int len = strlen(expression);
    expression[len] = '@';
    expression[len + 1] = '\0';

    int globalSign = 1;
    int output = 0;

    while (strlen(expression) > breakValue)
    {
        int result = 0;

        char charNumber1[10] = "";
        int charNumber1Size = 0;

        char charNumber2[10] = "";
        int charNumber2Size = 0;

        int number1 = 0;
        int number2 = 0;

        int i = 0;
        int stop = 0;

        char temp[10] = "";
        int tempSize = 0;

        char numberChar[10] = "";
        int numberCharSize = 0;

        int sign1 = 1;
        int sign2 = 1;

        for (i = 0; i < strlen(expression); i++)
        {    
            charNumber1[charNumber1Size++] = expression[i];

            if (isalnum(expression[i]) && (!isalnum(expression[i + 1])))
            {
                break;
            }
        }
        
        charNumber1[charNumber1Size++] = '\0';
        
        for (int j = i; j < strlen(expression) - 1; j++)
        {
            if (!isalnum(expression[j - 1]) && !isalnum(expression[j]) && isalnum(expression[j + 1]))
            {
                i = j;
                break;
            }
            else if (!isalnum(expression[j]) && isalnum(expression[j + 1]))
            {
                i = j + 1;
                break;
            }
            
        }
        
        for (i; i < strlen(expression) - 1; i++)
        {
            charNumber2[charNumber2Size++] = expression[i];
            

            if (isalnum(expression[i]) && (!isalnum(expression[i + 1])))
            {
                stop = i + 1;
                break;
            }
        }

        // printf("%s %s\n", charNumber1, charNumber2);
        sign1 = ((charNumber1[0] == '-') ? -1 : 1);
        sign2 = ((charNumber2[0] == '-') ? -1 : 1);
        
        if (sign1 < 0 || sign2 < 0)
        {
            globalSign *= -1;
        }
        
        i = (!isalnum(charNumber1[0]) ? 1 : 0);
        int mulNo = ((i == 0) ? strlen(charNumber1) - 1 : strlen(charNumber1) - 2);
        int mul = 1;
        
        for (int i = 0; i < mulNo; i++)
        {
            mul *= 10;
        }

       for (int i = 0; i < strlen(charNumber1); i++)
       {
            number1 += (charNumber1[i] - '0') * mul;
            mul /= 10;
       }
       
        i = (!isalnum(charNumber2[0]) ? 1 : 0);
        mulNo = ((i == 0) ? strlen(charNumber2) - 1 : strlen(charNumber2) - 2);
        mul = 1;

        for (int i = 0; i < mulNo; i++)
        {
            mul *= 10;
        }

        for (i; i < strlen(charNumber2); i++)
        {
            number2 += (charNumber2[i] - '0') * mul;
            mul /= 10;
        }

        if (expression[1] == '-')
        {
            result = number1 - number2;
        }
        else if (expression[1] == '+')
        {
            result = number1 + number2;
        }
        else if (expression[1] == '*')
        {
            result = number1 * number2;
        }
        else if (expression[1] == '/')
        {
            result = number1 / number2;
        }

        output = result;
        
        while (result > 0)
        {
            numberChar[numberCharSize++] = (result % 10) + '0';
            result /= 10;
        }
        
        numberChar[numberCharSize++] = '\0';

        for (int i = numberCharSize - 2; i >= 0; i--)
        {
            temp[tempSize++] = numberChar[i];
        }
        
        for (int i = stop; i <= strlen(expression); i++)
        {
            temp[tempSize++] = expression[i];
        }

        strcpy(expression, temp);

        // counter++;    
        // printf("%s\n", expression); 
           
        // counter++;
    }

    // printf("%i\n", output * globalSign);

    return output * globalSign;
    // return output;

    // printf("\n===================\n");
}

int returnResultExpressionReverse(char *expression)
{
    int breakVar = ((strlen(expression) == 3) ? 3 : 4);

    char tempVar[10] = "";
    tempVar[0] = '@';
    tempVar[1] = '\0';

    int output;
    int globalSign = 1;

    strcat(tempVar, expression);
    strcpy(expression, tempVar);

    while (strlen(expression) > breakVar)
    {
        int result = 0;
        char charNumber1[10] = "";
        int charNumber1Size = 0;

        char charNumber2[10] = "";
        int charNumber2Size = 0;

        int stop = 0;
        int stopExpression = 0;

        int sign1 = 1;
        int sign2 = 1;

        for (int i = strlen(expression) - 1; i >= 0; i--)
        {
            charNumber1[charNumber1Size++] = expression[i];

            if (!isalnum(expression[i - 2]) && expression[i - 1] == '-' && isalnum(expression[i]))
            {
                stop = i - 2;
                sign1 = -1;
                break;
            }
            else if (!isalnum(expression[i - 1]) && isalnum(expression[i]))
            {
                stop = i - 1;
                break;
            }
        }

        charNumber1[charNumber1Size++] = '\0';
        char reverse1[10] = "";
        int reverse1Size = 0;

        for (int i = strlen(charNumber1) - 1; i >= 0; i--)
        {
            reverse1[reverse1Size++] = charNumber1[i];
        }

        reverse1[reverse1Size++] = '\0';

        for (int i = stop - 1; i >= 0; i--)
        {
            charNumber2[charNumber2Size++] = expression[i];

            if (!isalnum(expression[i - 2]) && expression[i - 1] == '-' && isalnum(expression[i]))
            {
                stopExpression = i - 2;
                sign2 = -1;
                break;
            }
            else if (!isalnum(expression[i - 1]) && isalnum(expression[i]))
            {
                stopExpression = i - 1;
                break;
            }
        }

        charNumber2[charNumber2Size++] = '\0';
        char reverse2[10] = "";
        int reverse2Size = 0;

        for (int i = strlen(charNumber2) - 1; i >= 0; i--)
        {
            reverse2[reverse2Size++] = charNumber2[i];
        }

        reverse2[reverse2Size++] = '\0';

        int number1 = 0;
        int number2 = 0;

        int mulNo1 = ((reverse1[0] == '-') ? strlen(reverse1) - 2 : strlen(reverse1) - 1);
        int mulNo2 = ((reverse2[0] == '-') ? strlen(reverse2) - 2 : strlen(reverse2) - 1);
        
        int mul1 = 1;
        int mul2 = 1;

        for (int i = 0; i < mulNo1; i++)
        {
            mul1 *= 10;
        }

        for (int i = 0; i < mulNo2; i++)
        {
            mul2 *= 10;
        }

        for (int i = ((reverse1[0] == '-') ? 1 : 0); i < strlen(reverse1); i++)
        {
            number1 += (reverse1[i] - '0') * mul1;
            mul1 /= 10;
        }

        for (int i = ((reverse2[0] == '-') ? 1 : 0); i < strlen(reverse1); i++)
        {
            number2 += (reverse2[i] - '0') * mul2;
            mul2 /= 10;
        }

        if (expression[stop] == '-')
        {
            result = abs(number2 - number1);
        }
        else if (expression[stop] == '+')
        {
            result = number2 + number1;
        }
        else if (expression[stop] == '*')
        {
            result = number2 * number1;
        }
        else if (expression[stop] == '/')
        {
            result = number2 / number1;
        }

        if (number2 - number1 < 0 && expression[stop] == '-')
        {
            globalSign *= -1;
        }
        
        output = result;

        char temp[10] = "";
        strncat(temp, expression, stopExpression + 1);

        char tempNumber[10];
        char tempNumberSize = 0;

        while (result > 0)
        {
            tempNumber[tempNumberSize++] = (result % 10) + '0';
            result /= 10;
        }
        
        int lenTemp = strlen(temp);

        if (sign1 < 0 || sign2 < 0)
        {
            temp[lenTemp++] = '-';
            result *= -1;
            globalSign = -1;
        }

        for (int i = tempNumberSize - 1; i >= 0; i--)
        {
            temp[lenTemp++] = tempNumber[i];
        }
        temp[lenTemp++] = '\0';
        strcpy(expression, temp);
    }
    
    return output * globalSign;
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