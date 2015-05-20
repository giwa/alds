#include <stdio.h>
#define MAX 100001

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int A[], int p, int r){
    int x = A[r];
    int i = p - 1;
    for (int j = p; j < r; j++){
        if (A[j] <= x) {
            i++;
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[i + 1], &A[r]);
    return i + 1;
}

int main(){
    int A[MAX];
    int n, r;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &A[i]);
    r = partition(A, 0, n - 1);
    for (int i = 0; i < n; i++){
        if (i) printf(" ");
        if (i == r) printf("[%d]", A[i]);
        else printf("%d", A[i]);
    }

    return 0;
}
