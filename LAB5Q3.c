#include <stdio.h>
#include <stdlib.h>
// Comparison function for qsort
int compare(const void *a, const void *b) {
    long long x = *(const long long *)a;
    long long y = *(const long long *)b;

    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}
// First index where arr[index] >= target
int lowerBound(long long arr[], int n, long long target) {
    int low = 0, high = n;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid;
    }

    return low;
}
// First index where arr[index] > target
int upperBound(long long arr[], int n, long long target) {
    int low = 0, high = n;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] <= target)
            low = mid + 1;
        else
            high = mid;
    }

    return low;
}
int main() {
    int N, Q;

    scanf("%d %d", &N, &Q);

    long long *points =
        (long long *)malloc(N * sizeof(long long));

    for (int i = 0; i < N; i++) {
        scanf("%lld", &points[i]);
    }

    // Sort all points
    qsort(points, N, sizeof(long long), compare);

    for (int i = 0; i < Q; i++) {

        long long L, R;
        scanf("%lld %lld", &L, &R);

        int left = lowerBound(points, N, L);
        int right = upperBound(points, N, R);

        printf("%d\n", right - left);
    }

    free(points);

    return 0;
}