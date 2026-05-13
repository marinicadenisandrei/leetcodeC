/* Leetcode - 468. Validate IP Address (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define ARRAY_SIZE 50
#define NUMBER_OF_TESTS 3

void reset ();
void green ();
void yellow ();
void red ();

char* validIPAddress(char *queryIpVar);
bool isHexString(char str[]);

int main()
{
    yellow();

    printf("Leetcode - 468. Validate IP Address (C language) - Medium\n");

    char queryIP[NUMBER_OF_TESTS][ARRAY_SIZE] = {"172.16.254.1","2001:0db8:85a3:0:0:8A2E:0370:7334","256.256.256.256"};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%s | ", validIPAddress(queryIP[test]));

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

bool isHexString(char str[]) {
    for (int k = 0; str[k] != '\0'; k++) {
        if (!isxdigit((unsigned char)str[k])) {
            return false;
        }
    }

    return true;
}

char* validIPAddress(char *queryIpVar)
{
    bool ipv4flag = true;
    bool ipv6flag = true;

    char ipv4copy[100];
    char ipv6copy[100];

    strcpy(ipv4copy, queryIpVar);
    strcpy(ipv6copy, queryIpVar);

    // IPv4 check
    char *partsipv4[4];
    int numbersipv4[4];
    int indexipv4 = 0;

    char *tokenipv4 = strtok(ipv4copy, ".");

    while (tokenipv4 != NULL && indexipv4 < 4) {
        partsipv4[indexipv4] = tokenipv4;
        numbersipv4[indexipv4] = atoi(partsipv4[indexipv4]);

        indexipv4++;

        tokenipv4 = strtok(NULL, ".");
    }

    if (indexipv4 != 4) {
        ipv4flag = false;
    }

    for (int k = 0; k < indexipv4; k++) {
        if (numbersipv4[k] < 0 || numbersipv4[k] > 255) {
            ipv4flag = false;
        }
    }

    // IPv6 check
    char *partsipv6[8];
    int indexipv6 = 0;

    char *tokenipv6 = strtok(ipv6copy, ":");

    while (tokenipv6 != NULL && indexipv6 < 8) {
        partsipv6[indexipv6] = tokenipv6;

        indexipv6++;

        tokenipv6 = strtok(NULL, ":");
    }

    if (indexipv6 != 8) {
        ipv6flag = false;
    }

    for (int k = 0; k < indexipv6; k++) {
        if (strlen(partsipv6[k]) > 4 || strlen(partsipv6[k]) == 0 || !isHexString(partsipv6[k])) {
            ipv6flag = false;
            break;
        }
    }

    if (ipv4flag) {
        return "IPv4";
    } else if (ipv6flag) {
        return "IPv6";
    }

    return "Neither";
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