/* Leetcode - 483. Smallest Good Base (C language) - Hard*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

char* smallestGoodBase(char *nVar);
char *toBase(const char *nVar, int base);
bool checkOnesString(const char *str);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 483. Smallest Good Base (C language) - ");

    red();

    printf("Hard\n");

    char n[NUMBER_OF_TESTS][ARRAY_SIZE] = {"13","4681","1000000000000000000"};
    
    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%s | ", smallestGoodBase(n[test]));

        green();

        printf("Passed\n");
    }

    reset();

    return 0;
}

char* smallestGoodBase(char *nVar)
{
    long long nVarInt = atoll(nVar);   
    static char result[32];

    for (long long i = 2; i < nVarInt - 1; i++)
    {
        if (checkOnesString(toBase(nVar, i)))
        {
            sprintf(result, "%lld", i);   
            return result;                
        }
    }

    sprintf(result, "%lld", nVarInt - 1); 
    return result;
}

char *toBase(const char *nVar, int base) {
    unsigned long long n = strtoull(nVar, NULL, 10);

    static char buf[32];          
    int i = sizeof(buf) - 1;
    buf[i] = '\0';

    if (n == 0) { buf[--i] = '0'; return &buf[i]; }

    while (n > 0) {
        buf[--i] = '0' + (n % base); 
        n /= base;                   
    }
    return &buf[i];
}

bool checkOnesString(const char *str)
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] != '1')
        {
            return false;
        }
    }
    
    return true;
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
