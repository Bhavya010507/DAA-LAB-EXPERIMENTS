#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ITEMS 100
#define MAX_CAPACITY 1000
void printTable(int dp[MAX_ITEMS + 1][MAX_CAPACITY + 1],
                int items, int W) {

    printf("\nDP Table after processing %d item(s):\n\n", items);

    printf("      ");
    for (int w = 0; w <= W; w++) {
        printf("%4d", w);
    }

    printf("\n");

    for (int i = 0; i <= items; i++) {

        printf("i=%-2d ", i);

        for (int w = 0; w <= W; w++) {
            printf("%4d", dp[i][w]);
        }

        printf("\n");
    }

    printf("\n");
}

int knapsack(int n, int W, int weight[], int value[]) {

    int dp[MAX_ITEMS + 1][MAX_CAPACITY + 1];

    // Initialize DP table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            dp[i][w] = 0;
        }
    }

    printf("\nInitial DP Table:\n");
    printTable(dp, 0, W);

    // Build DP table
    for (int i = 1; i <= n; i++) {

        for (int w = 0; w <= W; w++) {

            // Item can fit
            if (weight[i - 1] <= w) {

                int include =
                    value[i - 1] +
                    dp[i - 1][w - weight[i - 1]];

                int exclude =
                    dp[i - 1][w];

                if (include > exclude)
                    dp[i][w] = include;
                else
                    dp[i][w] = exclude;
            }

            // Item cannot fit
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }

        printf("Item %d: Weight = %d, Value = %d\n",
               i, weight[i - 1], value[i - 1]);

        printTable(dp, i, W);
    }

    return dp[n][W];
}

int main() {

    FILE *input;
    FILE *output;

    char line[100];

    input = fopen("Knapsack data (2) (1).txt", "r");

    if (input == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    output = fopen("result.txt", "w");

    if (output == NULL) {
        printf("Error creating result.txt\n");
        fclose(input);
        return 1;
    }

    int testCase = 0;

    while (fgets(line, sizeof(line), input)) {

        // Detect #Test
        if (strncmp(line, "#Test", 5) == 0) {

            int n, W;

            // Read n and W
            fscanf(input, "%d %d", &n, &W);

            int weight[MAX_ITEMS];
            int value[MAX_ITEMS];

            // Read weights and values
            for (int i = 0; i < n; i++) {
                fscanf(input, "%d %d",
                       &weight[i],
                       &value[i]);
            }

            testCase++;

            printf("\n====================================\n");
            printf("TEST CASE %d\n", testCase);
            printf("n = %d, Capacity = %d\n", n, W);
            printf("====================================\n");

            int result =
                knapsack(n, W, weight, value);

            printf("Maximum Value = %d\n", result);

            // Store result in result.txt
            fprintf(output,
                    "#Test %d (%d %d) %d\n",
                    testCase, n, W, result);
        }
    }

    fclose(input);
    fclose(output);

    printf("\nAll test cases completed.\n");
    printf("Results stored in result.txt\n");

    return 0;
}