
#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int data;
    struct ListNode* next;
};
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *prev = NULL , *current = head, *next = NULL;

    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
void display_LIST(struct ListNode* head){
    while (head != NULL){
        printf("%d-> ",head->data);
        head = head-> next;
    }
    printf("NULL\n");
}

int main(){
    int n, data;
    struct ListNode *head = NULL, *temp = NULL, *newnode ;

    printf("enter number of nodes:");
    scanf("%d",&n);

    for(int i =0;i<n;i++){
        printf("enter data for node %d:",i+1);
        scanf("%d",&data);

        newnode = malloc(sizeof(struct ListNode));
        newnode->data = data;
        newnode->next = NULL;

        if(head == NULL){
            head = temp = newnode;
        }  else {
            temp-> next = newnode;
            temp =newnode;
        }
    }

    printf("Original List:\n");
    display_LIST(head);

    head = reverseList(head);

    printf("Reversed List:\n");
    display_LIST(head);
    return 0;
}
