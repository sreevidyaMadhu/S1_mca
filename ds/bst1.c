#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

// Function declarations
void insertion();

void main() {
    int choice;
    while (1) {
        printf("\n\n===== BINARY SEARCH TREE MENU =====\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
         switch (choice) {
            case 1:
                insertion();
                break;
         }
        }
}


void insertion(){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter the element to insert:");
    scanf("%d", &newnode->data);
    newnode->right=newnode->left=NULL;
    root=insert(root,newnode);
    printf("value inserted successfully");
}

struct node *insert(struct node *root,struct node *newnode){
    if(root==NULL){
        return newnode;
    }
    if(newnode->data < root->data){
        root->left=insert(root->left,newnode);
    }
    else if(newnode->data>root->data){
        root->right=insert(root->right)
    }
    return root;
}
struct node *delete(struct node *root,int value){
    if(root==NULL)
    struct node *temp;
    {
        printf("not found");
        return root;
    }
    if(value<root->data){
        root->left=delete(root->left,value);
    }
    else if(value>root->data){
        root->right=delete(root->right,value);
    }
    else{
        if(root->left==NULL)
        
        {
            temp=root->left;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            temp=root->left;
            free(root);
            return temp;

        }
        root->data=find_min(root->right)->data;
        root->right=delete(root->right,root->data);
    }
    return root;
}
void deletion()
{
    int value;
    printf("enter the node to delete:");
    scanf("%d",&value);
    root=delete(root,value);
    display();
}

struct node *find_min(struct node *root)
{
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}