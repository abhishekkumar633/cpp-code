#include <stdio.h>
#include <stdlib.h>

void dijkstra(int n, int cost[20][20], int s, int dist[20]) {
    int visited[20], count = 1, min, v;

    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
        dist[i] = cost[s][i];
    }

    dist[s] = 0;
    visited[s] = 1;

    while (count < n) {
        min = 999;
        for (int i = 1; i <= n; i++) {
            if (dist[i] < min && !visited[i]) {
                min = dist[i];
                v = i;
            }
        }

        visited[v] = 1;
        count++;

        for (int i = 1; i <= n; i++) {
            if (!visited[i] && dist[i] > dist[v] + cost[v][i]) {
                dist[i] = dist[v] + cost[v][i];
            }
        }
    }
}

int main() {
    int cost[20][20], dist[20], s, n;

    printf("Enter number of nodes:\n");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0 && i != j)
                cost[i][j] = 999; // Use a large number to represent infinity
        }
    }

    printf("Enter source vertex:\n");
    scanf("%d", &s);

    dijkstra(n, cost, s, dist);

    printf("Shortest paths from node %d:\n", s);
    for (int i = 1; i <= n; i++) {
        if (i != s)
            printf("%d -> %d = %d\n", s, i, dist[i]);
    }

    return 0;
}
