#include <stdio.h>
void main(){
    int a[2][2];
    for(int i=0;i<2;i++){
        scanf("%d %d",&a[i][0],&a[i][1]);
    }
    int sum =0;
    for(int i=0;i<2;i++){
        printf("%d %d\n",a[i][0],a[i][1]);
        sum=sum+a[i][0]+a[i][1];
    }
    printf("%d",sum);
}