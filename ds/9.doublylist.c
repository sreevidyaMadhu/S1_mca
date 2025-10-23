#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* head = NULL;
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
void insertAtBeginning(int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("%d inserted at the beginning\n", value);
}
void insertAtEnd(int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("%d inserted at the end\n", value);
}
void insertAtPosition(int value, int position) {
    if (position < 1) {
        printf("Invalid position\n");
        return;
    }
    if (position == 1) {
        insertAtBeginning(value);
        return;
    }
    struct Node* newNode = createNode(value);
    struct Node* temp = head;
    for (int i = 1; i < position - 1; i++) {
        if (temp == NULL) {
            printf("Position out of bounds\n");
            free(newNode);
            return;
        }
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of bounds\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    printf("%d inserted at position %d\n", value, position);
}
void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    printf("Doubly Linked List elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    printf("%d deleted from the beginning\n", temp->data);
    free(temp);
}
void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (head->next == NULL) {
        printf("%d deleted from the end\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    printf("%d deleted from the end\n", temp->data);
    free(temp);
}
void deleteAtPosition(int position) {
    if (head == NULL || position < 1) {
        printf("Invalid position or list is empty\n");
        return;
    }
    struct Node* temp = head;
    if (position == 1) {
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        printf("%d deleted from position 1\n", temp->data);
        free(temp);
        return;
    }
    for (int i = 1; i < position; i++) {
        if (temp == NULL) {
            printf("Position out of bounds\n");
            return;
        }
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of bounds\n");
        return;
    }
    temp->prev->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    printf("%d deleted from position %d\n", temp->data, position);
    free(temp);
}
int main() {
    int choice, value, position;
    while (1) {
        printf("\n1. Insert at Beginning\n  2. Insert at End\n  3. Insert at Position\n  4. Display\n  5. Delete at Beginning\n  6. Delete at End\n  7. Delete at Position\n  8. Exit\n  enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(value, position);
                break;
            case 4:
                display();
                break;
            case 5:
                deleteFromBeginning();
                break;
            case 6:
                deleteFromEnd();
                break;
            case 7:
                printf("Enter position: ");
                scanf("%d", &position);
                deleteAtPosition(position);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice\n");
                exit(0);

        }
    }
    return 0;

}
