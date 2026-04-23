//Create and Traverse Singly Linked List
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* createList(int n) {
    struct node *head = NULL, *temp = NULL, *newNode = NULL;
    int value, i;

    for (i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &value);

        newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) 
        {
            head = newNode;   
        } else {
            //traversing
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode; 
        }
    }
    return head;
}

void printList(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int n;
    struct node *head = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    head = createList(n);   

    printf("\nLinked List:\n");
    printList(head);       

    return 0;
}