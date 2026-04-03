#include<stdio.h>
#define MAX 5

int dq[MAX];
int front = -1;
int rear = -1;

// Check empty
int isEmpty() {
    return front == -1;
}

// Check full
int isFull() {
    return (front == (rear + 1) % MAX);
}

void push_front(int x){
    if(isFull()){
        printf("Overflow\n");
        return;
    }

    if(isEmpty()){
        front = rear = 0;
    }
    else if(front == 0){
        front = MAX - 1;
    }
    else{
        front--;
    }

    dq[front] = x;
}

void push_back(int x){
    if(isFull()){
        printf("Overflow\n");
        return;
    }

    if(isEmpty()){
        front = rear = 0;
    }
    else if(rear == MAX - 1){
        rear = 0;
    }
    else{
        rear++;
    }

    dq[rear] = x;
}

void pop_front(){
    if(isEmpty()){
        printf("Underflow\n");
        return;
    }

    printf("Deleted: %d\n", dq[front]);

    if(front == rear){
        front = rear = -1;
    }
    else if(front == MAX - 1){
        front = 0;
    }
    else{
        front++;
    }
}

void pop_back(){
    if(isEmpty()){
        printf("Underflow\n");
        return;
    }

    printf("Deleted: %d\n", dq[rear]);

    if(front == rear){
        front = rear = -1;
    }
    else if(rear == 0){
        rear = MAX - 1;
    }
    else{
        rear--;
    }
}

// Get front element
void getFront(){
    if(isEmpty()){
        printf("Deque is empty\n");
    } else {
        printf("Front: %d\n", dq[front]);
    }
}

// Get rear element
void getRear(){
    if(isEmpty()){
        printf("Deque is empty\n");
    } else {
        printf("Rear: %d\n", dq[rear]);
    }
}

// Size
int size(){
    if(isEmpty()) return 0;
    if(rear >= front)
        return rear - front + 1;
    else
        return MAX - front + rear + 1;
}

// Display deque
void display(){
    if(isEmpty()){
        printf("Deque is empty\n");
        return;
    }

    int i = front;
    printf("Deque: ");

    while(1){
        printf("%d ", dq[i]);
        if(i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// Main function
int main(){
    push_back(10);
    push_back(20);
    push_front(5);
    push_front(2);

    display();

    pop_front();
    pop_back();

    display();

    getFront();
    getRear();

    printf("Size: %d\n", size());

    return 0;
}