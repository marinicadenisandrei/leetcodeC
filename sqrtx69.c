#include <stdio.h>

int main(){

    int x = 8;
    int counter = 0;
    int lista[100] = {};
    int listOfPrimeNo[6] = {2,3,5,7,11,13};
    int divizor = 0;
    int listSqrt[10] = {};
    

    for (int i = 0; i < 6; i++)
    {
        if(x % listOfPrimeNo[i] == 0){
            divizor = listOfPrimeNo[i];
            break;
        }
    }

    while (x > 1)
    {
        x = x/divizor;
        listSqrt[counter] = divizor;
        counter = counter + 1;
    }

    counter = counter / 2;
    
    int final = 1;

    for (int i = 0; i < counter; i++)
    {
        final = final * listSqrt[i];
        
    }
    
    printf("%i", final);
}