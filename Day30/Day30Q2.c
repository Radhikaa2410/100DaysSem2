#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
};
struct node* createList() {
    int n, value;
    struct node *head = NULL, *temp = NULL, *newNode;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) return NULL;

    for (int i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &value);

        newNode = createNode(value);

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    return head;
}


struct node* reverse(struct node* head) {
    struct node *prev = NULL, *curr = head, *next;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

struct node* add(struct node* l1, struct node* l2) {
    struct node dummy;
    dummy.next = NULL;
    struct node* temp = &dummy;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {

        int sum = carry;

        if (l1 != NULL) {
            sum += l1->data;
            l1 = l1->next;
        }

        if (l2 != NULL) {
            sum += l2->data;
            l2 = l2->next;
        }

        carry = sum / 10;

        struct node* newNode = createNode(sum % 10);
        temp->next = newNode;
        temp = newNode;
    }

    return dummy.next;
}


struct node* addTwoNumbers(struct node* l1, struct node* l2) {
    l1 = reverse(l1);
    l2 = reverse(l2);

    struct node* result = add(l1, l2);

    return reverse(result);
}


void printList(struct node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {

    printf("Create First Linked List\n");
    struct node* l1 = createList();

    printf("\nCreate Second Linked List\n");
    struct node* l2 = createList();

    struct node* result = addTwoNumbers(l1, l2);

    printf("\nResult: ");
    printList(result);

    return 0;
}