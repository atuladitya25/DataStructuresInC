#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int vertice;
    int weight;
    struct Node* next;
};

struct Edge {
    int vertice1;
    int vertice2;
    int weight;
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

void insertEdge(struct Graph* graph, int sv, int dv, int weight){
    struct Node* newNode = makeNode(dv-1,weight);
    newNode->next=graph->verticeList[sv-1];
    graph->verticeList[sv-1]=newNode;

    newNode = makeNode(sv-1,weight);
    newNode->next=graph->verticeList[dv-1];
    graph->verticeList[dv-1]=newNode;
}

void removeEdge(struct Graph* graph, int sv, int dv, int weight){

    graph->verticeList[sv-1]=graph->verticeList[sv-1]->next;
    graph->verticeList[dv-1]=graph->verticeList[dv-1]->next;
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

bool traversePaths(struct Graph* graph, int startVertice, int visitedArr[]){
    int i;
    int parent;
    int descendantOf;
    int parentArr[graph->vertices];
    for(i=0;i<graph->vertices;i++){
        parentArr[i]=-1;
    }
    int stackArr[graph->vertices];
     int top =0;
    stackArr[top]=startVertice;
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
    for(i=0;i<graph->vertices;i++){
        if(visitedArr[i]==0){
            return traversePaths(graph,i, visitedArr);
        }
    }
    return false;
}


bool cycleCheck(struct Graph* graph){
    int i;
    int visitedArr[graph->vertices];
    for(i=0;i<graph->vertices;i++){
        visitedArr[i]=0;
    }
    return traversePaths(graph,0,visitedArr);
}

void sortEdgeArr(struct Edge edgeArray[], int edgeNum){
    int i,j,tempVert1,tempVert2,tempWeight;
    for(i=0;i<edgeNum;i++){
        for(j=i;j<edgeNum;j++){
            if(edgeArray[i].weight>edgeArray[j].weight){
                tempVert1 = edgeArray[i].vertice1;
                tempVert2 = edgeArray[i].vertice2;
                tempWeight = edgeArray[i].weight;
                // printf("%d and %d before exchange are %d,%d,%d and %d,%d,%d\n",
                //         i,j,edgeArray[i].vertice1,edgeArray[i].vertice2,edgeArray[i].weight,
                //         edgeArray[j].vertice1,edgeArray[j].vertice2,edgeArray[j].weight);
                // printf("Temp %d, %d, %d\n",tempVert1,tempVert2,tempWeight);
                edgeArray[i].vertice1 = edgeArray[j].vertice1;
                edgeArray[i].vertice2 = edgeArray[j].vertice2;
                edgeArray[i].weight = edgeArray[j].weight;
                edgeArray[j].vertice1 = tempVert1; 
                edgeArray[j].vertice2 = tempVert2;
                edgeArray[j].weight = tempWeight;
                // printf("%d and %d after exchange are %d,%d,%d and %d,%d,%d\n",
                //         i,j,edgeArray[i].vertice1,edgeArray[i].vertice2,edgeArray[i].weight,
                //         edgeArray[j].vertice1,edgeArray[j].vertice2,edgeArray[j].weight);
            }
        }
    }
}

void addEdge(struct Edge edgeArray[],int i, int x, int y,int z){
    edgeArray[i].vertice1 = x;
    edgeArray[i].vertice2 = y;
    edgeArray[i].weight = z;
}

int main(){
    int selection;
    int vertices;
    int edges;
    int i,j;
    printf("Enter number of vertices in the graph \n ");
    scanf("%d", &vertices);
    printf("Enter number of edges in the graph \n ");
    scanf("%d", &edges);
    struct Graph* graph = makeGraph(vertices);
    struct Edge edgeArray[edges];
    for(i=0;i<edges;i++)
    {
        int ev[3];
        printf("Enter starting and ending vertices and weight : ");
        //struct Edge* edge = malloc(sizeof(struct Edge));
        for(j=0;j<3;j++){
            scanf("%d",&ev[j]);
        }
        addEdge(edgeArray,i,ev[0],ev[1],ev[2]);
    }
    // i=0;
    // addEdge(edgeArray,i++,1,2,4);
    // addEdge(edgeArray,i++,1,3,4);
    // addEdge(edgeArray,i++,2,3,2);
    // addEdge(edgeArray,i++,3,4,3);
    // addEdge(edgeArray,i++,3,5,2);
    // addEdge(edgeArray,i++,3,6,4);
    // addEdge(edgeArray,i++,4,6,3);
    // addEdge(edgeArray,i++,5,6,3);
    // for(i=0;i<edges;i++){
    //     printf("Edge from %d to %d has weight %d\n",edgeArray[i].vertice1,edgeArray[i].vertice2,edgeArray[i].weight);
    // }
    sortEdgeArr(edgeArray,edges);
    //printf("After sort \n ");
    // for(i=0;i<edges;i++){
    //     printf("Edge from %d to %d has weight %d\n",edgeArray[i].vertice1,edgeArray[i].vertice2,edgeArray[i].weight);
    // }
    for(i=0;i<edges;i++){
        insertEdge(graph,edgeArray[i].vertice1,edgeArray[i].vertice2,edgeArray[i].weight);
        //printf("Adding Edge from %d to %d which has weight %d\n",edgeArray[i].vertice1,edgeArray[i].vertice2,edgeArray[i].weight);
        if(cycleCheck(graph)){
            removeEdge(graph,edgeArray[i].vertice1,edgeArray[i].vertice2,edgeArray[i].weight);
            //printf("Caused a cycle. Removing Edge from %d to %d which has weight %d\n",edgeArray[i].vertice1,edgeArray[i].vertice2,edgeArray[i].weight);
        }
        //printf("Graph now\n");
        //printGraph(graph);
        //scanf("%d",&selection);
    } 
    printGraph(graph);
    //findShortestPath(graph,1,6);
    return 0;
}