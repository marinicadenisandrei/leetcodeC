/* Leetcode - 332. Reconstruct Itinerary (C language) - Hard */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ARRAY_SIZE 10
#define NUMBER_OF_TESTS 2

char** findItinerary(char ticketsVar[ARRAY_SIZE][2][ARRAY_SIZE], int ticketsVarSize);
void printArray(char **array, int arraySize);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    printf("Leetcode - 332. Reconstruct Itinerary (C language) - ");

    red();

    printf("Hard\n");

    char tickets[NUMBER_OF_TESTS][ARRAY_SIZE][2][ARRAY_SIZE] = {{{"MUC","LHR"},{"JFK","MUC"},{"SFO","SJC"},{"LHR","SFO"}}, {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}}};
    int ticketsSize[NUMBER_OF_TESTS] = {4,5};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        printf("Test %i: ", test + 1);

        reset();

        printArray(findItinerary(tickets[test], ticketsSize[test]), ticketsSize[test] + 1);

        green();

        printf("Passed\n");
    }

    reset();
    
    return 0;
}

void printArray(char **array, int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        printf("%s%s%s", (i == 0 ? "[" : ""), array[i], (i < arraySize - 1 ? ", " : "] | "));
    }
}

char** findItinerary(char ticketsVar[ARRAY_SIZE][2][ARRAY_SIZE], int ticketsVarSize)
{
    char back[ARRAY_SIZE][ARRAY_SIZE] = {""};
    int backSize = 0;

    char front[ARRAY_SIZE][ARRAY_SIZE] = {""};
    int frontSize = 0;

    char **result = (char **)malloc((ARRAY_SIZE) * sizeof(char *));
    int resultSize = 0;

    strcpy(back[backSize++], ticketsVar[0][0]);
    strcpy(back[backSize++], ticketsVar[0][1]);

    char lastStation[ARRAY_SIZE] = "";
    strcpy(lastStation, ticketsVar[0][1]);

    bool flag = true;

    while (flag)
    {
        flag = false;

        for (int i = 1; i < ticketsVarSize; i++)
        {
            if (strcmp(lastStation, ticketsVar[i][0]) == 0)
            {
                strcpy(lastStation, ticketsVar[i][1]);
                strcpy(back[backSize++], ticketsVar[i][1]);

                flag = true;

                for (int j = i; j < ticketsVarSize - 1; j++)
                {  
                    strcpy(ticketsVar[j][0], ticketsVar[j + 1][0]);
                    strcpy(ticketsVar[j][1], ticketsVar[j + 1][1]);
                }

                break;

                ticketsVarSize--;
            }
        }
    }

    flag = true;
    strcpy(lastStation, ticketsVar[0][0]);

    while (flag)
    {
        flag = false;

        for (int i = 1; i < ticketsVarSize; i++)
        {
            if (strcmp(lastStation, ticketsVar[i][1]) == 0)
            {
                strcpy(lastStation, ticketsVar[i][0]);
                strcpy(front[frontSize++], ticketsVar[i][0]);

                flag = true;
            }
        }
    }

    for (int i = 0; i < frontSize; i++)
    {
        result[resultSize] = (char *)malloc(ARRAY_SIZE * sizeof(char));
        strcpy(result[resultSize++], front[i]);
    }
    
    for (int i = 0; i < backSize; i++)
    {
        result[resultSize] = (char *)malloc(ARRAY_SIZE * sizeof(char));
        strcpy(result[resultSize++], back[i]);
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