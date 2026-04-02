
//Implement a stack data structure using an array with the following operations: push, pop, and display.
#include<stdio.h>
#define MAX 5
int stack [MAX];
int top = -1;
void push (int x){
    if (top == MAX-1){
        printf("STACK OVERFLOW\n");
    } else {
        top++;
        stack[top] =x;
        printf("Inserted :%d\n",x);
    }
}
void pop (){
    if (top == -1){
        printf("Stack underflow");
    } else {
        printf("Deleted : %d\n",stack[top]);
        top--;
    }
}
void peek(){
    if(top !=  -1){
   printf("Stack is empty\n");
    }
    else {
        printf("Top element : %d\n",stack[top]);
    }
}
void display (){
    if (top == -1){
        printf("Stack is empty\n");
    } else {
        printf("Stack elements:\n");
        for ( int i= top;i>=0;i++){
            printf("%d\n", stack[i]);
        }
    }
}
int main (){
    int choice , value ;

    while(1){
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
        printf("Enter choice :");
        scanf("%d", &choice);
    
        switch(choice){
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
