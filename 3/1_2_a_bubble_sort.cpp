#include <iostream>

using namespace std;

static const int MAX = 100;
int cnt = 0;

void trace(int *a, int n) {
    for (int i = 0; i < n; i++) {
        if(i > 0) cout << ' ';
        cout << a[i];
    }
    cout << '\n';
}

void bubble_sort(int *a, int n) {
    int tmp;
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j > i; j--) {
            if (a[j] < a[j - 1]) {
                cnt++;
                tmp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = tmp;
            }
        }
//        trace(a, n);
    }
}


int main(){
    int R[MAX], n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> R[i];

    bubble_sort(R, n);
    trace(R, n);
    cout << cnt << endl;

    return 0;
}


