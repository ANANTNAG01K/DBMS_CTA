#include <stdio.h>

#define MAX_SIZE 100

void insert_element(int arr[], int *size, int element, int position) {
    if (*size >= MAX_SIZE) {
        printf("Error: Array is full. Cannot insert element.\n");
        return;
    }
    if (position < 0 || position > *size) {
        printf("Error: Invalid position. Please enter a position between 0 and %d.\n", *size);
        return;
    }

    // Shift elements to the right to make space for the new element
    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position] = element; // Insert the new element
    (*size)++;
    printf("Element %d inserted at position %d.\n", element, position);
}

void delete_element(int arr[], int *size, int position) {
    if (*size == 0) {
        printf("Error: Array is empty. Cannot delete element.\n");
        return;
    }
    if (position < 0 || position >= *size) {
        printf("Error: Invalid position. Please enter a position between 0 and %d.\n", *size - 1);
        return;
    }

    // Shift elements to the left to fill the gap
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*size)--; // Decrease the size of the array
    printf("Element at position %d deleted.\n", position);
}

void display_array(const int arr[], int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }

    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int search_element(const int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i; // Return the index if found
        }
    }
    return -1; // Return -1 if not found
}

int main() {
    int arr[MAX_SIZE];
    int size = 0; // Current size of the array
    int choice, element, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Display Array\n");
        printf("4. Search Element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                printf("Enter position to insert (0 to %d): ", size);
                scanf("%d", &position);
                insert_element(arr, &size, element, position);
                break;
            case 2:
                if (size == 0) {
                    printf("Array is empty. Nothing to delete.\n");
                } else {
                    printf("Enter position to delete (0 to %d): ", size - 1);
                    scanf("%d", &position);
                    delete_element(arr, &size, position);
                }
                break;
            case 3:
                display_array(arr, size);
                break;
            case 4:
                printf("Enter element to search: ");
                scanf("%d", &element);
                position = search_element(arr, size, element);
                if (position != -1) {
                    printf("Element %d found at position %d.\n", element, position);
                } else {
                    printf("Element %d not found in the array.\n", element);
                }
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
