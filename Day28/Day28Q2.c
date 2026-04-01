#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node {
    int data;
    struct node* next;
};

// Create node
struct node* createNode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

// Insert at end
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

// Reverse linked list
struct node* reverse(struct node* head) {
    struct node *prev = NULL, *next = NULL;

    while (head != NULL) {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

// Check palindrome
bool isPalindrome(struct node* head) {

    if (head == NULL || head->next == NULL)
        return true;

    struct node *slow = head, *fast = head;

    // Find middle
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse second half
    struct node* secondHalf = reverse(slow);

    struct node* firstHalf = head;

    // Compare
    while (secondHalf != NULL) {
        if (firstHalf->data != secondHalf->data)
            return false;

        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true;
}

// Print list
void printList(struct node* head){
    while(head){
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct node* head = NULL;
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    printList(head);

    if (isPalindrome(head))
        printf("Linked List is Palindrome\n");
    else
        printf("Linked List is NOT Palindrome\n");

    return 0;
}