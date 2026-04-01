
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

// Create Circular Linked List
struct node* createList(int n) {
    struct node *head = NULL, *temp = NULL, *newNode;
    int value;

    for(int i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &value);

        newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            newNode->next = head;   // circular link
            temp = head;
        }
        else {
            temp->next = newNode;
            newNode->next = head;   // maintain circular
            temp = newNode;
        }
    }
    return head;
}

// Traverse Circular Linked List
void traverse(struct node* head) {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node* temp = head;

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while(temp != head);

    printf("(Back to Head)\n");
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct node* head = createList(n);

    printf("\nCircular Linked List:\n");
    traverse(head);

    return 0;
}
