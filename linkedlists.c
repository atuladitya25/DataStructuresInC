#include <stdio.h>
#include <stdlib.h>
  
struct Node {
    int data;
    struct Node* next;
};
  
struct Node* createNode(struct Node* nextOne) {

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter number to add to the node : ");
    scanf("%d", &(newNode -> data));
    //newNode -> data = 4;
    newNode -> next = NULL ;
    nextOne -> next = newNode;
    return newNode;
}

void createNodeAt(struct Node * head) {

}

int main()
{
    struct Node* head = NULL;
    struct Node* next = NULL;

    int selection;
  
    head = (struct Node*)malloc(sizeof(struct Node));
    head->next=NULL;
    head->data=-13;
    next = head;
  
    while(1==1)
    {
        printf("Enter 1 to create new node at the end \n ");
        printf("Enter 2 to create new node in between at a position , anything else to exit and traverse the nodes : ");
        scanf("%d", &selection);
        if(selection == 1){
            struct Node* newNode = createNode(next);
            next = newNode;
        }
        else if(selection == 2){
            //createNodeAt(&head);
        }
        else{
            break;
        }
    }

    next = head;
    //next = next->next;
    printf("Data in Node = %d \n ",next->data);
    printf("Data in Node = %d \n ",head->next->data);
    printf("The data in the list is \n ");
    int i=1;
    while (next -> next != NULL) {
        next = next -> next;
        printf("Data in Node %d = %d \n ",i,next->data); 
        i++;
    }
  
    return 0;
}