#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int vertice;
    struct Node* next;
};

struct Graph {
    int vertices;
    struct Node** verticeList;
};

struct Graph* makeGraph(int vertices){
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->verticeList = malloc(vertices * sizeof(struct Node));
    int i;
    for (i = 0; i < vertices; i++)
        graph->verticeList[i] = NULL;

    return graph;
}

struct Node* makeNode(int vertice){
    struct Node* node = malloc(sizeof(struct Node));
    node->vertice = vertice;
    node->next = NULL;
    return node;
}

void addEdge(struct Graph* graph, int sv, int dv){
    struct Node* newNode = makeNode(dv-1);
    newNode->next=graph->verticeList[sv-1];
    graph->verticeList[sv-1]=newNode;

    newNode = makeNode(sv-1);
    newNode->next=graph->verticeList[dv-1];
    graph->verticeList[dv-1]=newNode;
}

void printGraph(struct Graph* graph){
    int i;
    printf("Printing now\n");
    for (i = 0; i < graph->vertices; i++)
    {
        printf("Edges from vertice %d are to : ",i+1);
        struct Node* head = graph->verticeList[i];
        while(head!=NULL){
            printf("%d ",(head->vertice)+1);
            head=head->next;
        }
        printf("\n");
    }
}

bool cycleCheck(struct Graph* graph){
    int i;
    int parent;
    int descendantOf;
    int visitedArr[graph->vertices];
    int parentArr[graph->vertices];
    for(i=0;i<graph->vertices;i++){
        visitedArr[i]=0;
        parentArr[i]=-1;
    }
    int stackArr[graph->vertices];
     int top =0;
    stackArr[top]=0;
    visitedArr[stackArr[top]]=1;
    while(top>=0){
        struct Node* temp = graph->verticeList[stackArr[top]];
        parent = stackArr[top];
        descendantOf = parentArr[top];
        top--;
        while(temp!=NULL){
            if(visitedArr[temp->vertice]==0){
                top++;
                stackArr[top]=temp->vertice;
                parentArr[top]=parent;
                visitedArr[temp->vertice]=1;
            }
            else{
                if(temp->vertice!=descendantOf)
                    return true;
            }
            temp=temp->next;
        }
    }
    return false;
}

int main(){
    int selection;
    int vertices;
    int i;
    printf("Enter number of vertices in the graph \n ");
    scanf("%d", &vertices);
    struct Graph* graph = makeGraph(vertices);
    while(1==1)
    {
        printf("Enter 1 to add a new edge \n");
        printf("Enter anything else to exit and print breadth first traversal\n ");
        scanf("%d", &selection);

        if(selection == 1){  
            int ev[2];
            printf("Enter starting and ending vertices : ");
            for(i=0;i<2;i++)
            {
                scanf("%d", &ev[i]);
            }
            addEdge(graph,ev[0],ev[1]);
        }
        else{
            break;
        }
    }
    printGraph(graph);
    bool check = cycleCheck(graph);
    if(check){
        printf("\n There is a cycle");
    }
    else{
        printf("\n There is no cycle");
    }
    return 0;
}