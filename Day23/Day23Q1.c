#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node* next;
};

struct node* createNode(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode ;
}

void PrintList(struct node* head){
    while( head != NULL){
        printf("%d->", head->data);
        head = head-> next;
    }
    printf("NULL\n");
}

struct node* sorted_merge(struct node *head1 , struct node *head2 ){
    if(head1 == NULL) return head2 ;
    else if (head2  == NULL) return head1;

    struct node *merge = NULL;
    struct node *q = NULL;

    if (head1-> data <= head2->data){
        merge  = q = head1;
        head1  = head1-> next;
    } else {
        merge = q = head2;
        head2 = head2 -> next;
    }
    while ( head1 != NULL  && head2 != NULL){
        if (head1 ->data <= head2-> data){
            q-> next = head1;
            head1 = head1-> next;
        }
        else {
            q-> next  = head2;
            head2 = head2 -> next;
        }
        q = q-> next ;
    }
    if ( head1 != NULL) q->  next = head1;
    else q-> next = head2 ;
    return merge ;
}
int main() {
    struct node *head1 = NULL, *head2 = NULL, *tail1 = NULL, *tail2 = NULL;

    int n1, n2, val;
    printf("Enter number of elements in first sorted list: ");
    scanf("%d", &n1);
    printf("Enter %d sorted elements:\n", n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &val);
        struct node* newNode = createNode(val);
        if (head1 == NULL) head1 = tail1 = newNode;
        else { tail1->next = newNode; tail1 = newNode; }
    }

    printf("Enter number of elements in second sorted list: ");
    scanf("%d", &n2);
    printf("Enter %d sorted elements:\n", n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &val);
        struct node* newNode = createNode(val);
        if (head2 == NULL) head2 = tail2 = newNode;
        else { tail2->next = newNode; tail2 = newNode; }
    }

    printf("First list:\n");
    PrintList(head1);
    printf("Second list:\n");
    PrintList(head2);

    struct node* merged = sorted_merge(head1, head2);

    printf("Merged sorted list:\n");
    PrintList(merged);

    return 0;
}