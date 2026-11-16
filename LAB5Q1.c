#include <stdio.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void quickSort3Way(int arr[], int low, int high) {

    if (low >= high)
        return;

    // First element as pivot
    int pivot = arr[low];

    int lt = low;
    int i = low + 1;
    int gt = high;

    while (i <= gt) {

        if (arr[i] < pivot) {

            swap(&arr[lt], &arr[i]);
            lt++;
            i++;
        }

        else if (arr[i] > pivot) {

            swap(&arr[i], &arr[gt]);
            gt--;

        }

        else {
            i++;
        }
    }

    // Sort elements smaller than pivot
    quickSort3Way(arr, low, lt - 1);

    // Sort elements greater than pivot
    quickSort3Way(arr, gt + 1, high);
}
int main() {

    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    quickSort3Way(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {

        printf("%d", arr[i]);

        if (i < n - 1)
            printf(" ");
    }

    return 0;
}