#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int value;
    int freq;
} Element;
// Swap two elements
void swap(Element *a, Element *b) 
{
    Element temp = *a;
    *a = *b;
    *b = temp;
}
// Partition based on frequency
int partition(Element arr[], int low, int high) {
    Element pivot = arr[high];

    int i = low - 1;

    for (int j = low; j < high; j++) {

        // Higher frequency should come first
        if (arr[j].freq > pivot.freq) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);

    return i + 1;
}

// QuickSort based on frequency
void quickSort(Element arr[], int low, int high) {
    if (low < high) {

        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {

    int n, k;
    scanf("%d %d", &n, &k);

    int *a = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    Element *unique = (Element *)malloc(n * sizeof(Element));

    int u = 0;

    // Count frequencies
    for (int i = 0; i < n; i++) {

        int found = -1;

        for (int j = 0; j < u; j++) {
            if (unique[j].value == a[i]) {
                found = j;
                break;
            }
        }

        if (found != -1) {
            unique[found].freq++;
        }
        else {
            unique[u].value = a[i];
            unique[u].freq = 1;
            u++;
        }
    }

    // Sort unique elements by frequency
    quickSort(unique, 0, u - 1);

    // Print top k frequent elements
    for (int i = 0; i < k && i < u; i++) {
        printf("%d", unique[i].value);

        if (i < k - 1 && i < u - 1)
            printf(" ");
    }

    free(a);
    free(unique);

    return 0;
}