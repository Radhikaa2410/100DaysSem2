#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 26

// Queue implementation
typedef struct {
    int data[MAX];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = q->rear = 0;
}

bool isEmpty(Queue *q) {
    return q->front == q->rear;
}

void push(Queue *q, int x) {
    q->data[q->rear++] = x;
}

int pop(Queue *q) {
    return q->data[q->front++];
}

// Main function
void findOrder(char words[][100], int n) {
    int graph[MAX][MAX] = {0};
    int indegree[MAX] = {0};
    bool present[MAX] = {0};

    // Mark all characters present
    for (int i = 0; i < n; i++) {
        for (int j = 0; words[i][j]; j++) {
            present[words[i][j] - 'a'] = true;
        }
    }

    // Build graph
    for (int i = 0; i < n - 1; i++) {
        char *w1 = words[i];
        char *w2 = words[i + 1];

        int len = strlen(w1) < strlen(w2) ? strlen(w1) : strlen(w2);
        bool found = false;

        for (int j = 0; j < len; j++) {
            if (w1[j] != w2[j]) {
                int u = w1[j] - 'a';
                int v = w2[j] - 'a';

                // Avoid duplicate edge
                if (!graph[u][v]) {
                    graph[u][v] = 1;
                    indegree[v]++;
                }

                found = true;
                break;
            }
        }

        // Invalid case: prefix issue
        if (!found && strlen(w1) > strlen(w2)) {
            printf("");
            return;
        }
    }

    // Topological Sort
    Queue q;
    initQueue(&q);

    for (int i = 0; i < MAX; i++) {
        if (present[i] && indegree[i] == 0) {
            push(&q, i);
        }
    }

    char result[MAX];
    int idx = 0;

    while (!isEmpty(&q)) {
        int u = pop(&q);
        result[idx++] = u + 'a';

        for (int v = 0; v < MAX; v++) {
            if (graph[u][v]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    push(&q, v);
                }
            }
        }
    }

    // Count total unique characters
    int total = 0;
    for (int i = 0; i < MAX; i++) {
        if (present[i]) total++;
    }

    // Cycle check
    if (idx != total) {
        printf("");
        return;
    }

    result[idx] = '\0';
    printf("%s", result);
}

// Driver code
int main() {
    char words[][100] = {"baa", "abcd", "abca", "cab", "cad"};
    int n = 5;

    findOrder(words, n);

    return 0;
}