#include <stdio.h>
int fibonacci(int n){
    int a = -1;
    int b = 1;
    int c ;
     
    while(1){
        c=a+b;
        printf("%d ",c);
        if (c==n){
            printf("\nthe term is reached\n");
            break;
        }
        a=b;
        b=c;
        
    }
}
void main(){
    int n;
    printf("enter the Fibonacci sequence up to a specified term:");
    scanf("%d",&n);
    fibonacci(n);
}