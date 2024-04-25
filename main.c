#include "bst.h"
#include <stdio.h>
#include <string.h>

typedef struct {
    char make[50];
    char model[50];
    int price;
} Vehicle;

int compareVehicles(void* a, void* b) {
    Vehicle* vehicleA = (Vehicle*)a;
    Vehicle* vehicleB = (Vehicle*)b;
    return vehicleA->price - vehicleB->price;
}

void printVehicle(void* data) {
    Vehicle* vehicle = (Vehicle*)data;
    printf("%s, %s, %d\n", vehicle->make, vehicle->model, vehicle->price);
}

void insertCarsFromFile(BSTNode** root, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    char line[150];
    while (fgets(line, sizeof(line), file)) {
        Vehicle* vehicle = (Vehicle*)malloc(sizeof(Vehicle));
        if (sscanf(line, "%49[^,],%49[^,],%d", vehicle->make, vehicle->model, &(vehicle->price)) == 3) {
            *root = insert(*root, vehicle, compareVehicles);
        } else {
            free(vehicle); // If the line doesn't contain valid data, free the allocated memory
        }
    }

    fclose(file);
}

int main() {
    BSTNode* root = NULL;

    insertCarsFromFile(&root, "data/cars.csv");

    // Now, we can print in order to check if the tree is correct.
    printInOrder(root, printVehicle);

    printf("Freeing tree\n");
    freeTree(root);

    return 0;
}