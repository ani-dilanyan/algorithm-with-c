#include <stdio.h>
#include <string.h>

// Defining the Student struct
typedef struct {
    char name[50];
    int grade;
} Student;

// Creating method for swaping array's two elements
void swap(Student *arr, int i, int j) {
    Student temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}


// Creating Bubble Sort function for sorting and printing number of swaps and comparisons 
void BubbleSort(Student array[], int size) {
    int comparisons = 0;
    int swaps = 0;
    int swapped;
    for (int i = 0; i < size - 1; i++) {
        swapped = 0;
        for (int j = 0; j < size - i - 1; j++) {
            comparisons++;
            if (array[j].grade > array[j + 1].grade || 
                (array[j].grade == array[j + 1].grade && strcmp(array[j].name, array[j + 1].name) > 0)) {
                swap(array, j, j + 1);
                swaps++;
                swapped = 1; 
            }
        }

        if (!swapped) {
            break;
        }
    }

    printf("Number of comparisons: %d\n", comparisons);
    printf("Number of swaps: %d\n", swaps);
}


// Creating function for printing list of students
void print_students_list(Student* students, int size){
    for (int i = 0; i < size; i++) {
        printf("%s: %d\n", students[i].name, students[i].grade);
    }
}


int main() {
    Student students[] = {
        {"Alice", 85},
        {"Bob", 70},
        {"Charlie", 90},
        {"Diana", 75}
    }; // Defining array of students

    int size = sizeof(students) / sizeof(students[0]); // Size of the array 

    // Printing original and sorted arrays
    printf("Original list:\n");
    print_students_list(students, size);

    BubbleSort(students, size);

    printf("Sorted list:\n");
    print_students_list(students, size);

    return 0;
}
