
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};
struct node *head = NULL;
void  insert(int value){
    struct node *newNode = malloc(sizeof(struct node)),*temp;
newNode->data = value;
newNode->next = NULL;
if(head == NULL){
    head = newNode;
} else {
    temp = head;
    while(temp-> next != NULL){
        temp = temp-> next;
    }
    temp-> next = newNode;
}

}

void delete_key(int key){
    struct node *temp =  head , *prev  = NULL;

    if(head == NULL){
        printf("List is empty");
        return;
    }
    if(temp != NULL && temp->data == key){
        head = temp-> next;
        free(temp);
        printf("Firse occurance deleted");
        return ;
    }

    while(temp != NULL && temp->data != key){
        prev = temp;
       temp =  temp-> next;
    }
if (temp == NULL){
    printf("Not found");
    return ;
}
prev-> next = temp->next;
free(temp);
printf("First occruance deleted.");
    }

    void display_List(){
        struct node *temp = head;
        if(head == NULL){
            printf("List is empty");
            return;
        }
        while(temp != NULL){
            printf("%d->",temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
int main(){
    int  n , value , key,i;
    printf("Enter number of nodes:");
    scanf("%d",&n);

    for(int i = 0;i<n;i++){
        printf("Enter value :");
        scanf("%d",&value);
        insert(value);
    }
    printf("LinkedList:");
    display_List();

    printf("Enter key to delete :");
scanf("%d",&key);

delete_key(key);

printf("After deleteion ");
display_List();
return 0;
}
