#include <stdio.h>
#include <stdlib.h>

#define SZ 101

struct Node {
    int val;
    int numNeighbors;
    struct Node** neighbors;
};

struct Node* vis[SZ];

// DFS clone
struct Node* dfs(struct Node* u){
    if(vis[u->val] != NULL)
        return vis[u->val];

    struct Node* c = (struct Node*)malloc(sizeof(struct Node));
    c->val = u->val;
    c->numNeighbors = u->numNeighbors;

    if(u->numNeighbors > 0){
        c->neighbors = (struct Node**)malloc(
            u->numNeighbors * sizeof(struct Node*)
        );
    } else {
        c->neighbors = NULL;
    }

    vis[u->val] = c;

    for(int i = 0; i < u->numNeighbors; i++){
        c->neighbors[i] = dfs(u->neighbors[i]);
    }

    return c;
}

struct Node* cloneGraph(struct Node* s){
    if(s == NULL) return NULL;

    for(int i = 0; i < SZ; i++)
        vis[i] = NULL;

    return dfs(s);
}

// Utility: create node
struct Node* newNode(int val, int n){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->numNeighbors = n;
    node->neighbors = (n > 0) ? (struct Node**)malloc(n * sizeof(struct Node*)) : NULL;
    return node;
}

// Utility: print graph (DFS)
int printed[SZ];

void printGraph(struct Node* u){
    if(u == NULL || printed[u->val]) return;

    printed[u->val] = 1;

    printf("Node %d: ", u->val);
    for(int i = 0; i < u->numNeighbors; i++){
        printf("%d ", u->neighbors[i]->val);
    }
    printf("\n");

    for(int i = 0; i < u->numNeighbors; i++){
        printGraph(u->neighbors[i]);
    }
}

int main(){
    // Example graph:
    // 1--2
    // |  |
    // 4--3

    struct Node* n1 = newNode(1, 2);
    struct Node* n2 = newNode(2, 2);
    struct Node* n3 = newNode(3, 2);
    struct Node* n4 = newNode(4, 2);

    n1->neighbors[0] = n2;
    n1->neighbors[1] = n4;

    n2->neighbors[0] = n1;
    n2->neighbors[1] = n3;

    n3->neighbors[0] = n2;
    n3->neighbors[1] = n4;

    n4->neighbors[0] = n1;
    n4->neighbors[1] = n3;

    printf("Original Graph:\n");
    for(int i = 0; i < SZ; i++) printed[i] = 0;
    printGraph(n1);

    struct Node* clone = cloneGraph(n1);

    printf("\nCloned Graph:\n");
    for(int i = 0; i < SZ; i++) printed[i] = 0;
    printGraph(clone);

    return 0;
}