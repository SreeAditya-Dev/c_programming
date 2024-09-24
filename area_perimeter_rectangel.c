#include <stdio.h>
 
void main(){
    int choice ;
    float area ;
    float perimeter ;
    float l;
    float b;
    printf("choice list\n 1.area of reactangel\n 2.perimeter of reactangle\n 3.exit\n");
    printf("enter the choice:");
    scanf("%d",&choice);
    
    switch (choice)
    {
    case 1:
        printf("enter the value of l ,b;");
        scanf("%f %f",&l,&b);
        area = l*b;
        printf("the area of the rectangle %f \n",area);
        break;
    
    case 2:
        printf("enter the value of l ,b;");
        scanf("%f %f",&l,&b);
        perimeter = 2*(l+b);
        printf("the perimeter of the rectangle %f \n",perimeter);
        break;
    
    case 3:
        printf("thankyou\n");
        break;
    }
}