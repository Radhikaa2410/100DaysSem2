
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* createList(int n){
    struct node *head = NULL, *temp = NULL ,*newnode;

    int i , value;
    for (i=0;i<n;i++){
        struct node* newnode = malloc(sizeof(struct node));

        if(newnode ==NULL){
            printf("memory allocation failed\n");
            exit(0);
        }

        printf("Enter data:");
        scanf("%d",&value);

        newnode->data = value;
        newnode->next = NULL;
        if(head == NULL){
            head = newnode;
            temp = newnode;
        
    } else {
        temp->next = newnode;
        temp = newnode;
    }
}
return head;
}

int count_element(struct node *head , int key){
    int count = 0;

    while(head != NULL){
        if(head->data == key){
            count++;
        }
        head =  head->next;
    }
    return count;
}

int main(){
    struct node *head;
    int n, key, result;

    printf("Enter number of nodes:");
    scanf("%d",&n);

    head = createList(n);

    printf("Enter element to count:");
    scanf("%d",&key);
    result = count_element(head,key);

    printf("Element %d occurs %d times.\n" , key,result);

    return 0;
}
