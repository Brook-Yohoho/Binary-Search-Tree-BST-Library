# Binary-Search-Tree-BST-Library

This repository contains a C library for working with binary search trees. The library provides essential functions for creating, manipulating, and managing BSTs. Below, I’ll explain the purpose of this library, its features, and how to use it.

# Features
The BST library includes the following functions:

Minimum: Returns the minimum value in the tree.
Maximum: Returns the maximum value in the tree.
Insert: Inserts a new value into the tree.
Search: Searches for a value in the tree.
Print: Prints the tree in order.
Free: Frees the memory used by the tree.

# Getting Started
Clone this repository to your local machine.
Compile the library using the provided Makefile.
Include the header file (bst.h) in your C programs.
Link your program with the compiled library.

# Usage
# Creating a BST

#include "bst.h"

int main() {
    // Create an empty BST
    BST* tree = bst_create();

    // Insert values into the tree
    bst_insert(tree, 5);
    bst_insert(tree, 3);
    // ... (insert other values)

    // Print the tree
    printf("Tree contents: ");
    bst_print(tree);

    // Find minimum and maximum
    printf("Minimum: %d\n", bst_minimum(tree));
    printf("Maximum: %d\n", bst_maximum(tree));

    // Search for a value
    int target = 5;
    if (bst_search(tree, target)) {
        printf("Found %d in the tree.\n", target);
    } else {
        printf("%d not found in the tree.\n", target);
    }

    // Free memory
    bst_free(tree);

    return 0;
}

# Deleting Nodes
To delete nodes from the tree, implement the transplant and delete functions. Then, test them using the example data provided.

# Organizing Vehicle Data
Organize the given CSV file of vehicle data into a balanced BST based on price. Implement a struct for vehicles and a comparison function to compare objects by price. Verify the correctness by printing the tree after reading all data from the file.

# Observations
Please record your observations about the organization of values in a text file named observations.txt.