#include<stdio.h>
#include<conio.h>
#include<process.h>
int ch,max,item,top=-1,s[20]; void menu(void);
void push(int); int pop(void); void display(void); void main()
{

printf("ENTER STACK SIZE:"); scanf("%d",&max);
menu();
getch();
}
void menu()
{
printf("1.PUSH\n2.POP\n3.EXIT\n"); printf("ENTER YOUR CHOICE:");
fflush(stdin);
scanf("%d",&ch);
switch(ch)
{
case 1:printf("ENTER THE ELEMENT\n"); scanf("%d",&item);
push(item);
menu();
break;
case 2:item=pop(); menu();
break;
case 3:exit(0);
}
}
void push(int item)
{
if(top==max-1)
printf("STACK IS OVER FLOW\n"); else
{
top++;
s[top]=item;
}
display();
}
int pop()
{
if(top==-1)
{
printf("STACK IS UNDER FLOW\n"); return 0;
}
else
{
item=s[top]; top--;
}
display(); 
return item;

}
void display()
{
int i;
printf(" top -->");
for(i=top;i>=0;i--)
printf("%d\n\t",s[i]);
}