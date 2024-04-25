#include "bst.h"
#include <stdlib.h>

// Function to create a new BST node.
BSTNode* createNode(void* data) {
    BSTNode* newNode = (BSTNode*)malloc(sizeof(BSTNode));
    if (newNode == NULL) {
        perror("Failed to create a new node");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;  // Initialize the parent.
    return newNode;
}

BSTNode* insert(BSTNode* root, void* data, int (*compare)(void*, void*)) {
    BSTNode* parent = NULL;
    BSTNode* current = root;

    // Finding correct position and the parent for the new node
    while (current != NULL) {
        parent = current;
        if (compare(data, current->data) < 0) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    BSTNode* newNode = createNode(data);
    newNode->parent = parent;

    if (parent == NULL) {
        root = newNode; // The tree was empty
    } else if (compare(data, parent->data) < 0) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }

    return root;
}

BSTNode* search(BSTNode* root, void* data, int (*compare)(void*, void*)) {
    if (root == NULL || compare(root->data, data) == 0) {
        return root;
    }
    if (compare(data, root->data) < 0) {
        return search(root->left, data, compare);
    }
    return search(root->right, data, compare);
}

void transplant(BSTNode** T, BSTNode* u, BSTNode* v) {
    if (u->parent == NULL) {
        *T = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    if (v != NULL) {
        v->parent = u->parent;
    }
}

BSTNode* tree_minimum(BSTNode* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

void delete(BSTNode** T, void* data, int (*compare)(void*, void*)) {
    BSTNode* z = search(*T, data, compare);
    if (z == NULL) return; // Node not found

    if (z->left == NULL) {
        transplant(T, z, z->right);
    } else if (z->right == NULL) {
        transplant(T, z, z->left);
    } else {
        BSTNode* y = tree_minimum(z->right);
        if (y->parent != z) {
            transplant(T, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        transplant(T, z, y);
        y->left = z->left;
        y->left->parent = y;
    }
    free(z);
}

void* minimum(BSTNode* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

void* maximum(BSTNode* root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root->data;
}

void printInOrder(BSTNode* root, void (*printData)(void*)) {
    if (root != NULL) {
        printInOrder(root->left, printData);
        printData(root->data);
        printInOrder(root->right, printData);
    }
}

// Function to free the memory of the BST.
void freeTree(BSTNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root->data); // Assuming that data should be freed as well.
        free(root);
    }
}