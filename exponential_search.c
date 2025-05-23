#include <stdio.h>
#include <time.h>
#include <math.h>

int min(int a, int b) {
    if (a < b)
        return a;
    else
        return b;
}


int binarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r-l) / 2;

        if (arr[mid] == x) return mid;
        if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);

        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}


int exponentialSearch(int arr[], int n, int x) {
    if (arr[0] == x) return 0;

    int i = 1;
    while (i < n && arr[i] <= x)
        i = i * 2;

    return binarySearch(arr, i / 2, min(i, n - 1), x);
}


int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    int result = exponentialSearch(arr, n, x);
    
    if (result == -1)
        printf("Element is not present in array\n");
    else
        printf("%d Found at Index: %d\n", x, result); 
    
    return 0;
}