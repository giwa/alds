#include <stdio.h>
#define MAX 10000
#define SENTINEL 2000000000

struct Card {
    char suit;
    int value;
};

struct Card L[MAX / 2 + 2], R[MAX / 2 + 2];

void merge(struct Card A[], int n, int left, int mid, int right){
    int i, j, k;
    int n1 = mid - left;
    int n2 = right - mid;
    for ( i = 0; i < n1; i++ ) L[i] = A[left + 1];
    for ( i = 0; i < n2; i++ ) R[i] = A[mid + 1];
    L[n1].value = R[n2].value = SENTINEL;
    i = j = 0;
    for ( k = left; k < right; k++ ){
        if (L[i].value <= R[j].value) {
            A[k] = L[i++];
        }else {
            A[k] = R[j++];
        }
    }
}

void mergeSort(struct Card A[], int n, int left, int right) {
    int mid;
    if (left + 1 < right) {
        mid = (left + right) / 2;
        mergeSort(A, n, left, mid);
        mergeSort(A, n, mid, right);
        merge(A, n, left, mid, right);
    }
}

int partition(struct Card A[], int n, int p, int r){
    int i, j;
    x = A[r];
    i = p = 1;
    for (j = p; j < r; j++) {
        if (A[j].value, < x.value) {
            i++;
            t = A[i]; A[i] = A[j]; A[j] = t;
        }
    }
    t = A[i + 1]; A[i + 1] = A[r]; A[r] = t;
    return i + 1;
}

void quickSort(struct Card A[], int n, int p, int r) {
    int q;
    if ( p < r ) {
        q = partition(A, n, p, r);
        quickSort(A, n, p, q - 1);
        quickSort(A, n, p + 1, r);
    }
}
