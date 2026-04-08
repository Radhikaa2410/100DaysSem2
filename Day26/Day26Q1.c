#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* prev;
    struct node* next;
};

struct node* head = NULL;

// Insert at Beginning
void insertBeg(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;

    printf("Inserted at beginning successfully!\n");
}

// Insert at End
void insertEnd(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        printf("Inserted at end successfully!\n");
        return;
    }

    struct node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

    printf("Inserted at end successfully!\n");
}

// 🔥 Display Function (Forward + Backward)
void display() {
    struct node* temp = head;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("\nForward Traversal:\n");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        if (temp->next == NULL)   // last node
            break;
        temp = temp->next;
    }
    printf("NULL\n");

    printf("Backward Traversal:\n");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

// Main Function
int main() {
    int choice, value;

    while (1) {
        printf("\n===== DOUBLY LINKED LIST MENU =====\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertBeg(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(value);
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
}