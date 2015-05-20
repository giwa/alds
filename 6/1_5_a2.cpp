#include <stdio.h>

int n, A[50];

int solve (int i, int m) {
    if (m == 0) return 1;
    if (i >= n) return 0;
    int res = solve(i + 1, m) || solve(i + 1, m - A[i]);
    return res;
}

int main() {
    int q, M, i;

    // get the number of A
    scanf("%d", &n);
    // get A elements
    for (i = 0; i < n; i++) scanf("%d", &A[i]);
    // get the number of M
    scanf("%d", &q);
    for (i = 0; i < q; i++) {
        // get M elements
        scanf("%d", &M);
        if (solve(0, M)) printf("yes\n");
        else printf("no\n");
    }

    return 0;
}
