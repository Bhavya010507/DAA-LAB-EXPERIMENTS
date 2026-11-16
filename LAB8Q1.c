#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int finish;
} Activity;

// Sort by increasing finish time
int compare(const void *a, const void *b) {
    Activity *x = (Activity *)a;
    Activity *y = (Activity *)b;

    if (x->finish < y->finish)
        return -1;
    if (x->finish > y->finish)
        return 1;

    return 0;
}

// Recursive activity selection
void activitySelection(Activity a[], int n, int index,
                       int lastFinish, Activity selected[],
                       int *count) {

    // Base case
    if (index >= n)
        return;

    // Select activity if it is compatible
    if (a[index].start >= lastFinish) {

        selected[*count] = a[index];
        (*count)++;

        // Search for next compatible activity
        activitySelection(a, n, index + 1,
                          a[index].finish,
                          selected, count);
    }
    else {
        // Skip incompatible activity
        activitySelection(a, n, index + 1,
                          lastFinish,
                          selected, count);
    }
}

int main() {
    int n;

    scanf("%d", &n);

    Activity activities[n];
    Activity selected[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d",
              &activities[i].start,
              &activities[i].finish);
    }

    // Sort by earliest finish time
    qsort(activities, n, sizeof(Activity), compare);

    int count = 0;

    activitySelection(activities, n, 0, -1,
                      selected, &count);

    // Maximum number of activities
    printf("%d\n", count);

    // Selected activities
    for (int i = 0; i < count; i++) {

        printf("(%d,%d)",
               selected[i].start,
               selected[i].finish);

        if (i < count - 1)
            printf(" ");
    }

    return 0;
}
