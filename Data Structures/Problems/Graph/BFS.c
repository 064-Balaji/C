#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

typedef struct Graph
{
    int numvertices;
    node **adjacency;
    int *visited;
}Graph;

node *createnode(int data){
    node *new = (node*) malloc(sizeof(node));
    new->data = data;
    new->next = NULL;
    return new;
}

Graph *createGraph(int numvertices){
    Graph *graph = (Graph*) malloc(sizeof(Graph));
    graph->numvertices = numvertices;
    graph->adjacency = (node**) malloc(numvertices * sizeof(node));
    graph->visited = (int*) malloc(numvertices * sizeof(int));

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

void BFS(Graph *graph, int startVertex) {
    int *queue = (int *)malloc(graph->numvertices * sizeof(int));
    int front = 0, rear = 0;

    graph->visited[startVertex] = 1;
    queue[rear++] = startVertex;

    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d -> ", currentVertex);

        node *temp = graph->adjacency[currentVertex];
        while (temp != NULL) {
            int adjVertex = temp->data;
            if (graph->visited[adjVertex] == 0) {
                graph->visited[adjVertex] = 1;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }

    free(queue);
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

    BFS(graph, start);
}