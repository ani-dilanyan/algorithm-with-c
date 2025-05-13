#include <stdio.h>

int linearSearch(int* arr, int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = { 1, 2, 3, 4, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 5;
    int i = linearSearch(arr, size, key);

    if (i == -1)
        printf("Key Not Found");
    else
        printf("%d Found at Index: %d", key,i);
        
    return 0;
}
