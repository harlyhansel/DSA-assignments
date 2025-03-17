#include <stdio.h>

int deleteElement(int arr[], int *size, int position) {
    if (position >= *size || position < 0) {
        printf("Invalid position!\n");
        return -1; // Return an invalid value to indicate failure
    }

    int deletedElement = arr[position];

    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;

    return deletedElement;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, size);

    // Delete element at the beginning
    int deletedBeginning = deleteElement(arr, &size, 0);
    printf("After deleting element %d at the beginning: ", deletedBeginning);
    printArray(arr, size);

    // Delete element from the middle
    int middle = size / 2;
    int deletedMiddle = deleteElement(arr, &size, middle);
    printf("After deleting element %d from the middle: ", deletedMiddle);
    printArray(arr, size);

    // Delete element at the end
    int deletedEnd = deleteElement(arr, &size, size - 1);
    printf("After deleting element %d at the end: ", deletedEnd);
    printArray(arr, size);

    return 0;
}
