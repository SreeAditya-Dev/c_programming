#include <stdio.h>


unsigned long  factorial(unsigned long n) {
    
    if (n == 0 || n == 1) {
        return 1;
    }
    
    else {
        return n * factorial(n - 1); 
    }
}

unsigned long  main() {
    unsigned long  number ;
    printf("enter the number:");
    scanf("%lu",&number);
    unsigned long  result = factorial(number);

    printf("Factorial of %lu is %lu\n", number, result);
    return 0;
}
