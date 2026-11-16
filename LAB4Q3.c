#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition using last element as pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);

    return i + 1;
}

// Randomized partition
int randomizedPartition(int arr[], int low, int high) {
    // Select random index between low and high
    int randomIndex = low + rand() % (high - low + 1);

    // Move randomly selected pivot to the end
    swap(&arr[randomIndex], &arr[high]);

    // Perform normal partition
    return partition(arr, low, high);
}

// Randomized Quicksort
void randomizedQuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = randomizedPartition(arr, low, high);

        randomizedQuickSort(arr, low, pivotIndex - 1);
        randomizedQuickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    int n;

    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Initialize random number generator
    srand(time(NULL));

    randomizedQuickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);

        if (i < n - 1) {
            printf(" ");
        }
    }

    return 0;
