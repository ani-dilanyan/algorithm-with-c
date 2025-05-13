// Task 3
#include <stdio.h>

void swap(int *arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}


void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


void recursive_selection_sort(int array[], int start_ind, int size) {
    if (start_ind == size - 1) {
        return;
    }

    int min_idx = start_ind;
    for (int i = start_ind + 1; i < size; i++) {
        if (array[i] < array[min_idx]) {
            min_idx = i;
        }
    }

    swap(array, start_ind, min_idx);

    recursive_selection_sort(array, start_ind + 1, size);
}


int main() {
    int data[] = {9, 5, 1, 4, 3};
    int size = sizeof(data) / sizeof(data[0]);

    printf("Original array: ");
    print_array(data, size);

    recursive_selection_sort(data, 0, size);

    printf("Sorted array: ");
    print_array(data, size);

    return 0;
}