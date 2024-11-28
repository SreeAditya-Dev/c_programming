#include <stdio.h>

float main(){
    float f;
    float c;
    printf("enter the Fahrenheit value:");
    scanf("%f",&f);
    c = ((f-32)*5)/9;
    printf("the celsius value is %f \n",c);
    return 0;
}