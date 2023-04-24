#include <stdio.h>

int main(void)
{
    int digits[] = {1,2,3};
    int len_digits = sizeof(digits)/sizeof(digits[0]);
    
    if(len_digits == 1){
        printf("%i", digits[0]+1);
    }
    else
    {
        int number = 1;
        int old = 0;
        int result = 0;
        int copie = 0;
        
        for(int j = 0; j < len_digits - 1; j++){
            number *= 10;
        }
        
        copie = number;
        
        for(int i = 0; i < len_digits; i++){
            result = old + number * digits[i];
            old = result;
            number /= 10;
        }
        
        result += 1;
        
        int mod = copie * 10;
        int divvar = copie;
        
        
        
        
        for(int i = 0; i < len_digits; i++){
            int rezultat = (result % mod) / divvar;
            printf("%i\n", rezultat);
            mod = mod / 10;
            divvar = divvar / 10;
        }
    }
    
    return 0;
}





