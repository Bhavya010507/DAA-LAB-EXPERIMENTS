#include <stdio.h>
#include <stdlib.h>
long long merge(long long arr[], long long temp[],
                int left, int mid, int right) {

    int i = left;
    int j = mid + 1;
    int k = left;

    long long inversions = 0;

    while (i <= mid && j <= right) {

        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];

            // All remaining elements in left half
            // are greater than arr[j]
            inversions += (mid - i + 1);
        }
    }

    // Copy remaining left elements
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // Copy remaining right elements
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy back to original array
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return inversions;
}

long long mergeSort(long long arr[], long long temp[],
                    int left, int right) {

    long long inversions = 0;

    if (left < right) {

        int mid = left + (right - left) / 2;

        // Count inversions in left half
        inversions += mergeSort(arr, temp, left, mid);

        // Count inversions in right half
        inversions += mergeSort(arr, temp, mid + 1, right);

        // Count inversions between two halves
        inversions += merge(arr, temp, left, mid, right);
    }

    return inversions;
}

int main() {

    int n;
    scanf("%d", &n);

    long long *arr = malloc(n * sizeof(long long));
    long long *temp = malloc(n * sizeof(long long));

    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }

    long long result = mergeSort(arr, temp, 0, n - 1);

    printf("%lld\n", result);

    free(arr);
    free(temp);

    return 0;
}