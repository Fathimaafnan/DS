#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the binary search tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data); // If the tree is empty, create a new node
    }
    
    // If the data is less, insert into the left subtree
    if (data < root->data) {
        root->left = insert(root->left, data);
    } 
    // If the data is greater, insert into the right subtree
    else {
        root->right = insert(root->right, data);
    }
    
    return root;
}

// Function to perform in-order traversal of the BST
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);   // Visit left subtree
        printf("%d ", root->data);  // Print node data
        inorder(root->right);  // Visit right subtree
    }
}

// Main function
int main() {
    struct Node* root = NULL;
    int n, value;

    // Asking the user how many nodes to insert
    printf("Enter the number of nodes to insert: ");
    scanf("%d", &n);

    // Inserting nodes into the BST
    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        root = insert(root, value);
    }

    // Performing in-order traversal and printing the tree
    printf("In-order traversal of the BST: ");
    inorder(root);  // Should print nodes in sorted order
    printf("\n");

    return 0;
}

