#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x);

int main(){

    int tests[] = {121,-121,10};
    int size = sizeof(tests)/sizeof(tests[0]);

    for (int i = 0; i < size; i++)
    {
        (isPalindrome(tests[i]) == 1) ? printf("True") : printf("False");
    }
    
    return 0;
}

bool isPalindrome(int x) {
    int n, d, k = 0;
    
    if (x < 0) return false;
    
    n = x;
    while (n) {
        d = n % 10;
        if (k > (0x7fffffff - d) / 10) return false;    // overflow
        k = k * 10 + d;
        n = n / 10;
    }
    
    return (k == x);
}