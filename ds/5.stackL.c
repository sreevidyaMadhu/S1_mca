#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* top = NULL;
void push(int value)
{
   struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data=value;
    newNode->next=top;
    top=newNode;
    printf("%d pushed\n",value); 
}
void pop()
{
    if(top==NULL)
    {
        printf("underflow");
        return;
    }
    struct Node* temp=top;
    top=top->next;
    printf("%d deleted ",temp->data);
    free(temp);

}
void display() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    struct Node* temp = top;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    int n;
    while (1) {
        printf("\n1. Push  2. Pop  3. Display  4. Exit\n");
        scanf("%d", &n);
        switch (n) {
            case 1: {
                int value;
                printf("Enter value: ");
                scanf("%d", &value);
                push(value);
                break;
            }
            case 2:
                pop();
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