
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
}

struct node* insertEnd(struct node* head, int data) {
    struct node* newNode = createNode(data);

    if (head == NULL)
        return newNode;

    struct node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

struct node* addTwoNumbers(struct node* l1, struct node* l2) {
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

        temp->next = createNode(sum % 10);
        temp = temp->next;
    }

    return dummy.next;
}

void printList(struct node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {

    struct node* l1 = NULL;
    struct node* l2 = NULL;
    int n1, n2, data;

    printf("Enter number of nodes in first list: ");
    scanf("%d", &n1);

    for (int i = 0; i < n1; i++) {
        printf("Enter digit: ");
        scanf("%d", &data);
        l1 = insertEnd(l1, data);
    }

    printf("Enter number of nodes in second list: ");
    scanf("%d", &n2);

    for (int i = 0; i < n2; i++) {
        printf("Enter digit: ");
        scanf("%d", &data);
        l2 = insertEnd(l2, data);
    }

    printf("First List: ");
    printList(l1);

    printf("Second List: ");
    printList(l2);

    struct node* result = addTwoNumbers(l1, l2);

    printf("Result: ");
    printList(result);

    return 0;
}
