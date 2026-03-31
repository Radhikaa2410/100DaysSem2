

#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct node {
    int data;
    struct node* next;
};

// Function to find middle using slow-fast method
struct node* findMiddle(struct node* head) {
    struct node* slow = head;
    struct node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;        // move one step
        fast = fast->next->next;  // move two steps
    }
    return slow; // slow will be at middle
}

// Function to print linked list
void printList(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int n, value;
    struct node *head = NULL, *temp = NULL, *newnode;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Create linked list from user input
    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &value);

        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = value;
        newnode->next = NULL;

        if (head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    printf("\nLinked List:\n");
    printList(head);

    // Find and print middle element
    struct node* middle = findMiddle(head);
    printf("Middle element = %d\n", middle->data);

    return 0;
}
// slow fast method 
/* slow and fast start at head then fast takes 2 steps while slw takes 1 step 
when fast reaches end the slow reaches mid 
hence on returning slow we get mid */
