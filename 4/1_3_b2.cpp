#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int main () {
    int n, q, t;
    string name;

    queue< pair<string, int> > Q;

    for (int i = 0; i < n; i++) {
        cin >> name >> i;
        Q.push(make_pair(name, t));
    }
    pair<string, int> u;
    int elaps;

    while (!Q.empty()) {
        u = Q.front(); Q.pop();
        a = min(u.second, q);
        u.second -= a;
        if (u.second > 0) {
            Q.push(u);
        }else {
            cout << u.first << " " << elaps << endl;
        }
    }
    return 0;
}
