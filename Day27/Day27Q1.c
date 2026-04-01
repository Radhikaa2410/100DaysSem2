
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* createNode(int data){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    return newnode;
}

struct node* insertEnd(struct node* head, int data) {
    struct node* newnode = createNode(data);

    if (head == NULL)
        return newnode;

    struct node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    return head;
}
void printList (struct node* head){
    while(head != NULL){
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
struct node* find_intersection(struct node* head1 , struct node* head2){
    if(head1 == NULL || head2 == NULL)
    return NULL;

    struct node* ptr1 = head1;
    struct node* ptr2 = head2;

    while(ptr1 != ptr2){
        ptr1 = (ptr1 == NULL)? head2 : ptr1->next;
        ptr2 = (ptr2 == NULL) ? head1 : ptr2->next;
    }

    return ptr1;
}

int main() {
    struct node *head1 = NULL, *head2 = NULL;
    int n1, n2, value;

    // First list input
    printf("Enter number of nodes in List 1: ");
    scanf("%d", &n1);

    for (int i = 0; i < n1; i++) {
        printf("Enter value: ");
        scanf("%d", &value);
        head1 = insertEnd(head1, value);
    }

    // Second list input
    printf("\nEnter number of nodes in List 2: ");
    scanf("%d", &n2);

    for (int i = 0; i < n2; i++) {
        printf("Enter value: ");
        scanf("%d", &value);
        head2 = insertEnd(head2, value);
    }

    // Ask user where to intersect
    int pos;
    printf("\nEnter position in List1 where List2 should intersect (0-based index, -1 for no intersection): ");
    scanf("%d", &pos);

    if (pos >= 0) {
        struct node* temp1 = head1;
        for (int i = 0; i < pos && temp1 != NULL; i++)
            temp1 = temp1->next;

        if (temp1 != NULL) {
            struct node* temp2 = head2;
            while (temp2->next != NULL)
                temp2 = temp2->next;

            temp2->next = temp1;  // Making intersection
        }
    }

    printf("\nList 1: ");
    printList(head1);

    printf("List 2: ");
    printList(head2);

    struct node* intersection = find_intersection(head1, head2);
   

    if (intersection != NULL)
        printf("\nIntersection Point: %d\n", intersection->data);
    else
        printf("\nNo Intersection\n");

    return 0;
}
