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
    node->weight= weight;
    node->next = NULL;
    return node;
}

void addEdge(struct Graph* graph, int sv, int dv,int weight){
    struct Node* newNode = makeNode(dv-1,weight);
    newNode->next=graph->verticeList[sv-1];
    graph->verticeList[sv-1]=newNode;

    newNode = makeNode(sv-1,weight);
    newNode->next=graph->verticeList[dv-1];
    graph->verticeList[dv-1]=newNode;
}

void sortEdges(struct Graph* graph){
    int i,tempVert,tempWeight;
    for(i=0;i<graph->vertices;i++){
        struct Node* j = graph->verticeList[i];
        while(j!=NULL){
            struct Node *k = j;
            while(k!=NULL){
                if(j->weight>k->weight){
                    tempVert = j->vertice;
                    tempWeight = j->weight;
                    j->vertice = k->vertice;
                    j->weight = k->weight;
                    k->vertice = tempVert;
                    k->weight = tempWeight;
                }
                k=k->next;
            }
            j=j->next;
        }
    }
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

void traversePaths(struct Graph* graph, struct Graph* msg, int startVertice, int visitedArr[]){
    struct Node* node = graph->verticeList[startVertice];
    visitedArr[startVertice]=1;
    while(node!=NULL){
        if(visitedArr[node->vertice]==0){
            struct Node* newNode = makeNode(node->vertice,node->weight);
            newNode->next=msg->verticeList[startVertice];
            msg->verticeList[startVertice]=newNode;

            newNode = makeNode(startVertice,node->weight);
            newNode->next=msg->verticeList[node->vertice];
            msg->verticeList[node->vertice]=newNode;
            traversePaths(graph,msg,node->vertice,visitedArr);
        }
        node=node->next;
    }
}


struct Graph* prim(struct Graph* graph){
    int i;
    int visitedArr[graph->vertices];
    for(i=0;i<graph->vertices;i++){
        visitedArr[i]=0;
    }
    struct Graph* msg = makeGraph(graph->vertices);
    traversePaths(graph,msg,0,visitedArr);
    return msg;
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
    //         int ev[2];
    //         printf("Enter starting and ending vertices : ");
    //         for(i=0;i<2;i++)
    //         {
    //             scanf("%d", &ev[i]);
    //         }
    //         addEdge(graph,ev[0],ev[1]);
    //     }
    //     else{
    //         break;
    //     }
    // }
    addEdge(graph,1,2,4);
    addEdge(graph,1,3,4);
    addEdge(graph,2,3,2);
    addEdge(graph,3,4,3);
    addEdge(graph,3,5,2);
    addEdge(graph,3,6,4);
    addEdge(graph,4,6,3);
    addEdge(graph,5,6,3);
    printf("\nGraph before Prim\n");
    printGraph(graph);
    sortEdges(graph);
    struct Graph* msg = prim(graph);
    printf("\nGraph after Prim\n");
    printGraph(msg);
    return 0;
}