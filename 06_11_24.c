#include <stdio.h>
int a=5;
void main(){
    int ar[4]={1,2,3,4};
    int *pt= &ar[0];
    int *ptr= &a;
    printf("%d\n",a);
    printf("%p\n",ptr);
    printf("%p\n",&a);
    printf("%p\n",pt);
    printf("%d\n",ar[0]);
    for(int i=0;i<4;i++){
        printf("%d %p %d \n",(ar+i),pt+i,*(pt+i));
    }
}