#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct node {
    int data;
    struct node* next;
};

struct node* top = NULL;

void push(int value){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL){
        printf("Stack Overflow\n");
        exit(1);
    }
    newnode->data = value;
    newnode->next = top;
    top = newnode;
}

int pop(){
    if (top == NULL){
        printf("Stack Underflow\n");
        exit(1);
    }
    struct node* temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);
    return value;
}

int Postfix(char* exp){
    int i = 0;

    while(exp[i] != '\0'){
        if (isdigit(exp[i])){
            push(exp[i] - '0');
        }
        else {
            int val2 = pop();
            int val1 = pop();

            switch (exp[i]){
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
            }
        }
        i++;  // IMPORTANT
    }
    return pop();  // final result
}

int main(){
    char exp[] = "23*54*+9-";  // Example postfix
    printf("Result = %d\n", Postfix(exp));
    return 0;
}