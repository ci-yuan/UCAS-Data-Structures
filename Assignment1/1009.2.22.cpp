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
        printf("%c,", a->v);
        a = a->nxt;
    }
    printf("%c\n", a->v);
}

void llreverse(linkNode * ll) {
    linkNode * p_prv = NULL;
    linkNode * p = ll->nxt;
    linkNode * tt;
    while (p) {
        tt = p->nxt;
        p->nxt = p_prv;
        p_prv = p;
        p = tt;
    }
    ll->nxt = p_prv;
}

int main() {
    char ch;
    linkNode * ll = new linkNode;
    linkNode * p = ll;
    while ((ch = getchar()) != EOF && ch != '\n') {
        if (ch != ',') {
            p->nxt = new linkNode(ch);
            ll->v += 1;
            p = p->nxt;
        }
    }
    llreverse(ll);
    printll(ll);
    return 0;
}