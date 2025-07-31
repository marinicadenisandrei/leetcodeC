/* Leetcode - 36. Valid Sudoku (C language) - Medium */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 50
#define SUDOKU_SIZE 9
#define NUMBER_OF_TESTS 2

struct squares_database{
    int istart;
    int iend;
    int jstart;
    int jend;
};

struct squares_database squares[ARRAY_SIZE] = {{0,3,0,3}, {0,3,3,6}, {0,3,6,9}, {3,6,0,3}, {3,6,3,6}, {3,6,6,9}, {6,9,0,3}, {6,9,3,6}, {6,9,6,9}};

void printArrayOfChars(char array[ARRAY_SIZE], int arraySize);
void formatSquares(char array[ARRAY_SIZE][ARRAY_SIZE], int arraySize, int squareNumber, char arrayFormating[ARRAY_SIZE]);
void createVerticalBoard(char array[ARRAY_SIZE][ARRAY_SIZE], char verticalArray[ARRAY_SIZE][ARRAY_SIZE], int size);
int findLocationSquare(int index1, int index2);
bool checkDuplicates(char array[ARRAY_SIZE], int arraySize, char element);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();
        
    printf("Leetcode - 36. Valid Sudoku (C language) - Medium\n");
    
    char board[NUMBER_OF_TESTS][ARRAY_SIZE][ARRAY_SIZE] = {
        {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}},

        {{'8','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}}
    };

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        char verticalBoard[ARRAY_SIZE][ARRAY_SIZE] = {};
        char squareFormat[ARRAY_SIZE] = {};

        createVerticalBoard(board[test], verticalBoard, 9);

        bool flagBoard = true;

        bool flagOrizontal = true;
        bool flagVertical = true;
        bool flagSquare = true;

        for (int i = 0; i < SUDOKU_SIZE; i++)
        {
            for (int j = 0; j < SUDOKU_SIZE; j++)
            {
                if (board[test][i][j] != '.')
                {
                    flagOrizontal = checkDuplicates(board[test][i], ARRAY_SIZE, board[test][i][j]);
                    flagVertical = checkDuplicates(verticalBoard[j], ARRAY_SIZE, board[test][i][j]);

                    int squareNo = findLocationSquare(i,j);

                    formatSquares(board[test], SUDOKU_SIZE, squareNo, squareFormat);

                    flagSquare = checkDuplicates(squareFormat, ARRAY_SIZE, board[test][i][j]);

                    if (flagOrizontal == 1 || flagVertical == 1 || flagSquare == 1) 
                    {
                        flagBoard = false;
                        break;
                    }
                }
            }
            if (flagBoard == false)
            {
                break;
            }   
        }

        green();

        printf("Test %i: ", test + 1);

        reset();

        printf("%s | ", (flagBoard == true) ? "true" : "false");
        
        green();

        printf("Passed\n");

        reset();
    }
    
    return 0;
}

void printArrayOfChars(char array[ARRAY_SIZE], int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        printf("%s%c%s", (i == 0) ? "\n[" : "", array[i], (i < arraySize - 1) ? ", " : "]\n");
    }
}

void formatSquares(char array[ARRAY_SIZE][ARRAY_SIZE], int arraySize, int squareNumber, char arrayFormating[ARRAY_SIZE])
{
    int location = squareNumber - 1;
    int indexFormat = 0;

    for (int i = squares[location].istart; i < squares[location].iend; i++)
    {
        for (int j = squares[location].jstart; j < squares[location].jend; j++)
        {
            arrayFormating[indexFormat] = array[i][j];
            indexFormat++;
        }
    }
}

void createVerticalBoard(char array[ARRAY_SIZE][ARRAY_SIZE], char verticalArray[ARRAY_SIZE][ARRAY_SIZE], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            verticalArray[i][j] = array[j][i];
        }
    }
}

int findLocationSquare(int index1, int index2)
{
    for (int i = 0; i < SUDOKU_SIZE; i++)
    {
        if (squares[i].istart <= index1 && index1 <= squares[i].iend && squares[i].jstart <= index2 && index2 <= squares[i].jend)
        {
            return i + 1;
        }
    }
}

bool checkDuplicates(char array[ARRAY_SIZE], int arraySize, char element)
{
    int counter = 0;
    
    for (int i = 0; i < arraySize; i++)
    {
        if (array[i] == element)
        {
            counter += 1;
        }

        if (counter > 1)
        {
            return true;
        }
    }


    return false;
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