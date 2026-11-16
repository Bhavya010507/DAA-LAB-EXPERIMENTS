#include <stdio.h>
#include <string.h>
#define MAX 1001
int dp[MAX][MAX];
int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    char A[MAX], B[MAX];

    scanf("%s", A);
    scanf("%s", B);

    int m = strlen(A);
    int n = strlen(B);

    // Build DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {

            // Characters match
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }

            // Characters do not match
            else {
                dp[i][j] = max(dp[i - 1][j],
                               dp[i][j - 1]);
            }
        }
    }

    printf("%d\n", dp[m][n]);

    return 0;
}