#include <stdio.h>
#include <stdlib.h>

#define MAX 100


struct Node {
    int vertex;
    struct Node* next;
};

struct Node* graph[MAX];
int visited[MAX];

// create  node
struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// add edge 
void addEdge(int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph[src];
    graph[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph[dest];
    graph[dest] = newNode;
}

// DFS function
void DFS(int vertex) {
    printf("%d ", vertex);
    visited[vertex] = 1;

    struct Node* temp = graph[vertex];

    while (temp != NULL) {
        int adj = temp->vertex;

        if (!visited[adj]) {
            DFS(adj);
        }

        temp = temp->next;
    }
}

int main() {
    int vertices = 5;

    // initialize graph
    for (int i = 0; i < MAX; i++) {
        graph[i] = NULL;
        visited[i] = 0;
    }

    // create edges
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(1, 4);

    printf("DFS starting from vertex 0:\n");
    DFS(0);

    return 0;
}
