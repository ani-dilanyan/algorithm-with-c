#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int start, int end) {
    int pivot = arr[start];
    int i = start;
    int j = end;

    while (i < j) {
        while (arr[i] <= pivot && i <= end - 1) {
            i++;
        }

        while (arr[j] > pivot && j >= start + 1) {
            j--;
        }
        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[start], &arr[j]);
    return j; 
}

void quickSort(int arr[], int start, int end) {
    if (start < end) {
        int partition_ind = partition(arr, start, end);

        quickSort(arr, start, partition_ind - 1);
        quickSort(arr, partition_ind + 1, end);
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
    quickSort(arr,0, n-1);
    printArray(arr, n);
    
    return 0;
}
