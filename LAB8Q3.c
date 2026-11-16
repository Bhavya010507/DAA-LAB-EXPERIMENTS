#include <stdio.h>
#include <stdlib.h>
typedef struct {
    long long start;
    long long finish;
} Activity;

// Sort by start time in decreasing order
int compare(const void *a, const void *b) {
    Activity *x = (Activity *)a;
    Activity *y = (Activity *)b;

    if (x->start < y->start)
        return 1;

    if (x->start > y->start)
        return -1;

    return 0;
}

// Recursive selection
int selectActivities(Activity a[], int n, int index,
                     long long nextStart, Activity selected[]) {

    // Base case
    if (index >= n)
        return 0;

    // Compatible with the already selected activity
    if (a[index].finish <= nextStart) {

        selected[0] = a[index];

        return 1 + selectActivities(
                       a,
                       n,
                       index + 1,
                       a[index].start,
                       selected + 1
                   );
    }

    // Skip incompatible activity
    return selectActivities(
               a,
               n,
               index + 1,
               nextStart,
               selected
           );
}

int main() {

    int n;
    scanf("%d", &n);

    Activity activities[n];
    Activity selected[n];

    for (int i = 0; i < n; i++) {
        scanf("%lld %lld",
              &activities[i].start,
              &activities[i].finish);
    }

    // Sort in non-increasing order of start time
    qsort(activities, n, sizeof(Activity), compare);

    // First activity has no activity after it,
    // so use a very large nextStart
    long long INF = 1000000000000000000LL;

    int count = selectActivities(
                    activities,
                    n,
                    0,
                    INF,
                    selected
                );

    printf("%d\n", count);

    for (int i = 0; i < count; i++) {
        printf("(%lld,%lld)",
               selected[i].start,
               selected[i].finish);

        if (i < count - 1)
            printf(" ");
    }

    return 0;
}