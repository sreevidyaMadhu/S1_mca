#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* front = NULL;
struct Node* rear = NULL;
struct Node* createNode(int value){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}

void enqueue(int value){
    struct Node* newNode=createNode(value);
    if(rear==NULL){
        front=rear=newNode;
        return;
    }
    rear->next=newNode;
    rear=newNode;
    printf("%d enqueued to queue\n",value);
}
void dequeue(){
    if(front==NULL){
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp=front;
    front=front->next;
    if(front==NULL){
        rear=NULL;
    }
    printf("%d dequeued from queue\n",temp->data);
    free(temp);
}
void display(){
    struct Node* temp=front;
    if(temp==NULL){
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
int main(){
    int choice, value;
    while(1){
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d",&value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
