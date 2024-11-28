#include <stdio.h>

int main() {
    int a[3];
    int i;

    printf("Enter three numbers:\n");
    for (i = 0; i < 3; i++) {
        scanf("%d", &a[i]);
    }

    printf("You entered: ");
    for (i = 0; i < 3; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    printf("%d",a);

    return 0;
}
