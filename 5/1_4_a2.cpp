#include <stdio.h>

int A[10000000], n;

int binarySearch(int key) {
    int left = 0;
    int right = n;
    int mid;

    while (left < right) {
        mid = (left + right) / 2;
        if (key == A[mid]) return 1;
        if (key > A[mid]) left = mid + 1;
        else if (key < A[mid]) right = mid;
    }
    return 0;
}
