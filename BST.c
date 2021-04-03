#include <stdio.h>
#include <stdlib.h>
  
struct Node {
    int data;
    struct Node* leftChild;
    struct Node* rightChild;
};
  
struct Node* createNode(struct Node* node) {

    int enterData;
    printf("Enter number to add to the node : ");
    scanf("%d", &enterData);
    struct Node* currNode = NULL;
    printf("Flag 1\n");
    while(node!=NULL){
        currNode = node;
        if(node->data > enterData){
            node = node-> leftChild;
        }
        else
        {
            node = node-> rightChild;
        }
    }
    printf("Flag2\n");
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = enterData;
    newNode -> leftChild = NULL ;
    newNode -> rightChild = NULL ;
    printf("Flag2.1\n");
    if(currNode==NULL){
        printf("Flag2.15\n");
        return newNode;
    }
    else if(currNode->data > enterData){
        printf("Data = %d \n",currNode->data);
        currNode -> leftChild = newNode;
        printf("Flag2.2\n");
    }
    else{
        printf("Data = %d \n",currNode->data);
        currNode -> rightChild = newNode;
        printf("Flag2.3\n");
    }
    printf("Flag3\n");
    return newNode;
}

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
            preOrderTraversal(head->leftChild);
        }
        printf("%d ",head->data);
        if(head->rightChild!=NULL){
            preOrderTraversal(head->rightChild);
        } 
    }

    return;
}

void postOrderTraversal(struct Node* head) {

    if(head!=NULL){
        if(head->leftChild!=NULL){
            preOrderTraversal(head->leftChild);
        }
        if(head->rightChild!=NULL){
            preOrderTraversal(head->rightChild);
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
        printf("Enter 4 to PreOrder Traversal \n ");
        printf("Enter anything else to exit \n ");
        scanf("%d", &selection);

        if(selection == 1){
            if(head==NULL) {
                head = createNode(head);
            }
            else
            {   
                struct Node* newNode = createNode(head);
                //next = newNode;
            }
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