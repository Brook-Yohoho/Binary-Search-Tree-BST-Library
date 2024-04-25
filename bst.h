#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>

// This is the node structure for the BST
typedef struct BSTNode {
    void* data;                // Pointer to the data, which allows for generic data types
    struct BSTNode* left;      // Pointer to the left child
    struct BSTNode* right;     // Pointer to the right child
    struct BSTNode* parent;    // Pointer to the parent node
} BSTNode;

// Function prototypes for BST operations
BSTNode* createNode(void* data); // Creates a new node with the provided data
BSTNode* insert(BSTNode* root, void* data, int (*compare)(void*, void*)); // Inserts a new node into the BST
BSTNode* search(BSTNode* root, void* data, int (*compare)(void*, void*)); // Searches for a node in the BST
void printInOrder(BSTNode* root, void (*printData)(void*)); // Prints the BST in-order
void* maximum(BSTNode* root); // Returns the maximum value in the BST
void* minimum(BSTNode* root); // Returns the minimum value in the BST
void freeTree(BSTNode* root); // Frees the memory allocated for the BST
void transplant(BSTNode** T, BSTNode* u, BSTNode* v); // Replaces one subtree as a child of its parent with another subtree
void delete(BSTNode** T, void* data, int (*compare)(void*, void*)); // Deletes a node from the BST

#endif // BST_H