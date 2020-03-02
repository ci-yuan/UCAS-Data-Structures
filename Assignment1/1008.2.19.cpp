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
        v = 0;
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

int main() {
    int mink, maxk, tt;
    scanf("%d %d", &mink, &maxk);
    linkNode * ll = new linkNode(0);
    linkNode * p = ll, *q;
    while (scanf("%d", &tt) == 1) {
        p->nxt = new linkNode(mink);
        ll->v += 1;
        p = p->nxt;
        mink = maxk;
        maxk = tt;
    }
    p = ll;
    for (p = ll; p->nxt && p->nxt->v <= mink; p = p->nxt);
    int delta = 0;
    linkNode * q_nxt;
    for (q = p->nxt; q && q->v < maxk; q = q_nxt) {
        q_nxt = q->nxt;
        delete q;
        delta += 1;
    }
    p->nxt = q;
    ll->v -= delta;
    printll(ll);
    return 0;
}