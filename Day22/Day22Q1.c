
// Count Nodes in Linked List
#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
int count_nodes(struct node* head) {
    int count = 0;
    struct node* temp = head;
    while( temp != NULL)
{
    count ++;
    temp = temp-> next;
}
return count ;
};
void printList(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    struct node*head = NULL , *temp = NULL , *newnode = NULL;
    int n, data;
    printf("ENTER NUMBER OD NODES:");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf("Enter data for node %d ", i+1);
        scanf("%d",&data);
   
        
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if(head == NULL){
        head =newnode ;
        temp =head;
    }
    else{
        temp->next = newnode;
        temp = newnode;
    }
    }
    int total  = count_nodes(head);
     printList(head);

    printf("The total no of nodes  = %d\n" , total);
        }
    

