#include <stdio.h>
#include <stdlib.h>

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

void DFS(struct Graph* graph){
    int i;
    int visitedArr[graph->vertices];
    for(i=0;i<graph->vertices;i++){
        visitedArr[i]=0;
    }
    printf("Searching Depth First : \n");
    int stackArr[graph->vertices];
     int top =0;
    stackArr[top]=graph->verticeList[top]->vertice;
    visitedArr[stackArr[top]]=1;
    while(top>=0){
        printf("%d ",stackArr[top]+1);
        //printf("Queue front %d\n",queueArr[front]);
        struct Node* temp = graph->verticeList[stackArr[top]];
        top--;
        //printf("Temp Vertice before update %d \n",temp->vertice+1);
        while(temp!=NULL){
            //printf("Temp Vertice %d \n",temp->vertice+1);
            if(visitedArr[temp->vertice]==0){
                top++;
                stackArr[top]=temp->vertice;
                visitedArr[temp->vertice]=1;
            }
            temp=temp->next;
        }
    }
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
    
    // addEdge(graph,3,5);
    // addEdge(graph,3,4);
    // addEdge(graph,1,4);
    // addEdge(graph,2,3);
    // addEdge(graph,2,4);
    // addEdge(graph,1,2);
    // addEdge(graph,4,5);
    printGraph(graph);
    DFS(graph);
    return 0;
}