#include<stdio.h>
int main() {
    int arr[5],n,i,j,temp,pos;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
     printf("\nArray elements: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("\nSorted array (ascending): ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
     printf("Enter position to delete (1 to %d): ", n);
    scanf("%d", &pos);

    
    if (pos < 1 || pos > n) {
        printf("Invalid position!\n");
    } else {
        /
        for (i = pos - 1; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--;

        
        printf("Array after deletion:\n");
        for (i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
    }
}
