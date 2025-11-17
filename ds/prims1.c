#include <stdio.h>
#include <limits.h>

#define MAX 100

int main() {
    int n, start;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter starting vertex (0 to %d): ", n-1);
    scanf("%d", &start);

    int V[MAX] = {0};
    int A[n][n];

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);

            // Replace 0 with INT_MAX only if not diagonal
            if (A[i][j] == 0 && i != j)
                A[i][j] = INT_MAX;
        }
    }

    int e = 0, cost = 0;
    V[start] = 1;  // Start from user-given vertex

    while (e < n - 1) {
        int min = INT_MAX;
        int u = -1, v = -1;

        for (int i = 0; i < n; i++) {
            if (V[i]) {
                for (int j = 0; j < n; j++) {
                    if (!V[j] && A[i][j] < min) {
                        min = A[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        V[v] = 1;
        printf("Edge {%d, %d} = %d\n", u, v, min);
        cost += min;
        e++;
    }

    printf("Minimum Cost: %d\n", cost);
    return 0;
}
