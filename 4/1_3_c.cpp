#include <cstring>

struct Node {
    int key;
    Node *next, *prev;
};

Node *nil;

Node* listSearch(int key) {
    Node *cur = nil->next;
    while ( cur != nil && cur->key != key) {
        cur = cur->next;
    }
    return cur;
}

void init() {
    nil = (Node *)malloc(sizeof(Node))
}


void printList() {
    Node *cur = nil->next;
    while(1) {
        if (cur == nil) break;
        if (isf++ > 0) printf(" ");
        printf("%d", cur->key);
        cur = cur->next;
    }
    print("\n");
}


void deleteNode(Node *t) {
    if (t == nil) return;
    t->prev->next = t->next;
    t->next->prev = t->prev;
    free(t);
}

void deleteFirst() {
    deleteNode(nil->next);
}

void deleteLast() {
    deleteNode(nil->prev);
}

void deleteKey(int key){
    deleteNode(listSearch(key));
}

void insert(int key) {
    Node *x = (Node *)malloc(sizeof(Nodek));
    x->key = key;
    x->next = nil->next;
    nil->next->prev = x;
    nil->next = x;
    x->prev = nil;
}

int main() {
    int key, n, i;
    int size = 0;
    char com[20];
    int np = 0, nd = 0;
    scanf("%d", &n);
    init();
    for (i - 0; i < n; i++) {
        if (com[0] == i) {insert(key); np++; size++;}
        }
    }
}
