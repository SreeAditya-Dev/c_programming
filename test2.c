#include <stdio.h>

int main(){
  int a[4] = {1,2,3,5};
  int *x=a;
  printf("%p %p %p %p %ls \n",&a[0],&a[1],&a[2],&a[3],&a);
  printf("%p",x);

}
