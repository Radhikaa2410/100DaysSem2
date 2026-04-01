
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct  node* createnewnode(int data){
struct node* newnode = (struct node*)malloc(sizeof(struct node));
newnode->data = data;
newnode->next = NULL;
return newnode;
};
struct node* insert_end(struct node* head , int data){
    struct node* newnode = createnewnode(data);

    if ( head == NULL)
    return  newnode ;
    struct node* temp =head;
    while (temp-> next !=NULL ){
        temp = temp -> next;
    }   
temp -> next = newnode;

return head;
}
void display(struct node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

struct node* rotateRight(struct node* head , int k){
    if(head == NULL || head->next == NULL || k ==0)
    return head;
    struct node* temp = head;
    int length = 1;

    while(temp->next != NULL){
        temp= temp->next;
        length++;
    }
    temp->next = head;

    k = k % length;
    int jump = length - k;
    struct node* newtail = temp;
    while ( jump--){
        newtail = newtail->next;
    }
    struct node* newhead = newtail->next;
    newtail->next = NULL;
    return newhead;
}
int main () {
    struct node* head = NULL;
    int n,data,k;
    printf("Enter no of nodes:");
    scanf("%d",&n);

    for (int i=0;i<n;i++){
        printf("Enter data for %d node " ,i+1);
        scanf("%d",&data);
        head = insert_end(head , data);
    }
    printf("Original List");
    display(head);

    printf("Enter k:");
    scanf("%d",&k);
   head =  rotateRight(head , k);

   printf("After Rotation ");
   display(head);

   return 0;
}
