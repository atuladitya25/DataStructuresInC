#include <stdio.h>
#include <stdlib.h>
  
struct Node {
    int data;
    struct Node* leftChild;
    struct Node* rightChild;
    int height;
};

void preOrderTraversal(struct Node* head) {

    if(head!=NULL){
        printf("%d ",head->data);
        if(head->leftChild!=NULL){
            preOrderTraversal(head->leftChild);
        }
        if(head->rightChild!=NULL){
            preOrderTraversal(head->rightChild);
        }
    }

    return;
}

void inOrderTraversal(struct Node* head) {

    if(head!=NULL){
        if(head->leftChild!=NULL){
            inOrderTraversal(head->leftChild);
        }
        printf("%d ",head->data);
        if(head->rightChild!=NULL){
            inOrderTraversal(head->rightChild);
        } 
    }

    return;
}

void postOrderTraversal(struct Node* head) {

    if(head!=NULL){
        if(head->leftChild!=NULL){
            postOrderTraversal(head->leftChild);
        }
        if(head->rightChild!=NULL){
            postOrderTraversal(head->rightChild);
        }
        printf("%d ",head->data);
    }

    return;
}

int main()
{
    struct Node* head = NULL;
    //struct Node* next = NULL;

    int selection;
  
    while(1==1)
    {
        printf("Enter 1 to add a new number \n");
        printf("Enter 2 to PreOrder Traversal \n ");
        printf("Enter 3 to InOrder Traversal \n ");
        printf("Enter 4 to PostOrder Traversal \n ");
        printf("Enter anything else to exit \n ");
        scanf("%d", &selection);

        if(selection == 1){  
            int enterData;
            printf("Enter number to add to the node : ");
            scanf("%d", &enterData);
            head = createNode(head,enterData);
        }
        else if(selection == 2){
            printf("Preorder : \n");
            preOrderTraversal(head);
            printf("\n");
        }
        else if(selection == 3){
            printf("Inorder : \n");
            inOrderTraversal(head);
            printf("\n");
        }
        else if(selection == 4){
            printf("Postorder : \n");
            postOrderTraversal(head);
            printf("\n");
        }
        else{
            break;
        }
    }
  
    return 0;
}