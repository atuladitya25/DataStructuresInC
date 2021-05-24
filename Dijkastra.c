#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertice;
    int weight;
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

struct Node* makeNode(int vertice, int weight){
    struct Node* node = malloc(sizeof(struct Node));
    node->vertice = vertice;
    node->weight = weight;
    node->next = NULL;
    return node;
}

void addEdge(struct Graph* graph, int sv, int dv, int weight){
    struct Node* newNode = makeNode(dv-1,weight);
    newNode->next=graph->verticeList[sv-1];
    graph->verticeList[sv-1]=newNode;

    newNode = makeNode(sv-1,weight);
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
            printf("%d(%d) ",(head->vertice)+1,head->weight);
            head=head->next;
        }
        printf("\n");
    }
}

void findShortestPath(struct Graph* graph,int pointA,int pointB){
    int i;
    int visitedArr[graph->vertices];
    int costArr[graph->vertices];
    int queueArr[graph->vertices];
    for(i=0;i<graph->vertices;i++){
        visitedArr[i]=0;
        costArr[i]=-1;
        queueArr[i]=-1;
    }
    printf("Visiting nodes : \n");
    int front =0;
    int rear =0;
    queueArr[front]=pointA-1;
    visitedArr[pointA-1]=1;
    costArr[pointA-1]=0;
    while(front<graph->vertices){
        printf("%d ",queueArr[front]+1);
        //printf("Queue front %d\n",queueArr[front]);
        struct Node* temp = graph->verticeList[queueArr[front]];
        int parentCost = costArr[queueArr[front]];
        front++;
        //printf("Temp Vertice before update %d \n",temp->vertice+1);
        while(temp!=NULL){
            //printf("Temp Vertice %d \n",temp->vertice+1);
            if(visitedArr[temp->vertice]==0){
                rear++;
                queueArr[rear]=temp->vertice;
                visitedArr[temp->vertice]=1;
            } 
            int costTemp = parentCost + temp->weight;
            printf("\nCalculated cost to %d = %d", temp->vertice+1,costTemp);
            if(costArr[temp->vertice]==-1||
                costTemp<costArr[temp->vertice])
            {
                costArr[temp->vertice]=costTemp;
            }
            temp=temp->next;
        }
        int i;
        printf("\nCost : ");
        for (i = 0; i < graph->vertices; i++)
        {
            printf("%d ", costArr[i]);
        }
        printf("\n");
    }
}

int main(){
    int selection;
    int vertices;
    int i;
    printf("Enter number of vertices in the graph \n ");
    scanf("%d", &vertices);
    struct Graph* graph = makeGraph(vertices);
    // while(1==1)
    // {
    //     printf("Enter 1 to add a new edge \n");
    //     printf("Enter anything else to exit and print breadth first traversal\n ");
    //     scanf("%d", &selection);

    //     if(selection == 1){  
    //         int ev[3];
    //         printf("Enter starting and ending vertices and weight : ");
    //         for(i=0;i<3;i++)
    //         {
    //             scanf("%d", &ev[i]);
    //         }
    //         addEdge(graph,ev[0],ev[1],ev[2]);
    //     }
    //     else{
    //         break;
    //     }
    // }
    
    addEdge(graph,1,3,4);
    addEdge(graph,1,2,4);
    addEdge(graph,2,3,2);
    addEdge(graph,3,6,6);
    addEdge(graph,3,5,1);
    addEdge(graph,3,4,3);
    addEdge(graph,4,6,2);
    addEdge(graph,5,6,3);
    printGraph(graph);
    findShortestPath(graph,1,6);
    return 0;
}