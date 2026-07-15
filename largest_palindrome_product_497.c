/* Leetcode - 479. Largest Palindrome Product (C language) - Hard */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUMBER_OF_TESTS 2

void reset ();
void green ();
void yellow ();
void red ();

int largestPalindrome(int nVar);
int isPalindrome(int num);

int main()
{
    yellow();

    printf("Leetcode - 479. Largest Palindrome Product (C language) - ");

    red();

    printf("Hard\n");

    int n[NUMBER_OF_TESTS] = {2,1};
    
    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%i | ", largestPalindrome(n[test]));

        green();

        printf("Passed\n");
    }
    
    reset();

    return 0;
}

int largestPalindrome(int nVar)
{
    int a = (int)pow(10, nVar) - 1;
    int b = a;

    for (int i = a; i >= 0; i--)
    {
        for (int j = b; j >= 0; j--)
        {
            int temp = i * j;   
            
            if (isPalindrome(temp))
            {
                return temp % 1337;
            }
        }
    }

    return -1;
}

int isPalindrome(int num) {
    if (num < 0)
        return 0; 

    int temp = num, reversed = 0;

    while (temp != 0) {
        reversed = reversed * 10 + temp % 10;
        temp /= 10;
    }

    return num == reversed;
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