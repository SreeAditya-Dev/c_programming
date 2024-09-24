#include <stdio.h>
#include <math.h>

int main() {
    int n;
    float a, d, r;

    printf("Enter the first term (a) and common difference (d) for AP: ");
    scanf("%f %f", &a, &d);

    printf("Enter the first term (a) and common ratio (r) for GP: ");
    scanf("%f %f", &a, &r);

    printf("Enter the term number (n): ");
    scanf("%d", &n);

    float nth_AP = a + (n - 1) * d;
    printf("The %d-th term of AP is: %.2f\n", n, nth_AP);

    float nth_GP = a * pow(r, n - 1);
    printf("The %d-th term of GP is: %.2f\n", n, nth_GP);

    return 0;
}
