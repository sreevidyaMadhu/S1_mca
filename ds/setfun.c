#include <stdio.h>

int main() {
    int U, A[20], B[20];
    int i;

    printf("Enter size of Universal Set: ");
    scanf("%d", &U);

    // Input Bit string for Set A
    printf("Enter bit string for Set A (0 or 1 for each element):\n");
    for (i = 0; i < U; i++)
        scanf("%d", &A[i]);

    // Input Bit string for Set B
    printf("Enter bit string for Set B (0 or 1 for each element):\n");
    for (i = 0; i < U; i++)
        scanf("%d", &B[i]);

    int Union[20], Intersection[20], Difference[20], SymDiff[20];

    // Perform operations
    for (i = 0; i < U; i++) {
        Union[i] = A[i] | B[i];
        Intersection[i] = A[i] & B[i];
        Difference[i] = A[i] & (!B[i]);
        SymDiff[i] = A[i] ^ B[i];
    }

    // Display results
    printf("\nSet A: ");
    for (i = 0; i < U; i++) printf("%d ", A[i]);

    printf("\nSet B: ");
    for (i = 0; i < U; i++) printf("%d ", B[i]);

    printf("\nUnion: ");
    for (i = 0; i < U; i++) printf("%d ", Union[i]);

    printf("\nIntersection: ");
    for (i = 0; i < U; i++) printf("%d ", Intersection[i]);

    printf("\nDifference (A - B): ");
    for (i = 0; i < U; i++) printf("%d ", Difference[i]);

    printf("\nSymmetric Difference: ");
    for (i = 0; i < U; i++) printf("%d ", SymDiff[i]);

    printf("\n");
    return 0;
}
