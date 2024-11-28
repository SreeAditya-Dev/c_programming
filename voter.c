#include <stdio.h>
#include <string.h>

struct voter
{
    int voter_id;
    char name[20];
    int age;
    char address[20];
};
struct voter arr[100];
void add_voter(){
    int count;
    printf("Enter the number of voters to add: ");
    scanf("%d", &count);
    getchar(); // Consume newline character after entering count

    for(int i = 0; i < count; i++){
        printf("Enter voter ID: ");
        scanf("%d", &arr[i].voter_id);
        getchar(); // Consume newline character after entering voter ID
        printf("Enter name: ");
        fgets(arr[i].name, sizeof(arr[i].name), stdin);
        arr[i].name[strcspn(arr[i].name, "\n")] = 0; // Remove trailing newline
        printf("Enter age: ");
        scanf("%d", &arr[i].age);
        getchar(); // Consume newline character after entering age
        printf("Enter address: ");
        fgets(arr[i].address, sizeof(arr[i].address), stdin);
        arr[i].address[strcspn(arr[i].address, "\n")] = 0; // Remove trailing newline
    }
}


void display_voter() {
    int i = 0;
    // We loop until we reach the end of the array or we find an 'empty' struct voter
    // An 'empty' struct voter is defined as one with a voter_id of 0, which we assume
    // is the default value of an uninitialized struct voter
    while (i < 100 && arr[i].voter_id != 0) {
        printf("Voter ID: %d\n", arr[i].voter_id);
        printf("Name: %s\n", arr[i].name);
        printf("Age: %d\n", arr[i].age);
        printf("Address: %s\n", arr[i].address);
        printf("\n");
        i++;
    }

}


void search_voter(){
    int id;
    printf("Enter voter ID: ");
    scanf("%d", &id);
    int i;
    int found = 0;
    for(i = 0; i < 100; i++){
        if(arr[i].voter_id == id){
            found = 1;
            break;
        }
    }
    if(found == 1){
        printf("Voter ID: %d\n", arr[i].voter_id);
        printf("Name: %s\n", arr[i].name);
        printf("Age: %d\n", arr[i].age);
        printf("Address: %s\n", arr[i].address);
    }else{
        printf("Voter not found\n");
    }
}

void main(){

    
    int choice;
    do{
    printf("enter the choice\n1.add voter\n2.display voter\n3.search voter\n4.exit\n");
    printf("enter the choice:");
    scanf("%d",&choice);
    getchar();
    printf("\n");
    switch (choice)
    {
    case(1):
        add_voter();
        break;
    case(2):
        display_voter();
        break;
    case(3):
        search_voter();
        break;
    case(4):
        break;
    default:
        printf("wrong choice\n");
        printf("\n");
        break;
    }

    }while(choice!=4);

}