#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* left;
    struct Node* right;
    int height;
} node;

node* root = NULL;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(node* root) {
    if (!root)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

node* rightRotate(node* x) {
    node* y = x->left;
    node* T2 = y->right;

    y->right = x;
    x->left = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

node* leftRotate(node* x) {
    node* y = x->right;
    node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(node* root) {
    if (!root)
        return 0;
    return height(root->left) - height(root->right);
}

node* Balance(node* root, int key) {
    if (!root)
        return NULL;

    int balance = getBalance(root);

    if (balance > 1 && key < root->left->val)
        return rightRotate(root);
    if (balance < -1 && key > root->right->val)
        return leftRotate(root);
    if (balance > 1 && key > root->left->val) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && key < root->right->val) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

node* newNode(int val) {
    node* newn = (node*)malloc(sizeof(node));
    newn->val = val;
    newn->left = NULL;
    newn->right = NULL;
    newn->height = 1; // New nodes are initially at height 1
    return newn;
}

node* insert(node* root, int key) {
    if (!root)
        return newNode(key);

    if (key < root->val)
        root->left = insert(root->left, key);
    else if (key > root->val)
        root->right = insert(root->right, key);
    else
        return root; // Duplicate keys not allowed

    root->height = 1 + max(height(root->left), height(root->right));

    return Balance(root, key);
}

void preOrder(node* root) {
    if (!root)
        return;

    printf("%d\t", root->val);

    if (root->left)
        preOrder(root->left);

    if (root->right)
        preOrder(root->right);
}

int main() {
    root = insert(root, 3);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 1);
    root = insert(root, 5);
    root = insert(root, 6);

    preOrder(root);
    printf("\n");
    printf("Height of AVL tree is %d\n", root->height);

    return 0;
}
