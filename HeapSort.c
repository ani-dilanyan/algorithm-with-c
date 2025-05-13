#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void heapify(int arr[], int n, int i) {
    int largest_ind = i;
    int left_ind = 2 * i + 1;
    int right_ind = 2 * i + 2;


    if (left_ind < n && arr[left_ind] > arr[largest_ind]){
        largest_ind = left_ind;
    }

    if (right_ind < n && arr[right_ind] > arr[largest_ind]){
        largest_ind = right_ind;
    }


    if (largest_ind != i) {
        swap(&arr[i], &arr[largest_ind]);
        
        heapify(arr, n, largest_ind);
    }
}


void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--){
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}


void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printArray(arr, n);
    heapSort(arr, n);
    printArray(arr, n);
    
    return 0;
}
