#include <stdio.h>
// Swap two elements
void swap(long long *a, long long *b) {
    long long temp = *a;
    *a = *b;
    *b = temp;
}

// Partition an array using a pivot from the OTHER array
int partition(long long arr[], int low, int high, long long pivot) {
    int i = low;

    // First move the matching element to the end
    for (int j = low; j <= high; j++) {
        if (arr[j] == pivot) {
            swap(&arr[j], &arr[high]);
            break;
        }
    }

    // Partition elements around pivot
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }

    swap(&arr[i], &arr[high]);

    return i;
}

// Match nuts and bolts
void matchPairs(long long nuts[], long long bolts[],
                int low, int high) {

    if (low < high) {

        // Use a bolt as pivot to partition nuts
        int pivotIndex =
            partition(nuts, low, high, bolts[high]);

        // Use matching nut as pivot to partition bolts
        partition(bolts, low, high, nuts[pivotIndex]);

        // Match left side
        matchPairs(nuts, bolts, low, pivotIndex - 1);

        // Match right side
        matchPairs(nuts, bolts, pivotIndex + 1, high);
    }
}

int main() {
    int n;

    scanf("%d", &n);

    long long nuts[n];
    long long bolts[n];

    // Input nuts
    for (int i = 0; i < n; i++) {
        scanf("%lld", &nuts[i]);
    }

    // Input bolts
    for (int i = 0; i < n; i++) {
        scanf("%lld", &bolts[i]);
    }

    matchPairs(nuts, bolts, 0, n - 1);

    // Print nuts
    for (int i = 0; i < n; i++) {
        printf("%lld", nuts[i]);

        if (i < n - 1)
            printf(" ");
    }

    printf("\n");

    // Print bolts
    for (int i = 0; i < n; i++) {
        printf("%lld", bolts[i]);

        if (i < n - 1)
            printf(" ");
    }

    return 0;
}