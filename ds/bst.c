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
void deletion();
void display();
void inorder(struct node *root);
void preorder(struct node *root);
void postorder(struct node *root);
struct node *insert(struct node *root, struct node *newnode);
struct node *delete(struct node *root, int key);
struct node *find_min(struct node *root);

void main() {
    int choice;
    while (1) {
        printf("\n\n===== BINARY SEARCH TREE MENU =====\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display (Inorder, Preorder, Postorder)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertion();
                break;
            case 2:
                deletion();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

// ========================= INSERTION =========================
void insertion() {
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter element to insert: ");
    scanf("%d", &newnode->data);
    newnode->left = newnode->right = NULL;
    root = insert(root, newnode);
    printf("Element inserted successfully!\n");
}

struct node *insert(struct node *root, struct node *newnode) {
    if (root == NULL)
        return newnode;
    if (newnode->data < root->data)
        root->left = insert(root->left, newnode);
    else if (newnode->data > root->data)
        root->right = insert(root->right, newnode);
    else
        printf("Duplicate value ignored: %d\n", newnode->data);
    return root;
}

// ========================= DELETION =========================
void deletion() {
    int key;
    printf("Enter element to delete: ");
    scanf("%d", &key);
    root = delete(root, key);
}

struct node *delete(struct node *root, int key) {
    if (root == NULL) {
        printf("Element not found!\n");
        return root;
    }
    if (key < root->data)
        root->left = delete(root->left, key);
    else if (key > root->data)
        root->right = delete(root->right, key);
    else {
        // Node found
        if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            printf("Element deleted successfully!\n");
            return temp;
        }
        else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            printf("Element deleted successfully!\n");
            return temp;
        }
        // Node with two children
        struct node *temp = find_min(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}

// Find the minimum node (used in deletion)
struct node *find_min(struct node *root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

// ========================= DISPLAY (All Traversals) =========================
void display() {
    if (root == NULL) {
        printf("Tree is empty!\n");
        return;
    }

    printf("\nInorder Traversal   : ");
    inorder(root);

    printf("\nPreorder Traversal  : ");
    preorder(root);

    printf("\nPostorder Traversal : ");
    postorder(root);

    printf("\n");
}

// ========================= TRAVERSAL FUNCTIONS =========================
void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
