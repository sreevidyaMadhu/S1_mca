#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
struct Node* head = NULL;
struct Node* createNode(int value){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}
void insertAtBeg(int value){
    struct Node* newNode=createNode(value);
        if(head == NULL) {
            head = newNode;
            newNode->next = head; 
            return;
        }
        struct Node* temp = head;
        while(temp->next != head) {
            temp = temp->next;
        }
    temp->next = newNode;
    newNode->next=head;
    head=newNode;
}
void insertAtEnd(int value){
    struct Node* newNode=createNode(value);
    if(head==NULL){
        head=newNode;
        newNode->next=head;
        return;
    }
    struct Node*temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->next=head;
}
void insertAtPosition(int value,int pos){
    struct Node* newNode=createNode(value);
    if (head == NULL) {
        if (pos != 1) {
            printf("List is empty, can only insert at position 1\n");
            return;
        }
        head = newNode;
        newNode->next = head;
        return;
    }


    if(pos==1){
        struct Node* temp = head;
        while (temp->next !=head){
            temp= temp->next;
        }
        temp->next=newNode;
        newNode->next=head;
        head=newNode;
        return;

    }
    struct Node* temp=head;
    for(int i=1;temp->next!=head && i<pos-1;i++){
        temp=temp->next;

    }
    if(temp==head){
        printf("position not found!\n");
        return;
    }
    newNode->next=temp->next;
    temp->next=newNode;

}
void deleteBegin(){
    if(head==NULL){
        printf("List is empty");
        return;
    }
    if(head->next==head){
        printf("%d deleted from beginning\n",head->data);
        free(head);
        head=NULL;
        return;
    }
    struct Node* temp=head;
    struct Node* last=head;
    while(last->next!=head){
        last=last->next;
    }
    head=head->next;
    last->next=head;
    printf("%d deleted from beginning\n",temp->data);
    free(temp);
}
void deleteEnd(){
    if(head == NULL){
        printf("Linked list is empty\n");
        return;
    }
    if(head->next == head){
        printf("%d deleted from end\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    struct Node* temp = head;
    while(temp->next->next != head){
        temp = temp->next;
    }
    struct Node* del=temp->next;
    printf("%d deleted from end\n", del->data);
    free(del);
    temp->next = head;
}

void deleteAtPos(int pos){
    if(head==NULL){
        printf("linked list is empty");
        return;
    }
    if(pos==1){
        deleteBegin();
        return;
    }
    struct Node* temp=head;
    for(int i=1;temp!=NULL&&i<pos-1;i++){
    temp=temp->next;
    }
    if(temp->next==NULL||temp==NULL){
             printf("position not found");
             return;
        }
        struct Node*del=temp->next;
        temp->next=del->next;
        printf("%d deleted from %d position",del->data,pos);
        free(del);

}
void display() {
    if (head == NULL) {   
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(back to head)\n");
}
int main(){
    int choice, value, pos;
    while(1){
        printf("\nlinked list menu:\n");
        printf("1. insert at beginning\n");
        printf("2. insert at end\n");
        printf("3. insert at a position\n");
        printf("4. delete from beginning\n");
        printf("5. delete from end\n");
        printf("6. delete from a position\n");
        printf("7. display\n");
        printf("8. exit\n");
        printf("enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: 
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeg(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                printf("Enter position: ");
                scanf("%d", &pos);
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtPosition(value, pos);
                break;
            case 4:
                deleteBegin();
                break;
            case 5:
                deleteEnd();
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteAtPos(pos);
                break;
            case 7:
                display();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
}