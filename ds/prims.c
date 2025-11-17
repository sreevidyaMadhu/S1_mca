#include <stdio.h>

#define INF 9999
#define MAX 100

int main() {
    int cost[MAX][MAX];
    int visited[MAX] = {0};
    int n, start;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix (0 for no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0 && i != j)
                cost[i][j] = INF; // no edge
        }
    }

    printf("Enter starting node (0 to %d): ", n - 1);
    scanf("%d", &start);

    visited[start] = 1; // Start from any user-chosen node

    int edge_count = 0;
    int mincost = 0;

    printf("\nEdges in Minimum Spanning Tree:\n");

    while (edge_count < n - 1) {
        int min = INF;
        int a = -1, b = -1;

        // Find minimum cost edge from visited → unvisited
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        printf("%d - %d : %d\n", a, b, min);
        mincost += min;
        visited[b] = 1;
        edge_count++;
    }

    printf("\nTotal Minimum Cost = %d\n", mincost);
    return 0;
}
