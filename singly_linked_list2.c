#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *head ,*temp,*newnode;

void main(){
    head= NULL;
    int choice;
    while(1){
        newnode=(struct Node*) malloc(sizeof(struct Node));
        printf("enter the data:");
        scanf("%d",&newnode->data);
        newnode -> next=0;
        if(head==0){
            head=temp=newnode;
        }else{
            temp -> next=newnode;
            temp=newnode;
        }
        printf("enter the choice (0,1):");
        scanf("%d",&choice);
        if(choice==0)
            break;
    }

    temp=head;
    while (temp!=0)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL");
    printf("\n");
    
}

