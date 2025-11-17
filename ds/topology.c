#include <stdio.h>
#include <string.h>
#define MAX_NODES 100

int indegree(int graph[][MAX_NODES], int n, int node);

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int A[MAX_NODES][MAX_NODES];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    int V[MAX_NODES] = {0}; // visited array initialized to 0
    int count = 0;

    printf("\nTopological Order:\n");

    while (count < n) {
        int found = 0; // did we find any vertex this round?

        for (int i = 0; i < n; i++) {
            if (indegree(A, n, i) == 0 && !V[i]) {
                printf("%d ", i);
                V[i] = 1;
                for (int j = 0; j < n; j++)
                    A[i][j] = 0; // remove outgoing edges
                count++;
                found = 1;
                break; // go back to while loop
            }
        }

        if (!found) {
            printf("\nCycle detected or invalid input!\n");
            break;
        }
    }

    printf("\n");
    return 0;
}

int indegree(int graph[][MAX_NODES], int n, int node) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += graph[i][node];
    return sum;
}