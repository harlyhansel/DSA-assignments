#include<stdio.h>
int main() {
    //Define the array
    int arr[] = {1,2,3,4,5,6};
    //Calculate the number of elements in the array
    int size = sizeof(arr) / sizeof(arr[0]);
    //The for loop to traverse the array
    for (int i = 0; i < size; i++) {
        printf("Element at index %d: %d\n", i, arr[i]);
    }

    return 0;
}