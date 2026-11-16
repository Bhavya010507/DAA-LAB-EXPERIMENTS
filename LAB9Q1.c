#include <stdio.h>
#define INF 1000000000000000000LL
int main() {
    int n, m, source;

    scanf("%d %d", &n, &m);
    scanf("%d", &source);

    long long graph[n][n];

    // Initialize graph
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = INF;
        }
    }

    // Input directed edges
    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;

        scanf("%d %d %lld", &u, &v, &w);

        // In case multiple edges exist
        if (w < graph[u][v]) {
            graph[u][v] = w;
        }
    }

    long long dist[n];
    int visited[n];

    // Initialize distances
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    // Distance from source to itself
    dist[source] = 0;

    for (int count = 0; count < n; count++) {

        int u = -1;
        long long minDist = INF;

        // Find unvisited vertex with minimum distance
        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }

        // Remaining vertices are unreachable
        if (u == -1)
            break;

        visited[u] = 1;

        // Relax all outgoing edges
        for (int v = 0; v < n; v++) {

            if (!visited[v] &&
                graph[u][v] != INF &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Output shortest distances
    for (int i = 0; i < n; i++) {

        if (dist[i] == INF)
            printf("INF");
        else
            printf("%lld", dist[i]);

        if (i < n - 1)
            printf(" ");
    }

    return 0;
}