#include <stdio.h>

#define MAX_SIZE 100

void insertElement(int array[], int size, int element, int position) {
    if (size >= MAX_SIZE) {
        printf("Array is full. Insertion failed.\n");
        return;
    }
    
    // Make room for the new element by shifting all elements to the right
    for (int i = size - 1; i >= position; i--) {
        array[i + 1] = array[i];
    }
    
    // Insert the new element at the specified position
    array[position] = element;
    
    printf("Element inserted successfully.\n");
}

int main() {
    int array[MAX_SIZE];
    int size, element, position;

    printf("Enter the size of the array (up to %d): ", MAX_SIZE);
    scanf("%d", &size);

    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    printf("Enter the element to be inserted: ");
    scanf("%d", &element);

    printf("Enter the position at which to insert the element (0-%d): ", size);
    scanf("%d", &position);

    insertElement(array, size, element, position);

    printf("Array after insertion: ");
    for (int i = 0; i <= size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}