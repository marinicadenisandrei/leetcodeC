#include <stdio.h>
#include <math.h>
#include <string.h>

int transformToDecimal(const char* a, const char* b);
void trasformToBinary(int a);

int main(){
    // char l1[10] = "1010";
    // char l2[10] = "1011";

    char l1[10] = "11";
    char l2[10] = "1";

    int var = transformToDecimal(l1, l2);

    trasformToBinary(var);
}

int transformToDecimal(const char* a, const char* b){
    
    int len_a = strlen(a);
    int len_b = strlen(b);

    int num1 = 0;
    int num2 = 0;

    int character1;
    int character2;

    for (int i = 0; i < len_a; i++)
    {
        character1 = a[i] - '0';
        character1 = character1 * pow(2, len_a-i-1);
        num1 += character1;
    }
    
    for (int i = 0; i < len_b; i++)
    {
        character2 = b[i] - '0';
        character2 = character2 * pow(2, len_b-i-1);
        num2 += character2;
    }

    num1 = num1 + num2;

    return num1;
}

void trasformToBinary(int a){
    
    int result = 0;
    int final[10] = {};
    int counter = 0;

    while (a >= 1)
    {
        if(a % 2 == 0){
            final[counter] = 0;
        }
        else
        {
            final[counter] = 1;
        }

        a = a / 2;
        counter += 1;
    }

    for(int i = counter - 1; i >= 0; i--)
    {
        printf("%i", final[i]);
    }
}