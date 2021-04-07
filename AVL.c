#include <stdio.h>
#include <stdlib.h>
  
struct Node {
    int data;
    struct Node* leftChild;
    struct Node* rightChild;
    int height;
};

void rightRotate(struct Node* node){

    struct Node* newNode = node -> leftChild;
    node -> leftChild -> rightChild = node;
    node -> leftChild = NULL;

    node->height = node -> height = 1 + max(height(node -> rightChild), height(node -> leftChild));
    newNode->height = node -> height = 1 + max(height(node -> rightChild), height(node -> leftChild));

    return newNode;
}

void leftRotate(struct Node* node){

    struct Node* newNode = node -> rightChild;
    node -> rightChild -> leftChild = node;
    node -> rightChild = NULL;

    node->height = node -> height = 1 + max(height(node -> rightChild), height(node -> leftChild));
    newNode->height = node -> height = 1 + max(height(node -> rightChild), height(node -> leftChild));

    return newNode;
}

int max(int height1, int height2){

    if( height1 > height2) {
        return height1;
    }
    else {
        return height2;
    }
}

int height(struct Node* node){
    if(node -> height == NULL){
        return 0;
    }
    return node -> height;
}

struct Node* balanceNode(struct Node* node){

    int balance = height(node -> leftChild) - height(node -> rightChild);
    if(balance > 1 || balance <-1) {

        if(balance>1){
            if(height(node->leftChild->leftChild) - height(node->leftChild->rightChild)>0){
                return rightRotate(node);
            }
            else{
                node -> leftChild = leftRotate(node->leftChild);
                return rightRotate(node);
            }
        }
        else{
            if(height(node->rightChild->rightChild) - height(node->rightChild->leftChild)>0){
                return leftRotate(node);
            }
            else{
                node -> rightChild = rightRotate(node->rightChild);
                return leftRotate(node);
            }
        }
    }

}
  
struct Node* createNode(struct Node* node, int enterData) {

    if(node==NULL){
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = enterData;
        newNode -> leftChild = NULL ;
        newNode -> rightChild = NULL ;
        newNode -> height = 1;
        return newNode;
    }
    else if(node->data > enterData){
        node-> leftChild = createNode(node-> leftChild, enterData);
    }
    else if(node->data < enterData){
        node-> rightChild = createNode(node-> rightChild, enterData);
    }

    node -> height = 1 + max(height(node -> rightChild), height(node -> leftChild));

    return balanceNode(node);
    
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