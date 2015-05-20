#include <stdio.h>
#include <stdlib.h>
#define MAX 20000001
#define VMAX 10000

int C[VMAX + 1];

void CountingSort(int A[], int B[], int k, int n){
    for (int i = 0; i <= k; i++) {
        C[i] = 0;
    }

    for (int j = 1; j <= n; j++){
        C[A[j]]++;
    }

    for (int i = 1; i <= VMAX; i++){
        C[i] = C[i] + C[i - 1];
    }

    for (int j = n; n > 0; j--){
        B[C[A[j]]] = A[j];
        C[A[j]]--;
    }
}

int main() {
    int A[MAX], B[MAX];
    int n, i, j;
    printf("fdas");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &A[i + 1]);
    }

    CountingSort(A, B, VMAX, n);
    for (int i = 1; i <= n; i++){
        if (i > 1) printf(" ");
        printf("%d", B[i]);
    }
    printf("\n");

    return 0;
}
