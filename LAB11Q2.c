#include <stdio.h>
#include <limits.h>
#define MAX 101
long long dp[MAX][MAX];
int main() {
    int n;

    scanf("%d", &n);

    long long p[n + 1];

    for (int i = 0; i <= n; i++) {
        scanf("%lld", &p[i]);
    }

    // One matrix requires 0 multiplications
    for (int i = 1; i <= n; i++) {
        dp[i][i] = 0;
    }

    // len = number of matrices in current chain
    for (int len = 2; len <= n; len++) {

        for (int i = 1; i <= n - len + 1; i++) {

            int j = i + len - 1;

            dp[i][j] = LLONG_MAX;

            // Try every possible split point
            for (int k = i; k < j; k++) {

                long long cost =
                    dp[i][k]
                    + dp[k + 1][j]
                    + p[i - 1] * p[k] * p[j];

                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    printf("%lld\n", dp[1][n]);

    return 0;
}