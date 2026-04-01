
#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff;
    int exp;
    struct node* next;
};

struct node* createNode(int coeff, int exp) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}
struct node* insertTerm(struct node* head, int coeff, int exp) {
    struct node* newNode = createNode(coeff, exp);

    if (head == NULL)
        return newNode;

    struct node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

void display(struct node* head) {
    struct node* temp = head;

    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->exp);

        if (temp->next != NULL && temp->next->coeff >= 0)
            printf(" + ");
        else if (temp->next != NULL)
            printf(" ");

        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct node* poly = NULL;
    int n, coeff, exp;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &coeff, &exp);
        poly = insertTerm(poly, coeff, exp);
    }

    printf("Polynomial: ");
    display(poly);

    return 0;
}
