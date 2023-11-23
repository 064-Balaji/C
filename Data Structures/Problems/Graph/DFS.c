#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int data;
    struct node *next;
}node;

typedef struct
{
    int numVertices;
    node **adjacency;
    int *visited;
}Graph;

node *createnode(int data){
    node *newnode = (node*) malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

Graph *createGraph(int numvertices){
    Graph *graph = (Graph*) malloc(sizeof(Graph));

    graph->numVertices = numvertices;
    graph->adjacency = (node **) malloc(numvertices * sizeof(node));
    graph->visited = (int *) malloc(numvertices * sizeof(int));

    for (int i = 0; i < numvertices; i++)
    {
        graph->adjacency[i] = NULL;
        graph->visited[i] = 0;
    }
    
    return graph;
}

void addEdge(Graph *graph, int src, int dst){
    node *newnode = createnode(dst);
    newnode->next = graph->adjacency[src];
    graph->adjacency[src] = newnode;

    newnode = createnode(src);
    newnode->next = graph->adjacency[dst];
    graph->adjacency[dst]=newnode;
}

void DFS(Graph *graph, int startvertex){
    node *temp = graph->adjacency[startvertex];
    graph->visited[startvertex] = 1;
    printf("%d-> ", startvertex);

    while (temp != NULL)
    {
        int connectedvertex = temp->data;
        if(graph->visited[connectedvertex] == 0){
            DFS(graph, connectedvertex);
        }
        temp = temp->next;
    }
}

int main(){
    int vertex, edge, src, dst, start;
    printf("Enter the no of vertices:");
    scanf("%d", &vertex);
    printf("Enter the no of edges");
    scanf("%d", &edge);

    Graph *graph = createGraph(vertex);

    for (int i = 0; i < edge; i++)
    {
        printf("Enter %d edge (src, dst): ", i+1);
        scanf("%d %d", &src, &dst);
        addEdge(graph, src, dst);
    }

    printf("Enter the start vertex: ");
    scanf("%d", &start);

    DFS(graph, start);
}