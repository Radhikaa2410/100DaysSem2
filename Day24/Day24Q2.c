
#include <stdio.h>
#include <stdlib.h>

// Definition of ListNode
struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* removeElements(struct ListNode* head, int val) {
    
    
    while (head != NULL && head->val == val) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
    
    
    struct ListNode* current = head;
    
    while (current != NULL && current->next != NULL) {
        
        if (current->next->val == val) {
            struct ListNode* temp = current->next;
            current->next = temp->next;
            free(temp);
        } 
        else {
            current = current->next;
        }
    }
    
    return head;
}


struct ListNode* insert(struct ListNode* head, int value) {
    
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = NULL;
    
    if (head == NULL) {
        return newNode;
    }
    
    struct ListNode* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = newNode;
    return head;
}


void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    
    struct ListNode* head = NULL;
    int n, value, valToRemove;
    
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &value);
        head = insert(head, value);
    }
    
    printf("\nOriginal List:\n");
    printList(head);
    
    printf("\nEnter value to remove: ");
    scanf("%d", &valToRemove);
    
    head = removeElements(head, valToRemove);
    
    printf("\nUpdated List:\n");
    printList(head);
    
    return 0;
}
