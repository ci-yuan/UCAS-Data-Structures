// Xu Zefan 2018K8009929037
// Assignments for Data Structures Course in UCAS

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

struct linkNode {
    int data, freq, seq;
    linkNode * next, * pre;
    linkNode() {
        data = 0;
        freq = 0;
        seq = 0;
        next = NULL;
        pre = NULL;
    }
    linkNode(int x): data(x) {
        freq = 0;
        seq = 0;
        next = NULL;
        pre = NULL;
    }
};

void link2(linkNode * p, linkNode * q) {
    if (p) {
        p->next = q;
    }
    if (q) {
        q->pre = p;
    }
}

void link3(linkNode * p, linkNode * x, linkNode * q) {
    if (p) {
        p->next = x;
    }
    if (q) {
        q->pre = x;
    }
    x->pre = p;
    x->next = q;
}

void printll(linkNode * ll) {
    for (linkNode *p = ll->next; p != ll; p = p->next) {
        printf("%d", p->data);
        if (p->next != ll) {
            printf(" ");
        }
    }
    printf("\n");
}

linkNode * locatell(linkNode * ll, int tt) {
    for (linkNode *p = ll->next; p != ll; p = p->next) {
        if (p->data == tt) {
            p->freq += 1;
            return p;
        }
    }
    return NULL;
}

void movell(linkNode * ll, linkNode * pp) {
    linkNode * q;
    for(q = pp->pre; q != ll; q = q->pre) {
        if (q->freq > pp->freq) {
            break;
        }
        if (q->freq == pp->freq && q->seq < pp->seq){
            break;
        }
    }
    if (pp != q) {
        link2(pp->pre, pp->next);
        link3(q, pp, q->next);
    }
}

int main() {
    int nn;
    scanf("%d", &nn);
    linkNode * ll = new linkNode(nn);
    link2(ll, ll);
    linkNode * p = ll;
    int tt;
    for (int i = 0; i < nn; i++) {
        scanf("%d", &tt);
        link3(p, new linkNode(tt), ll);
        p = p->next;
    }
    // printll(ll);

    int cnt = 1;
    while (scanf("%d", &tt) == 1) {
        p = locatell(ll, tt);
        if (!p->seq) {
            p->seq = cnt++;
        }
        movell(ll, p);
        // printll(ll);
    }
    printll(ll);
    return 0;
}