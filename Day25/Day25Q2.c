
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to detect cycle and return starting node
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    // Phase 1: Detect cycle
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // Phase 2: Find starting node
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;  // cycle start
        }
    }
    return NULL;  // no cycle
}

int main() {
    int n, i, pos;
    struct ListNode *head = NULL, *temp = NULL, *newnode;
    struct ListNode *cycleNode = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Create linked list
    for (i = 0; i < n; i++) {
        newnode = (struct ListNode*)malloc(sizeof(struct ListNode));

        printf("Enter value: ");
        scanf("%d", &newnode->val);

        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }

        // Store node where cycle should connect
        if (i == pos)
            cycleNode = newnode;
    }

    printf("Enter position to create cycle (-1 for no cycle): ");
    scanf("%d", &pos);

    if (pos >= 0) {
        temp = head;
        for (i = 0; i < pos; i++)
            temp = temp->next;

        cycleNode = temp;
        newnode->next = cycleNode;
    }

    struct ListNode *result = detectCycle(head);

    if (result)
        printf("Cycle starts at node with value: %d\n", result->val);
    else
        printf("No cycle detected.\n");

    return 0;
}
