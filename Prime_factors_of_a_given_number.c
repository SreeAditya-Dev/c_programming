#include <stdio.h>


int prime(int n) {
    if (n <= 1) {
        return 0;  
    }

    for (int i = 2; i * i <= n; i++) {  
        if (n % i == 0) {
            return 0;  
        }
    }
    return 1;  
}
int main() {
    int n;
    printf("Prime factors of a given number....\n");
    printf("Enter the number: ");
    scanf("%d", &n);  

    int mid = n / 2;
    printf("The prime factors are: ");
    for (int i = 2; i <= mid; i++) {  
        if (n % i == 0 && prime(i)) {  
            printf("%d ", i);
        }
    }

    if (prime(n)) {
        printf("%d", n);
    }

    printf("\n");
    return 0;  
}
