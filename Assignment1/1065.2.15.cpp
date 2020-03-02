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

linkNode * linkab(linkNode * a, linkNode * b) {
    linkNode * p = a;
    while (p->nxt) {
        p = p->nxt;
    }
    p->nxt = b->nxt;
    a->v += b->v;
    delete b;
    return a;
}

int main() {
    linkNode * lla = new linkNode;
    linkNode * llb = new linkNode;
    scanf("%d %d", &(lla->v), &(llb->v));
    int tt;
    linkNode * p = lla;
    for (int i = 0; i < lla->v; i++) {
        scanf("%d", &tt);
        p->nxt = new linkNode(tt);
        p = p->nxt;
    }
    p = llb;
    for (int i = 0; i < llb->v; i++) {
        scanf("%d", &tt);
        p->nxt = new linkNode(tt);
        p = p->nxt;
    }
    if (lla->v <= llb->v) {
        lla = linkab(lla, llb);
    } else {
        lla = linkab(llb, lla);
    }
    printll(lla);
    return 0;
}