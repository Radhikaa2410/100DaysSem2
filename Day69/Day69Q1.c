#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Node for adjacency list
typedef struct Node {
    int v, w;
    struct Node* next;
} Node;

// Heap node
typedef struct {
    int v, dist;
} HeapNode;

// Min Heap
typedef struct {
    int size, capacity;
    HeapNode* arr;
} MinHeap;

// Create node
Node* createNode(int v, int w) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->v = v;
    node->w = w;
    node->next = NULL;
    return node;
}

// Add edge
void addEdge(Node** adj, int u, int v, int w) {
    Node* node = createNode(v, w);
    node->next = adj[u];
    adj[u] = node;
}

// Heap functions
MinHeap* createHeap(int cap) {
    MinHeap* h = (MinHeap*)malloc(sizeof(MinHeap));
    h->size = 0;
    h->capacity = cap;
    h->arr = (HeapNode*)malloc(cap * sizeof(HeapNode));
    return h;
}

void swap(HeapNode* a, HeapNode* b) {
    HeapNode t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(MinHeap* h, int i) {
    while (i && h->arr[(i - 1)/2].dist > h->arr[i].dist) {
        swap(&h->arr[i], &h->arr[(i - 1)/2]);
        i = (i - 1)/2;
    }
}

void heapifyDown(MinHeap* h, int i) {
    int s = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < h->size && h->arr[l].dist < h->arr[s].dist)
        s = l;
    if (r < h->size && h->arr[r].dist < h->arr[s].dist)
        s = r;

    if (s != i) {
        swap(&h->arr[i], &h->arr[s]);
        heapifyDown(h, s);
    }
}

void push(MinHeap* h, int v, int d) {
    h->arr[h->size].v = v;
    h->arr[h->size].dist = d;
    heapifyUp(h, h->size);
    h->size++;
}

HeapNode pop(MinHeap* h) {
    HeapNode root = h->arr[0];
    h->arr[0] = h->arr[h->size - 1];
    h->size--;
    heapifyDown(h, 0);
    return root;
}

int isEmpty(MinHeap* h) {
    return h->size == 0;
}

// Dijkstra
void dijkstra(Node** adj, int n, int src, int* dist) {
    MinHeap* h = createHeap(n * n);

    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;
    push(h, src, 0);

    while (!isEmpty(h)) {
        HeapNode node = pop(h);
        int u = node.v;

        // ⚡ Skip outdated entries (important optimization)
        if (node.dist > dist[u]) continue;

        Node* temp = adj[u];
        while (temp) {
            int v = temp->v;
            int w = temp->w;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(h, v, dist[v]);
            }
            temp = temp->next;
        }
    }
}

// Main
int main() {
    int n, e;

    printf("Enter vertices and edges: ");
    scanf("%d %d", &n, &e);

    Node** adj = (Node**)malloc(n * sizeof(Node*));
    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    printf("Enter edges (u v w):\n");
    for (int i = 0; i < e; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(adj, u, v, w);
        // For undirected graph, also add:
        // addEdge(adj, v, u, w);
    }

    int src;
    printf("Enter source: ");
    scanf("%d", &src);

    int* dist = (int*)malloc(n * sizeof(int));

    dijkstra(adj, n, src, dist);

    printf("Shortest distances:\n");
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX)
            printf("%d -> INF\n", i);
        else
            printf("%d -> %d\n", i, dist[i]);
    }

    // Free memory
    for (int i = 0; i < n; i++) {
        Node* temp = adj[i];
        while (temp) {
            Node* t = temp;
            temp = temp->next;
            free(t);
        }
    }
    free(adj);
    free(dist);

    return 0;
}