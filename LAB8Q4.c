#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int value;
    int weight;
    double ratio;
} Item;
// Sort items by decreasing value/weight ratio
int compare(const void *a, const void *b) {
    Item *x = (Item *)a;
    Item *y = (Item *)b;

    if (x->ratio < y->ratio)
        return 1;
    else if (x->ratio > y->ratio)
        return -1;
    else
        return 0;
}
int main() {
    int n, W;

    // Input n and capacity
    scanf("%d %d", &n, &W);

    Item items[n];

    // Input value and weight
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].value, &items[i].weight);

        items[i].ratio =
            (double)items[i].value / items[i].weight;
    }

    // Sort by value/weight ratio
    qsort(items, n, sizeof(Item), compare);

    double maxValue = 0.0;
    int remaining = W;

    for (int i = 0; i < n; i++) {

        // Take complete item
        if (items[i].weight <= remaining) {

            maxValue += items[i].value;
            remaining -= items[i].weight;
        }

        // Take fraction of item
        else {

            double fraction =
                (double)remaining / items[i].weight;

            maxValue += items[i].value * fraction;

            break;
        }
    }

    printf("%.1f\n", maxValue);

    return 0;
}