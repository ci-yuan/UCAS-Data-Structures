// Xu Zefan 2018K8009929037
// Assignments for Data Structures Course in UCAS

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

struct linkNode {
    int v;
    linkNode* nxt;
    linkNode() {
        nxt = NULL;
    }
    linkNode(int x): v(x) {
        nxt = NULL;
    }
};

void printll(linkNode * a) {
    if (a->v == 0 || !a->nxt) {
        printf("NULL\n");
        return;
    }
    a = a->nxt;
    while(a->nxt) {
        printf("%d ", a->v);
        a = a->nxt;
    }
    printf("%d\n", a->v);
}

int deleteNode(linkNode * p, int k) {
    if (k >= p->v) {
        return -1;
    }
    p->v -= 1;
    for (int i = 0; i < k; i++){
        p = p->nxt;
    }
    p->nxt = p->nxt->nxt;
    return 0;
}

int main() {
    linkNode * lla = new linkNode;
    int k;
    scanf("%d %d", &(lla->v), &k);
    int tt;
    linkNode * p = lla;
    for (int i = 0; i < lla->v; i++) {
        scanf("%d", &tt);
        p->nxt = new linkNode(tt);
        p = p->nxt;
    }
    deleteNode(lla, k);
    printll(lla);
    return 0;
}