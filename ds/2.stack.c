#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("Overflow\n");
        return;
    } else {
        top++;
        stack[top] = value;
        printf("%d pushed\n", value);
    }
}

void pop() {
    if (top == -1) {
        printf("Underflow\n");
        return;
    } else {
        int x = stack[top];
        top--;
        printf("Deleted %d\n", x);
    }
}
void display() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    } else {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int n;
    while (1) {
        printf("\n1. Push  2. Pop  3. Display  4. Exit\n");
        if (scanf("%d", &n) != 1) {
            printf("Invalid input\n");
            // Clear input buffer
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }
        switch (n) {
            case 1: {
                int value;
                printf("Enter value: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input\n");
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF);
                    break;
                }
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
