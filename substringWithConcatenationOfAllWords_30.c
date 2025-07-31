#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NUMBER_OF_TESTS 3
#define CHARACTER_ARRAY_SIZE 50
#define ARRAY_SIZE 30

int findSubstringInString(char string[], char substring[]);
int permutationsWord(char wordsArray[ARRAY_SIZE][CHARACTER_ARRAY_SIZE], int wordsArraySize, char outputArray[ARRAY_SIZE][CHARACTER_ARRAY_SIZE]);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    printf("Leetcode - 30. Substring with Concatenation of All Words - ");

    red();

    printf("Hard\n");

    char s[ARRAY_SIZE][CHARACTER_ARRAY_SIZE] = {"barfoothefoobarman", "wordgoodgoodgoodbestword", "barfoofoobarthefoobarman"};
    char words[ARRAY_SIZE][ARRAY_SIZE][CHARACTER_ARRAY_SIZE] = {{"foo","bar"}, {"word","good","best","word"}, {"bar","foo","the"}};
    int wordsSize[ARRAY_SIZE] = {2,4,3};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        char output[ARRAY_SIZE][CHARACTER_ARRAY_SIZE] = {""};
        int outputSize = permutationsWord(words[test], wordsSize[test], output);;

        int indexArray[CHARACTER_ARRAY_SIZE] = {0};
        int indexArraySize = 0;

        for (int i = 0; i < outputSize; i++)
        {
            if (findSubstringInString(s[test], output[i]) != -1)
            {
                indexArray[indexArraySize] = findSubstringInString(s[test], output[i]);
                indexArraySize++;
            }
        }

        green();

        printf("Test %i: ", test + 1);

        reset();
        
        printf("%s", (indexArraySize == 0) ? "[] | " : "");

        for (int i = 0; i < indexArraySize; i++)
        {
            printf("%s%i%s", (i == 0) ? "[" : "", indexArray[i], (i < indexArraySize - 1 ? ", " : "] | "));
        }   

        green();

        printf("Passed\n");

        reset();
    }
    
    return 0;
}

int findSubstringInString(char string[], char substring[])
{
    char *result = strstr(string, substring);

    if (result != NULL) {
        int index = result - string;
        return index;
    } 
    else 
    {
        return -1;
    }
}

int permutationsWord(char wordsArray[ARRAY_SIZE][CHARACTER_ARRAY_SIZE], int wordsArraySize, char outputArray[ARRAY_SIZE][CHARACTER_ARRAY_SIZE])
{
    int numberOfPermutations = 1;

    char numbersIndex[] = "";
    int numbersIndexStart = 0;

    for (int i = 0; i < wordsArraySize; i++)
    {
        numbersIndex[i] = (char) (i + '0');
        numberOfPermutations *= (i+1);
    } 
    
    char c[] = "";

    int index1 = 0;
    int index2 = 1;

    int counter = 0;
    
    while (counter < numberOfPermutations)
    {
        if (index2 < wordsArraySize)
        {
            c[0] = numbersIndex[index1];
            numbersIndex[index1] = numbersIndex[index2];
            numbersIndex[index2] = c[0];
        }

        if (index2 == wordsArraySize)
        {
            c[0] = numbersIndex[wordsArraySize - 1];
            numbersIndex[wordsArraySize - 1] = numbersIndex[0];
            numbersIndex[0] = c[0];

            index1 = -1;
            index2 = 0;
        }

        index1++;
        index2++; 

        for (int i = 0; i < wordsArraySize; i++)
        {
            strcat(outputArray[counter], wordsArray[numbersIndex[i] - '0']);
        }
    
        counter++;
    }

    return counter;
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