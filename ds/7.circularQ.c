#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;



void enqueue(int value) {
    if ((front == (rear + 1) % SIZE)) {
        printf("Queue is Full (Overflow)\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear = (rear + 1) % SIZE;
    queue[rear] = value;
    printf("%d enqueued\n", value);
}
void dequeue() {
    if (front == -1) {
        printf("Queue is Empty (Underflow)\n");
        return;
    }

    int deleted = queue[front];

    if (front == rear) {
        
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }

    printf("%d dequeued\n", deleted);
}
void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50); 
    display();
    dequeue();
    dequeue();
    display();
    enqueue(60);
    display();
    return 0;
}