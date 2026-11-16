#include <stdio.h>
#include <stdlib.h>
typedef struct {
    long long start;
    long long end;
} Balloon;
// Compare balloons by ending position
int compare(const void *a, const void *b) {
    Balloon *x = (Balloon *)a;
    Balloon *y = (Balloon *)b;

    if (x->end < y->end)
        return -1;
    if (x->end > y->end)
        return 1;

    return 0;
}
int minArrows(Balloon balloons[], int n) {

    // Sort according to ending position
    qsort(balloons, n, sizeof(Balloon), compare);

    // First balloon always requires an arrow
    int arrows = 1;

    // Shoot first arrow at end of first balloon
    long long arrowPosition = balloons[0].end;

    for (int i = 1; i < n; i++) {

        // Current balloon is not hit by previous arrow
        if (balloons[i].start > arrowPosition) {

            arrows++;

            // Shoot new arrow at current balloon's end
            arrowPosition = balloons[i].end;
        }
    }

    return arrows;
}
int main() {

    int n;
    scanf("%d", &n);

    Balloon *balloons =
        (Balloon *)malloc(n * sizeof(Balloon));

    for (int i = 0; i < n; i++) {
        scanf("%lld %lld",
              &balloons[i].start,
              &balloons[i].end);
    }

    printf("%d\n", minArrows(balloons, n));

    free(balloons);

    return 0;
}