#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Detect cycle using Floyd’s Algorithm
int detectCycle(struct Node* head) {
    struct Node *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          // move 1 step
        fast = fast->next->next;    // move 2 steps

        if (slow == fast)
            return 1; // Cycle exists
    }
    return 0; // No cycle
}

int main() {
    struct Node *head = NULL, *temp = NULL;
    int n, x;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Create linked list
    for (int i = 0; i < n; i++) {
        printf("Enter data: ");
        scanf("%d", &x);

        struct Node* newNode = createNode(x);

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // OPTIONAL: create a cycle manually for testing
    char choice;
    printf("Do you want to create a cycle? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y') {
        int pos;
        printf("Enter position to link last node (0-based index): ");
        scanf("%d", &pos);

        struct Node* cycleNode = head;
        for (int i = 0; i < pos; i++) {
            cycleNode = cycleNode->next;
        }
        temp->next = cycleNode; // creating cycle
    }

    // Check cycle
    if (detectCycle(head))
        printf("Cycle Detected\n");
    else
        printf("No Cycle\n");

    return 0;
}