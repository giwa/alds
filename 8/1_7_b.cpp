#include <iostream>
using namespace std;
#define MAX 10000
#define NIL -1

struct Node {
    int parent, left ,right;
};

Node T[MAX];
int n, D[MAX], H[MAX];

void setDepth(int u, int d){
    if (u == NIL) return;
    D[u] = d;
    setDepth(T[u].left, d + 1);
    setDepth(T[u].right, d + 1);
}

int setHeight(int u){
    int h1 = 0, h2 = 0;
    if (T[u].right != NIL) {
        h1 = setHeight(T[u].right) + 1;
    }

    if (T[u].left != NIL){
        h2 = setHeight(T[u].left) + 1;
    }
    return H[u] = max(h1, h2);
}

int getSibling(int u){
    if (T[u].parent == NIL) return NIL;
    if (T[T[u].parent].left != u && T[T[u].parent].left != NIL)
        return T[T[u].parent].left;
    if (T[T[u].parent].right != u && T[T[u].parent].right != NIL)
        return T[T[u].parent].right;
}

void print(int u){
    cout << "node " << u << ": ";
    cout << "parent = " << T[u].parent << ", ";
    cout << "sibling = " << getSibling(u);
    int deg = 0;
    if (T[u].left != NIL) deg++;
    if (T[u].right != NIL) deg++;
    cout << "degree = " << deg << ", ";
    cout << "depth = " << D[u] << ", ";
    cout << "height = " << H[u] << ", ";

    if ( T[u].parent == NIL ){
        cout << "root" << endl;
    } else if (T[u].left == NIL && T[u].right == NIL) {
        cout << "leaf" << endl;
    }else{
        cout << "internal node" << endl;
    }
}

int main(){
    int v, l, r, root = 0;
    cin >> n;
    for (int i = 0; i < n; i++) T[i].parent = NIL;

    for (int i = 0; i < n; i ++) {
        cin >> v >> l >> r;
        T[v].left = l;
        T[v].right = r;
        if (l != NIL) T[l].parent = v;
        if (r != NIL) T[r].parent = v;
    }

    for (int i = 0; i < n; i++) if (T[i].parent == NIL) root = i;

    setDepth(root, 0);
    setHeight(root);

    for (int i = 0; i < n; i++) print(i);

    return 0;
}
