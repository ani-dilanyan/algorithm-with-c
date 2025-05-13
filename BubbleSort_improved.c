#include <stdbool.h>
#include <stdio.h>

void swap(int *a, int *b) { 
    int temp = *a;
    *a=*b;
    *b = temp;
}

void bubbleSort(int arr[], int n) { 
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) { 
            if (arr[j] > arr[j + 1]) {
                swap(arr + j, arr + j + 1);
                swapped = true;
            } 
        }
        if (swapped == false){
            break;
        }
    }
}

int main() {
    int arr[] = {6, 0, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, n);
    
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0; 
}